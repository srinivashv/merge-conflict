import re
import sqlite3

def is_valid_user_id(user_id):
    # Ensure that the user_id is an integer
    return re.match(r'^\d+$', user_id) is not None

def get_user_details(user_id):
    # Validate the input to ensure it's a valid integer
    if not is_valid_user_id(user_id):
        raise ValueError("Invalid user ID")

    # Use parameterized queries to prevent SQL injection
    query = "SELECT * FROM users WHERE id = ?;"
    
    # Assuming 'cursor' is already defined (e.g., from an SQLite connection)
    cursor.execute(query, (user_id,))
    return cursor.fetchone()

# Example usage
user_id = '105'  # Simulated user input
try:
    user_details = get_user_details(user_id)
    print(user_details)
except ValueError as e:
    print(e)
