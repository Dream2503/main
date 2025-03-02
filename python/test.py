# from fractions import Fraction
#
# from linear_algebra import MathNum, Variable
#
#
# def main():
#     # res = MathNum(5/2 + 5)
#     # res = res ** 2
#     # res = res.ln() * res.sin()
#     # # res = res.sqrt()
#     # print(res)
#     # print(res.evaluate())
#     res = Variable("1/5x")
#     res = res / Variable("1/19x")
#     print(res)
#
#
# if __name__ == "__main__":
#     main()



# total_test_cases: int = int(input())
# res: list[str] = []
# 
# for i in range(total_test_cases):
#     size: int = int(input())
#     lst: list[str] = list(input().split())
#     lst.sort(reverse=True)
# 
#     for j in range(size - 1):
#         if (lst[j + 1] + lst[j]) > (lst[j] + lst[j + 1]):
#             temp: str = lst[j]
#             lst[j] = lst[j + 1]
#             lst[j + 1] = temp
# 
#     res.append("".join(lst))
# 
# for ans in res:
#     print(ans)
