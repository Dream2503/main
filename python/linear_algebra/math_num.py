from fractions import Fraction
from typing import Any, Literal
import math, cmath

FUNCTIONS: set[str] = {"sqrt", "cbrt", "log", "ln", "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh", "tanh",
                       "asinh", "acosh", "atanh", "+", "-", "*", "/", "**"}
math.ln = math.log
math.log = math.log10
math.π = math.pi
cmath._log = cmath.log
cmath.ln = lambda x: cmath._log(x, cmath.e)
cmath.log = cmath.log10
cmath.π = cmath.pi


class MathNum:
    pi: str = "π"  # alt + 227
    e: str = "e"

    def __init__(self, num: Any, domain: Literal["real", "complex"] = "real"):
        if isinstance(num, MathNum):
            self.value: tuple[Fraction, Fraction] | str = num.value
            self.domain: str = num.domain
            self.operations: list[tuple[str, MathNum | None]] = num.operations.copy()

        else:
            if isinstance(num, complex):
                domain = "complex"

            if num in ("π", "e"):
                self.value: tuple[Fraction, Fraction] | str = num

            elif isinstance(num, tuple):
                self.value: tuple[Fraction, Fraction] | str = Fraction(num[0]), Fraction(num[1])
                domain = "real" if self.value[1] == 0 else "complex"

            elif domain == "real":
                self.value: tuple[Fraction, Fraction] | str = Fraction(num), Fraction(0)

            else:
                res: complex = complex(num)
                self.value: tuple[Fraction, Fraction] = Fraction(res.real), Fraction(res.imag)

            self.domain: str = domain
            self.operations: list[tuple[str, MathNum | None]] = []

    def __repr__(self) -> str:
        return f"MathNum(value={self.value}, operations={self.operations}, domain={self.domain})"

    def __str__(self) -> str:
        res: str = recur_str(self.value, self.operations)
        res = optimize_braces(res)
        return res

    def __add__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("+", MathNum(other)))
        return res

    def __sub__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("-", MathNum(other)))
        return res

    def __mul__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("*", MathNum(other)))
        return res

    def __truediv__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("/", MathNum(other)))
        return res

    def __pow__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("**", MathNum(other)))
        return res

    __radd__ = lambda self, other: MathNum(other) + self
    __rsub__ = lambda self, other: MathNum(other) - self
    __rmul__ = lambda self, other: MathNum(other) * self
    __rtruediv__ = lambda self, other: MathNum(other) / self
    __rpow__ = lambda self, other: MathNum(other) ** self
    expression = lambda self: str(self)
    copy = lambda self: MathNum(self)

    def sqrt(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("sqrt", None))
        return res

    def cbrt(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("cbrt", None))
        return res

    def log(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("log", None))
        return res

    def ln(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("ln", None))
        return res

    def sin(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("sin", None))
        return res

    def cos(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("cos", None))
        return res

    def tan(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("tan", None))
        return res

    def asin(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("asin", None))
        return res

    def acos(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("acos", None))
        return res

    def atan(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("atan", None))
        return res

    def sinh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("sinh", None))
        return res

    def cosh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("cosh", None))
        return res

    def tanh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("tanh", None))
        return res

    def asinh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("asinh", None))
        return res

    def acosh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("acosh", None))
        return res

    def atanh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append(("atanh", None))
        return res

    def value_str(self) -> str:
        if self.domain == "real":
            return str(self.value[0])

        else:
            res: str = ""
            is_complete: bool = self.value[0] != 0 and self.value[1] != 0

            if is_complete:
                res += "("

            if self.value[0] != 0:
                res += str(self.value[0])

            if is_complete:
                res += f" + "

            if self.value[1] != 0:
                res += f"{self.value[1]}i"

            if is_complete:
                res += ")"

            return res

    def evaluate(self, level: int = -1) -> float:
        number: list[float, float] = [0, 0]

        for i in range(2):
            try:
                number[i] = float(self.value[i])
            except (IndexError, ValueError):
                number[i] = eval(f"math.{self.value[0]}")

        if self.domain == "real":
            num: float = float(number[0])

        else:
            num: complex = complex(number[0], number[1])

        for idx, operation in enumerate(self.operations):
            if operation[1] is None:
                if self.domain == "real":
                    num = eval(f"math.{operation[0]}({num})")

                else:
                    num = eval(f"cmath.{operation[0]}({num})")

            else:
                num = eval(f"{num} {operation[0]} {operation[1].evaluate()}")

        return num


def recur_str(value: tuple[Fraction, Fraction], operations: list[tuple[str, "MathNum | None"]]) -> str:
    if not operations:
        return MathNum(value).value_str()

    elif operations[-1][1] is None:
        return f"{operations[-1][0]}({recur_str(value, operations[:-1])})"

    else:
        return f"({recur_str(value, operations[:-1])} {operations[-1][0]} {operations[-1][1]})"


def optimize_braces(expression: str) -> str:
    size: int = len(expression)
    target_braces: dict[str, set[int]] = {"start": set(), "end": set()}
    start_brace_cnt: int = 0
    end_brace_cnt: int = 0

    for i in range(size - 1):
        if expression[i] == "(":
            start_brace_cnt += 1

            if expression[i + 1] == "(" and not expression[i - 1].isalpha():
                target_braces["start"].add(start_brace_cnt)

    for i in range(size - 1):
        if expression[i] == ")":
            end_brace_cnt += 1

            if expression[i + 1] == ")":
                target_braces["end"].add(end_brace_cnt)

    # for i in range(size - 1, 0, -1):
    #     if expression[i] == ")":
    #         end_brace_cnt += 1
    #
    #         if expression[i - 1] == ")":
    #             target_braces["end"].add(end_brace_cnt)

    to_remove: set[int] = target_braces["start"] & target_braces["end"]
    target_braces["start"] = to_remove.copy()
    target_braces["end"] = to_remove.copy()
    total_brace_cnt: int = start_brace_cnt
    start_brace_cnt = 0
    end_brace_cnt = 0
    i = 0

    while to_remove and total_brace_cnt and i < size:
        if expression[i] == "(":
            start_brace_cnt += 1

        elif expression[i] == ")":
            end_brace_cnt += 1

        if start_brace_cnt in target_braces["start"]:
            expression = expression[:i] + expression[i + 1:]
            size -= 1
            target_braces["start"].remove(start_brace_cnt)

        if (end_brace_cnt) in target_braces["end"]:
            expression = expression[:i] + expression[i + 1:]
            size -= 1
            target_braces["end"].remove(end_brace_cnt)

        i += 1

    return expression
