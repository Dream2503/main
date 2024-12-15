from os import remove
from pickle import load, dump
from random import randint
from typing import Literal


def check_database() -> None:
    """checks the existence of the necessary files to run the program,
    if not available then it creates them with default configuration"""
    try:
        open("bank_details.dat", "rb").close()
        open("reserved.dat", "rb").close()

    except FileNotFoundError:
        reset_database("silent")


def reset_database(mode: Literal["silent", "loud"]) -> None:
    """resets the configuration of the database to default\n
    silent mode --> doesn't display the reset successful message\n
    loud mode --> shows the reset successful message"""
    default_details: dict[str, int | str | float] = {
        "account no.": 1000,
        "username": "admin",
        "password": "2503",
        "name": "dream",
        "gender": 'M',
        "phone no.": "12345",
        "balance": 10000.00
    }
    default_username: str = "admin"
    default_ac_no: int = 1000

    with open("bank_details.dat", "wb") as bank_details:
        dump(default_details, bank_details)

    with open("reserved.dat", "wb") as reserved:
        dump(default_username, reserved)
        dump(default_ac_no, reserved)

    if mode == "loud":
        print("\nData Successfully Restore!!")


def display_database() -> None:
    """displays all details contained in the database"""
    with open("bank_details.dat", "rb") as bank_details:
        with open("reserved.dat", "rb") as reserved:
            details: list[dict[str, int | str | float]] = []
            usernames: list[str] = []
            ac_nos: list[int] = []

            try:
                while True:
                    details.append(load(bank_details))
                    usernames.append(load(reserved))
                    ac_nos.append(load(reserved))

            except EOFError:
                print("\nDetails:", details, "\nUsernames:", usernames, "\nAccount nos.:", ac_nos)


def delete_database() -> None:
    """deletes all the database files\n
    THE DELETED DATA ARE NOT RECOVERABLE ANYMORE!"""
    remove("bank_details.dat")
    remove("reserved.dat")
    print("\nData Successfully Deleted")


def enter_specific(itype: Literal["password", "phone no."]) -> str:
    """accepts the specific type of input from the user\n
    password type --> accepts a password with specific requirements\n
    phone no. type --> accepts a phone number with specific requirements"""
    if itype == "password":
        special_characters: str = "!#$%&( )*+,-./:;<=>?@[]^_`{|}~"
        valid: list[bool] = [False, False, False]

        while True:
            print(
                "\nThe password must at least be 8 character long and must contain one alphabet, number and special symbol.")
            password: str = input("Enter password: ")

            for ch in password:
                if ch.isalpha():
                    valid[0] = True

                elif ch.isdigit():
                    valid[1] = True

                elif ch in special_characters:
                    valid[2] = True

            if valid == [True, True, True]:
                conform_password: str = input("Enter password again: ")

                if password == conform_password:
                    print("Password Accepted!\n")
                    return password

                else:
                    print("Incorrect Password. Try Again...")
                    return enter_specific("password")

            else:
                print("Invalid Password. Try Again...\n")

    elif itype == "phone no.":
        while True:
            ph_no: str = input("Enter phone no.: ")

            if not (ph_no.isnumeric() and len(ph_no) == 10):
                print("Enter only '10 DIGIT PHONE NUMBER'.\n")

            else:
                return ph_no


def extract_account(usernames: str) -> dict[str, int | str | float]:
    """takes a username and returns the details associated with that username\n"""
    with open("bank_details.dat", "rb") as bank_details:
        try:
            while True:
                detail: dict[str, int | str | float] = load(bank_details)

                if detail["username"] in usernames:
                    return detail

        except EOFError:
            print("\nNo account found with the given username")


def save_details(details: dict[str, int | str | float], to_delete: bool = False) -> None:
    """takes an account and updates the database"""
    with open("bank_details.dat", "rb+") as bank_details:
        try:
            while True:
                pos: int = bank_details.tell()
                account: dict[str, int | str | float] = load(bank_details)

                if details["username"] == account["username"]:
                    bank_details.seek(pos)

                    if to_delete:
                        dump(b'', bank_details)
                    else:
                        dump(details, bank_details)

                    return

        except EOFError:
            dump(details, bank_details)

            with open("reserved.dat", 'ab') as reserved:
                dump(details["username"], reserved)
                dump(details["account no."], reserved)


