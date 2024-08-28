#include <iostream>

using namespace std;

// ANSI escape codes for colors
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

int main() {
    // Output with colors
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;
    cout << RED << BOLD << "----                                  ---" << RESET << endl;
    cout << RED << BOLD << "-                  KDA                  -" << RESET << endl;
    cout << RED << BOLD << "-              CALCULATOR               -" << RESET << endl;
    cout << RED << BOLD << "---                                   ---" << RESET << endl;
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;
    cout << GREEN << "-      " << "+     |      " << "-      |      " << "*     -" << RESET << endl;
    cout << GREEN << "-     " << "Add    |   " << "Subtract  |  " << "Multiply  -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "/     |      " << "m      |      " << "L     -" << RESET << endl;
    cout << GREEN << "-   " << "Divide   |     " << "Mod     |     " << "Log    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "S     |      " << "C      |      " << "p     -" << RESET << endl;
    cout << GREEN << "-    " << "Square  |    " << "Cube     |    " << "Power   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "s     |      " << "c      |      " << "t     -" << RESET << endl;
    cout << GREEN << "-     " << "sin    |     " << "cos     |     " << "tan    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "r     |      " << "k      |      " << ".     -" << RESET << endl;
    cout << GREEN << "-  " << "sq root   |    " << "clear    |    " << "close   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    return 0;
}

