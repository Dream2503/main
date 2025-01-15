def calculate_sgpa(semester: dict[str, tuple[int, int]]) -> float:
    total_credits: int = 0
    total_points: int = 0

    for subject, (mark, credit) in semester.items():
        total_points += (mark // 10 + 1) * credit
        total_credits += credit

    return total_points / total_credits


def calculate_cgpa(*semesters: dict[str, tuple[int, int]]) -> float:
    total_credits: int = 0
    total_points: int = 0

    for semester in semesters:
        for subject, (mark, credit) in semester.items():
            total_points += (mark // 10 + 1) * credit
            total_credits += credit

    return total_points / total_credits


semester1: dict[str, tuple[int, int]] = {
    "Basic Electrical Engineering": (0, 0),
    "Computer Programming": (0, 0),
    "Constitution of India & Professional Ethics": (0, 0),
    "Engineering Mechanics": (0, 0),
    "Engineering Physics": (0, 0),
    "ODE & Matrix Algebra": (0, 0),
    "Basic Electrical Engineering Lab": (94, 1),
    "Communicative & Technical English": (0, 0),
    "Computer Programming Lab": (98, 2),
    "Workshop Practice": (0, 0),
}


def main() -> None:
    print("SGPA for Semester 1:", calculate_sgpa(semester1))
    print("Total CGPA:", calculate_cgpa(semester1))


if __name__ == "__main__":
    main()
