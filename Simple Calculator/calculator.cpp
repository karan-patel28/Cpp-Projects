// Author: Karan Patel
// Code: It is a simple calculator which you will see in any mobile or computer.
#include <iostream>

using namespace std;
// Fuction Declaration
int add(int a, int b);
int sub(int a, int b);
int division(int a, int b);
int multi(int a, int b);

int main() {
    cout << "Welcome to Simple Calculator Project!!!" << endl;
    cout << "You can exit by pressing any alphabet." << endl;

    int sum = 0;
    int num1 = 0, num2 = 0;
    string op = "";
    bool isFirstInteration = true;
    
    while (true)
    {
        if (isFirstInteration) {
            cout << "Enter First No:" << endl;
            // To check is inout is digit and if not we will break out from this loop
            if (!(cin >> num1)) {
                cin.clear();
                break;
            }
            cout << "Enter Second No:" << endl;
            cin >> num2;
            cout << "Enter Operation you want do (+ - for Additon | - for Subtraction | / - for Division | * - for Multiplicaiton):" << endl;
            cin >> op;
            isFirstInteration = false;
        } else {
            cout << "Enter No:" << endl;
            // This way sum keep adding like a real calculator
            num1 = sum;
            if (!(cin >> num2)) {
                cin.clear();
                break;
            }
            cout << "Enter Operation you want do (+ - for Additon | - for Subtraction | / - for Division | * - for Multiplicaiton):" << endl;
            cin >> op;
        }

        if (op == "+") {
            sum = add(num1, num2);
            cout << "You total is: " << sum << endl;
        } else if (op == "-") {
            sum = sub(num1, num2);
            cout << "You total is: " << sum << endl;
        } else if (op == "/") {
            if (num1 == 0 || num2 == 0) {
                cout << "Invalid values! Try again!" << endl;
            } else {
                sum = division(num1, num2);
            }
            cout << "You total is: " << sum << endl;
        } else if (op == "*") {
            sum = multi(num1, num2);
            cout << "You total is: " << sum << endl;
        }
    }
    cout << "You final total is: " << sum << endl;
    return sum;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int division(int a, int b) {
    return a / b;
}

int multi(int a, int b) {
    return a * b;
}