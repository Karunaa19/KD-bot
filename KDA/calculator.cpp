#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Addition {
public:
    double add(double a, double b) {
        return a + b;
    }
};

class Subtraction {
public:
    double subtract(double a, double b) {
        return a - b;
    }
};

class Multiplication {
public:
    double multiply(double a, double b) {
        return a * b;
    }
};

class Division {
public:
    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error! Division by zero." << endl;
            return NAN;
        }
    }
};

class Modulus {
public:
    double modulus(double a, double b) {
        return fmod(a, b);
    }
};

class NaturalLogarithm {
private:
    double number;

public:
    double calculate() {
        cout<<"Enter number"<<endl;
        cin>>number;
        if (number <= 0) {
            cerr << "Error: Natural logarithm is undefined for non-positive numbers." << endl;
            return -1;
        }
        return log(number);
    }
};


class Base10Logarithm {
private:
    double number;

public:
    double calculate() {
        cout<<"Enter number "<<endl;
        cin>>number;
        if (number <= 0) {
            cerr << "Error: Base-10 logarithm is undefined for non-positive numbers." << endl;
            return -1; 
        }
        return log10(number); 
    }
};

class Sine {
public:
    double sine(double a) {
        return sin(a);
    }
};

class Cosine {
public:
    double cosine(double a) {
        return cos(a);
    }
};

class Tangent {
public:
    double tangent(double a) {
        return tan(a);
    }
};

class Power {
public:
    double power(double a, double b) {
        return pow(a, b);
    }
};

class Square {
public:
    double square(double a) {
        return a * a;
    }
};

class Cube {
public:
    double cube(double a) {
        return a * a * a;
    }
};

class SquareRoot {
public:
    double squareRoot(double a) {
        if (a >= 0) {
            return sqrt(a);
        } else {
            cout << "Error! Square root of a negative number." << endl;
            return NAN;
        }
    }
};

class CubeRoot {
public:
    double cubeRoot(double a) {
        return cbrt(a);
    }
};

class SolveLinear {
public:
    double solve(double a, double b) {
        if (a == 0) {
            cout << "No solution (a cannot be 0 in a linear equation)" << endl;
            return NAN;
        } else {
            return -b / a;
        }
    }
};

class QuadraticSolver {
public:
    pair<double, double> solve(double a, double b, double c) {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            return make_pair(root1, root2);
        } 
        else if (discriminant == 0) {
                double root = -b / (2*a);
                cout << "Roots are real and the same.\n";
                cout << root;
        } 
        else {
            cout << "Complex roots: ";
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            return make_pair(realPart, imaginaryPart);
        }
    }
};

class Solve2Variables {
public:
    void solve(double a1, double b1, double c1, double a2, double b2, double c2) {
        double det = a1 * b2 - a2 * b1;
        if (det == 0) {
            cout << "No unique solution (determinant is 0)" << endl;
        } else {
            double x = (c1 * b2 - c2 * b1) / det;
            double y = (a1 * c2 - a2 * c1) / det;
            cout << "Value of x and y is : x = " << x << ", y = " << y << endl;
        }
    }
};

class Solve3Variables {
public:
    void solve(double a1, double b1, double c1, double d1,
               double a2, double b2, double c2, double d2,
               double a3, double b3, double c3, double d3) {
        double det = a1 * (b2 * c3 - b3 * c2) -
                     b1 * (a2 * c3 - a3 * c2) +
                     c1 * (a2 * b3 - a3 * b2);
        if (det == 0) {
            cout << "No unique solution (determinant is 0)" << endl;
        } else {
            double x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
            double y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
            double z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;
            cout << "Value of x, y, and z is : x = " << x << ", y = " << y << ", z = " << z << endl;
        }
    }
};
class CartesianToPolar {
public:
    pair<double, double> convert(double x, double y) {
        double r = sqrt(x * x + y * y);
        double theta = atan2(y, x);
        return make_pair(r, theta);
    }
};
class PolarToCartesian {
public:
    pair<double, double> convert(double r, double theta) {
        double x = r * cos(theta);
        double y = r * sin(theta);
        return make_pair(x, y);
    }
};

class Factorial {
public:
    double factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
};

class Permutation {
public:
    double permutation(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / fact.factorial(n - r);
    }
};

class Combination {
public:
    double combination(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / (fact.factorial(r) * fact.factorial(n - r));
    }
};

class MatrixOperations {
public:
    int matrix1[2][2];
    int matrix2[2][2];
    int result[2][2];


