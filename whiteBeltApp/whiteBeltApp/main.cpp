//���������� ��������� �������� �� ���������� ������ : ���, �������, ����, ����� � ��� ��������.�������� ������ �� ����� ��������, ��������� ��� �� ������� ������ � ����� �� �������� �������� ������ ����.������ � ������ ������ � ���� ������ ������������ � �������������� ����������� �������.
//
//������ �����
//
//������ ������ �������� ���� ����� ����� N �� 0 �� 10000 � ����� ���������.
//
//����� ���� N �����, ������ �� ������� �������� ��� ������ ������ �� 1 �� 15 �������� � 
//��� � ������� ���������� ��������, � ��� ����� ����� �� 0 �� 1000000000 � ����, ����� � ��� ��������.
//
//��������� ������ �������� ���� ����� ����� M �� 0 �� 10000 � ����� ��������.
//
//��������� M ����� �������� ������ ������ �� 1 �� 15 �������� � ������, 
//� ����� ����� �� 1 �� 1000000000 � ����� ��������(��������� ���������� � 1).
//
//������ ������
//
//��� ������� ���� name K, ��� K �� 1 �� N, �������� ����� ������ ��� � ������� K - �� ��������.
//
//��� ������� ���� date K, ��� K �� 1 �� N, �������� ����� ����� ����, ����� � 
//��� �������� K - �� ��������.
//
//��� ��������� �������� �������� bad request.
//
//NB: �������� ������� ����� �������� �� �������, ��������� ��� ������.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

struct Student {
    string first_name;
    string last_name;

    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;

    string first_name, last_name;
    int day, month, year;
    vector<Student> students;

    for (size_t i = 0; i < n; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;

        students.push_back(Student{
          first_name,
          last_name,
          day,
          month,
          year
            });
    }

    int m;
    cin >> m;
    string query;
    int student_number;

    for (int i = 0; i < m; ++i) {
        cin >> query >> student_number;
        --student_number;

        if (query == "name" && student_number >= 0 && student_number < n) {
            cout << students[student_number].first_name << " "
                << students[student_number].last_name << endl;
        }
        else if (query == "date" && student_number >= 0 && student_number < n) {
            cout << students[student_number].day << "."
                << students[student_number].month << "."
                << students[student_number].year << endl;
        }
        else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}