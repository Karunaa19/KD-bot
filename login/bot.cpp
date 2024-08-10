
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class heroSection {
public:
    void heroAfterlogin() {
        cout << endl;
        cout << endl;
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                         message KD bot.........                                |" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------" << endl;
    }
};

class ConversationManager {
public:
    void saveConversation(const string& username, const string& conversation) {
        ofstream file(username + "_conversation.txt", ios::app);
        file << conversation << endl;
        file.close();
        cout << "Conversation saved successfully!" << endl;
    }

    void deleteConversation(const string& username) {
        if (remove((username + "_conversation.txt").c_str()) == 0) {
            cout << "Conversation deleted successfully!" << endl;
        } else {
            cout << "Error deleting conversation or no conversation to delete." << endl;
        }
    }

    void loadConversation(const string& username) {
        ifstream file(username + "_conversation.txt");
        if (file.is_open()) {
            cout << "Previous conversation loaded:\n";
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No previous conversation found." << endl;
        }
    }
};

class loginRegistration : public heroSection {
public:

    void herobeforelogin() {
        cout << endl;
        cout << endl;
        system("cls");
        int c;
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                     please login to continue.........                          |" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------" << endl;
        cout << "\t\tPress 1 to LOGIN " << endl;
        cout << "\t\tPress 2 to REGISTER" << endl;
        cout << "\t\tPress 3 if you forget your PASSWORD" << endl;
        cout << "\t\tPress 4 to EXIT" << endl;
        cin >> c;
        cout << endl;

        switch (c) {
            case 1:
                userLogin();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                forgotPassword();
                break;
            case 4:
                cout << "Thank you!" << endl;
                break;
            default:
                system("cls");
                cout << "Please choose a valid number \n" << endl;
                herobeforelogin();
                break;
        }
    }

    void userLogin() {
        int count = 0;
        string userNam, userpass, id, pass;
        system("cls");
        cout << "Please enter the username and password: " << endl;
        cout << "Username: ";
        cin >> userNam;
        cout << "Password: ";
        cin >> userpass;

        ifstream read("records.txt"); // to read the data
        while (read >> id >> pass) {
            if (id == userNam && pass == userpass) {
                count = 1;
                break;
            }
        }
        read.close();
        if (count == 1) {
            cout << userNam << "\nYour login is successful \nThanks for logging in!\n";
            heroAfterlogin();
        } else {
            cout << "\nPlease check your username and password" << endl;
            herobeforelogin();
        }
    }

    void registerUser() {
        string ruserNam, rpassword;
        cout << "Enter the username: ";
        cin >> ruserNam;
        cout << "Enter the password: ";
        cin >> rpassword;

        ofstream write("records.txt", ios::app);
        write << ruserNam << ' ' << rpassword << endl;
        write.close();
        system("cls");
        cout << "Registration is successful!" << endl;
        herobeforelogin();
    }

    void forgotPassword() {
        int option;
        system("cls");
        cout << "Forgot password?" << endl;
        cout << "Press 1 to search your id by username" << endl;
        cout << "Press 2 to go back to the main menu" << endl;
        cin >> option;

        switch (option) {
            case 1: {
                int count = 0;
                string fuserNam, fid, fpass;
                cout << "Enter the username which you remember: ";
                cin >> fuserNam;
                ifstream forg("records.txt");
                while (forg >> fid >> fpass) {
                    if (fid == fuserNam) {
                        count = 1;
                        break;
                    }
                }
                forg.close();
                if (count == 1) {
                    cout << "Your account is found!\n";
                    cout << "Your password is: " << fpass << endl;
                } else {
                    cout << "Sorry! Your account is not found" << endl;
                }
                break;
            }
            case 2:
                herobeforelogin();
                break;
            default:
                cout << "Please try again" << endl;
                herobeforelogin();
        }
    }

    void resetPassword(const string& username) {
        string newPassword;
        cout << "Enter your new password: ";
        cin >> newPassword;

        ifstream inFile("records.txt");
        ofstream tempFile("temp.txt");

        string id, pass;
        while (inFile >> id >> pass) {
            if (id == username) {
                tempFile << id << ' ' << newPassword << endl;
            } else {
                tempFile << id << ' ' << pass << endl;
            }
        }

        inFile.close();
        tempFile.close();

        remove("records.txt");
        rename("temp.txt", "records.txt");

        cout << "Password reset successfully!" << endl;
        heroAfterlogin();
    }
};

class userManager {
    string loggedInUser;
    ConversationManager conversationManager;

public:
    void startChat() {
        cout << endl;
        cout << endl;
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;

        string conversation;
        cout << "Enter your conversation (type 'exit' to end): " << endl;
        cin.ignore();
        while (true) {
            string line;
            getline(cin, line);
            if (line == "exit") break;
            conversation += line + "\n";
        }

        conversationManager.saveConversation(loggedInUser, conversation);
        showMainMenu();
    }

    void showMainMenu() {
            // la main 
    }
};

class calculator : public heroSection {
public:
    void showCalculator() {
        heroAfterlogin();
       
    }
};

int main() {
    loginRegistration lg;
    lg.herobeforelogin();
    return 0;
}



