from fractions import Fraction

from linear_algebra import MathNum, Variable


def main():
    # res = MathNum(5/2 + 5)
    # res = res ** 2
    # res = res.ln() * res.sin()
    # res = res.sqrt()
    # print(res)
    # print(res.evaluate())
    res = MathNum()
    print(res + 1)
    # var1 = Variable("1/5x")
    # res = var1 / Variable("1/10x")
    print(res)


if __name__ == "__main__":
    main()

# sqrt((log(((3 + 5i) * (4 + 3i))) * sin(((3 + 5i) * (4 + 3i)))))
