# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values("recordDate", inplace=True)
    weather["recordDate"] = pd.to_datetime(weather["recordDate"])
    condition1 = (weather["recordDate"] - weather["recordDate"].shift(1)).dt.days == 1
    condition2 = weather["temperature"] > weather["temperature"].shift(1)
    return weather[condition1 & condition2][["id"]]
# leetcode submit region end(Prohibit modification and deletion)
