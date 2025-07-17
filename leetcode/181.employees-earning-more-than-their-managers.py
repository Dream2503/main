# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    res = []
    employee.set_index("id", inplace=True)

    for i in employee.index:
        manager_id = employee.loc[i, "managerId"]

        try:
            if pd.notna(manager_id) and employee.loc[i, "salary"] > employee.loc[manager_id, "salary"]:
                res.append(employee.loc[i, "name"])
        except KeyError:
            pass

    return pd.DataFrame({"Employee": res})
# leetcode submit region end(Prohibit modification and deletion)
