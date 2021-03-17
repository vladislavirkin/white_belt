//ƒополните класс Person из задачи Ђ»мена и фамилии Ч 2ї конструктором, 
//позвол€ющим задать им€ и фамилию человека при рождении, а также сам год рождени€.
// ласс не должен иметь конструктора по умолчанию.
//
//ѕри получении на вход года, который меньше года рождени€ :
//
//методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
//методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
//
// роме того, необходимо объ€вить константными все методы, которые по сути ими €вл€ютс€.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
    int year) {
    vector<string> names;
    // перебираем всю историю в хронологическом пор€дке
    for (const auto& item : names_by_year) {
        // если очередное им€ не относитс€ к будущему и отличаетс€ от предыдущего,
        if (item.first <= year && (names.empty() || names.back() != item.second)) {
            // добавл€ем его в историю
            names.push_back(item.second);
        }
    }
    return names;
}

string BuildJoinedName(vector<string> names) {
    // нет истории Ч им€ неизвестно
    if (names.empty()) {
        return "";
    }
    // мен€ем пр€мой хронологический пор€док на обратный
    reverse(begin(names), end(names));

    // начинаем строить полное им€ с самого последнего
    string joined_name = names[0];

    // перебираем все последующие имена
    for (int i = 1; i < names.size(); ++i) {
        if (i == 1) {
            // если это первое Ђисторическоеї им€, отдел€ем его от последнего скобкой
            joined_name += " (";
        }
        else {
            // если это не первое им€, отдел€ем от предыдущего зап€той
            joined_name += ", ";
        }
        // и добавл€ем очередное им€
        joined_name += names[i];
    }

    // если в истории было больше одного имени, мы открывали скобку Ч закроем еЄ
    if (names.size() > 1) {
        joined_name += ")";
    }
    // им€ со всей историей готово
    return joined_name;
}

string BuildFullName(const string& first_name, const string& last_name) {
    if (first_name.empty() && last_name.empty()) {
        return "Incognito";
    }
    else if (first_name.empty()) {
        return last_name + " with unknown first name";
    }
    else if (last_name.empty()) {
        return first_name + " with unknown last name";
    }
    else {
        return first_name + " " + last_name;
    }
}

class Person {
public:
    Person (const string& first_name, const string& last_name, const int& birthday_year) {
        birthday = birthday_year;
        first_names[birthday] = first_name;
        last_names[birthday] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birthday)
            first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birthday)
            last_names[year] = last_name;
    }

    string GetFullName(int year) const {
        if (year < birthday)
            return "No person";

        const vector<string> first_names_history = FindFirstNamesHistory(year);
        const vector<string> last_names_history = FindLastNamesHistory(year);

        string first_name;
        string last_name;
        if (!first_names_history.empty()) {
            first_name = first_names_history.back();
        }
        if (!last_names_history.empty()) {
            last_name = last_names_history.back();
        }
        return BuildFullName(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) const {
        if (year < birthday)
            return "No person";

        const string first_name = BuildJoinedName(FindFirstNamesHistory(year));

        const string last_name = BuildJoinedName(FindLastNamesHistory(year));

        return BuildFullName(first_name, last_name);
    }

private:
    vector<string> FindFirstNamesHistory(int year) const {
        return FindNamesHistory(first_names, year);
    }
    vector<string> FindLastNamesHistory(int year) const {
        return FindNamesHistory(last_names, year);
    }

    int birthday;

    map<int, string> first_names;
    map<int, string> last_names;
};


int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}