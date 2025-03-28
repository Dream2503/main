from math import factorial, comb as combination, perm as permutation

def approximate(func):
    def wrapper(*args, **kwargs):
        return round(func(*args, **kwargs), 6)

    return wrapper

@approximate
def binomial_distribution(x: int, n: int, p: float) -> float:
    return combination(n, x) * (p ** x) * ((1 - p) ** (n - x))


@approximate
def cumulative_binomial_distribution(x: int, n: int, p: float) -> float:
    res: float = 0

    for i in range(0, x + 1):
        res += binomial_distribution(i, n, p)

    return res


@approximate
def hypergeometric_distribution(x: int, n: int, a: int, N: int) -> float:
    return combination(a, x) * combination(N - a, n - x) / combination(N, n)


@approximate
def cumulative_hypergeometric_distribution(x: int, n: int, a: int, N: int) -> float:
    res: float = 0

    for i in range(0, x + 1):
        res += hypergeometric_distribution(i, n, a, N)

    return res


@approximate
def mean(*x_fx_pair: tuple[int, float]) -> float:
    res: float = 0

    for x, fx in x_fx_pair:
        res += x * fx

    return res


@approximate
def mean_binomial_distribution(n: int, p: float) -> float:
    return n * p


@approximate
def mean_hypergeometric_distribution(n: int, a: int, N: int):
    return n * a / N


@approximate
def variance(*x_fx_pair: tuple[int, float]) -> float:
    m: float = mean(*x_fx_pair)
    res: float = 0

    for x, fx in x_fx_pair:
        res += ((x - m) ** 2) * fx

    return res


@approximate
def variance_binomial_distribution(n: int, p: float) -> float:
    return n * p * (1 - p)


@approximate
def variance_hypergeometric_distribution(n: int, a: int, N: int) -> float:
    return (n * a * (N - n) * (N - a)) / ((N ** 2) * (N - 1))


@approximate
def standard_deviation(*x_fx_pair: tuple[int, float]) -> float:
    from math import sqrt
    return sqrt(variance(*x_fx_pair))


@approximate
def poisson_distribution(x: int, Y: float) -> float:
    from math import e
    return ((e ** -Y) * (Y ** x)) / factorial(x)


@approximate
def cumulative_poisson_distribution(x: int, Y: float) -> float:
    res: float = 0

    for i in range(x + 1):
        res += poisson_distribution(i, Y)

    return res


fact = factorial
C = combination
P = permutation
b = binomial_distribution
B = cumulative_binomial_distribution
h = hypergeometric_distribution
H = cumulative_hypergeometric_distribution
mu = mean
sigma_squared = variance
sigma = standard_deviation
f = poisson_distribution
F = cumulative_poisson_distribution


def main() -> None:
    res: float = mean((0, 1 / 8), (1, 3 / 8), (2, 3 / 8), (3, 1 / 8))
    print(res)


if __name__ == "__main__":
    main()
