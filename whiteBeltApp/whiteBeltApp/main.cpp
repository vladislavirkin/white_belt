//�������
//
//� ����������� ������ ���� ���� ������, ��������� �� ����� N � ��������� �� ��� N ����� S.
//����� ����� ����� � ������ ��������� ��������.
//
//������������ ������ S � ������������������ ������� �� �����������, ��������� ������� ����, � 
//�������� �� � ����������� ����� ������.
//
//�����������
//
//0 <= N <= 1000
//1 <= |S| <= 15
//
//������ ������ S[i] ����� �������� �� ��������� �������� : [0 - 9, a - z, A - Z]

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void printVector(const vector<char>& v) {
    for (auto& i : v)
    {
        cout << i << " ";
    }
}

bool gtStrings(const char& i, const char& j) { 
    return (tolower(i) < tolower(j)); 
}

int main() {
    int q;
    cin >> q;

    vector<char> a(q);

    for (auto& i : a)
    {
        cin >> i;
    }

    sort(begin(a), end(a), gtStrings);

    printVector(a);

    return 0;
}