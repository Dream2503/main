# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    res = pd.merge(employee[["empId", "name"]], bonus, "left")
    return res[pd.isna(res["bonus"]) | (res["bonus"] < 1000)][["name", "bonus"]]
# leetcode submit region end(Prohibit modification and deletion)
