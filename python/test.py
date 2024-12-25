from matrix import Matrix

m = Matrix(4, 5, matrix=[[10, 2, 2, 0, 3], [0, 10, 4, 6, 0], [0, 0, 10, 6, 0], [0, 0, 0, 10, 25]])
print(m.gauss_elimination())