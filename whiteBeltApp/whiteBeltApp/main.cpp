//–еализуйте справочник столиц стран.
//
//Ќа вход программе поступают следующие запросы :
//
//CHANGE_CAPITAL country new_capital Ч 
//изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, 
//если раньше еЄ не было.
//RENAME old_country_name new_country_name Ч переименование страны из old_country_name в new_country_name.
//ABOUT country Ч вывод столицы страны country.
//DUMP Ч вывод столиц всех стран.
//
//‘ормат ввода
//
//¬ первой строке содержитс€ количество запросов Q, в следующих Q строках Ч описани€ запросов.
//¬се названи€ стран и столиц состо€т лишь из латинских букв, цифр и символов подчЄркивани€.
//‘ормат вывода
//
//¬ыведите результат обработки каждого запроса :
//¬ ответ на запрос CHANGE_CAPITAL country new_capital выведите
//
//Introduce new country country with capital new_capital, если страны country раньше не существовало;
//Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
//Country country has changed its capital from old_capital to new_capital, если страна country до 
//текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
//
//¬ ответ на запрос RENAME old_country_name new_country_name выведите
//
//Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name 
//не существует или страна new_country_name уже существует;
//Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен 
//и страна имеет столицу capital.
//
//¬ ответ на запрос ABOUT country выведите
//
//Country country doesn't exist, если страны с названием country не существует;
//Country country has capital capital, если страна country существует и имеет столицу capital.
//
//¬ ответ на запрос DUMP выведите
//
//There are no countries in the world, если пока не было добавлено ни одной страны;
//последовательность пар вида country / capital, описывающую столицы всех стран, 
//если в мире уже есть хот€ бы одна страна.ѕри выводе последовательности пары указанного вида необходимо упор€дочить 
//по названию страны и раздел€ть между собой пробелом.

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