# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(product, sales, "inner", "product_id").groupby('product_id').filter(
        lambda x: x['sale_date'].min() >= pd.to_datetime('2019-01-01') and x['sale_date'].max() <= pd.to_datetime(
            '2019-03-31')).drop_duplicates(subset='product_id')[['product_id', 'product_name']]
# leetcode submit region end(Prohibit modification and deletion)
