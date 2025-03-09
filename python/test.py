from fractions import Fraction
from linear_algebra import MathNum, Variable, Polynomial


def main():
    # res = MathNum(5 / 2 + 5, datatype=Fraction)
    # res = res ** 2
    # res = res.ln() * res.sin()
    # res = res.sqrt()
    # print(res)
    # print(res.evaluate())
    # res = Variable(".2y^2", always_evaluate=False)
    # res = (res / Variable("1/19x")) ** 2
    # print(res)
    res = Polynomial("2x 3y 5z")
    res += Polynomial("9x^2 5y 3z")
    print(res)


if __name__ == "__main__":
    main()
