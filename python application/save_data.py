import json


users = {
    'username': "user1",
    'first_name': "f_user1",
    'last_name': "l_user1",
    'password': "password1"
}


with open('users.json', 'w') as file:
  json.dump(users, file)

def load_users():
  try:
    with open('users.json', 'r') as file:
      return json.load(file)
  except FileNotFoundError:
    return {}


def save_users(users):
  with open('users.json', 'w') as file:
    json.dump(users, file)