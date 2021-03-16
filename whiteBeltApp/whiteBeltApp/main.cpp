//Реализуйте класс ReversibleString, хранящий строку и 
//поддерживающий методы Reverse для переворота строки и ToString для получения строки.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString(){}
    ReversibleString(string aString) {
        line = aString;
    }
    void Reverse() {
        reverse(begin(line), end(line));
    }
    string ToString() const {
        return line;
    }
private:
    string line;
};


int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}