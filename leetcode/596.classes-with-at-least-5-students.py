# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    courses = courses.groupby("class").nunique()
    return courses[courses["student"] >= 5].reset_index()[["class"]]
# leetcode submit region end(Prohibit modification and deletion)
