# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def not_boring_movies(cinema: pd.DataFrame) -> pd.DataFrame:
    return cinema[(cinema["id"] % 2 == 1) & (cinema["description"] != "boring")].sort_values("rating", ascending=False)
# leetcode submit region end(Prohibit modification and deletion)
