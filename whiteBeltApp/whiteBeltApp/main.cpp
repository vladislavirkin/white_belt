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
    for (const auto& item : m) {
        cout << item.first << "/" << item.second << " ";
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;

    map<string, string> countries;
    string country, capital;
    string cmd;

    for (int i = 0; i < q; ++i) {        
        cin >> cmd;

        if (cmd == "DUMP") {                   
            if (countries.empty()) {                
                cout << "There are no countries in the world" << endl;                
            }
            else {
                printMap(countries);
            }
        }
        else {
            if (cmd == "ABOUT") {                
                cin >> country;                                          

                if (countries.count(country) == 1)
                    cout << "Country " << country << " has capital " << countries[country] << endl;                    
                else
                    cout << "Country " << country << " doesn't exist" << endl;
            }
            else {
                if (cmd == "CHANGE_CAPITAL") {
                    cin >> country >> capital;

                    if (countries.count(country) == 0) {
                        cout << "Introduce new country " << country << " with capital " << capital << endl;
                        countries[country] = capital;
                    }
                    else {
                        if (countries[country] == capital) {
                            cout << "Country " << country << " hasn't changed its capital" << endl;
                        }
                        else {
                            cout << "Country " << country << " has changed its capital from "
                                << countries[country] << " to " << capital << endl;
                            countries[country] = capital;
                        }
                    }
                }
                else {
                    if (cmd == "RENAME") {
                        string old_name, new_name;
                        cin >> old_name >> new_name;

                        if (old_name == new_name || (countries.count(new_name) == 1) ||
                            (countries.count(old_name) == 0)) {
                            cout << "Incorrect rename, skip" << endl;
                        }
                        else {
                            cout << "Country " << old_name << " with capital "
                                << countries[old_name] << " has been renamed to " << new_name << endl;
                            countries[new_name] = countries[old_name];
                            countries.erase(old_name);
                        }
                    }
                }
            }
            
        }
    }

    return 0;
}