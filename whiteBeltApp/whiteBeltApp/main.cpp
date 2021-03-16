//ƒополните класс из предыдущей задачи Ђ»мена и фамилии Ч 1ї методом GetFullNameWithHistory
//¬ отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние им€ и фамилию 
//к концу данного года, но ещЄ и все предыдущие имена и фамилии в обратном хронологическом пор€дке.
//≈сли текущие факты говор€т о том, что человек два раза подр€д 
//изменил фамилию или им€ на одно и то же, второе изменение при формировании истории нужно игнорировать.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

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
    string GetFullNameWithHistory(int year){
        string first_name = getLastChangedWithHistory(year, first_names);
        string last_name = getLastChangedWithHistory(year, last_names);
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
    string getLastChangedWithHistory(const int& year, map<int, string>& m) {
        vector<string> history;        
        for (const auto& item : m) {
            if (item.first <= year)
                history.push_back(item.second);
            else
                break;
        }
        reverse(begin(history), end(history));  
        history = buildUniqueHistory(history);

        string result;

        if (history.size() > 0) {
            result = history[0];
            if (history.size() > 1) {                
                    result += " (" + history[1];
                if (history.size() > 2) {
                    for (int i = 2; i < history.size(); ++i) {                        
                            result += ", " + history[i];
                    }
                }
                result += ")";
            }
        }                  

        return result;
    }    

    vector<string> buildUniqueHistory(vector<string>& v) {
        vector<string> result;

        if (v.size() == 0)
            return v;

        result.push_back(v[0]);

        for (auto& item : v) {
            if (item != result.back())
                result.push_back(item);
        }

        return result;
    }
};

int main() {
    Person person;

    //first test

    /*person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;
    */
    
    //second test

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
  
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
  
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    

    //third test

    /*person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }*/

    return 0;
}