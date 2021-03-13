// Реализуйте функцию void Reverse(vector<int>& v), 
// которая переставляет элементы вектора в обратном порядке.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Reverse(vector<int>& numbers)
{
    int tmp;
    for (int i = 0; i < numbers.size() / 2; ++i)
    {
        tmp = numbers[i];
        numbers[i] = numbers[numbers.size() - 1 - i];
        numbers[numbers.size() - 1 - i] = tmp;
    }    
}

int main() 
{
    vector<int> numbers = { 1, 2, 3, 4 , 5, 6 };

    Reverse(numbers);

    for (auto number : numbers)
        cout << number;

    return 0;
}