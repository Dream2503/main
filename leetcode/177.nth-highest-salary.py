# leetcode submit region begin(Prohibit modification and deletion)
import numpy as np
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    array = np.unique(employee["salary"].values)
    return pd.DataFrame({f"getNthHighestSalary({N})": [array[-N] if array.shape[0] >= N > 0 else None]})
# leetcode submit region end(Prohibit modification and deletion)
