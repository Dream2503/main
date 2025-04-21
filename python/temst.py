from csv import reader, writer

MAIN_FILE: str = ""
LOOKUP_FILE: str = ""
OUTPUT_FILE: str = ""
MAIN_SORT_PARAM: str = "Primary user email address"
LOOKUP_SORT_PARAM: str = "mail"
MERGE_HEADER: str = "accountEnabled"
MERGE_VALUE: str = "True"

with open(MAIN_FILE, "r", encoding="utf-8") as main:
    with open(LOOKUP_FILE, "r", encoding="utf-8") as lookup:
        main_list = list(reader(main))
        lookup_list = list(reader(lookup))
        main_header = main_list[0]
        lookup_header = lookup_list[0]

        sort_param_main_idx = main_header.index(MAIN_SORT_PARAM)
        sort_param_lookup_idx = lookup_header.index(LOOKUP_SORT_PARAM)

        delete_row_values = []

        for i in range(len(lookup_list)):
            for main_row in main_list:
                if lookup_list[i][sort_param_lookup_idx] == main_row[sort_param_main_idx]:
                    break

            else:
                delete_row_values.append(i)

        delete_row_values.reverse()

        for idx in delete_row_values:
            del lookup_list[idx]

        main_list.sort(key=lambda x: x[sort_param_main_idx])
        lookup_list.sort(key=lambda x: x[sort_param_lookup_idx])

        merge_value_idx = lookup_header.index(MERGE_HEADER)
        delete_row_values = [i for i in range(len(lookup_list)) if lookup_list[i][merge_value_idx] != MERGE_VALUE]
        delete_row_values.reverse()

        for value in delete_row_values:
            del main_list[value]

        with open(OUTPUT_FILE, "w", encoding="utf-8") as output:
            output_writer = writer(output)
            output_writer.writerows(main_list)
