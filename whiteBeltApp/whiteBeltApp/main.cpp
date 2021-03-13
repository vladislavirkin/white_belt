#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> result;

    while (n > 0)
    {
        result.push_back(n % 2);
        n /= 2;        
    }

    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i];
    }

    return 0;
}