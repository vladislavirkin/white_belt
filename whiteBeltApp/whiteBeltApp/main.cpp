//����� ���������� ����������� ���� �����, ���� ���� �� ��� ����� �������� ������������� ���� � ������.
//��������, ����� �eat� ����� �������� ������������� ���� ����� �tea�, 
//������� ��� ����� �������� ����������� ���� �����.���� ���� ����, ��������� ��� ������ �� ���, 
//�������� �� ����� ���� ���� ����������� ���� �����.
//
//��������
//
//���� �� �������� �������� ����, �������� �� ����� ����������� ���� �����, ����������� � ���������.
//��� ������� ����� � ������� ������� ����������, ������� ��� � ��� ����������� ������ �����.
//���� ��� ����� ���� ��� ������� �����(� ��� ����������� � ������� �������� ��������� == ), 
//�� ����� �������� ����������� ���� �����, � ��������� ������ �� ��������.
//
//��� ���� ���������� ������ ������� �� ����� ������ ������� � ��������� ������� BuildCharCounters.
//������ �����
//
//������� ���� ����� ��� ���� N, ����� � N ������� ���������� ���� ����, ������� ���������� ���������.
//�������������, ��� ��� ����� ������� ���� �� �������� ��������� ����.
//������ ������
//
//�������� N ����� : ��� ������ �������� ���� ���� YES, ���� ��� ����� �������� �����������,
//� NO � ��������� ������.

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> buildCharCounters(const string& word) {
    map<char, int> result;
    for (const auto& ch : word) {
        ++result[ch];
    }
    return result;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) 
    {
        string first, second;
        cin >> first >> second;

        map<char, int> first_map, second_map;

        first_map = buildCharCounters(first);
        second_map = buildCharCounters(second);
 
        if (first_map == second_map)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}