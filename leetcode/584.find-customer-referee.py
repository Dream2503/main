# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_customer_referee(customer: pd.DataFrame) -> pd.DataFrame:
    return customer.drop(customer[customer["referee_id"] == 2].index)[["name"]]
# leetcode submit region end(Prohibit modification and deletion)
