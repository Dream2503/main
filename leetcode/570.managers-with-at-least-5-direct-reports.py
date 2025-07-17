# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    counts = employee["managerId"].value_counts()
    res = counts[counts >= 5].index
    return employee[employee["id"].isin(res)][["name"]]
# leetcode submit region end(Prohibit modification and deletion)
