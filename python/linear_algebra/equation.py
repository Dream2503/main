from fractions import Fraction
from .math_num import MathNum
from typing import Generator, Any


class PolynomialError(Exception): ...


class Variable:
    """
# INITIALIZING VARIABLE OBJECT
    -> providing a valid expression in a str
        >>> v: Variable = Variable("7x^2")
        >>> print(v)
        7x^2

    -> providing the direct coefficient and variables property attributes
        >>> v: Variable = Variable(coefficient=7, variables_dict={"x": 2})
        >>> print(v)
        7x^2

# USING OPERATORS BETWEEN VARIABLE AND NUMERIC TYPE
    # ADDITION AND SUBTRACTION OF VARIABLE OBJECTS WITH DIFFERENT VARIABLE BASES ARE NOT IMPLEMENTED
    -> consider the following variables and one integer throughout the section
        >>> v1: Variable = Variable("5x")
        >>> v2: Variable = Variable("2x")
        >>> num: int = 7

        -> addition of two variables
            >>> v1 + v2
            Variable(coefficient=7, variables={'x': Fraction(1, 1)})

        -> subtraction of two variables
            >>> v1 - v2
            Variable(coefficient=3, variables={'x': Fraction(1, 1)})

        -> multiplication of variables and numeric dtypes
            >>> v1 * v2
            Variable(coefficient=10, variables={'x': Fraction(2, 1)})
            >>> v1 * num
            Variable(coefficient=35, variables={'x': Fraction(1, 1)})

        -> division of variables and numeric dtypes
            >>> v1 / v2
            Variable(coefficient=5/2, variables={'x': Fraction(0, 1)})
            >>> v1 / num
            Variable(coefficient=5/7, variables={'x': Fraction(1, 1)})

        -> exponentiating a variable
            >>> v1 ** 2
            Variable(coefficient=25, variables={'x': Fraction(2, 1)})

# USING IN-PLACE OPERATOR
    -> consider the following two variables and one integer throughout the section
    -> variables are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> v1: Variable = Variable("5x")
        >>> v2: Variable = Variable("2x")
        >>> num: int = 7

        -> in-place addition of two variables
            >>> v1 += v2
            >>> v1
            Variable(coefficient=7, variables={'x': Fraction(1, 1)})

        -> in-place subtraction of two variables
            >>> v1 -= v2
            >>> v1
            Variable(coefficient=3, variables={'x': Fraction(1, 1)})

        -> in-place multiplication of variables and numeric dtypes
            >>> v1 *= v2
            >>> v1
            Variable(coefficient=10, variables={'x': Fraction(2, 1)})
            >>> v1 *= num
            >>> v1
            Variable(coefficient=35, variables={'x': Fraction(1, 1)})

        -> in-place division of variables and numeric dtypes
            >>> v1 /= v2
            >>> v1
            Variable(coefficient=5/2, variables={})
            >>> v1 /= num
            >>> v1
            Variable(coefficient=5/7, variables={'x': Fraction(1, 1)})

        -> exponentiating a variable
            >>> v1 **= 2
            >>> v1
            Variable(coefficient=25, variables={'x': Fraction(2, 1)})

# OTHER BUILT-IN OPERATORS
    -> checking equality between variables
        >>> v1 == v2
        False

    -> absolute value of a variable
        >>> v1 += -1                            # making the variable negative by multiplying with -1
        >>> abs(v1)
        Variable(coefficient=5, variables={'x': Fraction(1, 1)})

    -> checking the truth value of a variable
        >>> v: Variable = Variable()
        >>> bool(v)
        False
        >>> bool(v1)
        True

# SUBSTITUTE THE VALUE OF A VALUE INTO THE VARIABLE
    >>> v: Variable = v1.substitute('x', 5)
    >>> v
    Variable(coefficient=25, variables={})

# CREATING A COPY OF THE VARIABLE
    >>> v: Variable = Variable("9x^2")
    >>> v.copy()
    Variable(coefficient=9, variables={'x': Fraction(2, 1)})
    """

    def __init__(self, expression: Any = "0", *, coefficient: MathNum = MathNum(),
                 variables_dict: dict[str, MathNum] | None = None, always_evaluate=True,
                 datatype: type = Fraction) -> None:
        """Initialization function for Variable class"""
        self._coefficient: MathNum = MathNum(coefficient)
        self._variables: dict[str, MathNum] = variables_dict.copy() if variables_dict is not None else {}
        self._parameters: dict[str, bool | type] = {"always_evaluate": always_evaluate, "datatype": datatype}

        if coefficient == MathNum():
            self._coefficient, self._variables = str_variable(str(expression), datatype)

        self._coefficient = self._coefficient.evaluate(return_type=datatype) if always_evaluate else self._coefficient

        temp: dict[str, MathNum] = {key: value.evaluate(return_type=datatype) if always_evaluate else value
                                    for key, value in self._variables.items() if value != MathNum()}
        self._variables = dict(sorted(temp.items()))

    @property
    def coefficient(self) -> MathNum:
        return self._coefficient

    @property
    def variables(self) -> dict[str, MathNum]:
        return self._variables

    def __str__(self) -> str:
        """Built-in str() overloaded function"""
        res: str = ""
        is_brace: bool = False

        if self._coefficient == MathNum():
            return '0'

        if self._variables == {}:
            return str(self._coefficient)

        if self._coefficient != 1:
            # if self._coefficient.operations:
            #     res += f"{self._coefficient}"
            #
            # else:
            res += str(self._coefficient)

        if len(self._variables) > 1:
            is_brace = True

        for variable, order in self._variables.items():
            if order != 0:
                if is_brace and order != 1:
                    res += '('

                if len(variable) > 1:
                    res += f"({variable})"

                else:
                    res += variable

                if order != 1:
                    # if order.operations:
                    #     res += f"^{str(order)}"
                    # else:
                    res += f"^{str(order)}"

                    if is_brace:
                        res += ')'
        return res

    def __repr__(self) -> str:
        return f"Variable(coefficient={self._coefficient}, variables={self._variables})"

    def __add__(self, other: "Variable") -> "Variable":
        """Operator+ overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient + other.coefficient, variables_dict=self.variables,
                            **self._parameters)

        else:
            return NotImplemented

    def __sub__(self, other: "Variable") -> "Variable":
        """Operator- overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            return Variable(coefficient=self.coefficient - other.coefficient, variables_dict=self.variables,
                            **self._parameters)

        else:
            return NotImplemented

    def __mul__(self, other: "Variable | Any") -> "Variable":
        """Operator* overloaded function"""
        if isinstance(other, Variable):
            coefficient: MathNum = self.coefficient * other.coefficient
            variables: dict[str, MathNum] = {}

            for element in (self.variables, other.variables):
                for var, order in element.items():
                    variables[var] = variables[var] + order if variables.get(var) is not None else order

            return Variable(coefficient=coefficient, variables_dict=variables, **self._parameters)

        else:
            try:
                return Variable(coefficient=self.coefficient * MathNum(other, datatype=self._parameters["datatype"]),
                                variables_dict=self.variables, **self._parameters)

            except ValueError:
                return NotImplemented

    def __truediv__(self, other: "Variable | Any") -> "Variable":
        """Operator/ overloaded function"""
        if isinstance(other, Variable):
            coefficient: MathNum = self.coefficient / other.coefficient
            variables: dict[str, MathNum] = {}

            for var, order in self.variables.items():
                variables[var] = variables[var] + order if variables.get(var) is not None else order

            for var, order in other.variables.items():
                variables[var] = variables[var] - order if variables.get(var) is not None else -order

            return Variable(coefficient=coefficient, variables_dict=variables, **self._parameters)

        else:
            try:
                return Variable(coefficient=self.coefficient / MathNum(other, datatype=self._parameters["datatype"]),
                                variables_dict=self.variables, **self._parameters)

            except ValueError:
                return NotImplemented

    def __pow__(self, value: Any) -> "Variable":
        """Operator** overloaded function"""
        try:
            power: MathNum = MathNum(value)
            return Variable(coefficient=self.coefficient ** power,
                            variables_dict={key: value * power for key, value in self.variables.items()},
                            **self._parameters)

        except ValueError:
            return NotImplemented

    def __iadd__(self, other: "Variable") -> "Variable":
        """Operator+= overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            self._coefficient += other.coefficient
            return self

        else:
            return NotImplemented

    def __isub__(self, other: "Variable") -> "Variable":
        """Operator-= overloaded function"""
        if isinstance(other, Variable) and self.variables == other.variables:
            self._coefficient -= other.coefficient
            return self

        else:
            return NotImplemented

    def __imul__(self, other: "Variable | Any") -> "Variable":
        """Operator*= overloaded function"""
        if isinstance(other, Variable):
            self._coefficient *= other.coefficient

            for var, order in other.variables.items():
                self.variables[var] = self.variables[var] + order if self.variables.get(var) is not None else order

            return self

        else:
            try:
                self._coefficient *= MathNum(other, datatype=self._parameters["datatype"])
                return self

            except ValueError:
                return NotImplemented

    def __itruediv__(self, other: "Variable | Any") -> "Variable":
        """Operator/= overload function"""
        if isinstance(other, Variable):
            self._coefficient /= other.coefficient

            for var, order in other.variables.items():
                self.variables[var] = self.variables[var] - order if self.variables.get(var) is not None else order

            return self

        else:
            try:
                self._coefficient /= MathNum(other, datatype=self._parameters["datatype"])
                return self

            except ValueError:
                return NotImplemented

    def __ipow__(self, power) -> "Variable":
        """Operator**= overloaded function"""
        try:
            self._coefficient **= power
            self._variables = {key: value * power for key, value in self.variables.items()}
            return self

        except ValueError:
            return NotImplemented

    def __eq__(self, other: Any) -> bool:
        """Operator== overloaded function"""
        if isinstance(other, Variable):
            return self.coefficient == other.coefficient and self.variables == other.variables

        else:
            try:
                return self.coefficient == MathNum(other, datatype=self._parameters["datatype"]) and not self.variables

            except ValueError:
                return NotImplemented

    __rmul__ = lambda self, other: self.__mul__(other)
    __rtruediv__ = lambda self, other: Variable(coefficient=other / self.coefficient,
                                                variables_dict={key: value * -1 for key, value in
                                                                self.variables.items()}, **self._parameters)
    __abs__ = lambda self: Variable(coefficient=abs(self.coefficient), variables_dict=self.variables.copy(),
                                    **self._parameters)
    __bool__ = lambda self: bool(self.coefficient)
    __neg__ = lambda self: self * -1
    __pos__ = lambda self: self
    __len__ = lambda self: len(self.variables)
    copy = lambda self: Variable(coefficient=self.coefficient, variables_dict=self.variables.copy(), **self._parameters)

    def substitute(self, variable: str, value: "Variable | Any") -> "Variable":
        """Substitutes a value of a variable with a number or another variable and returns a new variable"""
        if self.variables.get(variable, None) is not None:
            if isinstance(value, Variable):
                if len(value) == 1:
                    variables: dict[str, MathNum] = {}

                    for key, val in self.variables.items():
                        if key == variable:
                            first, second = tuple(value.variables.items())[0]
                            variables[first] = variables[first] + second * val if variables.get(
                                first) is not None else second * val

                        else:
                            variables[key] = variables[key] + val if variables.get(key) is not None else val

                    return Variable(coefficient=self.coefficient * value.coefficient, variables_dict=variables,
                                    **self._parameters)

            else:
                return Variable(coefficient=self.coefficient * (MathNum(value) ** self.variables[variable]),
                                variables_dict={key: value for key, value in self.variables.items() if key != variable},
                                **self._parameters)

        return self.copy()


def str_variable(expression: str, datatype: type) -> tuple[MathNum, dict[str, MathNum]]:
    res: MathNum = MathNum(0, datatype=datatype)
    on_coef: bool = True
    on_var: bool = True
    on_order: bool = False
    num_str: str = ""
    variable: str = ""
    var: list[str] = []
    i: int = 0
    size: int = len(expression)

    while i < size:
        if on_coef and expression[i].isalpha():
            res = MathNum(1, datatype=datatype)
            on_coef = False
            i -= 1

        elif on_coef and not expression[i].isalpha():
            while i < size and not expression[i].isalpha():
                num_str += expression[i]
                i += 1

            res = MathNum(num_str, datatype=datatype)
            num_str = ""
            i -= 1
            on_coef = False

        elif on_var and expression[i].isalpha():
            while i < size and expression[i] != '^':
                variable += expression[i]
                i += 1

            var.append(variable)
            on_var = False
            on_order = True
            variable = ""
            i -= 1

        elif on_var and not expression[i].isalpha():
            raise ValueError("Invalid Variable")

        elif on_order and expression[i].isalpha():
            var.extend(('1', expression[i]))

        elif on_order and expression[i] == '^':
            i += 1

            while i < size and not expression[i].isalpha():
                num_str += expression[i]
                i += 1

            var.append(num_str)
            num_str = ""
            on_order = False
            on_var = True
            i -= 1

        i += 1

    var.append("1") if len(var) % 2 != 0 else var
    variables: dict[str, MathNum] = {var[i - 1]: MathNum(var[i]) for i in range(1, len(var), 2)}
    return res, variables


from cmath import sqrt as sqrtc
from math import gcd, lcm, cos, acos, pi, sqrt as sqrtf


class Polynomial:
    """
    # I WILL BE PRINTING THE RESULTANT POLYNOMIAL BECAUSE THE POLYNOMIAL REPRESENTATION MAY SEEM VERY CONFUSING
    # INITIALIZING POLYNOMIAL OBJECT
    -> providing a valid expression in a str
        >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> print(poly)
        3x^3 - 5x^2 + 2x + 7

    -> providing the direct numerator variables and denominator variables property attributes
        >>> poly: Polynomial = Polynomial(numerator_variables=[Variable(coefficient=3, variables={'x': Fraction(3, 1)}),Variable(coefficient=-5, variables={'x': Fraction(2, 1)}), Variable(coefficient=2, variables={'x': Fraction(1, 1)}), Variable(coefficient=7, variables={})], denominator_variables=[Variable(coefficient=1, variables={})])
        >>> print(poly)
        3x^3 - 5x^2 + 2x + 7

