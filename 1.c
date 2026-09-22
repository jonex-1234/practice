students = """Rahul Kumar, 2026CS101
Anita Thomas, 2026CS102
NEHA GUPTA , 2026CS105
Priya Singh, 2026CS103
Mary Ann Thomas,
, 2026CS108
ARJUN MEHTA 2026CS104
Arun Sadanand, CS004"""

with open("students.txt", "w") as file:
    file.write(students)
    
    
    
    
import random
import string

def generate_password():

    capital = random.choice(string.ascii_uppercase)
    small = random.choice(string.ascii_lowercase)
    number = random.choice(string.digits)
    special = random.choice("#@$")

    remaining = random.choices(
        string.ascii_letters + string.digits + "#@$",
        k=4
    )

    password = [capital, small, number, special] + remaining

    random.shuffle(password)

    return ''.join(password)


try:

    with open("students.txt", "r") as file:
        lines = file.readlines()

    with open("users.txt", "w") as file:

        for line in lines:

            line = line.strip()

            try:

                name, roll_number = line.split(",")

                name = name.strip()
                roll_number = roll_number.strip()

                if name == "" or roll_number == "":
                    raise ValueError

                first_name = name.split()[0].lower()

                username = first_name + "_m" + roll_number.lower() + "@xyz.ac.in"

                password = generate_password()

                file.write(username + " - " + password + "\n")

            except ValueError:
                continue

    print("users.txt created successfully.")

except FileNotFoundError:
    print("students.txt file not found.")

except Exception as e:
    print("Error:", e)
    
    
    
    
    
    
    
with open("users.txt", "r") as file:
    print(file.read())
