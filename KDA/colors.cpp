#include <iostream>
using namespace std;

int main() {
    // ANSI escape codes for colors
    string reset = "\033[0m";  // Reset to default color
    string red = "\033[31m";   // Red text
    string green = "\033[32m"; // Green text
    string blue = "\033[34m";  // Blue text
    string yellow = "\033[33m";// Yellow text
    string cyan = "\033[36m";  // Cyan text
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string WHITE = "\033[37m";
    const string BOLD = "\033[1m";
    const string UNDERLINE = "\033[4m";

    cout << "\t\t\t\t\t\t" << cyan << "*************************************************************" << reset << endl;
    cout << "\t\t\t\t\t\t" << cyan << "*                                                           *" << reset << endl;
    cout << "\t\t\t\t\t\t" << cyan << "*             " << BLUE << BOLD << "     Hi, I am KDA bot" << cyan << "                         *" << reset << endl;
    cout << "\t\t\t\t\t\t" << cyan << "*" << BLUE << BOLD << "        Hi " + string("loggedInUser") + ", how are you feeling today?  " << cyan << "      *" << reset << endl;
    cout << "\t\t\t\t\t\t" << cyan << "*                                                           *" << reset << endl;
    cout << "\t\t\t\t\t\t" << cyan << "*************************************************************" << reset << endl;

    return 0;
}
