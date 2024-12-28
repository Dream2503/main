from collections import namedtuple
from .equation import Polynomial, Variable
from fractions import Fraction
from math import gcd, lcm, sqrt
from typing import Callable, Literal, Generic, TypeVar, Iterator

Type = TypeVar("Type")
Order = namedtuple("Order", ["row", "column"])


class MatrixError(Exception): ...


class Matrix(Generic[Type]):
    """
# INITIALIZING MATRIX OBJECT
    -> using input method
        >>> m: Matrix[Fraction] = Matrix(2, 3, method="input")           # this is a matrix with 2 rows and 3 columns
        Enter row (space-separated values): 1 2 3
        Enter row (space-separated values): 4 5 6
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> providing a valid nested list and convert it to matrix
        >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 2, 3], [4, 5, 6]])     # here matrix= is keyword only argument
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> by providing a type of matrix to generate
        -> null matrix
            >>> m: Matrix[Fraction] = Matrix(3, 3, method="null")        # creating a null matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]]

        -> identity matrix
            >>> m: Matrix[Fraction] = Matrix(3, 3, method="identity")    # creating an identity matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(1, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)]]

# USING OPERATORS BETWEEN MATRIX AND NUMERIC TYPES
    -> consider the following matrices and one integer throughout the section
        >>> m1: Matrix[Fraction] = Matrix(matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix[Fraction] = Matrix(matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> addition of two matrices
            >>> m1 + m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> subtraction of two matrices
            >>> m1 - m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> multiplication of matrices and numeric types
            >>> m1 * m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(19, 1), Fraction(22, 1)], [Fraction(43, 1), Fraction(50, 1)]])
            >>> m1 * num
            Matrix(rows=2, columns=2, matrix=[[Fraction(7, 1), Fraction(14, 1)], [Fraction(21, 1), Fraction(28, 1)]])

# USING IN-PLACE OPERATOR
    -> consider the following two matrices and one integer throughout the section
    -> matrices are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> m1: Matrix[Fraction] = Matrix(matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix[Fraction] = Matrix(matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> in-place addition of two matrices
            >>> m1 += m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> in-place subtraction of two matrices
            >>> m1 -= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> in-place multiplication of matrices and numeric types
            >>> m1 *= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(19, 1), Fraction(22, 1)], [Fraction(43, 1), Fraction(50, 1)]])
            >>> m1 *= num
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(7, 1), Fraction(14, 1)], [Fraction(21, 1), Fraction(28, 1)]])

# OTHER BUILT-IN OPERATORS
    -> checking equality between matrices
        >>> m1 == m2
        False

    -> absolute value of matrix
        >>> m1 *= -1                            # making the matrix negative by multiplying with -1
        >>> abs(m1)
        Matrix(rows=2, columns=2, matrix=[[Fraction(1, 1), Fraction(2, 1)], [Fraction(3, 1), Fraction(4, 1)]])

    -> checking if an element is in matrix
        >>> 4 in m1
        True

        >>> 5 in m1
        False

    -> checking truth value of a matrix
        >>> m = Matrix(method="null")
        >>> bool(m)
        False

        >>> bool(m1)
        True

# ACCESSING ELEMENT OF A MATRIX
    -> consider the following matrix for this session
        >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 2, 3], [4, 5, 6]])

        -> using index
            >>> m[1]
            [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]

            >>> m[1][2]
            Fraction(6, 1)

        -> iterating using for loop
            >>> for row in m:
            ...     print(row)
            ...
            [Fraction(1, 1), Fraction(2, 1), Fraction(3, 1)]
            [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]

            >>> for row in m:
            ...     for element in row:
            ...         print(element, end=", ")
            ...
            '1', '2', '3,' '4,' '5', '6',

# FINDING THE SOLUTION TO A SYSTEM OF LINEAR EQUATION WITH SAME NO. OF EQUATIONS TO VARIABLES USING CRAMER'S RULE
    >>> m: Matrix[Fraction] = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.cramer_rule()
    ({'x1': Fraction(2, 1), 'x2': Fraction(3, 1), 'x3': Fraction(-1, 1)}

# CREATING A COPY OF THE MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    >>> m.copy()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(2, 1), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)], [Fraction(7, 1), Fraction(8, 1), Fraction(9, 1)]])

# FINDING DETERMINANT OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.determinant()
    Fraction(-1, 1)

# DIAGONALIZING A MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-5, -6, 6], [-9, -8, 12], [-12, -12, 16]])
    >>> m.diagonalize()
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(-2, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)]])

# CONVERTING A MATRIX TO ITS EQUIVALENT ECHELON FORM
    >>> m: Matrix[Fraction] = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.echelon_form()
    Matrix(rows=3, columns=4, matrix=[[Fraction(2, 1), Fraction(1, 1), Fraction(-1, 1), Fraction(8, 1)], [Fraction(0, 1), Fraction(1, 2), Fraction(1, 2), Fraction(1, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(-1, 1), Fraction(1, 1)]])

# FINDING THE EIGEN VALUES OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_values()
    {'lambda1': Fraction(5, 1), 'lambda2': Fraction(-3, 1), 'lambda3': Fraction(-3, 1)}

# FINDING THE EIGEN VECTORS OF A SQUARE MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_vectors()
    ((Fraction(-1, 1), Fraction(-2, 1), Fraction(1, 1)), (Fraction(1, 1), Fraction(1, 1), Fraction(1, 1)))

# FINDING THE SOLUTION TO A SYSTEM OF LINEAR EQUATION USING GAUSS ELIMINATION METHOD
    >>> m: Matrix[Fraction] = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.gauss_elimination()
    {'x1': Fraction(2, 1), 'x2': Fraction(3, 1), 'x3': Fraction(-1, 1)}

# FINDING THE INVERSE OF A NON-SINGULAR MATRIX USING GAUSS JORDAN ELIMINATION METHOD
    >>> m: Matrix[Fraction] = Matrix(matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.inverse()
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(3, 1), Fraction(-1, 1)], [Fraction(-2, 1), Fraction(-2, 1), Fraction(1, 1)], [Fraction(5, 1), Fraction(4, 1), Fraction(-1, 1)]])

# CHECKING IF THE SET OF ROW VECTORS ARE LINEARLY DEPENDENT OR INDEPENDENT
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.is_linearly_independent()
    False

# CHECKING IF A MATRIX IS A ORTHOGONAL MATRIX
    >>> m: Matrix[Fraction] = Matrix(method="identity")
    >>> m.is_orthogonal()
    True

# CHECKING IF A MATRIX IS A ORTHONORMAL SYSTEM OF COLUMN VECTORS
    >>> m: Matrix[Fraction] = Matrix(method="identity")
    >>> m.is_orthonormal_system()
    True

# CHECKING IF A MATRIX IS POSITIVE DEFINITE MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[3, -1, 1], [-1, 5, -1], [1, -1, 3]])
    >>> m.is_positive_definite()
    True

# CHECKING IF A MATRIX IS SKEW SYMMETRIC MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[0, 1, -2], [-1, 0, 3], [2, -3, 0]])
    >>> m.is_skew_symmetric()
    True

# CHECKING IF A MATRIX IS SQUARE OR NOT
    >>> m: Matrix[Fraction] = Matrix(method="null")
    >>> m.is_square()
    True

# CHECKING IF A MATRIX IS SYMMETRIC MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.is_symmetric()
    True

# GIVES THE NULLITY OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(4, 4, matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.nullity()
    2

# COMPUTING PSEUDO INVERSE OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, -1, 1], [-2, 2, -2]])
    >>> m.pseudo_inverse()
    Matrix(rows=3, columns=2, matrix=[[Fraction(-67, 1000), Fraction(133, 1000)], [Fraction(67, 1000), Fraction(-133, 1000)], [Fraction(-67, 1000), Fraction(133, 1000)]])

# USING THE MATRIX PRINT FUNCTION
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.print()
    ['1', '1', '-1']
    ['1', '2', '0']
    ['-1', '0', '5']

# FINDING THE RANK OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.rank()
    3

# SINGULAR VALUE DECOMPOSITION OF A MATRIX [A = U * sigma * trans(T)]
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.singular_value_decomposition()
    {
        'u': Matrix(rows=3, columns=3, matrix=[[Fraction(0, 1), Fraction(0, 1), Fraction(-500, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(250, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]]),
        'sigma': Matrix(rows=3, columns=3, matrix=[[Fraction(2133, 1000), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(3, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(879, 125)]]),
        'v': Matrix(rows=3, columns=3, matrix=[[Fraction(0, 1), Fraction(0, 1), Fraction(-500, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(250, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]])
    }

# FINDING THE SIMILAR MATRIX OF THE SELF MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[-5, 0, 15], [3, 4, -9], [-5, 0, 15]])
    >>> p: Matrix[Fraction] = Matrix(matrix=[[0, 1, 0], [1, 0, 0], [0, 0, 1]])
    >>> m.similar_matrix(p)
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(3, 1), Fraction(-9, 1)], [Fraction(0, 1), Fraction(-5, 1), Fraction(15, 1)], [Fraction(0, 1), Fraction(-5, 1), Fraction(15, 1)]])

# CALCULATES THE TRACE OF THE MATRIX
    >>> m: Matrix[Fraction] = Matrix(4, 4, matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.trace()
    16

# FINDING TRANSPOSE OF A MATRIX
    >>> m: Matrix[Fraction] = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.transpose()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(1, 1), Fraction(-1, 1)], [Fraction(1, 1), Fraction(2, 1), Fraction(0, 1)], [Fraction(-1, 1), Fraction(0, 1), Fraction(5, 1)]])

# DETERMINING THE TYPE OF THE MATRIX
    >>> M: Matrix[Fraction] = Matrix(2, 3, method="null")
    >>> m.type()
    'rectangular'
    """

    def __init__(self, rows: int = 0, columns: int = 0, method: Literal["input", "null", "identity", "pass"] = "pass",
                 *, matrix: list[list[Fraction]] = None) -> None:
        """Matrix object initializer function"""
        if matrix is not None:
            rows: int = len(matrix)
            columns: int = len(matrix[0])

        self._order: Order = Order(rows, columns)

        if rows <= 0 or columns <= 0:
            raise MatrixError("Row or column of a matrix cannot be negative or null")

        if method == "input":
            self._input()
            self._validate()

        elif method == "null":
            self._null()

        elif method == "identity":
            self._identity()

        elif method == "pass":
            self._matrix: list[list[Fraction]] = [row.copy() for row in matrix]
            self._validate()

    @property
    def row(self) -> int:
        return self._order.row

    @property
    def column(self) -> int:
        return self._order.column

    @property
    def order(self) -> Order:
        return self._order

    @property
    def matrix(self) -> list[list[Fraction]]:
        return self._matrix

    def __add__(self, other: "Matrix[Fraction]") -> "Matrix[Fraction]":
        """Operator+ overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix[Fraction] = Matrix(self.row, self.column, "null")

                for i in range(self.row):
                    for j in range(self.column):
                        result.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __sub__(self, other: "Matrix[Fraction]") -> "Matrix[Fraction]":
        """Operator- overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix[Fraction] = Matrix(self.row, self.column, "null")

                for i in range(self.row):
                    for j in range(self.column):
                        result.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __mul__(self, other: "Matrix[Fraction] | Fraction") -> "Matrix[Fraction]":
        """Operator* overloaded function"""
        if isinstance(other, Matrix):
            if self.column == other.row:
                result: Matrix[Fraction] = Matrix(self.row, other.column, "null")

                for k in range(self.row):
                    for i in range(other.column):
                        for j in range(self.column):
                            result.matrix[k][i] += self.matrix[k][j] * other.matrix[j][i]

                return result

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        try:
            other: Fraction = Fraction(str(other))
            result: Matrix[Fraction] = Matrix(self.row, self.column, "null")

            for i in range(self.row):
                for j in range(self.column):
                    result[i][j] = self.matrix[i][j] * other

            return result

        except ValueError:
            return NotImplemented

    def __iadd__(self, other: "Matrix[Fraction]") -> "Matrix[Fraction]":
        """Operator+= overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.row):
                    for j in range(self.column):
                        self.matrix[i][j] += other.matrix[i][j]

                return self

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __isub__(self, other: "Matrix[Fraction]") -> "Matrix[Fraction]":
        """Operator-= overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                for i in range(self.row):
                    for j in range(self.row):
                        self.matrix[i][j] -= other.matrix[i][j]

                return self

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __imul__(self, other: "Matrix[Fraction] | Fraction") -> "Matrix[Fraction]":
        """Operator*= overloaded function"""
        if isinstance(other, Matrix):
            if self.column == other.row:
                for k in range(self.row):
                    for i in range(other.column):
                        for j in range(self.column):
                            self.matrix[k][j] *= other.matrix[j][i]

                return self

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        else:
            try:
                other: Fraction = Fraction(str(other))

                for i in range(self.row):
                    for j in range(self.column):
                        self.matrix[i][j] *= other

                return self

            except ValueError:
                return NotImplemented

    def __contains__(self, item: Fraction) -> bool:
        """Built-in "in" overloaded keyword"""
        for row in self.matrix:
            for element in row:
                if element == item:
                    return True

    def __iter__(self) -> Iterator[list[Fraction]]:
        """Built-in iter() overloaded function"""
        for row in self.matrix:
            yield row

    __radd__: Callable[["Matrix[Fraction]"], "Matrix[Fraction]"] = lambda self, other: self.__add__(other)
    __rsub__: Callable[["Matrix[Fraction]"], "Matrix[Fraction]"] = lambda self, other: (-self).__add__(other)
    __rmul__: Callable[["Matrix[Fraction] | Fraction"], "Matrix[Fraction]"] = lambda self, other: self.__mul__(other)
    __bool__: Callable[[], bool] = lambda self: self.type() != "null"
    __pos__: Callable[[], "Matrix[Fraction]"] = lambda self: self
    __neg__: Callable[[], "Matrix[Fraction]"] = lambda self: self.__mul__(-1)
    __eq__: Callable[[], bool] = lambda self, other: self.matrix == other.matrix \
        if isinstance(other, Matrix) else NotImplemented
    __getitem__: Callable[[int], list[Fraction]] = lambda self, item: self.matrix[item]
    __name__: str = "Matrix"
    __str__: Callable[[], str] = lambda self: \
        f"\nrows = {self.row}\ncolumns = {self.column}\nmatrix = {self.matrix}"
    __repr__: Callable[[], str] = lambda self: \
        f"Matrix(rows={self.row}, columns={self.column}, matrix={self.matrix})"
    __abs__: Callable[[], "Matrix[Fraction]"] = lambda self: Matrix(
        matrix=[abs(self.matrix[i][j]) for i in range(self.row) for j in range(self.column)])
    __call__: Callable[[], str] = __repr__

    def _back_substitution(self, substituent: int = 1) -> list[Fraction | None]:
        """Back-substitutes the values in order to find the solution of the linear polynomial equations"""
        res: list[Fraction | None] = [None for _ in range(self.row)]

        for row in self.matrix[::-1]:
            poly: Polynomial = row[0]

            for idx, component in enumerate(res):
                if component is not None:
                    poly: Polynomial = poly.substitute(f"x{idx + 1}", component)

            var: list[Variable] = []

            for variable in poly.numerator:
                if variable.variables:
                    var.append(variable)

            if len(var) == 0:
                pass

            elif len(var) == 1:
                factor: Fraction = var[0].coefficient

                for i in range(len(poly.numerator)):
                    poly.numerator[i] /= factor

                idx: str = tuple(var[0].variables.keys())[0][1]

                try:
                    res[int(idx) - 1] = -poly.numerator[1].coefficient

                except IndexError:
                    res[int(idx) - 1] = Fraction(0)

            elif len(var) > 1:
                for variable in var[1:]:
                    element: str = tuple(variable.variables.keys())[0]
                    poly: Polynomial = poly.substitute(element, Fraction(1))
                    res[int(element[1]) - 1] = Fraction(substituent)

                for i in range(len(poly.numerator)):
                    poly.numerator[i] /= var[0].coefficient

                idx: str = tuple(var[0].variables.keys())[0][1]

                try:
                    res[int(idx) - 1] = -poly.numerator[1].coefficient

                except IndexError:
                    res[int(idx) - 1] = Fraction(0)

        return res

    @staticmethod
    def _dot_product(lst1: list[Fraction], lst2: list[Fraction]) -> Fraction:
        """Computes the dot product of two vectors"""
        if len(lst1) != len(lst2):
            raise MatrixError("Dot product of two unequal order of vector is not defined")

        res: Fraction = Fraction(0)

        for i in range(len(lst1)):
            res += lst1[i] * lst2[i]

        return res

    def _identity(self) -> None:
        """Initializes an identity matrix"""
        self._matrix: list[list[Fraction]] = [[Fraction(1) if i == j else Fraction(0) for j in range(self.column)]
                                              for i in range(self.row)]

    def _input(self) -> None:
        """Accept user input for construct the matrix with provided values"""
        self._matrix: list[list[Fraction]] = []

        for _ in range(self.row):
            row: list[str] = input("Enter row (space-separated values): ").split()

            if len(row) == self.column:
                self._matrix.append([Fraction(element) for element in row])

            else:
                raise MatrixError("Invalid matrix elements")

    def _null(self) -> None:
        """Initializes a null matrix"""
        self._matrix: list[list[Fraction]] = [[Fraction(0) for _ in range(self.column)] for _ in
                                              range(self.row)]

    @staticmethod
    def _simplify_row(lst: list[Fraction]) -> tuple[Fraction]:
        """Simplifies a list of Fractions by dividing them with their GCD"""
        factor: Fraction = Fraction(1)
        size: int = len(lst)
        all_neg: bool = True

        for i in range(size):
            factor: Fraction = Fraction(gcd(factor.numerator, lst[i].numerator),
                                        lcm(factor.denominator, lst[i].denominator))

            if lst[i] >= 0:
                all_neg: bool = False

        if all_neg:
            factor *= Fraction(-1)

        for i in range(size):
            lst[i] /= factor

        return tuple(lst)

    def _validate(self) -> None:
        """Validates the object and user input to initialize a matrix object."""
        if self.row != len(self.matrix):
            raise MatrixError("Invalid Matrix row")

        column_length: int = len(self.matrix[0])

        for column in self.matrix:
            if len(column) != column_length:
                raise MatrixError("Invalid Matrix column")

        for i in range(self.row):
            for j in range(self.column):
                try:
                    self.matrix[i][j] = Fraction(f"{self.matrix[i][j]}")

                except (TypeError, ValueError):
                    pass

    def cramer_rule(self) -> dict[str, Fraction] | tuple[int, str]:
        """Solves a system of linear equation where the matrix object is an augmented coefficient matrix of the set of linear equation by using Cramer's Rule."""
        if self.row < self.column:
            matrix: list[list[Fraction]] = [row for idx, row in enumerate(self.matrix) if idx < self.column - 1]

        else:
            matrix: list[list[Fraction]] = self.matrix

        result: Matrix[Fraction] = Matrix(matrix=matrix)

        temp_a: list[list[Fraction]] = []
        b: list[list[Fraction]] = []
        res: list[Fraction] = []

        for row in result:
            temp_a.append(row[:-1])
            b.append(row[-1])

        a: Matrix[Fraction] = Matrix(matrix=temp_a)
        det: Fraction = a.determinant()

        if det == 0:
            return 0, "The set of linear equations has no solutions"

        for i in range(self.row):
            temp_matrix: Matrix[Fraction] = a.copy()

            for j in range(self.row):
                temp_matrix[j][i] = b[j]

            res.append(temp_matrix.determinant() / det)

        return {f"x{i + 1}": val for i, val in enumerate(res)}

    def determinant(self) -> Fraction:
        """Finds the determinant of the matrix."""
        if not self.is_square():
            raise MatrixError("Determinant of rectangular matrix is not defined")

        result: Matrix[Fraction] = self.echelon_form()
        det: Fraction = Fraction(1)

        for i in range(result.row):
            det *= result.matrix[i][i]

        return det

    def diagonalize(self) -> "Matrix[Fraction]":
        vector: tuple[tuple[Fraction]] = self.eigen_vectors()
        matrix: list[list[Fraction]] = [list(vec) for vec in vector]
        x: Matrix[Fraction] = Matrix(matrix=matrix).transpose()
        return x.inverse() * self * x

    def echelon_form(self) -> "Matrix[Fraction]":
        """Returns the echelon_form of the current matrix."""
        result: Matrix[Fraction] = self.copy()
        pivot: int = 0

        while pivot + 1 < result.row:
            cnt: int = pivot

            try:
                while result.matrix[pivot][cnt] == 0:
                    pivot += 1

            except IndexError:
                return result

            if pivot != cnt:
                for i in range(result.column):
                    result.matrix[pivot][i], result.matrix[cnt][i] = result.matrix[cnt][i], result.matrix[pivot][i]

            pivot: int = cnt

            for i in range(pivot + 1, result.row):
                factor: Fraction = result.matrix[i][pivot] / result.matrix[pivot][pivot]

                for j in range(pivot, result.column):
                    result.matrix[i][j] -= (factor * result.matrix[pivot][j])

            pivot += 1

        return result

    def eigen_values(self) -> dict[str, Fraction]:
        """Finds the eigen values of a matrix."""

        def recursive_determinant(matrix: list[list[Polynomial]]):
            """Finds the determinant of a 2D-Array using recursive approach of finding determinant of sub-matrices."""
            if len(matrix) == 2:
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

            det: Polynomial = Polynomial()

            for i in range(len(matrix)):
                minor: list[list[Polynomial]] = [row[:i] + row[i + 1:] for row in matrix[1:]]
                det += ((-1) ** i) * (matrix[0][i] * recursive_determinant(minor))

            return det

        if not self.is_square():
            raise MatrixError("Eigen values for a non-square matrix are not defined")

        var: Polynomial = Polynomial("x")
        mat: list[list[Polynomial]] = \
            [[self.matrix[i][j] - var if i == j else self.matrix[i][j] for j in range(self.column)] for i in
             range(self.row)]
        char_poly: Polynomial = recursive_determinant(mat)
        res: tuple[float] = char_poly.roots()

        try:
            ans: tuple[Fraction] = tuple((Fraction(f"{round(element, 3)}") for element in res))

        except TypeError:
            ans: tuple[Fraction] = tuple(res)

        except ValueError:
            raise MatrixError("Complex roots are not supported.")

        return {f"lambda{i + 1}": val for i, val in enumerate(ans)}

    def eigen_vectors(self, is_absolute: bool = False) -> tuple[tuple[Fraction]]:
        """Finds the normalized eigen vectors for the corresponding eigen values of the matrix."""
        res: list = []
        cnt: dict[Fraction, int] = {}
        eigen_val: dict[str, Fraction] = self.eigen_values()

        if is_absolute:
            for key, value in eigen_val.items():
                eigen_val[key] = abs(value)

        var_mat: Matrix[Polynomial] = Matrix(matrix=[[Polynomial(f"x{i}")] for i in range(1, self.column + 1)])

        for value in eigen_val.values():
            cnt[value] = cnt.get(value, 0) + 1

        for key, value in cnt.items():
            matrix: list[list[Fraction]] = [[self.matrix[i][j] - (key if i == j else Fraction(0))
                                             for j in range(self.column)] for i in range(self.row)]
            char_matrix: Matrix[Polynomial] = Matrix(matrix=matrix).echelon_form() * var_mat
            for i in range(1, value + 1):
                eigen_vec: list[Fraction] = [Fraction(1) if value is None else value for value in
                                             char_matrix._back_substitution(substituent=i)]
                res.append(self._simplify_row(eigen_vec))

        return tuple(res)

    def gauss_elimination(self) -> dict[str, Fraction] | tuple[int, str]:
        """Solves the system of linear equations (assuming the "self" matrix as the augmented matrix) by gauss elimination method"""
        if self.row != self.column - 1:
            matrix: list[list[Fraction]] = [row for idx, row in enumerate(self.matrix) if idx < self.column - 1]
            order: Order = Order(len(matrix), len(matrix[0]))

        else:
            matrix: list[list[Fraction]] = self.matrix
            order: Order = self.order

        result: Matrix[Fraction] = Matrix(matrix=matrix).echelon_form()

        if result[-1][-2] == 0 and result[-1][-1] != 0:
            return 0, "The set of linear equations has no solutions"

        else:
            for i in range(order.row):
                result.matrix[i][-1] = -result.matrix[i][-1]

            matrix: list[list[Polynomial]] = [[Polynomial(f"x{i}")] for i in range(1, order.row + 1)]
            matrix.append([Fraction(1)])
            var_mat: Matrix[Polynomial] = Matrix(matrix=matrix)
            poly_mat: Matrix[Polynomial] = result * var_mat

            res: list[Fraction] = [1 if val is None else val for val in poly_mat._back_substitution()]
            return {f"x{i + 1}": val for i, val in enumerate(res)}

    def inverse(self) -> "Matrix[Fraction]":
        """Computes the inverse of a non-singular matrix using Gauss Jordan Elimination"""
        if not self.is_square():
            raise MatrixError("Inverse of a rectangular matrix is not defined")

        det: Fraction = self.determinant()

        if det == 0:
            raise MatrixError("Inverse of singular matrix is not defined")

        identity_mat: Matrix[Fraction] = Matrix(self.row, self.column, "identity")
        aug_matrix: Matrix[Fraction] = Matrix(matrix=[self.matrix[i] + identity_mat.matrix[i] for i in
                                                      range(self.row)])
        aug_matrix: Matrix[Fraction] = aug_matrix.echelon_form()
        aug_matrix._matrix = aug_matrix.matrix[::-1]

        for i in range(self.row):
            aug_matrix[i][:self.order[0]] = list(reversed(aug_matrix[i][:self.order[0]]))

        aug_matrix: Matrix[Fraction] = aug_matrix.echelon_form()
        res: list[list[Fraction]] = []

        for i in range(self.row - 1, -1, -1):
            factor: Fraction = 1 / aug_matrix[i][i]

            for j in range(self.row, self.row * 2):
                aug_matrix[i][j] *= factor

            res.append(aug_matrix[i][self.row:])

        return Matrix(matrix=res)

    def is_orthonormal_system(self) -> bool:
        """Checks whether the matrix is a orthonormal system of column vectors"""
        if not self.is_square():
            raise MatrixError("Orthonormal system is defined for square matrices only")

        matrix: Matrix[Fraction] = self.transpose()

        for i in range(matrix.row):
            for j in range(i, matrix.row):
                if ((i == j and self._dot_product(matrix[i], matrix[j]) != 1) or
                        (i != j and self._dot_product(matrix[i], matrix[j]) != 0)):
                    return False

        return True

    def is_positive_definite(self) -> bool:
        """Checks the positive definite of a matrix"""
        if not self.is_symmetric():
            return False

        for value in self.eigen_values().values():
            if value <= 0:
                return False

        for i in range(1, self.row + 1):
            temp_mat: Matrix[Fraction] = Matrix(matrix=[self.matrix[j][:i] for j in range(i)])

            if temp_mat.determinant() <= 0:
                return False

        return True

    @staticmethod
    def normalize(eigen_vector: tuple[Fraction]) -> tuple[Fraction]:
        """Normalizes a eigen vector"""
        total: Fraction = Fraction(0)

        for value in eigen_vector:
            total += value ** 2

        factor: Fraction = Fraction(str(round(sqrt(float(total)), 3)))

        if factor:
            return tuple(value / factor for value in eigen_vector)

        else:
            return eigen_vector

    def pseudo_inverse(self) -> "Matrix[Fraction]":
        """Computes the pseudo inverse of a matrix"""
        svd: dict[str, Matrix[[Fraction]]] = self.singular_value_decomposition()
        sigma_plus: Matrix[Fraction] = svd["sigma"].transpose()

        for i in range(sigma_plus.row):
            for j in range(sigma_plus.column):
                if sigma_plus[i][j] != Fraction(0):
                    sigma_plus[i][j] = Fraction(1) / sigma_plus[i][j]

        a_plus: Matrix[Fraction] = svd["v"] * sigma_plus * svd["u"].transpose()

        for i in range(a_plus.row):
            for j in range(a_plus.column):
                a_plus[i][j] = Fraction(str(round(float(a_plus[i][j]), 3)))

        return a_plus

    def rank(self) -> int:
        """Gives the rank of the matrix"""
        result: Matrix[Fraction] = self.echelon_form()
        rank: int = result.row
        i: int = rank - 1
        j: int = result.column - 1

        while result.matrix[i][j] == 0 and i > 0 and j > 0:
            rank -= 1
            i -= 1
            j -= 1

        return rank

    def singular_value_decomposition(self) -> dict[str, "Matrix[Fraction]"]:
        """Gives the singular value decomposition of the matrix [A = U * sigma * trans(T)]"""
        aat: Matrix[Fraction] = self * self.transpose()
        aat_eigen_val: list[Fraction] = sorted(aat.eigen_values().values(), reverse=True)
        sigma_: Matrix[Fraction] = Matrix(self.row, self.column, "null")

        for i in range(len(aat_eigen_val)):
            sigma_[i][i] = Fraction(str(round(sqrt(abs(float(aat_eigen_val[i]))), 3)))

        aat_eigen_vec: tuple[tuple[Fraction]] = aat.eigen_vectors(is_absolute=True)
        u: Matrix[Fraction] = Matrix(matrix=[list(self.normalize(vec)) for vec in aat_eigen_vec]).transpose()

        ata: Matrix[Fraction] = self.transpose() * self
        ata_eigen_vec: tuple[tuple[Fraction]] = ata.eigen_vectors(is_absolute=True)
        v: Matrix[Fraction] = Matrix(matrix=[list(self.normalize(vec)) for vec in ata_eigen_vec])

        return {"u": u, "sigma": sigma_, "v": v.transpose()}

    def transpose(self) -> "Matrix[Fraction]":
        """Gives the transpose of the matrix"""
        result: Matrix[Fraction] = Matrix(self.column, self.row, "null")

        for i in range(self.row):
            for j in range(self.column):
                result.matrix[j][i] = self.matrix[i][j]

        return result

    def type(self) -> str:
        if self.row == 1 and self.column != 1:
            res: str = "row"

        elif self.column == 1 and self.row != 1:
            res: str = "column"

        elif self.row == self.column:
            res: str = "square"
            is_scalar: bool = True
            is_identity: bool = True
            is_diagonal: bool = True

            for i in range(self.row):
                for j in range(self.column):
                    if i == j:
                        if self.matrix[i][j] != self.matrix[0][0]:
                            is_scalar: bool = False

                        elif self.matrix[i][j] != Fraction(1):
                            is_identity: bool = False

                    else:
                        if self.matrix[i][j] != Fraction():
                            is_scalar: bool = False
                            is_identity: bool = False
                            is_diagonal: bool = False

                if not (is_scalar and is_identity and is_diagonal):
                    break

            if is_identity:
                res: str = "identity"

            elif is_scalar:
                res: str = "scalar"

            elif is_diagonal:
                res: str = "diagonal"

        elif self.row != self.column:
            res: str = "rectangular"

        else:
            res: str = ""

        is_null: bool = True

        for i in range(self.row):
            for j in range(self.column):
                if self.matrix[i][j] != Fraction(0):
                    is_null: bool = False
                    break

            if not is_null:
                break

        if is_null:
            res: str = "null"

        return res

    copy: Callable[[], "Matrix[Fraction]"] = lambda self: Matrix(matrix=self.matrix)
    is_linearly_independent: Callable[[], bool] = lambda self: self.row == self.rank()
    is_orthogonal: Callable[[], bool] = lambda self: self.is_orthonormal_system()
    is_skew_symmetric: Callable[[], bool] = lambda self: self == (-self).transpose()
    is_square: Callable[[], bool] = lambda self: self.row == self.column
    is_symmetric: Callable[[], bool] = lambda self: self == self.transpose()
    nullity: Callable[[], int] = lambda self: self.row - self.rank()
    print: Callable[[], None] = \
        lambda self: [print([element.__str__() for element in self.matrix[i]]) for i in range(len(self.matrix))]
    similar_matrix: Callable[["Matrix[Fraction]"], "Matrix[Fraction]"] = \
        lambda self, matrix: matrix.inverse() * self * matrix
    trace: Callable[[], Fraction] = lambda self: sum(self.matrix[i][i] for i in range(self.row))