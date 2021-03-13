// Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, 
// в которой числа переставлены в обратном порядке.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed(const vector<int>& numbers)
{
    int tmp;
    vector<int> result;

    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        result.push_back(numbers[i]);       
    }

    return result;
}

int main() 
{
    vector<int> numbers = { 1, 2, 3, 4 , 5, 6 };

    numbers = Reversed(numbers);

    for (auto number : numbers)
        cout << number;

    return 0;
}