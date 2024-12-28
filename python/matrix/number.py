from fractions import Fraction
from typing import Callable
import math
import cmath


class Number:
    def __init__(self, num: "int | float | str | Fraction | Number") -> None:
        if isinstance(num, Number):
            self._value: Fraction | complex = num.value
            self._operations: list["str | Number"] = num.operations.copy()

        elif isinstance(num, complex):
            self._value: Fraction | complex = complex(num)
        else:
            self._value: Fraction | complex = Fraction(str(num))
            self._operations: list["str | Number"] = []

    @property
    def value(self) -> Fraction:
        return self._value

    @property
    def operations(self) -> list["str | Number"]:
        return self._operations

    def __repr__(self) -> str:
        return f"Number({self.value}, {self.operations})"

    def __str__(self) -> str:
        return self.display(self.value, self.operations)

    def __add__(self, other: "int | float | Fraction | Number") -> "Number":
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return Number(self.to_float() + other.to_float())

    def __sub__(self, other: "int | float | Fraction | Number") -> "Number":
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return Number(self.to_float() - other.to_float())

    def __mul__(self, other: "int | float | Fraction | Number") -> "Number":
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return Number(self.to_float() * other.to_float())

    def __truediv__(self, other: "int | float | Fraction | Number") -> "Number":
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return Number(self.to_float() / other.to_float())

    def __pow__(self, other: "int | float | Fraction | Number") -> "Number":
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return Number(self.to_float() ** other.to_float())

    def __eq__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return False

        return self.to_float() == other.to_float()

    def __ne__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return True

        return self.to_float() != other.to_float()

    def __lt__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return self.to_float() < other.to_float()

    def __le__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return self.to_float() <= other.to_float()

    def __gt__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return self.to_float() > other.to_float()

    def __ge__(self, other: "int | float | Fraction | Number") -> bool:
        try:
            other: Number = Number(other)

        except ValueError:
            return NotImplemented

        return self.to_float() >= other

    def __abs__(self) -> "Number":
        return Number(abs(self.to_float()))

    def __hash__(self) -> int:
        return hash((self.value, tuple(self.operations)))

    __radd__: Callable[["Number", "int | float | Fraction | Number"], "Number"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Number", "int | float | Fraction | Number"], "Number"] = lambda self, other: self.__sub__(other)
    __rmul__: Callable[["Number", "int | float | Fraction | Number"], "Number"] = lambda self, other: self.__mul__(other)
    __rtruediv__: Callable[["Number", "int | float | Fraction | Number"], "Number"] = lambda self, other: self.__truediv__(other)
    __pos__: Callable[["Number"], "Number"] = lambda self: self
    __neg__: Callable[["Number"], "Number"] = lambda self: self.__mul__(-1)

    def to_float(self) -> float | complex:
        val: float | complex = float(self.value) if isinstance(self.value, Fraction) else self.value

        for operation in self.operations:
            if operation == "log":
                operation = "log10"

            elif operation == "ln":
                operation = "log"

            if isinstance(val, float):
                val: float | complex = eval(f"math.{operation}({val})")
            else:
                if operation == "cbrt":
                    val: float | complex = val ** (1/3)

                else:
                    val: float | complex = eval(f"cmath.{operation}({val})")

        return val

    def display(self, value: Fraction | complex, operations: list["str | Number"]) -> str:
        if operations:
            return f"{operations[0]}({self.display(value, operations[1:])})"

        return str(value)

    sqrt: Callable[[], None] = lambda self: self.operations.append("sqrt")
    cbrt: Callable[[], None] = lambda self: self.operations.append("cbrt")
    ln: Callable[[], None] = lambda self: self.operations.append("ln")
    log: Callable[[], None] = lambda self: self.operations.append("log")
    sin: Callable[[], None] = lambda self: self.operations.append("sin")
    cos: Callable[[], None] = lambda self: self.operations.append("cos")
    tan: Callable[[], None] = lambda self: self.operations.append("tan")
    asin: Callable[[], None] = lambda self: self.operations.append("asin")
    acos: Callable[[], None] = lambda self: self.operations.append("acos")
    atan: Callable[[], None] = lambda self: self.operations.append("atan")
    sinh: Callable[[], None] = lambda self: self.operations.append("sinh")
    cosh: Callable[[], None] = lambda self: self.operations.append("cosh")
    tanh: Callable[[], None] = lambda self: self.operations.append("tanh")
    asinh: Callable[[], None] = lambda self: self.operations.append("asinh")
    acosh: Callable[[], None] = lambda self: self.operations.append("acosh")
    atanh: Callable[[], None] = lambda self: self.operations.append("atanh")
    copy: Callable[[], "Number"] = lambda self: Number(self)