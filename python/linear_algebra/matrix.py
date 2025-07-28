from collections import namedtuple
from fractions import Fraction
from math import gcd, lcm, sqrt
from typing import Literal, Iterator, Any
from .math_num import MathNum
from .equation import Polynomial, Variable

Order = namedtuple("Order", ["row", "column"])

ROW: str = "row"
COLUMN: str = "column"
SQUARE: str = "square"
RECTANGULAR: str = "rectangular"
NULL: str = "null"
SCALAR: str = "scalar"
IDENTITY: str = "identity"
DIAGONAL: str = "diagonal"


class MatrixError(Exception): ...


class Matrix:
    """
# INITIALIZING MATRIX OBJECT
    -> using input method
        >>> m: Matrix = Matrix(2, 3, method="input")           # this is a matrix with 2 rows and 3 columns
        Enter row (space-separated values): 1 2 3
        Enter row (space-separated values): 4 5 6
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> providing a valid nested list and convert it to matrix
        >>> m: Matrix = Matrix(matrix=[[1, 2, 3], [4, 5, 6]])     # here matrix= is keyword only argument
        >>> print(m)

        rows = 2
        columns = 3
        matrix = [[Fraction(1, 1), Fraction(2, 2), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)]]

    -> by providing a type of matrix to generate
        -> null matrix
            >>> m: Matrix = Matrix(3, 3, method="null")        # creating a null matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]]

        -> identity matrix
            >>> m: Matrix = Matrix(3, 3, method="identity")    # creating an identity matrix of order 3
            >>> print(m)

            rows = 3
            columns = 3
            matrix = [[Fraction(1, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)]]

# USING OPERATORS BETWEEN MATRIX AND NUMERIC TYPES
    -> consider the following matrices and one integer throughout the section
        >>> m1: Matrix = Matrix(matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix = Matrix(matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> addition of two matrices
            >>> m1 + m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> subtraction of two matrices
            >>> m1 - m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> multiplication of matrices and numeric dtypes
            >>> m1 * m2
            Matrix(rows=2, columns=2, matrix=[[Fraction(19, 1), Fraction(22, 1)], [Fraction(43, 1), Fraction(50, 1)]])
            >>> m1 * num
            Matrix(rows=2, columns=2, matrix=[[Fraction(7, 1), Fraction(14, 1)], [Fraction(21, 1), Fraction(28, 1)]])

# USING IN-PLACE OPERATOR
    -> consider the following two matrices and one integer throughout the section
    -> matrices are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> m1: Matrix = Matrix(matrix=[[1, 2], [3, 4]])
        >>> m2: Matrix = Matrix(matrix=[[5, 6], [7, 8]])
        >>> num: int = 7

        -> in-place addition of two matrices
            >>> m1 += m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(6, 1), Fraction(8, 1)], [Fraction(10, 1), Fraction(12, 1)]])

        -> in-place subtraction of two matrices
            >>> m1 -= m2
            >>> m1
            Matrix(rows=2, columns=2, matrix=[[Fraction(-4, 1), Fraction(-4, 1)], [Fraction(-4, 1), Fraction(-4, 1)]])

        -> in-place multiplication of matrices and numeric dtypes
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
        >>> m: Matrix = Matrix(matrix=[[1, 2, 3], [4, 5, 6]])

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
    >>> m: Matrix = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.cramer_rule()
    ({'x1': Fraction(2, 1), 'x2': Fraction(3, 1), 'x3': Fraction(-1, 1)}

# CREATING A COPY OF THE MATRIX
    >>> m: Matrix = Matrix(matrix=[[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    >>> m.copy()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(2, 1), Fraction(3, 1)], [Fraction(4, 1), Fraction(5, 1), Fraction(6, 1)], [Fraction(7, 1), Fraction(8, 1), Fraction(9, 1)]])

# FINDING DETERMINANT OF A SQUARE MATRIX
    >>> m: Matrix = Matrix(matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.determinant()
    Fraction(-1, 1)

# DIAGONALIZING A MATRIX
    >>> m: Matrix = Matrix(matrix=[[-5, -6, 6], [-9, -8, 12], [-12, -12, 16]])
    >>> m.diagonalize()
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(-2, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)]])

# CONVERTING A MATRIX TO ITS EQUIVALENT ECHELON FORM
    >>> m: Matrix = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.echelon_form()
    Matrix(rows=3, columns=4, matrix=[[Fraction(2, 1), Fraction(1, 1), Fraction(-1, 1), Fraction(8, 1)], [Fraction(0, 1), Fraction(1, 2), Fraction(1, 2), Fraction(1, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(-1, 1), Fraction(1, 1)]])

# FINDING THE EIGEN VALUES OF A SQUARE MATRIX
    >>> m: Matrix = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_values()
    {'lambda1': Fraction(5, 1), 'lambda2': Fraction(-3, 1), 'lambda3': Fraction(-3, 1)}

# FINDING THE EIGEN VECTORS OF A SQUARE MATRIX
    >>> m: Matrix = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.eigen_vectors()
    ((Fraction(-1, 1), Fraction(-2, 1), Fraction(1, 1)), (Fraction(1, 1), Fraction(1, 1), Fraction(1, 1)))

# FINDING THE SOLUTION TO A SYSTEM OF LINEAR EQUATION USING GAUSS ELIMINATION METHOD
    >>> m: Matrix = Matrix(matrix=[[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    >>> m.gauss_elimination()
    {'x1': Fraction(2, 1), 'x2': Fraction(3, 1), 'x3': Fraction(-1, 1)}

# FINDING THE INVERSE OF A NON-SINGULAR MATRIX USING GAUSS JORDAN ELIMINATION METHOD
    >>> m: Matrix = Matrix(matrix=[[2, 1, -1], [-3, -1, 2], [-2, 1, 2]])
    >>> m.inverse()
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(3, 1), Fraction(-1, 1)], [Fraction(-2, 1), Fraction(-2, 1), Fraction(1, 1)], [Fraction(5, 1), Fraction(4, 1), Fraction(-1, 1)]])

# CHECKING IF THE SET OF ROW VECTORS ARE LINEARLY DEPENDENT OR INDEPENDENT
    >>> m: Matrix = Matrix(matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.is_linearly_independent()
    False

# CHECKING IF A MATRIX IS A ORTHOGONAL MATRIX
    >>> m: Matrix = Matrix(method="identity")
    >>> m.is_orthogonal()
    True

# CHECKING IF A MATRIX IS A ORTHONORMAL SYSTEM OF COLUMN VECTORS
    >>> m: Matrix = Matrix(method="identity")
    >>> m.is_orthonormal_system()
    True

# CHECKING IF A MATRIX IS POSITIVE DEFINITE MATRIX
    >>> m: Matrix = Matrix(matrix=[[3, -1, 1], [-1, 5, -1], [1, -1, 3]])
    >>> m.is_positive_definite()
    True

# CHECKING IF A MATRIX IS SKEW SYMMETRIC MATRIX
    >>> m: Matrix = Matrix(matrix=[[0, 1, -2], [-1, 0, 3], [2, -3, 0]])
    >>> m.is_skew_symmetric()
    True

# CHECKING IF A MATRIX IS SQUARE OR NOT
    >>> m: Matrix = Matrix(method="null")
    >>> m.is_square()
    True

# CHECKING IF A MATRIX IS SYMMETRIC MATRIX
    >>> m: Matrix = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.is_symmetric()
    True

# GIVES THE NULLITY OF A MATRIX
    >>> m: Matrix = Matrix(4, 4, matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.nullity()
    2

# COMPUTING PSEUDO INVERSE OF A MATRIX
    >>> m: Matrix = Matrix(matrix=[[1, -1, 1], [-2, 2, -2]])
    >>> m.pseudo_inverse()
    Matrix(rows=3, columns=2, matrix=[[Fraction(-67, 1000), Fraction(133, 1000)], [Fraction(67, 1000), Fraction(-133, 1000)], [Fraction(-67, 1000), Fraction(133, 1000)]])

# USING THE MATRIX PRINT FUNCTION
    >>> m: Matrix = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.print()
    ['1', '1', '-1']
    ['1', '2', '0']
    ['-1', '0', '5']

# FINDING THE RANK OF A MATRIX
    >>> m: Matrix = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.rank()
    3

# SINGULAR VALUE DECOMPOSITION OF A MATRIX [A = U * sigma * trans(T)]
    >>> m: Matrix = Matrix(matrix=[[-2, 2, -3], [2, 1, -6], [-1, -2, 0]])
    >>> m.singular_value_decomposition()
    {
        'u': Matrix(rows=3, columns=3, matrix=[[Fraction(0, 1), Fraction(0, 1), Fraction(-500, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(250, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]]),
        'sigma': Matrix(rows=3, columns=3, matrix=[[Fraction(2133, 1000), Fraction(0, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(3, 1), Fraction(0, 1)], [Fraction(0, 1), Fraction(0, 1), Fraction(879, 125)]]),
        'v': Matrix(rows=3, columns=3, matrix=[[Fraction(0, 1), Fraction(0, 1), Fraction(-500, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(250, 559)], [Fraction(0, 1), Fraction(0, 1), Fraction(0, 1)]])
    }

# FINDING THE SIMILAR MATRIX OF THE SELF MATRIX
    >>> m: Matrix = Matrix(matrix=[[-5, 0, 15], [3, 4, -9], [-5, 0, 15]])
    >>> p: Matrix = Matrix(matrix=[[0, 1, 0], [1, 0, 0], [0, 0, 1]])
    >>> m.similar_matrix(p)
    Matrix(rows=3, columns=3, matrix=[[Fraction(4, 1), Fraction(3, 1), Fraction(-9, 1)], [Fraction(0, 1), Fraction(-5, 1), Fraction(15, 1)], [Fraction(0, 1), Fraction(-5, 1), Fraction(15, 1)]])

# CALCULATES THE TRACE OF THE MATRIX
    >>> m: Matrix = Matrix(4, 4, matrix=[[1, 2, 3, 4], [2, 3, 4, 5], [3, 4, 5, 6], [4, 5, 6, 7]])
    >>> m.trace()
    16

# FINDING TRANSPOSE OF A MATRIX
    >>> m: Matrix = Matrix(matrix=[[1, 1, -1], [1, 2, 0], [-1, 0, 5]])
    >>> m.transpose()
    Matrix(rows=3, columns=3, matrix=[[Fraction(1, 1), Fraction(1, 1), Fraction(-1, 1)], [Fraction(1, 1), Fraction(2, 1), Fraction(0, 1)], [Fraction(-1, 1), Fraction(0, 1), Fraction(5, 1)]])

# DETERMINING THE TYPE OF THE MATRIX
    >>> M: Matrix = Matrix(2, 3, method="null")
    >>> m.type()
    'rectangular'
    """

    def __init__(self, rows: int = 0, columns: int = 0, method: Literal["input", "null", "identity", "pass"] = "pass",
                 *, matrix: list[list[Any]] | None = None, always_evaluate: bool = True, datatype: type = Fraction) -> None:
        """Matrix object initializer function"""
        if matrix is not None:
            rows = len(matrix)
            columns = len(matrix[0])

        self._order: Order = Order(rows, columns)

        if rows <= 0 or columns <= 0:
            raise MatrixError("Row or column of a matrix cannot be negative or null")

        if method == "input":
            self._input()

        elif method == "null":
            self._null()

        elif method == "identity":
            self._identity()

        elif method == "pass":
            if matrix is None:
                raise MatrixError("Matrix object requires a valid matrix")

            self._matrix: list[list[MathNum]] = [[MathNum(element) for element in row] for row in matrix]
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
    def matrix(self) -> list[list[MathNum]]:
        return self._matrix

    def __add__(self, other: "Matrix") -> "Matrix":
        """Operator+ overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix = Matrix(self.row, self.column, "null")

                for i in range(self.row):
                    for j in range(self.column):
                        result.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for addition\n")

        else:
            return NotImplemented

    def __sub__(self, other: "Matrix") -> "Matrix":
        """Operator- overloaded function"""
        if isinstance(other, Matrix):
            if self.order == other.order:
                result: Matrix = Matrix(self.row, self.column, "null")

                for i in range(self.row):
                    for j in range(self.column):
                        result.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]

                return result

            else:
                raise MatrixError("Invalid order for subtraction\n")

        else:
            return NotImplemented

    def __mul__(self, other: "Matrix | Any") -> "Matrix":
        """Operator* overloaded function"""
        if isinstance(other, Matrix):
            if self.column == other.row:
                result: Matrix = Matrix(self.row, other.column, "null")

                for k in range(self.row):
                    for i in range(other.column):
                        for j in range(self.column):
                            result.matrix[k][i] += self.matrix[k][j] * other.matrix[j][i]

                return result

            else:
                raise MatrixError("Invalid matrix order for multiplication\n")

        try:
            num: MathNum = MathNum(str(other))
            result = Matrix(self.row, self.column, "null")

            for i in range(self.row):
                for j in range(self.column):
                    result[i][j] = self.matrix[i][j] * num

            return result

        except ValueError:
            return NotImplemented

    def __iadd__(self, other: "Matrix") -> "Matrix":
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

    def __isub__(self, other: "Matrix") -> "Matrix":
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

    def __imul__(self, other: "Matrix | Any") -> "Matrix":
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
                num: MathNum = MathNum(str(other))

                for i in range(self.row):
                    for j in range(self.column):
                        self.matrix[i][j] *= num

                return self

            except ValueError:
                return NotImplemented

    def __contains__(self, item: Any) -> bool:
        """Built-in "in" overloaded keyword"""
        for row in self.matrix:
            for element in row:
                if element == item:
                    return True

        return False

    def __iter__(self) -> Iterator[list[MathNum]]:
        """Built-in iter() overloaded function"""
        for row in self.matrix:
            yield row

    def __eq__(self, other: "Matrix") -> bool:
        """Operator== overloaded function"""
        if isinstance(other, Matrix):
            return self.matrix == other.matrix

        return NotImplemented

    def __str__(self) -> str:
        """Built-in str() overloaded function"""
        return f"rows = {self.row}\ncolumns = {self.column}\nmatrix = {self.matrix}\n"

    def __repr__(self) -> str:
        """Built-in repr() overloaded function"""
        return f"Matrix(rows={self.row}, columns={self.column}, matrix={self.matrix})"

    __radd__ = lambda self, other: self.__add__(other)
    __rsub__ = lambda self, other: (-self).__add__(other)
    __rmul__ = lambda self, other: self.__mul__(other)
    __bool__ = lambda self: self.type() != "null"
    __pos__ = lambda self: self
    __neg__ = lambda self: self.__mul__(-1)
    __getitem__ = lambda self, item: self.matrix[item]
    __name__: str = "Matrix"
    __abs__ = lambda self: Matrix(matrix=[abs(self.matrix[i][j]) for i in range(self.row) for j in range(self.column)])
    __call__ = __repr__

    def _back_substitution(self, substitute: int = 1) -> list[Fraction | None]:
        """Back-substitutes the values in order to find the solution of the linear polynomial equations"""
        res: list[Fraction | None] = [None for _ in range(self.row)]

        for row in self.matrix[::-1]:
            poly: Polynomial = row[0]

            for idx, component in enumerate(res):
                if component is not None:
                    poly = poly.substitute(f"x{idx + 1}", component)

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

                idx = int(tuple(var[0].variables.keys())[0][1])

                try:
                    res[idx - 1] = -poly.numerator[1].coefficient

                except IndexError:
                    res[idx - 1] = Fraction(0)

            elif len(var) > 1:
                for variable in var[1:]:
                    element: str = tuple(variable.variables.keys())[0]
                    poly = poly.substitute(element, Fraction(1))
                    res[int(element[1]) - 1] = Fraction(substitute)

                for i in range(len(poly.numerator)):
                    poly.numerator[i] /= var[0].coefficient

                idx = int(tuple(var[0].variables.keys())[0][1])

                try:
                    res[idx - 1] = -poly.numerator[1].coefficient

                except IndexError:
                    res[idx - 1] = Fraction(0)

        return res

    @staticmethod
    def _dot_product(lst1: list[Any], lst2: list[Any]) -> Any:
        """Computes the dot product of two vectors"""
        if len(lst1) != len(lst2):
            raise MatrixError("Dot product of two unequal order of vector is not defined")

        res: Fraction = Fraction(0)

        for i in range(len(lst1)):
            res += lst1[i] * lst2[i]

        return res

    def _identity(self) -> None:
        """Initializes an identity matrix"""
        self._matrix = [[Fraction(1) if i == j else Fraction(0) for j in range(self.column)]
                        for i in range(self.row)]

    def _input(self) -> None:
        """Accept user input for construct the matrix with provided values"""
        self._matrix = []

        for _ in range(self.row):
            row: list[str] = input("Enter row (space-separated values): ").split()

            if len(row) == self.column:
                self._matrix.append([Fraction(element) for element in row])

            else:
                raise MatrixError("Invalid matrix elements")

        self._validate()

    def _null(self) -> None:
        """Initializes a null matrix"""
        self._matrix = [[Fraction(0) for _ in range(self.column)] for _ in
                        range(self.row)]

    @staticmethod
    def _simplify_row(lst: list[Fraction]) -> tuple[Fraction, ...]:
        """Simplifies a list of Fractions by dividing them with their GCD"""
        factor: Fraction = Fraction(1)
        size: int = len(lst)
        all_neg: bool = True

        for i in range(size):
            factor = Fraction(gcd(factor.numerator, lst[i].numerator),
                              lcm(factor.denominator, lst[i].denominator))

            if lst[i] >= 0:
                all_neg = False

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
                    self.matrix[i][j] = Fraction(str(self.matrix[i][j]))

                except (TypeError, ValueError):
                    pass

    def cramer_rule(self) -> dict[str, Any] | tuple[int, str]:
        """Solves a system of linear equation where the matrix object is an augmented coefficient matrix of the set of linear equation by using Cramer's Rule."""
        if self.row < self.column:
            matrix: list[list[Any]] = [row for idx, row in enumerate(self.matrix) if idx < self.column - 1]

        else:
            matrix = self.matrix

        result: Matrix = Matrix(matrix=matrix)

        temp_a: list[list[Any]] = []
        b: list[list[Any]] = []
        res: list[Any] = []

        for row in result:
            temp_a.append(row[:-1])
            b.append(row[-1])

        a: Matrix = Matrix(matrix=temp_a)
        det: Any = a.determinant()

        if det == 0:
            return -1, "The set of linear equations has no solutions"

        for i in range(self.row):
            temp_matrix = a.copy()

            for j in range(self.row):
                temp_matrix[j][i] = b[j]

            res.append(temp_matrix.determinant() / det)

        return {f"x{i + 1}": val for i, val in enumerate(res)}

    def determinant(self) -> Any:
        """Finds the determinant of the matrix."""
        if not self.is_square():
            raise MatrixError("Determinant of rectangular matrix is not defined")

        result: Matrix = self.echelon_form()
        det: Fraction = Fraction(1)

        for i in range(result.row):
            det *= result.matrix[i][i]

        return det

    def diagonalize(self) -> "Matrix":
        vectors: tuple[tuple[Fraction, ...], ...] = self.eigen_vectors()
        x: Matrix = Matrix(matrix=[list(vector) for vector in vectors]).transpose()
        return x.inverse() * self * x

    def echelon_form(self) -> "Matrix":
        """Returns the echelon_form of the current matrix."""
        result: Matrix = self.copy()
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

            pivot = cnt

            for i in range(pivot + 1, result.row):
                factor: Fraction = result.matrix[i][pivot] / result.matrix[pivot][pivot]

                for j in range(pivot, result.column):
                    result.matrix[i][j] -= (factor * result.matrix[pivot][j])

            pivot += 1

        return result

    def eigen_values(self) -> dict[str, Fraction | float]:
        """Finds the eigen values of a matrix."""

        def recursive_determinant(matrix: list[list[Polynomial]]) -> Polynomial:
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
        temp: tuple[float | complex, ...] = char_poly.roots()
        res: list[float] = []

        for element in temp:
            if isinstance(element, complex):
                raise MatrixError("Complex roots are not supported")

            else:
                res.append(element)

        try:
            ans: tuple[Fraction, ...] = tuple((Fraction(f"{round(element, 3)}") for element in res))
            return {f"lambda{i + 1}": val for i, val in enumerate(ans)}

        except TypeError:
            return {f"lambda{i + 1}": val for i, val in enumerate(res)}

        except ValueError:
            raise MatrixError("Complex roots are not supported.")

    def eigen_vectors(self, is_absolute: bool = False) -> tuple[tuple[Fraction, ...], ...]:
        """Finds the normalized eigen vectors for the corresponding eigen values of the matrix."""
        res: list[tuple[Fraction, ...]] = []
        cnt: dict[Fraction | float, int] = {}
        eigen_val: dict[str, Fraction | float] = self.eigen_values()

        if is_absolute:
            for key, value in eigen_val.items():
                eigen_val[key] = value.__abs__()

        var_mat: Matrix = Matrix(matrix=[[Polynomial(f"x{i}")] for i in range(1, self.column + 1)])

        for value in eigen_val.values():
            cnt[value] = cnt.get(value, 0) + 1

        for factor, rpt in cnt.items():
            matrix: list[list[Any]] = [[self.matrix[i][j] - (factor if i == j else Fraction(0))
                                        for j in range(self.column)] for i in range(self.row)]
            char_matrix: Matrix = Matrix(matrix=matrix).echelon_form() * var_mat

            for i in range(1, rpt + 1):
                eigen_vec: list[Fraction] = [Fraction(1) if rpt is None else rpt for rpt in
                                             char_matrix._back_substitution(substitute=i)]
                res.append(self._simplify_row(eigen_vec))

        return tuple(res)

    def gauss_elimination(self) -> dict[str, Fraction] | tuple[int, str]:
        """Solves the system of linear equations (assuming the "self" matrix as the augmented matrix) by gauss elimination method"""
        if self.row != self.column - 1:
            matrix: list[list[Any]] = [row for idx, row in enumerate(self.matrix) if idx < self.column - 1]
            order: Order = Order(len(matrix), len(matrix[0]))

        else:
            matrix = self.matrix
            order = self.order

        result: Matrix = Matrix(matrix=matrix).echelon_form()

        if result[-1][-2] == 0 and result[-1][-1] != 0:
            return 0, "The set of linear equations has no solutions"

        else:
            for i in range(order.row):
                result.matrix[i][-1] = -result.matrix[i][-1]

            matrix = [[Polynomial(f"x{i}")] for i in range(1, order.row + 1)]
            matrix.append([Fraction(1)])
            var_mat: Matrix = Matrix(matrix=matrix)
            poly_mat: Matrix = result * var_mat

            res: list[Fraction] = [Fraction(1) if val is None else val for val in poly_mat._back_substitution()]
            return {f"x{i + 1}": val for i, val in enumerate(res)}

    def inverse(self) -> "Matrix":
        """Computes the inverse of a non-singular matrix using Gauss Jordan Elimination"""
        if not self.is_square():
            raise MatrixError("Inverse of a rectangular matrix is not defined")

        det: Any = self.determinant()

        if det == 0:
            raise MatrixError("Inverse of singular matrix is not defined")

        identity_mat: Matrix = Matrix(self.row, self.column, "identity")
        aug_matrix: Matrix = Matrix(matrix=[self.matrix[i] + identity_mat.matrix[i] for i in range(self.row)])
        aug_matrix = aug_matrix.echelon_form()
        aug_matrix._matrix = aug_matrix.matrix[::-1]

        for i in range(self.row):
            aug_matrix[i][:self.order[0]] = list(reversed(aug_matrix[i][:self.order[0]]))

        aug_matrix = aug_matrix.echelon_form()
        # print(aug_matrix)
        # exit(0)
        res: list[list[Fraction]] = []

        for i in range(self.row - 1, -1, -1):
            factor: Any = 1 / aug_matrix[i][i]

            for j in range(self.row, self.row * 2):
                aug_matrix[i][j] *= factor

            res.append(aug_matrix[i][self.row:])

        return Matrix(matrix=res)

    def is_orthonormal_system(self) -> bool:
        """Checks whether the matrix is a orthonormal system of column vectors"""
        if not self.is_square():
            raise MatrixError("Orthonormal system is defined for square matrices only")

        matrix: Matrix = self.transpose()

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
            temp_mat: Matrix = Matrix(matrix=[self.matrix[j][:i] for j in range(i)])

            if temp_mat.determinant() <= 0:
                return False

        return True

    @staticmethod
    def normalize(eigen_vector: tuple[Fraction, ...]) -> tuple[Fraction, ...]:
        """Normalizes a eigen vector"""
        total: Fraction = Fraction(0)

        for value in eigen_vector:
            total += value ** 2

        factor: Fraction = Fraction(str(round(sqrt(float(total)), 3)))

        if factor:
            return tuple(value / factor for value in eigen_vector)

        else:
            return eigen_vector

    def print(self) -> None:
        """Prints the matrix"""

        for i in range(len(self.matrix)):
            print([element.__str__() for element in self.matrix[i]])

    def pseudo_inverse(self) -> "Matrix":
        """Computes the pseudo inverse of a matrix"""
        svd: dict[str, Matrix] = self.singular_value_decomposition()
        sigma_plus: Matrix = svd["sigma"].transpose()

        for i in range(sigma_plus.row):
            if sigma_plus[i][i] != Fraction(0):
                sigma_plus[i][i] = Fraction(1) / sigma_plus[i][i]

        a_plus: Matrix = svd["v"] * sigma_plus * svd["u"].transpose()

        for i in range(a_plus.row):
            for j in range(a_plus.column):
                a_plus[i][j] = Fraction(str(round(float(a_plus[i][j]), 3)))

        return a_plus

    def rank(self) -> int:
        """Gives the rank of the matrix"""
        result: Matrix = self.echelon_form()
        rank: int = result.row

        for i in range(self.row):
            if result.matrix[i][i] == 0:
                rank -= 1

        return rank

    def singular_value_decomposition(self) -> dict[str, "Matrix"]:
        """Gives the singular value decomposition of the matrix [A = U * sigma * trans(T)]"""
        aaT: Matrix = self * self.transpose()
        aat_eigen_val: list[Fraction | float] = list(sorted(aaT.eigen_values().values(), reverse=True))
        sigma: Matrix = Matrix(self.row, self.column, "null")

        for i in range(len(aat_eigen_val)):
            sigma[i][i] = Fraction(str(round(sqrt(abs(float(aat_eigen_val[i]))), 3)))

        aat_eigen_vec: tuple[tuple[Fraction, ...], ...] = aaT.eigen_vectors(is_absolute=True)
        u: Matrix = Matrix(matrix=[list(self.normalize(vec)) for vec in aat_eigen_vec]).transpose()

        aTa: Matrix = self.transpose() * self
        ata_eigen_vec: tuple[tuple[Fraction, ...], ...] = aTa.eigen_vectors(is_absolute=True)
        v: Matrix = Matrix(matrix=[list(self.normalize(vec)) for vec in ata_eigen_vec]).transpose()

        return {"u": u, "sigma": sigma, "v": v}

    def transpose(self) -> "Matrix":
        """Gives the transpose of the matrix"""
        result: Matrix = Matrix(self.column, self.row, "null")

        for i in range(self.row):
            for j in range(self.column):
                result.matrix[j][i] = self.matrix[i][j]

        return result

    def type(self) -> str:
        if self.row == 1 and self.column != 1:
            res = ROW

        elif self.column == 1 and self.row != 1:
            res = COLUMN

        elif self.row == self.column:
            res = "square"
            is_scalar: bool = True
            is_identity: bool = True
            is_diagonal: bool = True

            for i in range(self.row):
                for j in range(self.column):
                    if i == j:
                        if self.matrix[i][j] != self.matrix[0][0]:
                            is_scalar = False

                        elif self.matrix[i][j] != Fraction(1):
                            is_identity = False

                    else:
                        if self.matrix[i][j] != Fraction(0):
                            is_scalar = False
                            is_identity = False
                            is_diagonal = False

                if not (is_scalar and is_identity and is_diagonal):
                    break

            if is_identity:
                res = IDENTITY

            elif is_scalar:
                res = SCALAR

            elif is_diagonal:
                res = DIAGONAL

        elif self.row != self.column:
            res = RECTANGULAR

        else:
            res = ""

        is_null: bool = True

        for i in range(self.row):
            for j in range(self.column):
                if self.matrix[i][j] != Fraction(0):
                    is_null = False
                    break

            if not is_null:
                break

        if is_null:
            res = NULL

        return res

    copy = lambda self: Matrix(matrix=self.matrix)
    is_linearly_independent = lambda self: self.row == self.rank()
    is_orthogonal = lambda self: self.is_orthonormal_system()
    is_skew_symmetric = lambda self: self == (-self).transpose()
    is_square = lambda self: self.row == self.column
    is_symmetric = lambda self: self == self.transpose()
    nullity = lambda self: self.row - self.rank()
    similar_matrix = lambda self, matrix: matrix.inverse() * self * matrix
    trace = lambda self: Fraction(sum(self.matrix[i][i] for i in range(self.row)))
