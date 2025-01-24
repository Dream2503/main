try:
    from functions import *

except ModuleNotFoundError:
    from os import system

    system("pip install PyPDF2 pdfminer.six pymupdf")
    del system

finally:
    from functions import *

MAIN_MENU_1 = """
Note: place all your files that need to be processed in the "input" folder and access the processed files from the "output" folder
   -> if multiple files exists and ordering matters then numbers the files by renaming them to preserve the ordering.

Choose any one the functionality mentioned below:
    1. Merge PDFs: Combine multiple PDFs into a single document.
    2. Split PDFs: Extract specific pages or ranges into separate files.
    3. Extract Text: Retrieve text from PDF.
    4. Extract Images: Save embedded images from PDFs.
    5. Rotate Pages: Rotate individual or all pages in a PDF.
    6. Delete Pages: Remove unwanted pages from a document.
    7. Watermarking: Add text watermarks to pages.
    
    8. Next Page
    9. Exit
    
"""


def main() -> None:
    current_menu: int = 1
    ch: int = 0
    output: str
    values: list[str]

    from os import listdir
    path_list: list[str] = listdir(r".\input")
    del listdir

    if not path_list:
        raise ValueError("No files in the \"output\" folder")

    path_list = [r".\input\\" + path for path in path_list]

    while True:
        print(globals()[f"MAIN_MENU_{current_menu}"])

        try:
            ch: int = int(input("Enter your choice: "))

            if 0 > ch or ch > 10:
                raise ValueError

        except ValueError:
            input("Enter valid choice. Try Again...")

        match current_menu:
            case 1:
                match ch:
                    case 1:
                        output = input("Enter the output file name: ")
                        merge(path_list, output)
                        input("PDFs has been successfully merged. Check the output folder for the result.")

                    case 2:
                        while True:
                            print("Enter the page no. ranges to split with space separated: ")
                            print("For Example: 1-3 5-8 13-16")
                            values = input("Enter the values: ").split()
                            split_range: list[tuple[int, int]] = []

                            try:
                                for value in values:
                                    first, second = value.split('-')
                                    split_range.append((int(first), int(second)))

                                break

                            except ValueError:
                                input("Invalid format or input. Try again...")

                        output = input("Enter the output file prefix name: ")
                        split(path_list[0], tuple(split_range), output)
                        input("PDF split has been successfully performed. Check the output folder for the results.")

                    case 3:
                        output = input("Enter the output file name: ")
                        to_text(path_list[0], output)
                        input("PDF to Text has been successfully converted. Check the output folder for the result.")

                    case 4:
                        output = input("Enter the output folder name to store all the images: ")
                        extract_image(path_list[0], output)
                        input(
                            "Images from the pdf has been successfully extracted. Check the output folder for the result.")

                    case 5:
                        while True:
                            values = input(
                                "OPTIONAL: Enter the specific page numbers to rotate (space separated): ").split()

                            if values:
                                try:
                                    rotate_page: tuple[int] | None = tuple(int(value) for value in values)
                                    break

                                except ValueError:
                                    print("Invalid page nos. Try again...")

                            else:
                                rotate_page = None
                                break

                        angle: int = int(input("Enter the clockwise angle to rotate (ex-90): "))
                        output = input("Enter the output file name: ")
                        rotate(path_list[0], rotate_page, angle, output)
                        input("The pages of the PDF has successfully rotated. Check the output folder for the result.")

                    case 6:
                        while True:
                            values = input("Enter the specific page number to delete (space separated): ").split()

                            try:
                                delete_page: tuple[int] = tuple(int(value) for value in values)
                                break

                            except ValueError:
                                print("Invalid page nos. Try again...")

                        output = input("Enter the output file name: ")
                        delete(path_list[0], delete_page, output)
                        input("The pages of the PDF has successfully deleted. Check the output folder for the result.")

                    case 7:
                        watermark: str = input("Enter the text to have as a watermark: ")
                        output = input("Enter the output file name: ")
                        add_watermark(path_list[0], watermark, output)
                        input("The watermark has been added to the pdf. Check the output folder for the result.")

                    case 8:
                        current_menu = 2

                    case 9:
                        print("Thank you for using :)")
                        break

                    case 0:
                        clear_directory(r".\output")
                        input("Output directory was successfully cleared.")


if __name__ == "__main__":
    main()
