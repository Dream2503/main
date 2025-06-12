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
    "Basic Electronics Engineering": (46, 3),
    "Data Structures & Algorithms": (48.5, 3),
    "Engineering Chemistry": (48, 3),
    "Engineering Thermodynamics": (46, 2),
    "Environmental Science & Engineering": (26, 0),
    "Probability & Statistics": (50, 3),

    "Basic Electronics Engineering Lab": (91, 1),
    "Corporate Communication Skills": (91, 2),
    "Data Structures & Algorithms Lab": (97, 2),
    "Engineering Graphics": (91, 1),
}
semester3: dict[str, tuple[int, int]] = {
    "Design & Analysis of Algorithms": (100, 4),
    "Digital Electronics": (100, 3),
    "Discrete Mathematics": (100, 3),
    "**Management & Economics for Engineers**": (100, 3),
    "OOP Using Java": (100, 3),
    "Operating Systems": (100, 3),

    "Design & Analysis of Algorithms Lab": (100, 1),
    "Digital Electronics Lab": (100, 1),
    "OOP Using Java Lab": (100, 1),
    "Operating Systems Lab": (100, 1),
    "**Summer Internship - I**": (100, 1)
}
semester4: dict[str, tuple[int, int]] = {
    "**Biology for Engineers**": (100, 3),
    "Computer Organization & Architecture": (100, 3),
    "Database Management Systems": (100, 4),
    "Optimization Techniques": (100, 3),
    "Programming in Python": (100, 3),
    "**Program Elective - I**": (100, 3),
    "**Honours / Minor - I**": (100, 3),

    "Computer Organization & Architecture Lab": (100, 1),
    "Database Management Systems Lab": (100, 2),
    "Internet & Web Technology Lab": (100, 2),
    "Programming in Python Lab": (100, 1),
}
semester5: dict[str, tuple[int, int]] = {}
semester6: dict[str, tuple[int, int]] = {}
semester7: dict[str, tuple[int, int]] = {}
semester8: dict[str, tuple[int, int]] = {}


def calculate_cgpa(*semesters: dict[str, tuple[int, int]]) -> float:
    total_credits: int = 0
    total_marks: int = 0

    for semester in semesters:
        for mark, credit in semester.values():
            total_marks += (10 if (mark // 10 + 1) > 10 else (mark // 10 + 1)) * credit
            total_credits += credit

    return total_marks / total_credits


def total_score(*semesters: dict[str, tuple[int, int]], zero_credit: bool = True) -> tuple[float, int, float]:
    res: float = 0.0
    total: int = 0

    for semester in semesters:
        for mark, credit in semester.values():
            if mark and (credit or zero_credit):
                res += mark
                total += 100

    return res, total, round(res / total * 100, 2)


def main() -> None:
    print("Total marks scored {0} out of {1} -> {2}%".format(*total_score(semester1, semester2, zero_credit=False)))
    print("Total CGPA:", calculate_cgpa(semester1, semester2))


if __name__ == "__main__":
    main()
