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