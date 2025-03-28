def calculate_sgpa(semester: dict[str, tuple[int, int]]) -> float:
    total_credits: int = 0
    total_marks: int = 0

    for mark, credit in semester.values():
        total_marks += (10 if (mark // 10 + 1) > 10 else (mark // 10 + 1)) * credit
        total_credits += credit

    return total_marks / total_credits


def calculate_cgpa(*semesters: dict[str, tuple[int, int]]) -> float:
    total_sgpa: float = 0
    total_sem: int = 0

    for semester in semesters:
        total_sgpa += calculate_sgpa(semester)
        total_sem += 1

    return total_sgpa / total_sem


def total_score(*semesters: dict[str, tuple[int, int]], zero_credit: bool = True) -> tuple[float, int, float]:
    res: float = 0.0
    total: int = 0

    for semester in semesters:
        for mark, credit in semester.values():
            if mark:
                res += mark
                total += 100

                if not (credit or zero_credit):
                    res -= mark
                    total -= 100

    return res, total, round(res / total * 100, 2)


semester1: dict[str, tuple[int, int]] = {
    "Basic Electrical Engineering": (93, 3),
    "Computer Programming": (99, 3),
    "Constitution of India & Professional Ethics": (73, 0),
    "Engineering Mechanics": (95, 2),
    "Engineering Physics": (94, 3),
    "ODE & Matrix Algebra": (92, 3),
    "Basic Electrical Engineering Lab": (94, 1),
    "Communicative & Technical English": (91, 2),
    "Computer Programming Lab": (98, 2),
    "Workshop Practice": (90, 1),
}
semester2: dict[str, tuple[int, int]] = {
    "Basic Electronics Engineering": (0, 3),
    "Data Structures & Algorithms": (0, 3),
    "Engineering Chemistry": (0, 3),
    "Engineering Thermodynamics": (0, 2),
    "Environmental Science & Engineering": (0, 0),
    "Probability & Statistics": (0, 3),
    "Basic Electronics Engineering Lab": (0, 1),
    "Corporate Communication Skills": (0, 2),
    "Data Structures & Algorithms Lab": (0, 2),
    "Engineering Graphics": (0, 1),
}


def main() -> None:
    marks, total, percentage = total_score(semester1, semester2, zero_credit=False)
    print("Total marks scored {0} out of {1} -> {2}%".format(marks, total, percentage))
    print("Total CGPA:", calculate_cgpa(semester1, semester2))
    # print("\nSGPA for 1st Semester:", calculate_sgpa(semester1))
    # print("SGPA for 1st Semester:", calculate_sgpa(semester2))


if __name__ == "__main__":
    main()
