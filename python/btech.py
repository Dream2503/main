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
    "Basic Electronics Engineering": (90, 3),
    "Data Structures & Algorithms": (94, 3),
    "Engineering Chemistry": (95, 3),
    "Engineering Thermodynamics": (90, 2),
    "Environmental Science & Engineering": (60, 0),
    "Probability & Statistics": (96, 3),

    "Basic Electronics Engineering Lab": (91, 1),
    "Corporate Communication Skills": (91, 2),
    "Data Structures & Algorithms Lab": (97, 2),
    "Engineering Graphics": (91, 1),
}
semester3: dict[str, tuple[int, int]] = {
    "Design & Analysis of Algorithms": (30 + 0 + 0, 4),
    "Digital Electronics": (48 + 0, 3),
    "Discrete Mathematics": (50 + 0, 3),
    "Management & Economics for Engineers": (50 + 0, 3),
    "OOP Using Java": (29 + 0 + 0, 3),
    "Operating Systems": (55 + 0, 3),

    "Design & Analysis of Algorithms Lab": (0, 1),
    "Digital Electronics Lab": (97, 1),
    "OOP Using Java Lab": (0, 1),
    "Operating Systems Lab": (0, 1),
    "Python Programming, Machine Learning, and Deep Learning for Industry [Summer Internship - I]": (0, 1),
}
semester4: dict[str, tuple[int, int]] = {
    "Artificial Intelligence": (100, 3),
    "Biology for Engineers": (100, 3),
    "Computer Organization & Architecture": (100, 3),
    "Database Management Systems": (100, 4),
    "Optimization Techniques": (100, 3),
    "Programming in Python": (100, 3),
    "Statistical Inference": (100, 3),

    "Computer Organization & Architecture Lab": (100, 1),
    "Database Management Systems Lab": (100, 2),
    "Internet & Web Technology Lab": (100, 2),
    "Programming in Python Lab": (100, 1),
}
semester5: dict[str, tuple[int, int]] = {
    "Computer Networks": (100, 3),
    "Machine Learning": (100, 4),
    "Software Engineering": (100, 3),
    "Formal Languages & Automata Theory": (100, 3),
    "**Program Elective - II**": (100, 3),
    "**Program Elective - III**": (100, 3),
    "**Honours / Minor - II**": (100, 3),

    "Computer Networks Lab": (100, 1),
    "Machine Learning Lab": (100, 1),
    "Software Engineering Lab": (100, 1),
    "Soft Skills & Inter-Personal Skills": (100, 1),
    "**Summer Internship - II**": (100, 1),
}
semester6: dict[str, tuple[int, int]] = {
    "Internet of Things": (100, 3),
    "Soft Computing": (100, 3),
    "Compiler Design": (100, 3),
    "**Program Elective - IV**": (100, 3),
    "**Program Elective - V**": (100, 3),
    "**Program Elective - VI**": (100, 3),
    "**Honours / Minor - III**": (100, 4),

    "Internet of Things Lab": (100, 3),
    "Soft Computing Lab": (100, 3),
    "Emerging Technologies Lab / Entrepreneurship & Innovation": (100, 2),
    "Professional & Technical Writing": (100, 1),
    "**Yoga / NSS / NCC / PES / CPA**": (100, 0)
}
semester7: dict[str, tuple[int, int]] = {
    "**Open Elective - I**": (100, 3),
    "**MOOC - I**": (100, 3),
    "**Honours / Minor - IV**": (100, 4),
    "**Honours / Minor - V**": (100, 4),

    "**Skill Lab & Project - I**": (100, 2),
    "**Summer Internship - III**": (100, 1),
}
semester8: dict[str, tuple[int, int]] = {
    "**Open Elective - II**": (100, 3),
    "**MOOC - II**": (100, 3),

    "Presentation Skills & Technical Seminar": (100, 1),
    "**Project - II**": (100, 8),
}


def calculate_cgpa(*semesters: dict[str, tuple[int, int]]) -> float:
    total_credits: int = 0
    total_marks: int = 0

    for semester in semesters:
        for mark, credit in semester.values():
            total_marks += (10 if (mark // 10 + 1) > 10 else (mark // 10 + 1)) * credit
            total_credits += credit

    return round(total_marks / total_credits, 2)


def total_score(*semesters: dict[str, tuple[int, int]], zero_credit: bool = True) -> tuple[int, int, float]:
    total: int = 0
    res: int = 0

    for semester in semesters:
        for mark, credit in semester.values():
            if mark and (credit or zero_credit):
                res += mark
                total += 100

    return res, total, round(res / total * 100, 2)


def main() -> None:
    semesters = (semester1, semester2, semester3)

    for i, sem in enumerate(semesters):
        print(f"Semester {i + 1}:")
        print("Total marks scored {0} out of {1} -> {2}%".format(*total_score(sem, zero_credit=False)))

        if i in (0, 1):
            print("Total marks scored {0} out of {1} -> {2}% (including zero credit subject)".format(*total_score(sem, zero_credit=True)))

        print("Total SGPA:", calculate_cgpa(sem))
        print("=" * 80)

    print("Total marks scored {0} out of {1} -> {2}%".format(*total_score(*semesters, zero_credit=False)))
    print("Total marks scored {0} out of {1} -> {2}% (including zero credit subject)".format(*total_score(*semesters, zero_credit=True)))
    print("Total CGPA:", calculate_cgpa(*semesters))


if __name__ == "__main__":
    main()
