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

void printVector(const vector<string>& v) {
    for (auto& i : v)
    {
        cout << i << " ";
    }
}

bool gtStrings(string first, string second) { 
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);      

    return first < second;
}

int main() {
    int q;
    cin >> q;

    vector<string> a(q);

    for (auto& i : a)
    {
        cin >> i;
    }

    sort(begin(a), end(a),
        // ���������� ��� ���������� � ������-�������, ������������ ������ ��� ����� ��������
        [](const string& l, const string& r) {
            // ���������� �����������������...
            return lexicographical_compare(
                // ... ��� ������� ������ l ...
                begin(l), end(l),
                // ... �� ����� ��������� ������ r ...
                begin(r), end(r),
                // ..., ��������� � �������� ����������� ��������� ��������� �������� ��� ����� ��������
                [](char cl, char cr) { return tolower(cl) < tolower(cr); }
            );
        }
    );

    printVector(a);

    return 0;
}