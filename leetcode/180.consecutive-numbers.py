# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    array = logs["num"].values
    res = set()

    for i in range(2, len(array)):
        if array[i - 2] == array[i - 1] == array[i]:
            res.add(array[i])
            i += 2

    return pd.DataFrame({"ConsecutiveNums": tuple(res)})
# leetcode submit region end(Prohibit modification and deletion)
