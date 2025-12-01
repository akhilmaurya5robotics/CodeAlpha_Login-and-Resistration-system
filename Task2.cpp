#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// Load users from file into a map
void loadUsers(unordered_map<string, string> &users)
{
    ifstream infile("users.txt");
    string username, password;
    while (infile >> username >> password)
    {
        users[username] = password;
    }
    infile.close();
}

// Registration function
void registerUser(unordered_map<string, string> &users)
{
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    if (users.find(username) != users.end())
    {
        cout << "Error: Username already exists.\n";
        return;
    }
    cout << "Enter new password: ";
    cin >> password;
    // Simple validation
    if (username.empty() || password.empty())
    {
        cout << "Error: Username and password cannot be empty.\n";
        return;
    }
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();
    users[username] = password;
    cout << "Registration successful!\n";
}

// Login function
void loginUser(const unordered_map<string, string> &users)
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    auto it = users.find(username);
    if (it != users.end() && it->second == password)
    {
        cout << "Login successful!\n";
    }
    else
    {
        cout << "Error: Invalid username or password.\n";
    }
}

int main()
{
    unordered_map<string, string> users;
    loadUsers(users);

    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser(users);
    }
    else if (choice == 2)
    {
        loginUser(users);
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}