def accept_amount() -> float:
    """accepts valid amount from user and returns it"""
    while True:
        try:
            res: float = float(input("\nEnter amount: "))

            if res < 0:
                raise ValueError

        except ValueError:
            print("Input Valid Number. Try Again...")

        else:
            return res


def check_element(itype: Literal["username", "account no."], element: int | str) -> bool:
    with open("reserved.dat", "rb") as reserved:
        try:
            while True:
                if itype == "username":
                    elem: str = load(reserved)
                    _: int = load(reserved)

                else:
                    _: str = load(reserved)
                    elem: int = load(reserved)

                if element == elem:
                    return True

        except EOFError:
            return False


def create_account() -> None:
    """creates bank account and updates the necessary files with the new details"""
    print("\nCreating Account")
    name: str = input("Enter name: ").title()

    while True:
        gender: str = input("Enter gender(M/F): ").upper()

        if not (len(gender) == 1 and gender in "MF"):
            print("Choose either 'M' or 'F'.\n")

        else:
            break

    ph_no: str = enter_specific("phone no.")

    with open("reserved.dat", "ab") as reserved:
        while True:
            username: str = input("Enter a unique username: ")

            if check_element("username", username):
                print("Username already taken. Try Again...\n")

            else:
                dump(username, reserved)
                break

        password: str = enter_specific("password")

        while True:
            rand_ac_no: int = randint(1001, 9999)

            if not check_element("account no.", rand_ac_no):
                dump(rand_ac_no, reserved)
                break

    user_details: dict[str, int | str | float] = {
        "account no.": rand_ac_no,
        "username": username,
        "password": password,
        "name": name,
        "gender": gender,
        "phone no.": ph_no,
        "balance": 0.00,
    }
    with open("bank_details.dat", "ab") as bank_details:
        dump(user_details, bank_details)

    display_account(user_details)


def login_account() -> dict[str, int | str | float]:
    """logins the account and returns the logged in account details[dict]"""
    global LOGGED_IN
    print("\nLogging In Account")
    username: str = input("Enter username: ")

    with open("bank_details.dat", "rb") as bank_details:
        try:
            while True:
                account: str = load(bank_details)

                if account["username"] == username:
                    while True:
                        password: str = input("Enter password: ")

                        if account["password"] == password:
                            print("\nLogin Successful!")
                            input("press enter to continue...")
                            LOGGED_IN: bool = True
                            return account

                        else:
                            print("Incorrect password, try again\n")

        except EOFError:
            print("No such username found.\n")

        while not LOGGED_IN:
            inp: str = input("Press '1' to create an account or '2' to try again: ")

            if inp == '1':
                return create_account()

            elif inp == '2':
                return login_account()

            print("Invalid Input.\n")


def display_account(account: dict[str, int | str | float]) -> None:
    """displays all the details of the provided account"""
    print("Account Details\n")

    for key, value in account.items():
        if key == "password":
            print(f"{key} --> {"*" * len(value)}")
            continue

        print(f"{key} --> {value}")

    input("\npress enter to continue...")


def edit_account() -> None:
    """edits the logged in account details and updates the database"""

    def edit_detail(itype: Literal["name", "password", "phone no."]) -> None:
        """edits the account details of provided type"""
        while True:
            check_password: str = input("\nEnter password: ")

            if check_password != ACTIVE["password"]:
                print("Incorrect password, Try Again...")
            else:
                break

        if itype == "name":
            new_name: str = input("Enter new name: ")
            ACTIVE["name"] = new_name

        elif itype == "password":
            new_password: str = enter_specific("password")
            ACTIVE["password"] = new_password

        elif itype == "phone no.":
            new_ph_no: str = enter_specific("phone no.")
            ACTIVE["phone no."] = new_ph_no

        save_details(ACTIVE)

    edit_menu: str = "\
1. Name\n\
2. Password\n\
3. Phone Number\n"
    print("\nEditing Account Details")
    print(edit_menu)

    while True:
        inp: str = input("Select what to edit --> ")

        if inp == "1":
            edit_detail("name")
            print("\nSuccessfully New Name Updated.")

        elif inp == "2":
            edit_detail("password")
            print("\nSuccessfully New Password Updated.")

        elif inp == "3":
            edit_detail("phone no.")
            print("\nSuccessfully New Phone Number Updated")

        else:
            print("Enter Valid Input. Try Again...\n")
            continue

        input("press enter to continue...")
        break


