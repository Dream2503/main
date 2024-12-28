from matrix import Matrix

m = Matrix(4, 4, matrix=[
    [2, 2, 3],
    [10, 4, 6],
    [0, 10, 25]
])
print(m.eigen_vectors())

# from matrix import Number
#
# num1 = Number(15)
# num1.sqrt()
# num1.ln()
# num2 = Number(51)
# num2.ln()
# num2.sqrt()
# res = num1 + num2
# print(num1)
# print(num1.to_float())
# print(num2)
# print(num2.to_float())
# print(res)
# print(res.to_float())