# USING OPERATORS BETWEEN POLYNOMIAL AND NUMERIC TYPE
    -> consider the following polynomials and one integer throughout the section
        >>> poly1: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> poly2: Polynomial = Polynomial("4x^4 6x^2 -1x 9")
        >>> num: int = 7

        -> addition of polynomials and numeric dtypes
            >>> print(poly1 + poly2)
            4x^4 + 3x^3 + x^2 + x + 16
            >>> print(poly1 + num)
            x^3 - 5x^2 + 2x + 14

        -> subtraction of polynomials and numeric dtypes
            >>> print(poly1 - poly2)
            -4x^4 + 3x^3 - 11x^2 + 3x - 2
            >>> print(poly1 - num)
            x^3 - 5x^2 + 2x - 0

        -> multiplication of polynomials and numeric dtypes
            >>> print(poly1 * poly2)
            12x^7 - 20x^6 + 26x^5 - 5x^4 + 44x^3 - 5x^2 + 11x + 63
            >>> print(poly1 * num)
            3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after multiplying

        -> division of polynomials and numeric dtypes
            >>> print(poly1 / poly2)
            (3x^3 - 5x^2 + 2x + 7) / (4x^4 + 6x^2 - x + 9)
            >>> print(poly1 / num)
            3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after division

# USING IN-PLACE OPERATOR
    -> consider the following two polynomials and one integer throughout the section
    -> polynomials are all redefined after every operation to keep the initial value unchanged throughout the operations
        >>> poly1: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
        >>> poly2: Polynomial = Polynomial("4x^4 6x^2 -1x 9")
        >>> num: int = 7

        -> addition of polynomials and numeric dtypes
            >>> poly1 += poly2
            >>> print(poly1)
            4x^4 + 3x^3 + x^2 + x + 16
            >>> poly1 += num
            >>> print(poly1)
            x^3 - 5x^2 + 2x + 14

        -> subtraction of polynomials and numeric dtypes
            >>> poly1 -= poly2
            >>> print(poly1)
            -4x^4 + 3x^3 - 11x^2 + 3x - 2
            >>> poly1 -= num
            >>> print(poly1)
            x^3 - 5x^2 + 2x - 0

        -> multiplication of polynomials and numeric dtypes
            >>> poly1 *= poly2
            >>> print(poly1)
            12x^7 - 20x^6 + 26x^5 - 5x^4 + 44x^3 - 5x^2 + 11x + 63
            >>> poly1 *= num
            >>> print(poly1)
            3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after multiplying

        -> division of polynomials and numeric dtypes
            >>> poly1 /= poly2
            >>> print(poly1)
            (3x^3 - 5x^2 + 2x + 7) / (4x^4 + 6x^2 - x + 9)
            >>> poly1 /= num
            >>> print(poly1)
            V3x^3 - 5x^2 + 2x + 7                            # simplifies the polynomial after division

