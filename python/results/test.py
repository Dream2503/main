import asyncio
import csv
import fitz
import os
from playwright.async_api import async_playwright
from re import Match
import re
import string
from typing import Any, Generator

ERP_URL: str = "https://erp.silicon.ac.in/estcampus/index.php"
RESULT_URL: str = "https://sic-to-result.netlify.app/"
BRANCH: tuple[str, str, str, str] = ("CS", "EC", "EE", "EI")
YEAR: int = 24
SEM_COUNT: int = 2
FILENAME: str = f"batch{YEAR}.csv"
FIELDNAMES: list[str] = ["Name", "SIC"] + [f"SEM{i + 1}" for i in range(SEM_COUNT)] + ["CGPA"]
USERNAME: str = "24bcsh93"
PASSWORD: str = "Swapnaraj2503?"


def sics() -> Generator[str, Any, None]:
    for branch in BRANCH:
        for ch in string.ascii_uppercase:
            for n in range(1, 100):
                yield f"{YEAR}B{branch}{ch}{n:02d}"


def extract_results(filepath: str) -> dict[str, str | float] | None:
    text: str = ""

    with fitz.open(filepath) as doc:
        for page in doc:
            text += page.get_text()

    if "Sorry! Final Result Not yet Published" in text:
        return None

    name_match: Match[str] | None = re.search(r"Name\s*:\s*(.*?)\s*Regd No", text, re.DOTALL)
    name: str | None = name_match.group(1).strip() if name_match else None
    sic_match: Match[str] | None = re.search(r"SIC No\s*:\s*(\S+)", text)
    sic: str | None = sic_match.group(1).strip() if sic_match else None
    sgpas: list[str] = re.findall(r"SGPA\s*=\s*([\d.]+)", text)
    cgpa_match: Match[str] | None = re.search(r"CGPA\s*=\s*([\d.]+)", text)

    if name and sic and len(sgpas) >= SEM_COUNT and cgpa_match:
        result: dict[str, str | float] = {
            "Name": name,
            "SIC": sic,
            "CGPA": float(cgpa_match.group(1))
        }

        for i in range(SEM_COUNT):
            result[f"SEM{i + 1}"] = float(sgpas[i])

        return result

    else:
        return None


def init_csv(filename=FILENAME) -> None:
    with open(filename, "w", newline="") as f:
        csv.DictWriter(f, fieldnames=FIELDNAMES).writeheader()


def append_result_to_csv(result: dict[str, str | float], filename: str = FILENAME) -> None:
    with open(filename, "a", newline="") as f:
        csv.DictWriter(f, fieldnames=FIELDNAMES).writerow(result)


async def run():
    init_csv()

    async with async_playwright() as p:
        browser = await p.chromium.launch(headless=True)
        context = await browser.new_context(accept_downloads=True)
        page = await context.new_page()

        await page.goto(ERP_URL)
        await page.fill("input[name='username']", USERNAME)
        await page.fill("input[name='password']", PASSWORD)
        await page.click("button[type='submit']")
        await page.wait_for_load_state("networkidle")
        print("Logged in successfully!")

        result_page = await context.new_page()
        await result_page.goto(RESULT_URL)

        for sic in sics():
            print(f"Processing SIC: {sic}")
            await result_page.fill("input", sic)

            try:
                async with result_page.expect_download(timeout=5000) as download_info:
                    await result_page.click("button")

                download = await download_info.value
                save_path: str = f"{sic}.pdf"
                await download.save_as(save_path)
                data: dict[str, str | float] | None = extract_results(save_path)

                if data:
                    append_result_to_csv(data)
                    print(f"✅ {data['SIC']} - {data['Name']} - CGPA={data['CGPA']}")

                else:
                    print(f"❌ {sic} not published")

                os.remove(save_path)

            except Exception as e:
                print(f"⚠ Skipped {sic} due to error: {e}")

        await browser.close()
        print(f"📄 Results saved in {FILENAME}")


asyncio.run(run())