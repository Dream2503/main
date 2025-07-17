# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    res = 0

    for tiv_2015, df in insurance.drop_duplicates(["lat", "lon"]).groupby("tiv_2015"):
        if len(df) > 1:
            res += df["tiv_2016"].sum()

    return pd.DataFrame({"tiv_2016": [round(res, 2)]})
# leetcode submit region end(Prohibit modification and deletion)
