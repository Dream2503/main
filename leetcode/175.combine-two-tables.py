# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(person, address, "left", "personId").iloc[:, [2, 1, 4, 5]]
# leetcode submit region end(Prohibit modification and deletion)
