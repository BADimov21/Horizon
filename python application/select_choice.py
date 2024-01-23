from colorama import Fore
import json
from forms import add_user, login

print(Fore.MAGENTA + """
  _   _            _                
 | | | | ___  _ __(_)_______  _ __  
 | |_| |/ _ \| '__| |_  / _ \| '_ \ 
 |  _  | (_) | |  | |/ / (_) | | | |
 |_| |_|\___/|_|  |_/___\___/|_| |_|""")

print(Fore.LIGHTMAGENTA_EX + "\nWelcome to Horizon Login Form\n")


users = {
    'username': "user1",
    'first_name': "f_user1",
    'last_name': "l_user1",
    'password': "password1"
}


with open('users.json', 'w') as file:
  json.dump(users, file)


def main():
  while True:

    print(Fore.WHITE + "1. Register\n2. Login\n3. Exit")
    choice = input("Enter your choice: ")
    print("\n")

    if choice == '1':
      print(Fore.LIGHTCYAN_EX + "Register\n")
      first_name = input("Enter your first name: ")
      last_name = input("Enter your last name: ")
      username = input("Enter username: ")
      password = input("Enter password: ")
      add_user(username,first_name, last_name, password)

    elif choice == '2':
      print(Fore.LIGHTBLUE_EX + "Login")
      username = input("Enter username: ")
      password = input("Enter password: ")
      login(username, password)

    elif choice == '3':
      print(Fore.LIGHTMAGENTA_EX + "Exiting...")
      break

    else:
      print(Fore.RED + "Invalid choice. Please enter 1, 2, or 3.")


if __name__ == "__main__":
  main()