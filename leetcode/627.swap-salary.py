# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def swap_salary(salary: pd.DataFrame) -> pd.DataFrame:
    salary["sex"] = salary["sex"].replace({"m": "f", "f": "m"})
    return salary
# leetcode submit region end(Prohibit modification and deletion)
