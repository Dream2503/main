# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    triangle["triangle"] = "No"
    triangle.loc[(triangle["x"] + triangle["y"] > triangle["z"]) &
                 (triangle["y"] + triangle["z"] > triangle["x"]) &
                 (triangle["z"] + triangle["x"] > triangle["y"]), "triangle"] = "Yes"
    return triangle
# leetcode submit region end(Prohibit modification and deletion)
