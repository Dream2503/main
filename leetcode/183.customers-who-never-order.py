# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({"Customers": customers.set_index("id").drop(orders["customerId"])["name"]})
# leetcode submit region end(Prohibit modification and deletion)
