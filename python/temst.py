from csv import reader, writer
from time import perf_counter

MAIN_FILE: str = "DevicesWithInventory.csv"
LOOKUP_FILE: str = "exportUser.csv"
OUTPUT_FILE: str = "output.csv"
BLANK: str = "NA"
FILTERS: tuple[tuple[str, str]] = (
    ("OS", "iOS/iPadOS"),
    ("Ownership", "Corporate"),
    ("Device state", "Managed"),
)
HEADER_ORDER: tuple[str, ...] = (
    "Primary user email address", "Primary user display name", "Manufacturer", "Model", "Enrollment date",
    "Last check-in", "OS version", "Serial number", "IMEI", "MEID", "Subscriber carrier", "Total storage",
    "Free storage", "Ownership", "Device state", "OS", "ICCID", "EID", "Phone number"
)
PRIMARY_MAIN: str = "Primary user email address"
PRIMARY_LOOKUP: str = "mail"
LOOKUP_HEAD: str = "accountEnabled"
LOOKUP_VALUE: str = "True"


def filter(data: list[list[str]], check_head: str, check_value: str) -> None:
    head_idx: int = data[0].index(check_head)
    delete_idx: list[int] = [i for i in range(1, len(data)) if data[i][head_idx] != check_value]
    delete_idx.reverse()

    for i in delete_idx:
        del data[i]


def replace_blank(data: list[list[str]]) -> None:
    for i in range(1, len(data)):
        for j in range(len(data[0])):
            if data[i][j] == "":
                data[i][j] = BLANK


def sort_header(data: list[list[str]]) -> list[list[str]]:
    res: list[list[str]] = [[] for _ in range(len(data))]

    for value in HEADER_ORDER:
        head_idx: int = data[0].index(value)

        for j in range(len(data)):
            res[j].append(data[j][head_idx])

    return res


def lookup_remove(main_data: list[list[str]], lookup_data: list[list[str]], primary_main: str, primary_lookup,
                  head: str, value: str) -> list[list[str]]:
    primary_main_idx: int = main_data[0].index(primary_main)
    primary_lookup_idx: int = lookup_data[0].index(primary_lookup)
    head_idx: int = lookup_data[0].index(head)
    delete_idx: list[int] = []
    dict_lookup: dict[str, str] = {lookup_data[i][primary_lookup_idx]: lookup_data[i][head_idx] for i in
                                   range(1, len(lookup_data))}

    for i in range(1, len(main_data)):
        try:
            if dict_lookup.get(main_data[i][primary_main_idx]) != value:
                delete_idx.append(i)

        except KeyError:
            print(main_data[i][primary_main_idx])

    delete_idx.reverse()

    for i in delete_idx:
        del main_data[i]

    return main_data


def main() -> None:
    start: float = perf_counter()

    with open(MAIN_FILE, "r", encoding="utf-8") as f1:
        with open(LOOKUP_FILE, "r", encoding="utf-8") as f2:
            main_data: list[list[str]] = list(reader(f1, lineterminator="\n"))
            lookup_data: list[list[str]] = list(reader(f2, lineterminator="\n"))

            for operation in FILTERS:
                filter(main_data, *operation)

            replace_blank(main_data)
            main_data: list[list[str]] = sort_header(main_data)
            main_data: list[list[str]] = lookup_remove(main_data, lookup_data, PRIMARY_MAIN, PRIMARY_LOOKUP,
                                                       LOOKUP_HEAD, LOOKUP_VALUE)

            with open(OUTPUT_FILE, "w", encoding="utf-8") as output:
                output_writer = writer(output, lineterminator="\n")
                output_writer.writerows(main_data)

    print("time taken:", perf_counter() - start)


if __name__ == "__main__":
    main()
