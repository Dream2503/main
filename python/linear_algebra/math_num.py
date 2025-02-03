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

    def __init__(self, num: Any = 0, domain: Literal["real", "complex"] = "real", *,
                 operations: list[tuple[str, "MathNum | None"]] | None = None):
        # if domain not in ("real", "complex"):
        #     raise ValueError("Invalid number domain")
        #
        # if isinstance(num, MathNum):
        #     self._value: tuple[str | float, str | float] = num.value
        #     self._domain: str = num.domain
        #     self._operations: list[tuple[str, MathNum | None]] = num.operations.copy()
        #
        # else:
        #     if domain == "complex" or isinstance(num, complex):
        #         domain = "complex"
        #
        #         if isinstance(num, complex):
        #             res: complex = complex(num)
        #             self._value: tuple[str | float, str | float] = res.real, res.imag
        #         try:
        #             if num[0] in ("π", "e") and num[1] in ("π", "e"):
        #                 self._value: tuple[str | float, str | float] = num[0], num[1]
        #         except TypeError:
        #             pass
        #
        #     elif isinstance(num, float):
        #         self._value: tuple[str | float, str | float] = (num, 0)
        #
        #     elif isinstance(num, tuple):
        #         self._value: tuple[str | float, str | float] = num[0], num[1]
        #         domain = "real" if self.value[1] == 0 else "complex"
        #
        #     elif num in ("π", "e"):
        #         self._value: tuple[str | float, str | float] = num
        #
        #     elif domain == "real":
        #         self._value: tuple[str | float, str | float] = num, 0
        #
        #     from fractions import Fraction
        #
        #     if num[0] not in ("π", "e"):
        #         num[0] = float(Fraction(num[0]))
        #
        #     if num[1] not in ("π", "e"):
        #         num[1] = float(Fraction(num[1]))
        #
        #         if num[1] == 0:
        #             Fraction(1, 0)
        #
        #     self._domain: str = domain
        #     self._operations: list[tuple[str, MathNum | None]] = operations if operations is not None else []

    @property
    def value(self) -> tuple[str | float, str | float]:
        return self._value

    @property
    def operations(self) -> list[tuple[str, "MathNum | None"]]:
        return self._operations

    @property
    def domain(self) -> str:
        return self._domain

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
    __repr__ = lambda self: recur_str(self.value, self.operations)
    __str__ = lambda self: optimize_braces(repr(self))
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

            if self.value[0] != 0:
                res += str(self.value[0])

            if is_complete:
                res += " + "

            if self.value[1] != 0:
                res += f"{self.value[1]}j"

            if is_complete:
                res = f"({res})"

            return res

    def evaluate(self, level: int = -1) -> "MathNum":
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
            if idx == level:
                return MathNum(num, operations=self.operations[idx:])

            if operation[1] is None:
                if self.domain == "real":
                    num = eval(f"math.{operation[0]}({num})")

                else:
                    num = eval(f"cmath.{operation[0]}({num})")

            else:
                num = eval(f"{num} {operation[0]} {operation[1].evaluate()}")

        return MathNum(num)


def recur_str(value: tuple[str | float, str | float], operations: list[tuple[str, "MathNum | None"]]) -> str:
    if not operations:
        return MathNum(value).value_str()

    elif operations[-1][1] is None:
        return f"{operations[-1][0]}({recur_str(value, operations[:-1])})"

    else:
        return f"({recur_str(value, operations[:-1])} {operations[-1][0]} {operations[-1][1].__repr__()})"


def optimize_braces(expression: str) -> str:
    size: int = len(expression)
    brace_pos: list[int] = []
    brace_cnt: int = 0
    i: int = 0
    j: int = size - 1

    while i < j:
        while i < j:
            if expression[i] == "(":
                brace_cnt += 1

                if expression[i + 1] == "(":
                    brace_pos.append(i)
                    i += 2
                    break

            i += 1

        while i < j:
            if expression[j] == ")" and expression[j - 1] == ")":
                brace_pos.append(j)
                j -= 2
                break

            j -= 1

    brace_pos.sort()

    for idx, value in enumerate(brace_pos):
        partition: int = value - idx
        expression = expression[:partition] + expression[partition + 1:]

    return expression
