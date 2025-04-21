from csv import reader, writer
from time import perf_counter

MAIN_FILE: str = "main.csv"
LOOKUP_FILE: str = "lookup.csv"
OUTPUT_FILE: str = "output.csv"
BLANK: str = "NA"
FILTERS: tuple[tuple[str]] = (
    ("OS", "iOS/iPadOS"),
    ("Ownership", "Corporate"),
    ("Device state", "Managed"),
)
HEADER_ORDER = (
    "Primary user email address", "Primary user display name", "Manufacturer", "Model", "Enrollment date",
    "Last check-in", "OS version", "Serial number", "IMEI", "MEID", "Subscriber carrier", "Total storage",
    "Free storage", "Ownership", "Device state", "OS", "ICCID", "EID", "Phone number"
)
PRIMARY_MAIN = "Primary user email address"
PRIMARY_LOOKUP = "mail"
LOOKUP_HEAD = "accountEnabled"
LOOKUP_VALUE = "True"


def filter(data: list[list], check_head: str, check_value: str) -> None:
    head_idx = data[0].index(check_head)
    delete_idx = [i for i in range(1, len(data)) if data[i][head_idx] != check_value]
    delete_idx.reverse()

    for i in delete_idx:
        del data[i]


def replace_blank(data: list[list]) -> None:
    for i in range(len(data[0])):
        for j in range(1, len(data)):
            if data[j][i] == "":
                data[j][i] = BLANK


def sort_header(data: list[list]) -> list[list]:
    res = [[] for _ in range(len(data))]

    for value in HEADER_ORDER:
        head_idx = data[0].index(value)

        for j in range(len(data)):
            res[j].append(data[j][head_idx])

    return res


def lookup_remove(main_data: list[list], lookup_data: list[list], primary_main: str, primary_lookup, head: str,
                  value: str) -> list[list]:
    primary_main_idx = main_data[0].index(primary_main)
    primary_lookup_idx = lookup_data[0].index(primary_lookup)
    head_idx = lookup_data[0].index(head)
    delete_row_values = []

    for i in range(1, len(main_data)):
        for j in range(1, len(lookup_data)):
            if lookup_data[j][primary_lookup_idx] == main_data[i][primary_main_idx] and lookup_data[j][
                head_idx] == value:
                break

        else:
            delete_row_values.append(i)

    delete_row_values.reverse()

    for idx in delete_row_values:
        del main_data[idx]

    print(len(main_data))
    return main_data


def main() -> None:
    start = perf_counter()

    with open(MAIN_FILE, "r", encoding="utf-8") as f1:
        with open(LOOKUP_FILE, "r", encoding="utf-8") as f2:
            main_data = list(reader(f1, lineterminator="\n"))
            lookup_data = list(reader(f2, lineterminator="\n"))

            for operation in FILTERS:
                filter(main_data, *operation)

            replace_blank(main_data)
            main_data = sort_header(main_data)
            main_data = lookup_remove(main_data, lookup_data, PRIMARY_MAIN, PRIMARY_LOOKUP, LOOKUP_HEAD, LOOKUP_VALUE)

            with open(OUTPUT_FILE, "w", encoding="utf-8") as output:
                output_writer = writer(output, lineterminator="\n")
                output_writer.writerows(main_data)

    print("time taken:", perf_counter() - start)


if __name__ == "__main__":
    main()