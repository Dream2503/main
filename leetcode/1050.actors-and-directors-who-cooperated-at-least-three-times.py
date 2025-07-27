# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    counts = actor_director.groupby(["actor_id", "director_id"]).size().reset_index(name='count')
    return counts[counts['count'] >= 3][["actor_id", "director_id"]]
# leetcode submit region end(Prohibit modification and deletion)
