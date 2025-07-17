# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    unbanned_ids = set(users[users["banned"] == "No"]["users_id"])
    trips = trips[(trips["request_at"] >= "2013-10-01") & (trips["request_at"] <= "2013-10-03") &
                  trips["client_id"].isin(unbanned_ids) & trips["driver_id"].isin(unbanned_ids)]

    def generator():
        for date, df in trips.groupby("request_at"):
            cancel_count = df["status"].isin(["cancelled_by_driver", "cancelled_by_client"]).sum()
            yield date, round(cancel_count / len(df), 2)

    return pd.DataFrame(generator(), columns=["Day", "Cancellation Rate"])
# leetcode submit region end(Prohibit modification and deletion)
