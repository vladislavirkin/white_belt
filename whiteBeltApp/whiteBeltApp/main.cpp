#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

struct Day {
    int value;
    Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    Month(int new_value) {
        value = new_value;
    }
};

struct Year {
    int value;
    Year(int new_value) {
        value = new_value;
    }
};

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(Year new_year, Month new_month, Day new_day) {
        year = new_year.value;
        month = new_month.value;
        day = new_day.value;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {

    return 0;
}

istream& operator>>(istream & stream, Date& date) {
    int year, month, day;

    stream >> year;
    stream.ignore(1);
    stream >> month;
    stream.ignore(1);
    stream >> day;
    
    date = { year, month, day };

    return stream;
}

ostream& operator<<(ostream& stream, Date& date) {
    stream << date.GetYear() << "-" << setw(2) << setfill('0') << 
        date.GetMonth() << "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {

    }
    bool DeleteEvent(const Date& date, const string& event) {

        return 0;
    }
    int  DeleteDate(const Date& date) {

        return 0;
    }

    vector<string> Find(const Date& date) const {
        vector<string> result;

        return result;
    }
  
    void Print() const {

    }
private:
    map<Date, set<string>> history;
};

int main() {
    Database db;
    
    string command;
    while (getline(cin, command)) {
        try {
            if (command == "PRINT") {
                db.Print();
            }
            else {
                Date date;
                cin >> date;

                if (cin.peek() == '\n') {
                    if (command == "DEL") {
                        cout << date;
                        db.DeleteDate(date);
                    }
                }
                else {
                    string event;
                    cin >> event;
                    if (command == "ADD") {
                        db.AddEvent(date, event);
                    }
                    if (command == "FIND") {
                        db.Find(date);
                    }
                    if (command == "DEL") {
                        db.DeleteEvent(date, event);
                    }
                }
            }
        }
        catch (const std::exception&) {

        }
                   
    }

return 0;
}