def pay(username: str, iamount: float) -> None:
    """pays the amount to the username from the logged in account"""
    receiver_account: dict[str, int | str | float] = extract_account(username)
    ACTIVE["balance"] -= iamount
    receiver_account["balance"] += iamount
    save_details(ACTIVE)
    save_details(receiver_account)
    print("Transaction Completed Successfully!")
    input("\npress enter to continue...")


def transaction(itype: Literal["deposit", "withdraw"], iamount: float) -> None:
    """deposits or withdraws the amount of money from the logged in account"""
    if itype == "deposit":
        ACTIVE["balance"] += iamount

    elif itype == "withdraw":
        ACTIVE["balance"] -= iamount

    save_details(ACTIVE)
    print("\nTransaction Completed Successfully!!")
    input("press enter to continue...")


def delete_account() -> None:
    """deletes the logged in provided from the database"""
    global LOGGED_IN, ACTIVE
    print("\nDeleting Account.")

    while True:
        password1: str = input("Enter password: ")
        password2: str = input("Enter password again: ")

        if ACTIVE["password"] == password1 == password2:
            while True:
                conformation: str = input(
                    "\nDO YOU REALLY WANT TO DELETE YOUR ACCOUNT. TYPE 'YES' TO CONTINUE OR 'NO' TO ABORT: ").upper()

                if conformation == "YES":
                    save_details(ACTIVE, True)
                    print("Account Successfully Deleted!")

                    with open("reserved.dat", "rb+") as reserved:
                        while True:
                            pos: int = reserved.tell()
                            username: str = load(reserved)
                            _: int = load(reserved)

                            if username == ACTIVE["username"]:
                                reserved.seek(pos)
                                dump(b'', reserved)
                                dump(b'', reserved)
                                break

                    LOGGED_IN: bool = False
                    del ACTIVE
                    return

                elif conformation == "NO":
                    print("Account Deletion Unsuccessful!")
                    return

                else:
                    print("Invalid Input. Try Again...")

        else:
            print("Incorrect Password. Try Again...\n")


MAIN_MENU1: str = '''
    MAIN MENU   
1. Create Account
2. Login Account
3. Quit'''
MAIN_MENU2: str = '''
    MAIN MENU   
1. Account Details
2. Edit Details
3. Deposit
4. Withdraw
5. Pay
6. Balance Enquiry
7. Delete Account
8. Log Out'''
LOGGED_IN: bool = False
check_database()
ACTIVE: dict[str, int | str | float] = {}

while True:
    if not LOGGED_IN:
        print(MAIN_MENU1)
        check: str = input("\nEnter your choice: ")

        if check == '1':
            create_account()

        elif check == '2':
            if LOGGED_IN:
                print("\nAlready Logged In")

            else:
                ACTIVE: dict[str, int | str | float] = login_account()

        elif check == '3':
            print("\nThank you for using!")
            break

        elif check == "reset":
            reset_database("loud")

        elif check == "inspect":
            display_database()

        elif check == "delete":
            delete_database()
            break

        else:
            print("Invalid Input. Try Again...")

    else:
        print(MAIN_MENU2)
        check = input("\nEnter your choice: ")

        if check == '1':
            display_account(ACTIVE)

        elif check == '2':
            edit_account()

        elif check == '3':
            print("\nInitiating Transaction.", end="")
            amount: float = accept_amount()
            transaction("deposit", amount)

        elif check == '4':
            print("\nInitiating Transaction.", end="")
            amount: float = accept_amount()

            if ACTIVE["balance"] < amount:
                print("Insufficient Balance.")
                print(f"Available Balance --> {ACTIVE["balance"]} and Requested Amount ---> {amount}")
                input("press enter to continue...")

            else:
                transaction("withdraw", amount)

        elif check == '5':
            receiver: str = input("Enter Receiver's username: ")
            flag: bool = check_element("username", receiver)

            if flag:
                amount: float = accept_amount()

                if ACTIVE["balance"] < amount:
                    print("Insufficient Balance.")
                    print(f"Available Balance --> {ACTIVE["balance"]} and Requested Amount ---> {amount}")
                    input("press enter to continue...")

                else:
                    pay(receiver, amount)

            else:
                print("username doesn't exist")
                input("press enter to continue...")

        elif check == '6':
            print("\nYour Current Balance is", ACTIVE["balance"])
            input("press enter to continue...")

        elif check == '7':
            delete_account()

        elif check == '8':
            LOGGED_IN: bool = False
            del ACTIVE

        elif check == "inspect":
            display_database()

        else:
            print("Invalid Input. Try Again...")
