# Laptop Record Management
from csv import writer, reader

HEADER: list[str] = ["Model No", "Ram", "Memory Type", "Memory Size"]


def create() -> None:
    f = open("Laptop.csv", 'w')
    recs = writer(f, lineterminator='\n')
    recs.writerow(HEADER)

    while True:
        try:
            model: int = int(input("Enter Model No.: "))
            ram: int = int(input("Enter RAM (in GB): "))
            mem_type: str = input("Enter Memory Type (SSD/HDD): ").upper()
            mem_size: int = int(input("Enter Memory Size (in GB): "))

        except ValueError:
            print("\nINVALID INPUT")
            f.close()
            return

        data: list[int, str] = [model, ram, mem_type, mem_size]
        recs.writerow(data)
        ask: str = input("\nAdd more Records(y/n):")
        print()

        if ask in "Yy":
            continue

        break

    print("RECORD CREATED")
    f.close()


def display() -> None:
    try:
        f = open("Laptop.csv", 'r')

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    recs: list[list[str]] = list(reader(f))

    for data in recs:
        print(data)

    if recs:
        print("\nALL RECORD DISPLAYED")

    else:
        print("\nNO RECORD FOUND")

    f.close()


def append() -> None:
    f = open("Laptop.csv", 'a')
    recs = writer(f, lineterminator='\n')

    try:
        model: int = int(input("Enter Model No. : "))
        ram: int = int(input("Enter RAM (in GB) : "))
        mem_type: str = input("Enter Memory Type (SSD/HDD): ").upper()
        mem_size: int = int(input("Enter Memory Size (in GB): "))

    except ValueError:
        print("\nINVALID INPUT")
        f.close()
        return

    data: list[int, str] = [model, ram, mem_type, mem_size]
    recs.writerow(data)
    print("\nRECORD ADDED")
    f.close()


def search() -> None:
    try:
        f = open("Laptop.csv", 'r')

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: str = input("Enter Model no. : ")
    recs = reader(f)
    flag: bool = False

    for data in recs:
        if data[0] == mod:
            flag: bool = True
            print(data)
            break

    if not flag:
        print("\nNO RECORD FOUND")

    f.close()


def update() -> None:
    try:
        f = open("Laptop.csv", "r+")

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: str = input("Enter Model no. : ")
    recs = reader(f)
    new_recs: list[int, str] = []
    flag: bool = False

    for data in recs:
        if data[0] == mod:
            flag: bool = True

            try:
                ram: int = int(input("Enter New RAM (in GB) : "))
                mem_type: str = input("Enter New Memory Type (SSD/HDD): ").upper()
                mem_size: str = int(input("Enter New Memory Size (in GB): "))
                new_recs.append([data[0], ram, mem_type, mem_size])

            except ValueError:
                print("\nINVALID INPUT")
                f.close()
                return

        else:
            new_recs.append(data)

    f.close()

    if flag:
        f = open("Laptop.csv", 'w')
        recs = writer(f, lineterminator='\n')
        recs.writerows(new_recs)
        print("\nRECORD UPDATED")
        f.close()

    else:
        print("\nNO RECORD FOUND")


def delete() -> None:
    try:
        f = open("Laptop.csv", 'r')

    except FileNotFoundError:
        print("\nNO FILE FOUND")
        return

    mod: str = input("Enter Model No. : ")
    recs = reader(f)
    new_recs: list[list[str]] = []
    flag: bool = False

    for data in recs:
        if not (data[0] == mod):
            new_recs.append(data)

        else:
            print("\nRECORD DELETED")
            flag: bool = True

    f.close()

    if flag:
        f = open("Laptop.csv", 'w')
        recs = writer(f, lineterminator='\n')
        recs.writerows(new_recs)
        f.close()

    else:
        print("\nNO RECORD FOUND")


def main() -> int:
    while True:
        print("\n\n")
        print("\t\tMAIN MENU")
        print("*********************************************\n")
        print("1. Create Record")
        print("2. Display Record")
        print("3. Append Record")
        print("4. Search Record")
        print("5. Update Record")
        print("6. Delete Record")
        print("7. Exit from Project\n")
        print("*********************************************\n")
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
