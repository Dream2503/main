# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_inventory_imbalance(stores: pd.DataFrame, inventory: pd.DataFrame) -> pd.DataFrame:
    res = pd.DataFrame(columns=[
        "store_id", "store_name", "location",
        "most_exp_product", "cheapest_product",
        "imbalance_ratio"
    ])
    inventory = pd.merge(inventory, stores, how="left", on="store_id")

    for store_id, df in inventory.groupby("store_id"):
        if df["product_name"].nunique() >= 3:
            df_max = df[df["price"] == df["price"].max()].iloc[0]
            df_min = df[df["price"] == df["price"].min()].iloc[0]

            if df_max["quantity"] < df_min["quantity"]:
                res.loc[len(res)] = [
                    store_id,
                    df["store_name"].iloc[0],
                    df["location"].iloc[0],
                    df_max["product_name"],
                    df_min["product_name"],
                    df_min["quantity"] / df_max["quantity"]
                ]
    res["imbalance_ratio"] = res["imbalance_ratio"].round(2)
    return res.sort_values(["imbalance_ratio", "store_name"], ascending=[False, True])
# leetcode submit region end(Prohibit modification and deletion)
