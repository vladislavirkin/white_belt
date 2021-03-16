//���������� ����� ��� ��������, �������������� ������� ��������� ��������� ����� ������� � �����.
//��������, ��� � ������ ��� ����� ��������� �� ����� ������ ��������� ������� � 
//�� ����� ������ ��������� �����.
//��� ���� � �������� ������� ����� ����������� ��� ����� ����� �� �������� ��������,
//������� ���� � ���������������� ������� �������� changeLastName && ChangeFirstName �� ������� ����������.
//�������������, ��� ��� ����� � ������� �������.
//������, ������������ ������� GetFullName, ������ ��������� ���������� ����� �������� ��� � ������� 
//�������� �� ��������� �� ����� ������� ����.
//���� � ������� ���� �� ��������� �� ������ ��������� ������� � �����, ������� ������ "Incognito".
//���� � ������� ���� ��������� ��������� �������, 
//�� �� ���� �� ������ ��������� �����, ������� "last_name with unknown first name".
//���� � ������� ���� ��������� ��������� �����, 
//�� �� ���� �� ������ ��������� �������, ������� "first_name with unknown last name".

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        string first_name = getLastChanged(year, first_names);
        string last_name = getLastChanged(year, last_names);
        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else {
            if (first_name.empty())
                return last_name + " with unknown first name";
            else {
                if (last_name.empty())
                    return first_name + " with unknown last name";
            }
        }

        return first_name + " " + last_name;
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;

    string getLastChanged(const int& year, map<int, string>& m) {
        string result;
        for (const auto& item : m) {
            if (item.first <= year)
                result = item.second;
            else
                break;
        }

        return result;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}