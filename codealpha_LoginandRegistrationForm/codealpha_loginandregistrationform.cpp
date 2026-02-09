#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string hashPassword(const string &password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c; 
    }
    return to_string(hash);
}

bool userExists(const string &username) {
    ifstream file("users.txt");
    string line, storedUser;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> storedUser;
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.length() < 4) {
        cout << "Error: Invalid input (password must be at least 4 characters).\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << hashPassword(password) << endl;

    cout << "Registration successful!\n";
}


void loginUser() {
    string username, password, storedUser, storedHash;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> storedUser >> storedHash;

        if (storedUser == username &&
            storedHash == hashPassword(password)) {
            cout << "Login successful! Welcome, " << username << "!\n";
            return;
        }
    }

    cout << "Error: Invalid username or password.\n";
}


int main() {
    int choice;

    do {
        cout << "\n==== Login & Registration System ====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
