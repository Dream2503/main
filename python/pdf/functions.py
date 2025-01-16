from os import makedirs, remove
from PyPDF2 import PdfMerger, PdfReader, PdfWriter, PageObject
from pdfminer.high_level import extract_text
from pymupdf import Document
import fitz

def merge(path_list: list[str], output: str) -> None:
    pdf_merger: PdfMerger = PdfMerger()

    for pdf in path_list:
        pdf_merger.append(pdf)

    with open(f"./output/{output}", 'wb') as f:
        pdf_merger.write(f)


def split(path: str, split_range: tuple[tuple[int, int]], output_prefix: str) -> None:
    pdf_reader: PdfReader = PdfReader(path)

    for i, (start, end) in enumerate(split_range):
        pdf_writer: PdfWriter = PdfWriter()

        for page_num in range(start - 1, end):
            pdf_writer.add_page(pdf_reader.pages[page_num])

        output_filename: str = f"{output_prefix}_split_{start}-{end}.pdf"

        with open(f"./output/{output_filename}", 'wb') as output_pdf:
            pdf_writer.write(output_pdf)


def pdf_to_text(path: str, output: str) -> None:
    with open(f"./output/{output}", 'w', encoding='utf-8') as f:
        f.write(extract_text(path))


def images_from_pdf(pdf_path: str, output_dir: str) -> None:
    pdf_document: Document = fitz.open(pdf_path)

    for page_num in range(len(pdf_document)):
        page = pdf_document[page_num]
        images = page.get_images(full=True)

        for img_index, img in enumerate(images):
            image = pdf_document.extract_image(img[0])
            image_bytes = image["image"]
            image_path: str = f"./output/{output_dir}/page_{page_num + 1}_img_{img_index + 1}.{image["ext"]}"
            makedirs(f"./output/{output_dir}", exist_ok=True)

            with open(image_path, "wb") as img_file:
                img_file.write(image_bytes)