    void setMatrix1(int m[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix1[i][j] = m[i][j];
            }
        }
    }

    void setMatrix2(int m[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix2[i][j] = m[i][j];
            }
        }
    }

    void displayMatrix(int matrix[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addMatrices() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        displayMatrix(result);
    }

    void subtractMatrices() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        displayMatrix(result);
    }

    void multiplyMatrices() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        displayMatrix(result);
    }

    int determinantMatrix1() {
        return matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
    }
};

class ScientificCalculator {
    private:
    void showCalculator();
    void displayOutput(double answer1, double answer2 = 0);
    void clearScreen();
    void handleOperation(char operation);
    double num1, num2, answer1, answer2;
    char operation;
public:
void run();


};

void ScientificCalculator::showCalculator() {

     cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
     cout << "\t\t-                                                                                                                  --"<< endl;
     cout << "\t\t---                                             KDA Calculator                                                    ----"<< endl;                     
     cout << "\t\t-                                      solve your math problem here...                                             --"<< endl;
     cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
     cout << "\t\t-     +       |      -       |          *       |       /      |      %      |       k        |          .          |" << endl;
     cout << "\t\t-    Add      |   Subtract   |       multiply   |     Divide   |     mod     |     clear      |        close        |" << endl;
     cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
     cout << "\t\t-     s       |      c       |          t       |        S     |      C      |        p       |         r           |" << endl;
     cout << "\t\t-    sin      |     cos      |         tan      |      square  |     cube    |      power     |        sqrt         |" << endl;
     cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
     cout << "\t\t-     L       |      M       |          1       |       q      |       2     |        3       |         =            |  " << endl;
     cout << "\t\t-    log      |   modeset    |       ax+b=0     | ax^2+bx+c=0  |  anx+bny=cn | anx+bny+cnz=dn |        Ans           |" << endl;
     cout << "\t\t---------------------------------------------------------------------------------------------------------------------" << endl;
     cout << "\t\t-     A       |      B       |          Z       |       z      |      d      |        10      |         11           | "<<endl;
     cout << "\t\t- Pol to Cart | Cart to Pol  |   Permutations   | Combinations | Determinant |                |                      | "<<endl; 
     cout <<"\t\t-----------------------------------------------------------------------------------------------------------------------"<<endl; 
}

void ScientificCalculator::displayOutput(double answer1, double answer2) {
    cout << "\t\t--------------------------------------------------------------------------------------" << endl;
    cout << "\t\t------                                                                ----------------" << endl;
    cout << "\t\t---                                      Your answer                  |        " << endl;
    cout << "\t\t-                                            is:                      | " << fixed << setprecision(2) << answer1;
    if (answer2 != 0) {
        cout << ", " << fixed << setprecision(2) << answer2;
    }
    cout << endl;
    cout << "\t\t---                                                                    -----------------" << endl;
    cout << "\t\t----------------------------------------------------------------------------------------" << endl;
    showCalculator(); 
}

void ScientificCalculator::clearScreen() {
    system("cls"); 
}

