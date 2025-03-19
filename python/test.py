import time
from fractions import Fraction
from time import perf_counter

from linear_algebra import MathNum, Variable, Polynomial


def main():
    start = time.perf_counter()
    res = MathNum(5 / 2 + 5, datatype=Fraction)
    res = res ** 2
    res = res.ln() * res.sin()
    # res = res.sqrt()
    print(res)
    print(res.evaluate())
    # res = Variable(".2y^2", always_evaluate=False)
    # res = (res / Variable("1/19x")) ** 2
    # print(res)
    # res = Polynomial("10x^2 5x 1")
    # [print(element.evaluate(return_type=float)) for element in res.roots()]
    # print(res)

    print(perf_counter() - start)


if __name__ == "__main__":
    main()
