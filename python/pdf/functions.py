from shutil import rmtree
from PyPDF2 import PdfMerger, PdfReader, PdfWriter, PageObject
from pymupdf import Document, Page
import fitz, os


def merge(path_list: list[str], output: str) -> None:
    pdf_merger: PdfMerger = PdfMerger()

    for pdf in path_list:
        pdf_merger.append(pdf)

    with open(f"./output/{output}.pdf", 'wb') as f:
        pdf_merger.write(f)


def split(path: str, split_range: tuple[tuple[int, int]], output_prefix: str) -> None:
    pdf_reader: PdfReader = PdfReader(path)

    for i, (start, end) in enumerate(split_range):
        pdf_writer: PdfWriter = PdfWriter()

        for page_num in range(start - 1, end):
            pdf_writer.add_page(pdf_reader.pages[page_num])

        with open(f"./output/{output_prefix}_split_{start}-{end}.pdf", 'wb') as output_pdf:
            pdf_writer.write(output_pdf)


def to_text(path: str, output: str) -> None:
    from pdfminer.high_level import extract_text

    with open(f"./output/{output}.txt", 'w', encoding='utf-8') as f:
        f.write(extract_text(path))


def extract_image(pdf_path: str, output_dir: str) -> None:
    pdf_document: Document = fitz.open(pdf_path)

    for page_num in range(len(pdf_document)):
        page: Page = pdf_document[page_num]
        images = page.get_images(full=True)

        for img_index, img in enumerate(images):
            image = pdf_document.extract_image(img[0])
            image_bytes = image["image"]
            image_path: str = f"./output/{output_dir}/page_{page_num + 1}_img_{img_index + 1}.{image["ext"]}"
            os.makedirs(f"./output/{output_dir}", exist_ok=True)

            with open(image_path, "wb") as img_file:
                img_file.write(image_bytes)


def rotate(path: str, page_nos: tuple[int] | None, rotation_angle: int, output: str):
    reader: PdfReader = PdfReader(path)
    writer: PdfWriter = PdfWriter()
    page_nums: set[int] | None = set(page_nos) if page_nos else None

    for page_num in range(len(reader.pages)):
        page: PageObject = reader.pages[page_num]

        if page_nums is None or (page_nums is not None and (page_num + 1) in page_nums):
            page.rotate(rotation_angle)

        writer.add_page(page)

    with open(f"./output/{output}.pdf", "wb") as output_file:
        writer.write(output_file)


def delete(path: str, page_nos: tuple[int], output: str):
    reader: PdfReader = PdfReader(path)
    writer: PdfWriter = PdfWriter()
    page_nums: set[int] = set(page_nos)

    for page_num in range(len(reader.pages)):
        if page_num + 1 not in page_nums:
            writer.add_page(reader.pages[page_num])

    with open(f"./output/{output}.pdf", "wb") as output_file:
        writer.write(output_file)


def add_watermark(path: str, watermark: str, output: str):
    pdf_document: Document = fitz.open(path)
    watermark_color: tuple[int, int, int] = (0.5, 0.5, 0.5)
    font_size: int = 50

    for page in pdf_document:
        width, height = page.rect.width, page.rect.height
        page.insert_text(
            (width / 2, height / 2),
            watermark,
            fontsize=font_size,
            rotate=45,
            color=watermark_color,
        )

    pdf_document.save(f"./output/{output}.pdf")


def clear_directory(directory_path):
    for filename in os.listdir(directory_path):
        file_path = os.path.join(directory_path, filename)

        if os.path.isfile(file_path) or os.path.islink(file_path):
            os.remove(file_path)

        elif os.path.isdir(file_path):
            rmtree(file_path)
