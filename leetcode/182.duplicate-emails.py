# leetcode submit region begin(Prohibit modification and deletion)
import numpy as np
import pandas as pd


def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({"Email": person["email"][person["email"].duplicated(False)].unique()})
# leetcode submit region end(Prohibit modification and deletion)
