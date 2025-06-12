# Laptop Record Management
from pickle import load, dump


def create() -> None:
    f = open("Laptop.dat", "wb")

    while True:
        try:
            model: int = int(input("Enter Model No.: "))
            ram: int = int(input("Enter RAM (in GB): "))
            mem_type: str = input("Enter Memory Type (SSD/HDD): ").upper()
            mem_size: int = int(input("Enter Memory Size (in GB): "))


        except ValueError:
            print("\nINVALID MAIN_FILE")
            f.close()
            return

        data: list[int, str] = [model, ram, mem_type, mem_size]
        dump(data, f)
        ask: str = input("\nAdd more Records(y/n): ")
        print()

        if ask in "Yy":
            continue

        break

    print("RECORD CREATED")
    f.close()


def display() -> None:
    try:
        f = open("Laptop.dat", "rb")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    flag: bool = False

    while True:
        try:
            data: list[int, str] = load(f)

        except EOFError:
            if not flag:
                print("\nNO RECORD FOUND")

            else:
                print("\nALL RECORD DISPLAYED")
                f.close()

            return

        print(data)
        flag: bool = True


def append() -> None:
    f = open("Laptop.dat", "ab")

    try:
        model: int = int(input("Enter Model No. : "))
        ram: int = int(input("Enter RAM (in GB) : "))
        mem_type: str = input("Enter Memory Type (SSD/HDD): ").upper()
        mem_size: int = int(input("Enter Memory Size (in GB): "))

    except ValueError:
        print("\nINVALID MAIN_FILE")
        f.close()
        return

    data: list[int, str] = [model, ram, mem_type, mem_size]
    dump(data, f)
    print("\nRECORD ADDED")
    f.close()


def search() -> None:
    try:
        f = open("Laptop.dat", "rb")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: int = int(input("Enter Model no. : "))

    while True:
        try:
            data: list[int, str] = load(f)

        except EOFError:
            print("\nNO RECORD FOUND")
            f.close()
            return

        if data[0] == mod:
            print(data)
            break

    f.close()


def update() -> None:
    try:
        f = open("Laptop.dat", "rb+")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: int = int(input("Enter Model no. : "))
    cursor: int = 0

    while True:
        try:
            data: list[int, str] = load(f)

        except EOFError:
            print("\nNO RECORD FOUND")
            f.close()
            return

        if data[0] == mod:
            f.seek(cursor)

            try:
                data[1] = int(input("Enter New RAM (in GB) : "))
                data[2] = input("Enter New Memory Type (SSD/HDD): ").upper()
                data[3] = int(input("Enter New Memory Size (in GB): "))

            except ValueError:
                print("\nINVALID MAIN_FILE")
                f.close()
                return

            dump(data, f)
            print("\nRECORD UPDATED")
            break

        else:
            cursor: int = f.tell()

    f.close()


def delete() -> None:
    try:
        f = open("Laptop.dat", "rb")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: int = int(input("Enter Model No. : "))
    temp: list[list[int, str]] = []

    while True:
        try:
            data: list[int, str] = load(f)

        except EOFError:
            f.close()
            break

        if data[0] != mod:
            temp.append(data)

        else:
            print("RECORD DELETED")

        f = open("Laptop.dat", "wb")

        for i in temp:
            dump(i, f)

        f.close()


def main() -> int:
    while True:
        print("\n\n")
        print("\t\tMAIN_FILE MENU")
        print("*****************************************\n")
        print("1. Create Record")
        print("2. Display Record")
        print("3. Append Record")
        print("4. Search Record")
        print("5. Update Record")
        print("6. Delete Record")
        print("7. Exit from Project\n")
        print("*****************************************\n")
        choice = int(input("Enter your choice between 1 to 7 ---> "))
        print()

        if choice == 1:
            create()
        elif choice == 2:
            display()
        elif choice == 3:
            append()
        elif choice == 4:
            search()
        elif choice == 5:
            update()
        elif choice == 6:
            delete()
        elif choice == 7:
            print("EXIT SUCCESSFUL")
            break
        else:
            print("Invalid Input")

        return 0

if __name__ == "__main__":
    main()
