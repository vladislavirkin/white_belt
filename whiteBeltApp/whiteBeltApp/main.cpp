

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printVector(const vector<int>& v) {
    for (auto& i : v)
    {
        cout << i << " ";
    }
}

bool gtByAbsoluteValue(int i, int j) { 
    return (abs(i) < abs(j)); 
}

int main() {
    int q;
    cin >> q;

    vector<int> a(q);

    for (auto& i : a)
    {
        cin >> i;
    }

    sort(begin(a), end(a), gtByAbsoluteValue);

    printVector(a);

    return 0;
}