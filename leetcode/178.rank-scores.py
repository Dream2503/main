# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores["rank"] = scores["score"].rank(method="dense", ascending=False)
    return scores.sort_values("score", ascending=False).loc[["score", "rank"]]
# leetcode submit region end(Prohibit modification and deletion)
