#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void login(); 
void registerr();
void forgot(); 
void imp();
void copymain();
int main() {
    int c;
    cout << endl;
    cout << endl;
    system("cls");
    cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
    cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
    imp();
    return 0;
}

void imp(){
       int c;
    cout << endl;
    cout << endl;
    system("cls");
    cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
    cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
    cout << "\t\tPlease login to continue............" << endl;
    cout << "\t\tPress 1 to LOGIN " << endl;
    cout << "\t\tPress 2 to REGISTER|" << endl;
    cout << "\t\tPress 3 if you forget your PASSWORD" << endl;
    cout << "\t\tPress 4 to EXIT" << endl;
    cin >> c;
    cout << endl;

    switch (c) {
        case 1:
            login();
            break;
        case 2:
            registerr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "Thank you!" << endl;
            break;
        default:
            system("cls");
            cout << "Please choose a valid number \n" << endl;
            imp();
    }
}
void login() {
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
            
        }
    }
    read.close();
    if (count == 1) {
        cout << userNam << "\nYour login is successful \nThanks for logging in!\n";
        copymain();
    } else {
        cout << "\nPlease check your username and password" << endl;
    }
    
}

void registerr() {
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
    imp();
}

void forgot() {
    int option;
    system("cls");
    cout << "Forgot password?" << endl;
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "Enter your choice: ";
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
            break;
        default:
            cout << "Please try again" << endl;
            imp();
    }
}
void copymain(){
     cout << endl;
    cout << endl;
    system("cls");
    cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
    cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
}
