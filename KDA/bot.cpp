
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class heroSection {
public:
    void heroAfterlogin() {
        cout << endl;
        cout << endl;
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KDA bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|                         message KDA bot.........                                |" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------" << endl;

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
    void showMainMenu(){

    }

};

//calculator

// class Calculator: public heroSection {
// public:
// void introCalculator() {
//     heroSection:: heroCalculator();
//      cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//      cout << "\t\t-                                                                                                                  --"<< endl;
//      cout << "\t\t---                                             KDA Calculator                                                    ----"<< endl;                     
//      cout << "\t\t-                                      solve your math problem here...                                             --"<< endl;
//      cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//      cout << "\t\t-     +       |      -       |          *       |       /      |      %      |       k        |          .          |" << endl;
//      cout << "\t\t-    Add      |   Subtract   |       multiply   |     Divide   |     mod     |     clear      |        close        |" << endl;
//      cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//      cout << "\t\t-     s       |      c       |          t       |        S     |      C      |        p       |         r           |" << endl;
//      cout << "\t\t-    sin      |     cos      |         tan      |      square  |     cube    |      power     |        sqrt         |" << endl;
//      cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//      cout << "\t\t-     L       |      M       |          1        |       2     |      3      |        4       |         =            |  " << endl;
//      cout << "\t\t-    log      |   modeset    |       ax+b=0      | ax^2+bx+c=0 |  anx+bny=cn | anx+bny+cnz=dn |        Ans           |" << endl;
//      cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//      cout << "\t\t-     5       |      6       |          7        |       8     |      9      |        10      |         11           | "<<endl;
//      cout <<"\t\t-              |              |                   |             |             |                |                      | "<<endl; 
//      cout <<"\t\t-----------------------------------------------------------------------------------------------------------------------"<<endl;          
        
        
//             }
//  void displayOutput(double answer) {
//                 cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//                 cout << "\t\t-                                                                                                        ------------" << endl;
//                 cout << "\t\t---                                                                                                      |            " << endl;
//                 cout << "\t\t-                                                 Your answer is:                                        | " << answer << endl;
//                 cout << "\t\t----                                                                                                     -------------" << endl;
//                 cout << "\t\t----------------------------------------------------------------------------------------------------------------------" << endl;
//                 cout << "\t\t-     +       |      -       |          *       |       /     |      %      |       k        |          .           |" << endl;
//                 cout << "\t\t-    Add      |   Subtract   |       multiply   |     Divide  |     mod     |     clear      |        close         |" << endl;
//                 cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//                 cout << "\t\t-     s       |      c       |          t       |        S    |      C      |        p       |         r            |" << endl;
//                 cout << "\t\t-    sin      |     cos      |         tan      |      square |     cube    |      power     |        sqrt          |" << endl;
//                 cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//                 cout << "\t\t-     L       |      M       |          1       |       2     |      3      |        4       |         =            |  " << endl;
//                 cout << "\t\t-    log      |   modeset    |       ax+b=0     | ax^2+bx+c=0 |  anx+bny=cn | anx+bny+cnz=dn |        Ans           |" << endl;
//                 cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
//                 cout << "\t\t-     5       |      6       |          7       |       8     |     9       |        10      |         11           | "<<endl;
//                 cout <<"\t\t-              |              |                  |             |             |                |                      |"<<endl; 
//                 cout <<"\t\t----------------------------------------------------------------------------------------------------------------------"<<endl;          
        
            
//             }
 
//             double solveLinear() {
//                 double a,b,x;
//                 cout<<"Enter value of a and b"<<endl;
//                 cin>>a>>b;
//                 if (a == 0) {
//                     cout << "No solution (a cannot be 0 in a linear equation)" << endl;
//                 } else {
//                     x = -b / a;
//                     return x;
//                 }
//             }

 
//             void solveQuadratic() {
//                 double a,b,c;
//                 cout<<"Enter value of a,b and c :"<<endl;
//                 cin>>a>>b>>c;
//             double discriminant = b*b - 4*a*c;
//             double sqrt_val = sqrt(fabs(discriminant)); 

//             if (discriminant > 0) {
             
//                 double root1 = (-b + sqrt_val) / (2*a);
//                 double root2 = (-b - sqrt_val) / (2*a);
//                 cout << "Roots are real and different.\n";
//                 cout << "Root 1 = " << root1 << "\n";
//                 cout << "Root 2 = " << root2 << "\n";
//             } else if (discriminant == 0) {
               
//                 double root = -b / (2*a);
//                 cout << "Roots are real and the same.\n";
//                 cout << "Root 1 = Root 2 = " << root << "\n";
//             } else {
                
//                 double realPart = -b / (2*a);
//                 double imaginaryPart = sqrt_val / (2*a);
//                 cout << "Roots are complex and different.\n";
//                 cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i\n";
//                 cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i\n";
//             }
//             }
//             void solve2Variable() {
//                 double a1,b1,c1,a2,b2,c2;
//                 double det = a1 * b2 - a2 * b1;
//                 if (det == 0) {
//                     cout << "No unique solution (determinant is 0)" << endl;
//                 } else {
//                     double x = (c1 * b2 - c2 * b1) / det;
//                     double y = (a1 * c2 - a2 * c1) / det;
//                     cout << "value of x and y is : x = " << x << ", y = " << y << endl;
//                 }
//             }

            
//             void solve3Variable() {
//                 double a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3;
//                 double det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
//                 if (det == 0) {
//                     cout << "No unique solution (determinant is 0)" << endl;
//                 } else {
//                     double x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
//                     double y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
//                     double z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;
//                     cout << "Value of x,y and z is : x = " << x << ", y = " << y << ", z = " << z << endl;
//                 }
//             }

            
//         void calculation() {
//             double num1 = 0.0;
//             double num2 = 0.0;
//             double answer = 0.0;
//             char op = '\n';
//             bool converter = 0;
//             while(op != '.')
//             {
//                 if(converter == 1)
//                 {
//                     displayOutput(answer);
//                     cout<<"Enter: ";
//                     cin>>op;
//                     if(op == '+' || op == '-' || op == '*' || op== '/' || op == 'm' || op == 'p')
//                     {
//                         num1 = answer;

//                         cout<<"Enter num 2: ";
//                         cin>>num2;
//                     }
//                     else if(op == 'k')
//                     {
//                         system("cls");
//                         introCalculator();
                        
//                     }
//                     else if(op=='.'){
//                         system("cls");
//                         cout<<"\t\t\t\t\tTHANK YOU! ,Have a nice day!!!"<<endl;

//                     }
//                     else
//                     {
//                         num1 = answer;
//                     }

//                 }
//                 else if(op=='1'){
//                     answer=solveLinear();
//                     break;
                    
//                 }
//                 else if(op=='2'){
//                     introCalculator();
//                     solveQuadratic();

//                 }

//                 else if(op=='4'){
//                     introCalculator();
//                     solve2Variable();
//                     break;
//                 }
//                 else if(op=='5'){
//                     introCalculator();
//                     solve3Variable();
//                     break;
//                 }
//                 else
//                 {
//                     introCalculator();
//                     cout<<"Enter: ";
//                     cin>>op;
//                     if(op == '+' || op == '-' || op == '*' || op == '/' || op == 'm' || op == 'p')
//                     {
//                         cout<<"Enter num 1: ";
//                         cin>> num1;

//                         cout<<"Enter num 2: ";
//                         cin>>num2;
//                     }
//                     else if(op == 'k' )
//                     {
//                         introCalculator();
                        
//                     }
//                     else if(op=='.'){
//                         system("cls");
//                         cout<<"\t\t\t\t\tTHANK YOU! ,Have a nice day!!!"<<endl;

//                     }
//                     else
//                     {
//                         cout<<"Enter num 1: ";
//                         cin>>num1;
//                     }

//                     converter = 1;

//                 }

//                 switch(op)
//                 {
//                 case '+':
//                     answer = num1 + num2;
//                     break;
//                 case '-':
//                 if (num1<num2){
//                     answer = -(num1 - num2);
//                 }
//                 else {
//                     answer=num1-num2;
//                 }
//                 break;
//                 case '*':
//                     answer = num1 * num2;
//                     break;
//                 case '/':
//                 if(num2!=0){
//                     answer = num1 / num2;
//                     }
//                     else{
//                     answer='r';
//                     }
//                     break;
//                 case 'm':
//                     answer =   int(num1)  % int(num2);
//                     break;
//                 case 'L':
//                     answer = log(num1);
//                     break;
//                 case 'S':
//                     answer = num1*num1;
//                     break;
//                 case 'C':
//                     answer = num1*num1*num1;
//                     break;
//                 case 'p':
//                     answer = pow(num1,num2);
//                     break;
//                 case 's':
//                     answer = sin(num1);
//                     break;
//                 case '9':
//                     answer = cos(num1);
//                     break;
//                 case 't':
//                     answer = tan(num1);
//                     break;
//                 case 'r':
//                     answer = sqrt(num1);
//                     break;
//                 case '1':
//                 answer=solveLinear();
//                 break;   
//                 default:
//                     cout<<"*******************please!, Enter valid operator******************* "<<endl;
//                 }

//                 system("cls");

//             }  
                
//         }
//         };


class mainPage : public heroSection, public Calculator {
public:
    mainPage(){
     heroSection :: heroAfterlogin();
     char choice;
    cout<<"Wanna play games with bot? press 1 "<<endl;
    cout<<"press 2 to solve your math problem. "<<endl;
    cout<<"press 3 to chat with KDA bot... "<<endl;
    cin>>choice;
    }
    void displayMainMenu(){
        switch(choice){
            case 1: 
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
    }  
};





int main() {
    loginRegistration lg;
    lg.herobeforelogin();
    Calculator ca;
    ca.calculation();
    return 0;
}



