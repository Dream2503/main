from linear_algebra import MathNum

def main():
    # num = MathNum(3 + 5j, domain="complex")
    # res = num * (4 + 3j)
    # res = res.log() * res.sin()
    # res = res.sqrt()
    # print(res)
    MathNum()
    var = Variable("1/0x")
    print(var)
if __name__ == "__main__":
    main()

# sqrt((log(((3 + 5i) * (4 + 3i))) * sin(((3 + 5i) * (4 + 3i)))))


