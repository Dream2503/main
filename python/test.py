from fractions import Fraction

from linear_algebra import MathNum, Variable


def main():
    # res = MathNum(5/2 + 5)
    # res = res ** 2
    # res = res.ln() * res.sin()
    # # res = res.sqrt()
    # print(res)
    # print(res.evaluate())
    res = Variable("1/5x")
    res = res / Variable("1/19x")
    print(res)


if __name__ == "__main__":
    main()