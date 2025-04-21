from csv import reader, writer
from time import perf_counter

start = perf_counter()

INPUT: str = "main.csv"
OUTPUT: str = "output.csv"
FILTERS: tuple[tuple[str]] = (
    ("OS", "iOS/iPadOS"),
    ("Ownership", "Corporate"),
    ("Device state", "Managed")
)
HEADER_ORDER = (
    "Primary user email address", "Primary user display name", "Manufacturer", "Model", "Enrollment Data",
    "Last check-in", "OS version", "Serial number", "IMEI", "MEID", "Subscriber carrier", "Total storage",
    "Free storage", "Ownership", "Device state", "OS", "ICCID", "EID", "Phone number"
)

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
                data[j][i] = "NA"

def sort_header(data: list[list]) -> list[list]:
    res = [[] for _ in range(len(data))]

    for value in HEADER_ORDER:
        head_idx = data[0].index(value)

        for j in range(len(data)):
            res[j].append(data[j][head_idx])

    return res


def main() -> None:
    with open(INPUT, "r", encoding="utf-8") as f:
        data = list(reader(f))
        header = data[0]

        for operation in FILTERS:
            filter(data, *operation)

        replace_blank(data)
        data = sort_header(data)

        with open(OUTPUT, "w", encoding="utf-8") as output:
            output_writer = writer(output, lineterminator="\n")
            output_writer.writerows(data)


if __name__ == "__main__":
    main()

# MAIN_FILE: str = "main.csv"
# LOOKUP_FILE: str = "lookup.csv"
# OUTPUT_FILE: str = "output.csv"
# MAIN_SORT_PARAM: str = "Primary user email address"
# LOOKUP_SORT_PARAM: str = "mail"
# MERGE_HEADER: str = "accountEnabled"
# MERGE_VALUE: str = "True"
#
# with open(MAIN_FILE, "r", encoding="utf-8") as main:
#     with open(LOOKUP_FILE, "r", encoding="utf-8") as lookup:
#         main_list = list(reader(main, lineterminator='\n'))
#         lookup_list = list(reader(lookup, lineterminator='\n'))
#         main_header = main_list[0]
#         lookup_header = lookup_list[0]
#
#         sort_param_main_idx = main_header.index(MAIN_SORT_PARAM)
#         sort_param_lookup_idx = lookup_header.index(LOOKUP_SORT_PARAM)
#
#         delete_row_values = []
#
#         for i in range(len(lookup_list)):
#             for main_row in main_list:
#                 if lookup_list[i][sort_param_lookup_idx] == main_row[sort_param_main_idx]:
#                     break
#
#             else:
#                 delete_row_values.append(i)
#
#         delete_row_values.reverse()
#
#         for idx in delete_row_values:
#             del lookup_list[idx]
#
#         main_list.sort(key=lambda x: x[sort_param_main_idx])
#         lookup_list.sort(key=lambda x: x[sort_param_lookup_idx])
#
#         merge_value_idx = lookup_header.index(MERGE_HEADER)
#         delete_row_values = [i for i in range(1, len(lookup_list)) if lookup_list[i][merge_value_idx] != MERGE_VALUE]
#         delete_row_values.reverse()
#
#         for value in delete_row_values:
#             del main_list[value]
#
#         with open(OUTPUT_FILE, "w", encoding="utf-8") as output:
#             output_writer = writer(output, lineterminator="\n")
#             output_writer.writerow(main_header)
#             output_writer.writerows(main_list)

print("time taken:", perf_counter() - start)
