#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;
class loginRegistration {
public:
    public:
    void registerUser() {
        cout << "Enter a username to register: ";
        getline(cin, loggedInUser);
        cout << "Enter a password: ";
        getline(cin, loggedInPassword);
        saveCredentials();
        cout<<"Press any key to continue "<<endl;
        cin.ignore();
        cin.get();
        system("cls");
    }

    private:
    string loggedInUser;
    string loggedInPassword;
    bool isLoggedIn = false;

public:
    void login() {
        string username, password;
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

        if (checkCredentials(username, password)) {
            isLoggedIn = true;
            loggedInUser = username;
            loggedInPassword = password;
            cout << "Login successful!" << endl;
            cout<<"Press any key to continue "<<endl;
            cin.ignore();
            cin.get();
            system("cls");
            system(".\\KDABot"); // Pass loggedInUser as a parameter
        } else {
            cout << "Username or password incorrect. Please try again." << endl;
        }
    }

    void logout() {
        isLoggedIn = false;
        loggedInUser = "";
        loggedInPassword = "";
        cout << "You have successfully logged out." << endl;
    }

    void saveConversationHistory(const string &conversation) {
        ofstream outFile(loggedInUser + "_conversation.txt", ios::app);
        outFile << conversation;
        outFile.close();
    }

    void loadConversationHistory() {
        ifstream inFile(loggedInUser + "_conversation.txt");
        if (!inFile) {
            cout << "No previous conversation found." << endl;
        } else {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        }
    }

    void deleteConversationHistory() {
        if (remove((loggedInUser + "_conversation.txt").c_str()) == 0) {
            cout << "Conversation history deleted successfully." << endl;
        } else {
            cout << "Error deleting conversation history." << endl;
        }
    }

private:
    void saveCredentials() {
        ofstream outFile("users.txt", ios::app);
        outFile << loggedInUser << " " << loggedInPassword << endl;
        outFile.close();
    }

    bool checkCredentials(const string& username, const string& password) {
        ifstream inFile("users.txt");
        string storedUsername, storedPassword;

        while (inFile >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                return true;
            }
        }

        return false;
    }

   
};

int main() {
    system("cls");
    loginRegistration lg;
    int choice;

    while (true) {

        cout << "\t\t\t\t\t\t\t\tHi, I am KDA bot" << endl;
        cout << "\t\t\t\t\t\t\tI am your personal assistant!" << endl;
        cout << endl;
        cout << endl;
        cout << endl << endl << endl;
        cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                     please login to continue.........                          |" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------" << endl;
        cout << "\t\tPress 1 to REGISTER " << endl;
        cout << "\t\tPress 2 to LOGIN "<<endl;
        cout << "\t\tPress 3 to EXIT" << endl;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            lg.registerUser();
        } else if (choice == 2) {
            lg.login();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
