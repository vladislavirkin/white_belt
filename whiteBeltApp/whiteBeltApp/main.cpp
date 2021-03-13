#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int counter = -2;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'f')
        {
            ++counter;
        }

        if (counter == 0)
        {
            cout << i;
            break;
        }            
    }   

    if (counter < 0)
    {
        cout << counter;
    }

    return 0;
}