void ScientificCalculator::handleOperation(char operation) {
    switch (operation) {
        case '+':
            Addition addObj;
            answer1 = addObj.add(num1, num2);
            break;
        case '-':
            Subtraction subObj;
            answer1 = subObj.subtract(num1, num2);
            break;
        case '*':
            Multiplication mulObj;
            answer1 = mulObj.multiply(num1, num2);
            break;
        case '/':
            Division divObj;
            answer1 = divObj.divide(num1, num2);
            break;
        case '%':
            Modulus modObj;
            answer1 = modObj.modulus(num1, num2);
            break;
        case 's':
            Sine sinObj;
            answer1 = sinObj.sine(num1);
            break;
        case 'c':
            Cosine cosObj;
            answer1 = cosObj.cosine(num1);
            break;
        case 't':
            Tangent tanObj;
            answer1 = tanObj.tangent(num1);
            break;
        case 'S':
            Square sqObj;
            answer1 = sqObj.square(num1);
            break;
        case 'C':
            Cube cubeObj;
            answer1 = cubeObj.cube(num1);
            break;
        case 'p':
            Power powerObj;
            answer1 = powerObj.power(num1, num2);
            break;
        case 'r':
            SquareRoot sqrtObj;
            answer1 = sqrtObj.squareRoot(num1);
            break;
        case 'L':
            Logarithm logObj;
            answer1 = logObj.logarithm(num1);
            break;
            case '1': { // Solve Linear
            SolveLinear linearSolver;
            answer1 = linearSolver.solve(num1, num2);
            break;
        }
        case '2': { // Solve 2 Variables
            Solve2Variables twoVarSolver;
            twoVarSolver.solve(num1, num2, answer1, answer2, answer1, answer2); // Adjust accordingly
            break;
        }
        case '3': { // Solve 3 Variables
            Solve3Variables threeVarSolver;
            threeVarSolver.solve(num1, num2, answer1, answer2, answer1, answer2, answer1, answer2, answer1, answer2, answer1, answer2); // Adjust accordingly
            break;
        }
        case 'q': {
            QuadraticSolver quadSolverObj;
            tie(answer1, answer2) = quadSolverObj.solve(num1, num2, answer1); // For Quadratic Solver
            break;
        }
        case 'A': {
            CartesianToPolar cartesianToPolarObj;
            tie(answer1, answer2) = cartesianToPolarObj.convert(num1, num2); // For Cartesian to Polar Conversion
            break;
        }
        case 'B': {
            PolarToCartesian polarToCartesianObj;
            tie(answer1, answer2) = polarToCartesianObj.convert(num1, num2); // For Polar to Cartesian Conversion
            break;
        }
        case 'Z': {
            Permutation permObj;
            answer1 = permObj.permutation(static_cast<int>(num1), static_cast<int>(num2)); // For Permutation
            break;
        }
        case 'z': {
            Combination combObj;
            answer1 = combObj.combination(static_cast<int>(num1), static_cast<int>(num2)); // For Combination
            break;
        }

        case 1:
         MatrixOperations mo;
         int matrix1[2][2], matrix2[2][2], result[2][2];
            cout << "Matrix 1:" << endl;
            mo.inputMatrix(matrix1);
            cout << "Matrix 2:" << endl;
            mo.inputMatrix(matrix2);
            mo.addMatrices(matrix1, matrix2, result);
            cout << "Result of addition:" << endl;
            mo.displayMatrix(result);
            break;
        case 2:
        MatrixOperations mo;
        int matrix1[2][2],matrix2[2][2],result[2][2];
            cout << "Matrix 1:" << endl;
            mo.inputMatrix(matrix1);
            cout << "Matrix 2:" << endl;
            mo.inputMatrix(matrix2);
            mo.subtractMatrices(matrix1, matrix2, result);
            cout << "Result of subtraction:" << endl;
            mo.displayMatrix(result);
            break;
        case 3:
            cout << "Matrix 1:" << endl;
            mo.inputMatrix(matrix1);
            cout << "Matrix 2:" << endl;
            mo.inputMatrix(matrix2);
            mo.multiplyMatrices(matrix1, matrix2, result);
            cout << "Result of multiplication:" << endl;
            mo.displayMatrix(result);
            break;
        case 4:
            cout << "Matrix 1:" << endl;
            mo.inputMatrix(matrix1);
            int det;
            det = mo.determinant(matrix1);
            cout << "Determinant of Matrix 1: " << det << endl;
            break;

        case 'k': {
            clearScreen();
            // showCalculator();
            cout<<"\t\tTHANK YOU!!!"<<endl;
            cout << endl << "Press Enter to continue:";
            cin.ignore(); 
            cin.get();
            break;
        }

        case '.':
        break;
        exit(0);

        default:
        cout << "Invalid Operation!" << endl;
    }
    displayOutput(answer1, answer2);
}

void ScientificCalculator::run()
    { 
    showCalculator();
    while (true) {
        cout << "Enter operation: ";
        cin >> operation;
        if (operation == '.' ) {
            handleOperation(operation);
            continue;
        }
        if(operation=='k'){
            handleOperation(operation);
            continue;
        }
        cout << "Enter first number: ";
        cin >> num1;

        if (operation != 'L' && operation != 's' && operation != 'c' && operation != 't' && operation != 'S' && operation != 'C' && operation != 'r') {
            cout << "Enter second number: ";
            cin >> num2;
        }
        if (operation == '2') {
            cout <<"Enter additional values for 2-variable equation: ";
            cin >> answer1 >> answer2; // Placeholder for actual inputs
        } else if (operation == '3') {
            cout <<"Enter additional values for 3-variable equation: ";
            cin >> answer1 >> answer2 >> num2 >> num1; // Placeholder for actual inputs
        }


        handleOperation(operation);
    }
}

int main() {
    ScientificCalculator calculator;
    calculator.run();
    return 0;
}