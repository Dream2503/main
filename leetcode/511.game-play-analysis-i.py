# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    return activity.sort_values("event_date").drop_duplicates("player_id")[["player_id", "event_date"]].rename(
        columns={"event_date": "first_login"})
# leetcode submit region end(Prohibit modification and deletion)
