//� ����� input.txt �������� ������������ �����, �� ������ �� �������.
//�� ����������� ����� ����������� ��� ����� � ��� �� �������, �� ������ �� ������, 
//�� �������� ���, ����� � ������� �� ��� ���� ����� ��� ����� ����� ���������� �����.

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