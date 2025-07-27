# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    return activity[(activity["activity_date"] >= pd.to_datetime("2019-06-28")) & \
                    (activity["activity_date"] <= pd.to_datetime("2019-07-27"))]. \
        groupby("activity_date", as_index=False).nunique("user_id"). \
        rename(columns={"activity_date": "day", "user_id": "active_users"})[["day", "active_users"]]
# leetcode submit region end(Prohibit modification and deletion)
