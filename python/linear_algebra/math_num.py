from typing import Any, Callable
from .meth import *

str_equivalent: dict[float, str] = {PI: "π", E: "e"}
FUNCTIONS: set[str] = {"abs", "sqrt", "cbrt", "log", "ln", "sin", "cos", "tan", "asin", "acos", "atan", "sinh", "cosh",
                       "tanh", "asinh", "acosh", "atanh", "+", "-", "*", "/", "**"}


class MathNum:
    _pi: "MathNum"
    _e: "MathNum"

    def __init__(self, num: Any = 0, *, operations: list[tuple[Callable, "MathNum | None"]] | None = None,
                 domain: Literal["real", "complex", None] = None, datatype: type = Fraction):
        if isinstance(num, MathNum):
            self._value: tuple[Fraction, Fraction] = Fraction(num.value[0]), Fraction(num.value[1])
            self._operations: list[tuple[Callable, MathNum | None]] = num.operations.copy()

        else:
            if isinstance(num, (str, complex)):
                try:
                    temp: complex = complex(num)
                    self._value = (Fraction(str(temp.real)), Fraction(str(temp.imag)))

                except ValueError:
                    self._value = (Fraction(str(num)), Fraction())

            elif isinstance(num, tuple):
                self._value = (Fraction(str(num[0])), Fraction(str(num[1])))

            else:
                self._value = (Fraction(str(num)), Fraction(0))

            self._operations = operations if operations is not None else []

        if domain is not None:
            self._domain: str = domain

        else:
            self._domain: str = "real" if self._value[1] == 0 else "complex"

        if self._domain == "real":
            self._value = (self._value[0], 0)

        self._datatype = datatype

    @property
    def value(self) -> tuple[Any, Any]:
        return self._value

    @property
    def operations(self) -> list[tuple[Callable, "MathNum | None"]]:
        return self._operations

    @property
    def domain(self) -> str:
        return self._domain

    @property
    def pi(self) -> "MathNum":
        return self._pi

    @property
    def e(self) -> "MathNum":
        return self._e

    def __add__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((add, MathNum(other, datatype=self._datatype)))
        return res

    def __sub__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((sub, MathNum(other, datatype=self._datatype)))
        return res

    def __mul__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((mul, MathNum(other, datatype=self._datatype)))
        return res

    def __truediv__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((truediv, MathNum(other, datatype=self._datatype)))
        return res

    def __pow__(self, other: Any) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((pow, MathNum(other, datatype=self._datatype)))
        return res

    def __eq__(self, other: Any) -> bool:
        if isinstance(other, MathNum):
            return ((self.value == other.value and self.operations == other.operations) or
                    (self.evaluate(return_type=Fraction).value == other.evaluate(return_type=Fraction).value) and
                    self.domain == other.domain)

        else:
            try:
                return self == MathNum(other)

            except (ValueError, TypeError):
                return NotImplemented

    def __iadd__(self, other: Any) -> "MathNum":
        self.operations.append((add, MathNum(other, datatype=self._datatype)))
        return self

    def __isub__(self, other: Any) -> "MathNum":
        self.operations.append((sub, MathNum(other, datatype=self._datatype)))
        return self

    def __imul__(self, other: Any) -> "MathNum":
        self.operations.append((mul, MathNum(other, datatype=self._datatype)))
        return self

    def __itruediv__(self, other: Any) -> "MathNum":
        self.operations.append((truediv, MathNum(other, datatype=self._datatype)))
        return self

    def __ipow__(self, other: Any) -> "MathNum":
        self.operations.append((pow, MathNum(other, datatype=self._datatype)))
        return self

    def __lt__(self, other: Any) -> bool:
        if isinstance(other, MathNum):
            return ((self.value < other.value and self.operations == other.operations) or
                    (self.evaluate(return_type=Fraction).value < other.evaluate(return_type=Fraction).value) and
                    self.domain == other.domain)

        else:
            try:
                return self < MathNum(other)

            except (ValueError, TypeError):
                return NotImplemented

    def __gt__(self, other: Any) -> bool:
        if isinstance(other, MathNum):
            return ((self.value > other.value and self.operations == other.operations) or
                    (self.evaluate(return_type=Fraction).value > other.evaluate(return_type=Fraction).value) and
                    self.domain == other.domain)

        else:
            try:
                return self > MathNum(other)

            except (ValueError, TypeError):
                return NotImplemented

    def __ge__(self, other: Any) -> bool:
        if isinstance(other, MathNum):
            return ((self.value > other.value and self.operations == other.operations) or
                    (self.evaluate(return_type=Fraction).value >= other.evaluate(return_type=Fraction).value) and
                    self.domain == other.domain)

        else:
            try:
                return self >= MathNum(other)

            except (ValueError, TypeError):
                return NotImplemented

    __radd__ = lambda self, other: MathNum(other) + self
    __rsub__ = lambda self, other: MathNum(other) - self
    __rmul__ = lambda self, other: MathNum(other) * self
    __rtruediv__ = lambda self, other: MathNum(other) / self
    __rpow__ = lambda self, other: MathNum(other) ** self
    __ne__ = lambda self, other: not (self == other)
    __bool__ = lambda self: self.value[0] != 0 or self.value[1] != 0
    __repr__ = lambda self: MathNum.recur_str(self.value, self.operations, self._datatype)
    __str__ = lambda self: repr(self)
    __pos__ = lambda self: self
    __neg__ = lambda self: self * -1
    __float__ = lambda self: float(self.evaluate().value[0])
    __int__ = lambda self: int(float(self))
    expression = lambda self: str(self)
    copy = lambda self: MathNum(self, datatype=self._datatype)

    def __abs__(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((abs, None))
        return res

    def sqrt(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((sqrt, None))
        return res

    def cbrt(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((cbrt, None))
        return res

    def log(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((log, None))
        return res

    def ln(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((ln, None))
        return res

    def sin(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((sin, None))
        return res

    def cos(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((cos, None))
        return res

    def tan(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((tan, None))
        return res

    def asin(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((asin, None))
        return res

    def acos(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((acos, None))
        return res

    def atan(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((atan, None))
        return res

    def sinh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((sinh, None))
        return res

    def cosh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((cosh, None))
        return res

    def tanh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((tanh, None))
        return res

    def asinh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((asinh, None))
        return res

    def acosh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((acosh, None))
        return res

    def atanh(self) -> "MathNum":
        res: MathNum = self.copy()
        res.operations.append((atanh, None))
        return res

    def evaluate(self, level: int = -1, *, return_type: type = float) -> "MathNum":
        if self.domain == "real":
            num: Any = return_type(self.value[0])

        else:
            num = complex(float(self.value[0]), float(self.value[1]))

        for idx, operation in enumerate(self.operations):
            if idx == level:
                return MathNum(num, operations=self.operations[idx:], datatype=return_type)

            if operation[1] is None:
                if self.domain == "real":
                    num = operation[0](float(num))

                else:
                    num = operation[0](complex(num))

            else:
                num = operation[0](num, operation[1].evaluate(return_type=return_type).to_value())

        return MathNum(num, datatype=return_type)

    def to_value(self) -> Any:
        if self.value[1] != 0:
            return complex(self.value[0], self.value[1])
        else:
            return self._datatype(self.value[0])

    @staticmethod
    def value_str(value: tuple[Fraction, Fraction], datatype: type) -> str:
        res: str = ""
        is_complete: bool = value[0] != 0 and value[1] != 0
        comp: tuple[Fraction, Fraction] = (Fraction(math.pi), Fraction(math.e))

        if value[0] != 0:
            if value[0] in comp:
                res += str_equivalent[value[0]]

            else:
                res += MathNum.num_str(value[0], datatype)

        if is_complete:
            res += "" if value[1] < 0 else "+"

        if value[1] != 0:
            if value[1] in comp:
                res += str_equivalent[value[1]]

            else:
                res += f"{MathNum.num_str(value[1], datatype)}j"

        if is_complete:
            res = f"({res})"

        return res if res else "0"

    @staticmethod
    def recur_str(value: tuple[Fraction, Fraction], operations: list[tuple[str, "MathNum | None"]], return_type: type) -> str:
        if not operations:
            return MathNum.value_str(value, return_type)

        elif operations[-1][1] is None:
            return f"{operations[-1][0]}{MathNum.recur_str(value, operations[:-1], return_type)}"

        else:
            return f"({MathNum.recur_str(value, operations[:-1], return_type)} {operations[-1][0]} {operations[-1][1].__repr__()})"

    @staticmethod
    def num_str(num: Any, datatype: type) -> str:
        if datatype is Fraction:
            if num.denominator == 1:
                return str(num.numerator)

            else:
                return f"({num.numerator}/{num.denominator})"

        return str(datatype(num))


MathNum._pi = MathNum((math.pi, 0), datatype=float)
MathNum._e = MathNum((math.e, 0), datatype=float)