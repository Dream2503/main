# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world[(world["area"] >= 3e6) | (world["population"] >= 25e6)][["name", "population", "area"]]
# leetcode submit region end(Prohibit modification and deletion)
