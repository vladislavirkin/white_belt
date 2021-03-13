#include <iostream>
#include <vector>
#include <string>

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

vector<string> PalindromFilter(const vector<string> words, const int minLength)
{
    vector<string> result;
    for (auto str : words)
    {
        if (str.size() >= minLength)
        {
            if (IsPalindrom(str))
                result.push_back(str);
        }
    }

    return result;
}

int main() 
{
    vector<string> words;

    string str = " ";
    int minLength = 0;

    cin >> minLength;

    while (str != "exit")
    {
        cin >> str;
        words.push_back(str);
    }    

    words = PalindromFilter(words, minLength);

    for (int i = 0; i < words.size(); ++i)
        cout << words[i] << ", ";

    return 0;
}