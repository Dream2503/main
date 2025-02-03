from linear_algebra import MathNum, Variable

def main():
    # num = MathNum(3 + 5j, domain="complex")
    # res = num * (4 + 3j)
    # res = res.log() * res.sin()
    # # res = res.sqrt()
    # print(res.expression())
    # print(res.evaluate())
    var = Variable("5x")**2
    print(var)

if __name__ == "__main__":
    main()
