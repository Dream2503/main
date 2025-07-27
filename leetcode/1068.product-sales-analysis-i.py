# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(product, sales, "inner", "product_id")[["product_name", "year", "price"]]
# leetcode submit region end(Prohibit modification and deletion)
