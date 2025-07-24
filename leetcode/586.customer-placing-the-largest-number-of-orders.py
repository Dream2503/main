# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    # pd.DataFrame.max()
    grouped = orders.groupby("customer_number").nunique()
    return grouped[grouped["order_number"] == grouped["order_number"].max()].reset_index()[["customer_number"]]
# leetcode submit region end(Prohibit modification and deletion)
