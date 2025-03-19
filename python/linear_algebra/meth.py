from typing import Literal, Callable, Any
import math, cmath
from fractions import Fraction

PI: Fraction = Fraction(math.pi)
E: Fraction = Fraction(math.e)


def rename(name: str) -> Callable:
    def inner(func: Callable):
        class Wrapper:
            def __init__(self, func: Callable, name: str) -> None:
                self.func: Callable = func
                self.name: str = name

            def __call__(self, *args: Any, **kwargs: Any) -> Any:
                return self.func(*args, **kwargs)

            def __repr__(self) -> str:
                return self.name

        return Wrapper(func, name)

    return inner


@rename("+")
def add(x: float | complex, y: float | complex) -> float | complex:
    return x + y


@rename("-")
def sub(x: float | complex, y: float | complex) -> float | complex:
    return x - y


@rename("*")
def mul(x: float | complex, y: float | complex) -> float | complex:
    return x * y


@rename("/")
def truediv(x: float | complex, y: float | complex) -> float | complex:
    return x / y


@rename("**")
def pow(x: float | complex, y: float | complex) -> float | complex:
    return x ** y


@rename("abs")
def abs(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.fabs(x)

    else:
        return sqrt(x.real ** 2 + x.imag ** 2)


@rename("sqrt")
def sqrt(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.sqrt(x)

    else:
        return cmath.sqrt(x)


@rename("cbrt")
def cbrt(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.cbrt(x)

    else:
        return x ** (1 / 3)


@rename("log")
def log(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.log10(x)

    else:
        return cmath.log10(x)


@rename("ln")
def ln(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.log(x)

    else:
        return cmath.log(x)


@rename("sin")
def sin(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.sin(x)
    else:
        return cmath.sin(x)


@rename("cos")
def cos(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.cos(x)
    else:
        return cmath.cos(x)


@rename("tan")
def tan(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.tan(x)
    else:
        return cmath.tan(x)


@rename("asin")
def asin(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.asin(x)
    else:
        return cmath.asin(x)


@rename("acos")
def acos(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.acos(x)
    else:
        return cmath.acos(x)


@rename("atan")
def atan(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.atan(x)
    else:
        return cmath.atan(x)


@rename("sinh")
def sinh(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.sinh(x)
    else:
        return cmath.sinh(x)


@rename("cosh")
def cosh(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.cosh(x)
    else:
        return cmath.cosh(x)


@rename("tanh")
def tanh(x: float | complex, argument: Literal["deg", "rad"] = "deg") -> float | complex:
    if argument == "deg":
        x = math.radians(x)

    if isinstance(x, float):
        return math.tanh(x)
    else:
        return cmath.tanh(x)


@rename("asinh")
def asinh(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.asinh(x)
    else:
        return cmath.asinh(x)


@rename("acosh")
def acosh(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.acosh(x)
    else:
        return cmath.acosh(x)


@rename("atanh")
def atanh(x: float | complex) -> float | complex:
    if isinstance(x, float):
        return math.atanh(x)
    else:
        return cmath.atanh(x)
