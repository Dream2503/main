# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    my_numbers = my_numbers.drop_duplicates(keep=False)
    return pd.DataFrame(my_numbers.max(), columns=["num"])
# leetcode submit region end(Prohibit modification and deletion)
