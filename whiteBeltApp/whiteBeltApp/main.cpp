#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrom(const string str)
{
    int size = str.size();
    for (int i = 0; i < size / 2 + 1; i++)
    {
        if (str[i] != str[size - 1 - i])
            return false;
    }

    return true;
}

int main() 
{
    string str;

    cin >> str;

    if (IsPalindrom(str))
        cout << "true";
    else
        cout << "false";

    return 0;
}