# leetcode submit region begin(Prohibit modification and deletion)
from datetime import timedelta
import pandas as pd


def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity["event_date"] = pd.to_datetime(activity["event_date"])
    numerator = denominator = 0

    for _, df in activity.sort_values("event_date").groupby("player_id"):
        if len(df) > 1 and df["event_date"].iloc[0] + timedelta(days=1) == df["event_date"].iloc[1]:
            numerator += 1

        denominator += 1

    return pd.DataFrame({"fraction": [round(numerator / denominator, 2)]})
# leetcode submit region end(Prohibit modification and deletion)
