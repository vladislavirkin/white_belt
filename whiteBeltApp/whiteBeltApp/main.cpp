#include <iostream>
#include <vector>

using namespace std;

int Factorial(const int number)
{
    if (number < 0)
    {
        return 1;
    }

    int fact = 1;

    for (size_t i = 1; i <= number; i++)
    {
        fact *= i;
    }

    return fact;
}

int main() 
{
    int n;

    cin >> n;

    cout << Factorial(n);

    return 0;
}