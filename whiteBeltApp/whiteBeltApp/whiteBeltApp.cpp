#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, c;

    cin >> a >> b >> c;

    if (a < b && a < c)
    {
        cout << a;
    }
    else if (b < c && b < a)
    {
        cout << b;
    }
    else cout << c;
       
    return 0;
}