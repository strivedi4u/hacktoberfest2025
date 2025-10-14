import sqlite3

# Create a new SQLite database (or connect to an existing one)
def connect_db(db_name="my_database.db"):
    conn = sqlite3.connect(db_name)
    return conn

# Create a new table
def create_table(conn):
    with conn:
        conn.execute('''
            CREATE TABLE IF NOT EXISTS users (
                id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                email TEXT NOT NULL UNIQUE
            )
        ''')

# Add a new user
def add_user(conn, name, email):
    with conn:
        conn.execute('INSERT INTO users (name, email) VALUES (?, ?)', (name, email))

# Retrieve all users
def get_users(conn):
    cursor = conn.cursor()
    cursor.execute('SELECT * FROM users')
    return cursor.fetchall()

# Update user information
def update_user(conn, user_id, name, email):
    with conn:
        conn.execute('UPDATE users SET name = ?, email = ? WHERE id = ?', (name, email, user_id))

# Delete a user
def delete_user(conn, user_id):
    with conn:
        conn.execute('DELETE FROM users WHERE id = ?', (user_id,))

# Main function for testing
if __name__ == "__main__":
    connection = connect_db()
    create_table(connection)
    
    # Add users
    add_user(connection, "Alice", "alice@example.com")
    add_user(connection, "Bob", "bob@example.com")

    # Get and print all users
    users = get_users(connection)
    print("Users in the database:", users)

    # Update a user
    update_user(connection, 1, "Alice Smith", "alice.smith@example.com")

    # Get and print all users again
    users = get_users(connection)
    print("Updated users in the database:", users)

    # Delete a user
    delete_user(connection, 2)

    # Get and print all users after deletion
    users = get_users(connection)
    print("Final users in the database:", users)

    connection.close()
