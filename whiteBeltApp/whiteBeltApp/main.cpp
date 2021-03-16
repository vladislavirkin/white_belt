//Условие
//
//В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
//Между собой число и строки разделены пробелом.
//
//Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и 
//выведите их в стандартный поток вывода.
//
//Ограничения
//
//0 <= N <= 1000
//1 <= |S| <= 15
//
//Каждая строка S[i] может состоять из следующих символов : [0 - 9, a - z, A - Z]

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void printVector(const vector<string>& v) {
    for (auto& i : v)
    {
        cout << i << " ";
    }
}

bool gtStrings(string first, string second) { 
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);      

    return first < second;
}

int main() {
    int q;
    cin >> q;

    vector<string> a(q);

    for (auto& i : a)
    {
        cin >> i;
    }

    sort(begin(a), end(a),
        // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
        [](const string& l, const string& r) {
            // сравниваем лексикографически...
            return lexicographical_compare(
                // ... все символы строки l ...
                begin(l), end(l),
                // ... со всеми символами строки r ...
                begin(r), end(r),
                // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
                [](char cl, char cr) { return tolower(cl) < tolower(cr); }
            );
        }
    );

    printVector(a);

    return 0;
}