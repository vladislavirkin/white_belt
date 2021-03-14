//���������� ���������� ������ �����.
//
//�� ���� ��������� ��������� ��������� ������� :
//
//CHANGE_CAPITAL country new_capital � 
//��������� ������� ������ country �� new_capital, ���� ���������� ����� ������ � ����� ��������, 
//���� ������ � �� ����.
//RENAME old_country_name new_country_name � �������������� ������ �� old_country_name � new_country_name.
//ABOUT country � ����� ������� ������ country.
//DUMP � ����� ������ ���� �����.
//
//������ �����
//
//� ������ ������ ���������� ���������� �������� Q, � ��������� Q ������� � �������� ��������.
//��� �������� ����� � ������ ������� ���� �� ��������� ����, ���� � �������� �������������.
//������ ������
//
//�������� ��������� ��������� ������� ������� :
//� ����� �� ������ CHANGE_CAPITAL country new_capital ��������
//
//Introduce new country country with capital new_capital, ���� ������ country ������ �� ������������;
//Country country hasn't changed its capital, ���� ������ country �� �������� ������� ����� ������� new_capital;
//Country country has changed its capital from old_capital to new_capital, ���� ������ country �� 
//�������� ������� ����� ������� old_capital, �������� ������� �� ��������� � ��������� new_capital.
//
//� ����� �� ������ RENAME old_country_name new_country_name ��������
//
//Incorrect rename, skip, ���� ����� �������� ������ ��������� �� ������, ������ old_country_name 
//�� ���������� ��� ������ new_country_name ��� ����������;
//Country old_country_name with capital capital has been renamed to new_country_name, ���� ������ ��������� 
//� ������ ����� ������� capital.
//
//� ����� �� ������ ABOUT country ��������
//
//Country country doesn't exist, ���� ������ � ��������� country �� ����������;
//Country country has capital capital, ���� ������ country ���������� � ����� ������� capital.
//
//� ����� �� ������ DUMP ��������
//
//There are no countries in the world, ���� ���� �� ���� ��������� �� ����� ������;
//������������������ ��� ���� country / capital, ����������� ������� ���� �����, 
//���� � ���� ��� ���� ���� �� ���� ������.��� ������ ������������������ ���� ���������� ���� ���������� ����������� 
//�� �������� ������ � ��������� ����� ����� ��������.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> buildCharCounters(const string& word) {
    map<char, int> result;
    for (const auto& ch : word) {
        ++result[ch];
    }
    return result;
}

void printMap(const map<string, string>& m) {
    for (auto& item : m) {
        cout << item.first << " " << item.second << endl;
    }
}

int main() {
    int q;
    cin >> q;

    map<string, string> countries;

    for (int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "DUMP") {                   
            if (countries.size() == 0) {                
                cout << "There are no countries in the world" << endl;                
            }
            else {
                printMap(countries);
            }
        }
        else {
            if (cmd == "ADD") {
                int day;
                cin >> day;
                day -= 1;               

                string task;
                cin >> task;

                if (day < tasks.size())
                    tasks[day].push_back(task);
            }
            else if (cmd == "NEXT") 
            {
                int current_count = day_in_months[current_month];
                current_month++;
                if (current_month >= 12)
                    current_month %= 12;

                int next_count = day_in_months[current_month];                
                
                if (current_count > next_count)
                {                    
                    for (int i = next_count; i < current_count; i++)
                    {
                        tasks[next_count - 1].insert(end(tasks[next_count-1]), begin(tasks[i]), end(tasks[i]));
                    }                    
                }    
                tasks.resize(next_count);
            }
        }
    }

    return 0;
}