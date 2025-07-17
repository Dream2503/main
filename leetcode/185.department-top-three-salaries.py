#leetcode submit region begin(Prohibit modification and deletion)
import numpy as np
import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    ids = []
    department.set_index("id", inplace=True)


    for i, df in employee.groupby("departmentId"):
        df = df[df["salary"].isin(np.sort(df["salary"].unique())[-3:])]
        df["Department"] = department.loc[i, "name"]
        ids.append(df)

    if ids:
        res = pd.concat(ids, axis=0).loc[:, ["Department", "name", "salary"]]
        res.columns = ["Department", "Employee", "Salary"]

    else:
        res = pd.DataFrame(columns=["Department", "Employee", "Salary"])

    return res
#leetcode submit region end(Prohibit modification and deletion)
