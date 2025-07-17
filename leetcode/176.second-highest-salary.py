# leetcode submit region begin(Prohibit modification and deletion)
import numpy as np
import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    array = np.unique(employee["salary"].values)
    return pd.DataFrame({"SecondHighestSalary": [array[-2] if array.shape[0] >= 2 else None]})
# leetcode submit region end(Prohibit modification and deletion)
