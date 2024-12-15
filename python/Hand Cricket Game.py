from random import choice
from collections import namedtuple

PLAYABLES = namedtuple("Playables", ["bat", "bowl"])("bat", "bowl")
CHOOSABLES = namedtuple("Choosables", ["odd", "even"])("odd", "even")
SCOREABLES: tuple[int] = (1, 2, 3, 4, 5, 6)


def toss() -> dict[str, str]:
    toss_won: bool = False

    while True:
        user_choice: str = input("Choose odd/even: ").lower()
        print()

        if user_choice in CHOOSABLES:
            break

        else:
            print("Choose 'even' or 'odd' only!")

    while True:
        try:
            user_toss: int = int(input("Enter toss (1-6): "))

            if user_toss in SCOREABLES:
                break

            else:
                print("Enter number from 1 to 6 only!")

        except ValueError:
            print("Enter number from 1 to 6 only!")

    comp_toss: int = choice(SCOREABLES)
    print(f"Computer choose {comp_toss}")
    user_des = comp_des = ""

    if ((user_toss + comp_toss) % 2 == 0 and user_choice == CHOOSABLES.even) or \
            ((user_toss + comp_toss) % 2 == 1 and user_choice == CHOOSABLES.odd):
        toss_won: bool = True
        print("You won the toss\n")

        while True:
            user_des: str = input("Choose bat/bowl: ").lower()
            print()

            if user_des in PLAYABLES:
                break

            else:
                print("Choose 'bat' or 'bowl' only!")

    else:
        comp_des: str = choice(PLAYABLES)
        print(f"Computer won the toss and chooses to {comp_des}\n")

    if toss_won:
        if user_des == PLAYABLES.bat:
            comp_des: str = PLAYABLES.bowl

        else:
            comp_des: str = PLAYABLES.bat

    else:
        if comp_des == PLAYABLES.bat:
            user_des: str = PLAYABLES.bowl

        else:
            user_des: str = PLAYABLES.bat

    return {"user_des": user_des, "comp_des": comp_des}


def user_scoring(game: str) -> int:
    while True:
        try:
            if game == PLAYABLES.bat:
                user_score: int = int(input("Score a Run (1-6): "))

            else:
                user_score: int = int(input("Throw a ball (1-6): "))

            if user_score in SCOREABLES:
                return user_score

            else:
                print("Enter number from 1 to 6 only!")

        except ValueError:
            print("Enter number from 1 to 6 only!")


def comp_scoring(game: str) -> int:
    comp_score: int = choice(SCOREABLES)

    if game == PLAYABLES.bat:
        print(f"Computer scores {comp_score}")

    else:
        print(f"Computer bowls {comp_score}")

    return comp_score


def main():
    total_score: int = 0
    innings1: bool = True
    innings2: bool = False
    game: dict[str, str] = toss()

    while innings1:
        if game["user_des"] == PLAYABLES.bat:
            user_batting_score: int = user_scoring(PLAYABLES.bat)
            comp_bowling_score: int = comp_scoring(PLAYABLES.bowl)

            if user_batting_score == comp_bowling_score:
                print("\nUser OUT!!")
                print(f"Total run scored by User: {total_score}\n")
                print("Now User bowls and Computer bats")
                print(f"Computer needs {total_score + 1} runs to win\n")
                innings1: bool = False
                innings2: bool = True
                break

            else:
                total_score += user_batting_score
                print(f"Total user score {total_score}\n")

        elif game["user_des"] == PLAYABLES.bowl:
            user_bowling_score: int = user_scoring(PLAYABLES.bowl)
            comp_batting_score: int = comp_scoring(PLAYABLES.bat)

            if user_bowling_score == comp_batting_score:
                print("\nComputer OUT!!")
                print(f"Total run scored by Computer: {total_score}\n")
                print("Now User bats and Computer bowls")
                print(f"User needs {total_score + 1} runs to win\n")
                innings1: bool = False
                innings2: bool = True
                break

            else:
                total_score += comp_batting_score
                print(f"Total computer score {total_score}\n")

    while innings2:
        if game["user_des"] == PLAYABLES.bat:
            user_bowling_score: int = user_scoring(PLAYABLES.bowl)
            comp_batting_score: int = comp_scoring(PLAYABLES.bat)

            if user_bowling_score == comp_batting_score:
                print("Computer OUT!!")

                if total_score > 0:
                    print(f"User won the match by {total_score} runs!!")

                else:
                    print("Computer won the match")

                innings2: bool = False
                break

            else:
                total_score -= comp_batting_score

                if total_score <= 0:
                    print("Computer won the match")
                    break

                print(f"Computer needs more {total_score} to win\n")

        elif game["user_des"] == PLAYABLES.bowl:
            user_batting_score: int = user_scoring(PLAYABLES.bat)
            comp_bowling_score: int = comp_scoring(PLAYABLES.bowl)

            if user_batting_score == comp_bowling_score:
                print("User OUT!!")

                if total_score > 0:
                    print(f"Computer won the match by {total_score} runs!!")

                else:
                    print("User won the match")

                innings2: bool = False
                break

            else:
                total_score -= user_batting_score

                if total_score <= 0:
                    print("User won the match")
                    break

                print(f"User needs more {total_score} to win\n")


if __name__ == "__main__":
    main()