# OTHER BUILT-IN OPERATORS
    -> checking equality between polynomials
        >>> poly1 == poly2
        False

    -> checking the truth value of a polynomial
        >>> poly: Polynomial = Polynomial()
        >>> bool(poly)
        False
        >>> bool(poly1)
        True

# SUBSTITUTE THE VALUE OF A VALUE INTO THE POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> poly.substitute('x', 5)
    Polynomial(numerator=[Variable(coefficient=267, variables={})], denominator=[Variable(coefficient=1, variables={})]

# CREATING A COPY OF THE POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> print(poly.copy())
    3x^3 - 5x^2 + 2x + 7

# FINDING THE ROOTS OF A POLYNOMIAL
    >>> poly: Polynomial = Polynomial("3x^3 -5x^2 2x 7")
    >>> poly.roots()
    (-0.841, (1.254+1.097j), (1.254-1.097j))

# CONVERTING A QUADRATIC POLYNOMIAL TO ITS RESPECTIVE PRINCIPAL AXES FORM
    >>> poly: Polynomial = Polynomial("-11x1^2 84x1^1x2^1 24x2^2 -156")
    >>> poly.to_principal_axes()
    {'x1': [Polynomial(numerator=[Variable(coefficient=601000, variables={'y1': Fraction(1, 1)}), Variable(coefficient=-901500, variables={'y2': Fraction(1, 1)})], denominator=[Variable(coefficient=1083603, variables={})]], 'x2': [Polynomial(numerator=[Variable(coefficient=901500, variables={'y1': Fraction(1, 1)}), Variable(coefficient=601000, variables={'y2': Fraction(1, 1)})], denominator=[Variable(coefficient=1083603, variables={})]], 'conic_section': 'Hyperbola'}
    """

    def __init__(self, numerator: Any = "0", denominator: str = "1", *,
                 numerator_variables: list[Variable] | None = None, denominator_variables: list[Variable] | None = None,
                 always_evaluate: bool = True, datatype: type = Fraction) -> None:
        """Polynomial object initializer function"""
        self._parameters: dict[str, bool | type] = {"always_evaluate": always_evaluate, "datatype": datatype}

        if isinstance(numerator, Polynomial):
            self._numerator: list[Variable] = numerator.numerator.copy()
            self._denominator: list[Variable] = numerator.denominator.copy()

        else:
            self._numerator = numerator_variables if numerator_variables \
                else [Variable(element, **self._parameters) for element in numerator.split()]
            self._denominator = denominator_variables if denominator_variables \
                else [Variable(element, **self._parameters) for element in denominator.split()]


        self._pre_simplify()

    @property
    def numerator(self) -> list[Variable]:
        return self._numerator

    @property
    def denominator(self) -> list[Variable]:
        return self._denominator

    def __str__(self) -> str:
        """Built-in str() overloaded function"""
        # self._post_simplify()
        res: list[str] = []

        for term in (self.numerator, self.denominator):
            current: str = ""
            begin: bool = True

            for element in term:
                if begin:
                    begin = False
                    current += str(element)

                elif element.coefficient > 0:
                    current += " + "
                    current += str(element)

                else:
                    current += " - "
                    current += str(abs(element))

            res.append('0' if not current else current)

        if res[1] == '1':
            return f"{res[0]}"

        else:
            return f"({res[0]}) / ({res[1]})"

    def __repr__(self) -> str:
        return f"Polynomial(numerator={self.numerator}, denominator={self.denominator})"

    def __add__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator+ overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator = self.numerator + [var * other for var in self.denominator]
            denominator = self.denominator

        else:
            try:
                num, den = float(other).as_integer_ratio()
                num: MathNum = MathNum(num, datatype=self._parameters["datatype"])
                den: MathNum = MathNum(den, datatype=self._parameters["datatype"])
                numerator = ([var * den for var in self.numerator] + [var * num for var in self.denominator])
                denominator = [var * den for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator, **self._parameters)

    def __sub__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator- overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [var1 * var2 for var1 in self.numerator for var2 in other.denominator] + \
                                        [-var1 * var2 for var1 in other.numerator for var2 in self.denominator]
            denominator: list[Variable] = [var1 * var2 for var1 in self.denominator for var2 in other.denominator]

        elif isinstance(other, Variable):
            numerator = self.numerator + [var * -other for var in self.denominator]
            denominator = self.denominator

        else:
            try:
                num, den = float(other).as_integer_ratio()
                num: MathNum = MathNum(num, datatype=self._parameters["datatype"])
                den: MathNum = MathNum(den, datatype=self._parameters["datatype"])
                numerator = [var * den for var in self.numerator] + [var * -num for var in self.denominator]
                denominator = [var * den for var in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator, **self._parameters)

    def __mul__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator* overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [element1 * element2 for element1 in self.numerator for element2 in
                                         other.numerator]
            denominator: list[Variable] = [element1 * element2 for element1 in self.denominator for element2 in
                                           other.denominator]

        elif isinstance(other, Variable):
            numerator = [element * other for element in self.numerator]
            denominator = self.denominator

        else:
            try:
                num, den = float(other).as_integer_ratio()
                num: MathNum = MathNum(num, datatype=self._parameters["datatype"])
                den: MathNum = MathNum(den, datatype=self._parameters["datatype"])
                numerator = [element * num for element in self.numerator]
                denominator = [element * den for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator, **self._parameters)

    def __truediv__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator/ overloaded function"""
        if isinstance(other, Polynomial):
            numerator: list[Variable] = [element1 * element2 for element1 in self.numerator for element2 in
                                         other.denominator]
            denominator: list[Variable] = [element1 * element2 for element1 in self.denominator for element2 in
                                           other.numerator]

        elif isinstance(other, Variable):
            numerator = self.numerator
            denominator = [element * other for element in self.denominator]

        else:
            try:
                num, den = float(other).as_integer_ratio()
                num: MathNum = MathNum(num, datatype=self._parameters["datatype"])
                den: MathNum = MathNum(den, datatype=self._parameters["datatype"])
                numerator = [element * den for element in self.numerator]
                denominator = [element * num for element in self.denominator]

            except ValueError:
                return NotImplemented

        return Polynomial(numerator_variables=numerator, denominator_variables=denominator, **self._parameters)

    def __iadd__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator+= overloaded function"""
        result: Polynomial = self.__add__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __isub__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator-= overloaded function"""
        result: Polynomial = self.__sub__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __imul__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator*= overloaded function"""
        result: Polynomial = self.__mul__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __itruediv__(self, other: "Polynomial | Any") -> "Polynomial":
        """Operator/= overloaded function"""
        result: Polynomial = self.__truediv__(other)
        self._numerator = result.numerator
        self._denominator = result.denominator
        return self

    def __eq__(self, other: "Polynomial | Variable | Any") -> bool:
        """Operator== overloaded function"""
        if isinstance(other, Polynomial):
            return self.numerator == other.numerator and self.denominator == other.denominator

        elif isinstance(other, Variable):
            return self == Polynomial(numerator_variables=[other], **self._parameters)

        else:
            try:
                return self == Polynomial(numerator_variables=[
                    Variable(coefficient=MathNum(other, datatype=self._parameters["datatype"]), variables_dict={})],
                    **self._parameters)

            except ValueError:
                return NotImplemented

    __radd__ = lambda self, other: self.__add__(other)
    __rsub__ = lambda self, other: (-self).__add__(other)
    __rmul__ = lambda self, other: self.__mul__(other)
    __rtruediv__ = lambda self, other: Polynomial(numerator_variables=self.denominator,
                                                  denominator_variables=self.numerator, **self._parameters) * other
    __neg__ = lambda self: self * -1
    __pos__ = lambda self: self
    __bool__ = lambda self: self.numerator[0].coefficient != 0

    @DeprecationWarning
    def _post_simplify(self) -> None:
        """Simplifies the polynomial object after performing some mathematical operations"""
        try:
            factor: list[str | MathNum] | None = list(tuple(self.numerator[0].variables.items())[0])

        except IndexError:
            factor = None

        if len(self.denominator) == 1 and not self.denominator[0].variables and self.denominator[0].coefficient < 0:
            self.denominator[0] = abs(self.denominator[0])
            self._numerator = [var * -1 for var in self.numerator]

        if len(self.numerator) == 1:
            return

        try:
            coef: MathNum = self.numerator[0].coefficient

        except IndexError:
            coef = MathNum(1, datatype=self._parameters["datatype"])

        for element in self.numerator[1:]:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(MathNum(factor[1], datatype=self._parameters["datatype"]),
                                element.variables[str(factor[0])])

            else:
                factor = None

            frac1: Fraction = Fraction(coef.value[0])
            frac2: Fraction = Fraction(element.coefficient.value[0])
            coef = MathNum(Fraction(gcd(frac1.numerator, frac2.numerator), lcm(frac1.denominator, frac2.denominator)))

        if coef != MathNum(1, datatype=self._parameters["datatype"]):
            for i in range(len(self.numerator)):
                self.numerator[i] /= coef

        for element in self.denominator:
            if factor is not None and factor[0] in element.variables:
                factor[1] = min(MathNum(factor[1], datatype=self._parameters["datatype"]),
                                element.variables[str(factor[0])])

            else:
                factor = None

            frac1: Fraction = Fraction(coef.value[0])
            frac2: Fraction = Fraction(element.coefficient.value[0])
            coef = MathNum(Fraction(gcd(frac1.numerator, frac2.numerator), lcm(frac1.denominator, frac2.denominator)))

        if coef != MathNum(1, datatype=self._parameters["datatype"]):
            for i in range(len(self.denominator)):
                self.denominator[i] /= coef

        if factor:
            for term in (self.numerator, self.denominator):
                for element in term:
                    element.variables[str(factor[0])] -= MathNum(factor[1], datatype=self._parameters["datatype"])

    def _pre_simplify(self) -> None:
        """Simplifies the polynomial object after initializing a new polynomial instance"""
        factor: Variable | None = None
        check: str | None = None
        main_var: Variable | None = None
        broke: bool = False

        for idx, variable in enumerate(self.numerator):
            if variable.coefficient == 0:
                self.numerator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    variable.variables.pop(var)
                    broke = True
                    break

                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor = Variable(coefficient=MathNum(1, datatype=self._parameters["datatype"]),
                                      variables_dict={var: variable.variables[var]})
                    self.numerator.pop(idx)
                    check = var
                    main_var = variable
                    broke = True
                    break

            if broke and factor is None:
                self._pre_simplify()
                return

        if factor is not None and main_var is not None:
            self._numerator = [factor * element for element in self.numerator]
            self._denominator = [factor * element for element in self.denominator]
            self.numerator.append(Variable(coefficient=main_var.coefficient,
                                           variables_dict={key: value for key, value in main_var.variables.items()
                                                           if key != check}))
            self._pre_simplify()
            return

        factor = None
        check = None
        main_var = None
        broke = False

        for idx, variable in enumerate(self.denominator):
            if variable.coefficient == 0:
                self.denominator.pop(idx)
                continue

            for var, exp in variable.variables.items():
                if exp == 0:
                    variable.variables.pop(var)
                    broke = True
                    break

                elif exp < 0:
                    variable.variables[var] = abs(variable.variables[var])
                    factor = Variable(coefficient=MathNum(1, datatype=self._parameters["datatype"]), variables_dict={var: variable.variables[var]})
                    self.denominator.pop(idx)
                    check = var
                    main_var = variable
                    broke = True
                    break

            if broke and factor is None:
                self._pre_simplify()
                return

        if len(self.denominator) == 1 and self.denominator[0].coefficient == 0:
            raise ZeroDivisionError

        if main_var is not None and factor is not None:
            self._numerator = [factor * element for element in self.numerator]
            self._denominator = [factor * element for element in self.denominator]
            self.denominator.append(Variable(coefficient=main_var.coefficient,
                                             variables_dict={key: value for key, value in main_var.variables.items()
                                                             if key != check}))
            self._pre_simplify()

        self.numerator.sort(key=lambda value: tuple(value.variables.keys()))
        self.numerator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)
        self.denominator.sort(key=lambda value: tuple(value.variables.keys()))
        self.denominator.sort(key=lambda value: tuple(value.variables.values()), reverse=True)
        change = False

        while not change:
            res: list[Variable] = []
            size: int = len(self.numerator)
            i: int = 0

            while i < size:
                temp: Variable | None = None

                try:
                    if temp:
                        temp += self.numerator[i] + self.numerator[i + 1]
                    else:
                        temp = self.numerator[i] + self.numerator[i + 1]
                        change = True
                        i += 1

                except (TypeError, IndexError):
                    pass

                res.append(temp) if temp is not None else res.append(self.numerator[i])
                i += 1

            if change:
                self._numerator = res
                change = False

            else:
                change = True

        change = False

        while not change:
            res = []
            size = len(self.denominator)
            i = 0

            while i < size:
                temp = None

                try:
                    if temp:
                        temp += self.denominator[i] + self.denominator[i + 1]
                    else:
                        temp = self.denominator[i] + self.denominator[i + 1]
                        change = True
                        i += 1

                except (TypeError, IndexError):
                    pass

                res.append(temp) if temp else res.append(self.denominator[i])
                i += 1

            if change:
                self._denominator = res
                change = False

            else:
                change = True

    # @staticmethod
    # def _conic_section(eigen_values: dict[str, Fraction | float], determinant: Fraction) -> str:
    #     """Determines which type of conic section does the eigen vector represents"""
    #     are_positive: list[bool | None] = []
    #     is_zero_determinant: bool = True if determinant == Fraction(0) else False
    #
    #     for value in eigen_values.values():
    #         if value == Fraction(0):
    #             are_positive.append(None)
    #
    #         elif value > Fraction(0):
    #             are_positive.append(True)
    #
    #         else:
    #             are_positive.append(False)
    #
    #     if are_positive[0] is not None and are_positive[1] is not None:
    #         if are_positive[0] == are_positive[1] and not is_zero_determinant:
    #             return "Ellipse"
    #
    #         elif are_positive[0] != are_positive[1] and not is_zero_determinant:
    #             return "Hyperbola"
    #
    #         elif are_positive[0] == are_positive[1] and is_zero_determinant:
    #             return "Point"
    #
    #         elif are_positive[0] != are_positive[1] and is_zero_determinant:
    #             return "Intersecting Lines"
    #
    #     else:
    #         if (are_positive[0] is None or are_positive[1] is None) and is_zero_determinant:
    #             return "Parabola"
    #
    #     return "Unexpected Error"

    def roots(self) -> tuple[MathNum, ...]:
        """Computes the roots of the polynomial"""

        def quadratic_roots(b: MathNum, c: MathNum) -> tuple[MathNum, MathNum]:
            """Computes the quadratic roots of a second degree polynomial"""
            determinant: MathNum = b ** 2 - (4 * c)

            if determinant >= 0:
                root1: MathNum = (-b + determinant.sqrt()) / 2

                if determinant != 0:
                    root2: MathNum = (-b - determinant.sqrt()) / 2

                else:
                    root2 = root1

                return root1, root2

            else:
                return (MathNum((-b + determinant.sqrt()) / 2, domain="complex"),
                        MathNum((-b - determinant.sqrt()) / 2, domain="complex"))

        def cubic_roots(b: MathNum, c: MathNum, d: MathNum) -> tuple[MathNum, MathNum, MathNum]:
            """Computes the cubic roots of a 3rd degree polynomial"""
            q: MathNum = (c / 3) - (b ** 2 / 9)
            r: MathNum = ((c * b - 3 * d) / 6) - (b ** 3 / 27)
            check: MathNum = r ** 2 + q ** 3

            if check > 0:
                a: MathNum = MathNum((abs(r) + sqrtc(check)) ** (1 / 3), datatype=complex)

                if r >= 0:
                    t1: MathNum = a - (q / a)

                else:
                    t1 = (q / a) - a

                x2: MathNum = -t1 / 2 - b / 3
                y2: complex = complex(*(MathNum(3).sqrt() / 2 * (a + (q / a))).evaluate().value)
                res: tuple[MathNum, MathNum, MathNum] = (t1 - b / 3, MathNum((x2, y2.real), datatype=complex),
                                                         MathNum((x2, -y2.real), datatype=complex))
                return res
                # return tuple(round(element.real, 3) if element.imag == 0
                #              else complex(round(element.real, 3), round(element.imag, 3)) for element in res)

            else:
                theta: MathNum = MathNum() if q == 0 else (r / (-q) ** (3 / 2)).acos()
                phis: Generator[MathNum] = ((theta + (j * MathNum.pi)) / 3 for j in range(0, 5, 2))
                return tuple(phis)
                # return tuple(round(2 * sqrtf(-q) * cos(phi) - b / 3, 3) for phi in phis)

        var: tuple[str, MathNum] = tuple(self.numerator[0].variables.items())[0]
        factor: MathNum = self.numerator[0].coefficient
        constant: MathNum = self.numerator[-1].coefficient if self.numerator[-1].variables == {} else MathNum(0)
        coef: dict[int, MathNum] = {}

        for i in range(len(self.numerator)):
            if self.numerator[i].variables and (
                    len(self.numerator[i].variables) != 1 or var[0] not in self.numerator[i].variables):
                raise ValueError("roots of the this Equation cannot be determined")

            if self.numerator[i].variables:
                coef[int(self.numerator[i].variables[var[0]])] = self.numerator[i].coefficient / factor

        if var[1] == 2:
            return quadratic_roots(coef.get(1, 0), constant / factor)

        elif var[1] == 3:
            return cubic_roots(coef.get(2, 0), coef.get(1, 0), constant / factor)

        else:
            return NotImplemented

    # def to_principal_axes(self) -> dict[str, "Polynomial | str"]:
    #     """Converts a quadratic polynomial to its principal axes using matrix algebra"""
    #     from linear_algebra import Matrix
    #
    #     if tuple(self.numerator[0].variables.values())[0] > Fraction(2):
    #         raise PolynomialError("Quadratic polynomials can be transformed into its corresponding principal axes")
    #
    #     res: Matrix = Matrix(2, 2, "null")
    #
    #     for var in self.numerator:
    #         if var.variables:
    #             power: Fraction = tuple(var.variables.values())[0]
    #         else:
    #             power = Fraction(0)
    #
    #         if power == Fraction(2):
    #             position: int = int(tuple(var.variables.keys())[0][1]) - 1
    #             res[position][position] = var.coefficient
    #
    #         elif power == Fraction(1):
    #             pos1: int = int(tuple(var.variables.keys())[0][1]) - 1
    #             pos2: int = int(tuple(var.variables.keys())[1][1]) - 1
    #             res[pos1][pos2] = var.coefficient / 2
    #             res[pos2][pos1] = var.coefficient / 2
    #
    #     eigen_val: dict[str, Fraction | float] = res.eigen_values()
    #     numerator: list[Variable] = [Variable(coefficient=Fraction(value), variables_dict={f"y{idx + 1}": Fraction(2)})
    #                                  for idx, value in enumerate(eigen_val.values())]
    #     numerator.append(self.numerator[-1])
    #     q = Polynomial(numerator_variables=numerator)
    #     conic_sec: str = self._conic_section(eigen_val, q.numerator[-1].coefficient)
    #     eigen_vec: tuple[tuple[Fraction, ...], ...] = res.eigen_vectors()
    #     eigen_vec = tuple(Matrix.normalize(vec) for vec in eigen_vec)
    #     x: Matrix = Matrix(2, 2, matrix=[list(vec) for vec in eigen_vec]).transpose()
    #     y: Matrix = Matrix(2, 1, matrix=[[Polynomial("y1")], [Polynomial("y2")]])
    #     res = x * y
    #     return {"x1": res[0], "x2": res[1], "conic_section": conic_sec}

    copy = lambda self: Polynomial(numerator_variables=self.numerator, denominator_variables=self.denominator,
                                   **self._parameters)
    substitute = lambda self, variable, value: (
        Polynomial(numerator_variables=[var.substitute(variable, value) for var in self.numerator],
                   denominator_variables=[var.substitute(variable, value) for var in self.denominator],
                   **self._parameters))
