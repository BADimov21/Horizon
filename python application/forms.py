import json
from colorama import Fore
from save_data import load_users, save_users

users = {
    'username': "user1",
    'first_name': "f_user1",
    'last_name': "l_user1",
    'password': "password1"
}


with open('users.json', 'w') as file:
  json.dump(users, file)


def add_user(username, first_name, last_name, password):
  users = load_users()
  if username not in users:
    users[username] = {
      'first_name': first_name,
      'last_name': last_name,
      'password': password
    }
    save_users(users)
    print(Fore.GREEN + f"User {username} added successfully.\n")
  else:
    print(Fore.YELLOW + f"User {username} already exists.\n")
    

def login(username, password):
  users = load_users()
  if (username in users) and (users[username] == password):
    print(Fore.GREEN + "Login successful.\n")
  else:
    print(Fore.RED + "Invalid username or password.\n")