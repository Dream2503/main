# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return views[views["author_id"] == views["viewer_id"]].rename(columns={"author_id": "id"})[["id"]]. \
        drop_duplicates().sort_values("id")
# leetcode submit region end(Prohibit modification and deletion)
