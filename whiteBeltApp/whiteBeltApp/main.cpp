//� ���� ������� ��� ��������� �������� ��� ��������� ���������.������ ����� - ��������� ������, 
//������� ����������� � ���� � ��������������� �������.
//
//����� 1
//
//���� ��������� ������ ������� ���������� ����� input.txt � ���������� ��� �� ����� ��� ���������.
//�������������, ��� ���������� ����� input.txt ������������� ��������� ������.
//
//����� 2
//
//����� �������� ��� ���������� ����� input.txt, �� �� ���� ��� �������� ��� � ���� output.txt.
//����� ��� �� �������������, ��� ���������� ����� input.txt ������������� ��������� ������.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    // part 1

    ifstream input("input.txt");    
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }

    //part 2

    /*ifstream input("input.txt");
    ofstream output("output.txt");
    if (input) {
        while (getline(input, line)) {
            output << line << endl;
        }
    }*/
    
    return 0;
}