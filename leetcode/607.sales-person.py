# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    orders = pd.merge(orders, company[company["name"] == "RED"], "right", "com_id")
    temp = pd.merge(sales_person, orders, "right", "sales_id")
    return sales_person[~sales_person["name"].isin(temp["name_x"])][["name"]]
# leetcode submit region end(Prohibit modification and deletion)
