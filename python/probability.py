def factorial(n: int = 0) -> int:
    if n < 1:
        return 1

    res: int = 1

    for i in range(2, n + 1):
        res *= i

    return res


def combination(n: int = 0, r: int = 0) -> float:
    return factorial(n) / (factorial(n - r) * factorial(r))


def permutation(n: int = 0, r: int = 0) -> float:
    return factorial(n) / factorial(n - r)


def binomial_distribution(x: int, n: int, p: float) -> float:
    return combination(n, x) * (p ** x) * ((1 - p) ** (n - x))


def cumulative_binomial_distribution(x: int, n: int, p: float) -> float:
    res: float = 0

    for i in range(0, x + 1):
        res += binomial_distribution(i, n, p)

    return res


def hypergeometric_distribution(x: int, n: int, a: int, N: int) -> float:
    return combination(a, x) * combination(N - a, n - x) / combination(N, n)


def cumulative_hypergeometric_distribution(x: int, n: int, a: int, N: int) -> float:
    res: float = 0

    for i in range(0, x + 1):
        res += hypergeometric_distribution(i, n, a, N)

    return res


def mean(*x_fx_pair: tuple[int, float]) -> float:
    res: float = 0

    for x, fx in x_fx_pair:
        res += x * fx

    return res


def mean_binomial_distribution(n: int, p: float) -> float:
    return n * p


def mean_hypergeometric_distribution(n: int, a: int, N: int):
    return n * a / N


def variance(*x_fx_pair: tuple[int, float]) -> float:
    m: float = mean(*x_fx_pair)
    res: float = 0

    for x, fx in x_fx_pair:
        res += ((x - m) ** 2) * fx

    return res


def variance_binomial_distribution(n: int, p: float) -> float:
    return n * p * (1 - p)


def variance_hypergeometric_distribution(n: int, a: int, N: int) -> float:
    return (n * a * (N - n) * (N - a)) / ((N ** 2) * (N - 1))


def standard_deviation(*x_fx_pair: tuple[int, float]) -> float:
    from math import sqrt
    return sqrt(variance(*x_fx_pair))


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


def main() -> None:
    res: float = mean((0, 1 / 8), (1, 3 / 8), (2, 3 / 8), (3, 1 / 8))
    print(res)


if __name__ == "__main__":
    main()
