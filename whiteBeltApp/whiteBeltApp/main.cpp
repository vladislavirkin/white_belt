//Дан набор строк.Найдите количество уникальных строк в этом наборе.
//
//Формат ввода
//
//Сначала вводится количество строк N, затем — сами N строк, разделённые символом перевода строки.
//Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода
//
//Выведите единственное целое число — количество уникальных строк в данном наборе.

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;

    for (const auto& item : m) {
        result.insert(item.second);
    }

    return result;
}

int main() {
    map<int, string> m;
    typedef pair<int, string> intStringPair;

    m.insert(intStringPair(1, "odd"));
    m.insert(intStringPair(2, "even"));
    m.insert(intStringPair(3, "odd"));
    m.insert(intStringPair(4, "even"));
    m.insert(intStringPair(5, "odd"));

    set<string> values = BuildMapValuesSet(m);

    for (const string& line : values) {
        cout << line << endl;
    }

    return 0;
}