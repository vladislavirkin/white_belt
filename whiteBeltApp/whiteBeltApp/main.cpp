//В файле input.txt записаны вещественные числа, по одному на строчку.
//На стандартный вывод напечатайте эти числа в том же порядке, по одному на строке, 
//но сделайте так, чтобы у каждого из них было ровно три знака после десятичной точки.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    double number;    

    ifstream input("input.txt");    
    if (input) {
        cout << fixed << setprecision(3);
        while (input >> number) {
            cout << number << endl;
        }
    }
    
    return 0;
}