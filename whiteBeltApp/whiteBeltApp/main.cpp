//��� ����� ���������� ���������� ���� �����, ���� ��� ����� ������� ��������.
//���������� ��������� �������� ��� ������� ��������� :
//
//ADD word1 word2 � �������� � ������� ���� ���������(word1, word2).
//COUNT word � ������ ���������� ��������� ����� word.
//CHECK word1 word2 � ���������, �������� �� ����� word1 � word2 ����������.
//����� word1 � word2 ��������� ����������, ���� ����� �������� ADD ��� ���� �� ���� 
//������ ADD word1 word2 ��� ADD word2 word1.
//
//���������
//
//��� ���������, ����� �������, ��� �������� �� �������� ���������������, �� ����, 
//���� A - ������� B, � B - ������� C, �� �� ����� �� �������, ��� A - ������� C.
//
//������ �����
//
//������� �������� ���������� �������� Q, ����� Q ����� � ���������� ��������.
//�������������, ��� � ������ ������� CHECK � ADD ����� word1 � word2 ��������.
//��� ����� ������� ���� �� ��������� ����, ���� � �������� �������������.
//
//������ ������
//
//��� ������� ������� � ��������������� ������ �������� ����� �� ���� :
//
//� ����� �� ������ COUNT word �������� ������������ ����� ����� � ���������� ��������� ����� word.
//� ����� �� ������ CHECK word1 word2 �������� ������ YES, ���� word1 � word2 �������� ����������, 
//� NO � ��������� ������.

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, set<string>> words;       
    string cmd;        
    
    for (int i = 0; i < q; ++i) {        
        cin >> cmd;
        string word_1, word_2;

        if (cmd == "ADD") {                               
            cin >> word_1 >> word_2;

            words[word_1].insert(word_2);
            words[word_2].insert(word_1);
        }
        else {
            if (cmd == "COUNT") {                
                cin >> word_1;                                                          

                if (words.count(word_1) == 1)
                    cout << words[word_1].size() << endl;
                else
                    cout << 0 << endl;
            }
            else {
                if (cmd == "CHECK") {
                    cin >> word_1 >> word_2;          

                    bool flag = false;

                    if ((words.count(word_1) == 0) && (words.count(word_2) == 0)) {
                        cout << "NO" << endl;
                    }   
                    else {
                        if (words.count(word_1) == 1) {
                            flag = words[word_1].count(word_2) == 1;
                        }
                        else {
                            if (words.count(word_2) == 1) {
                                flag = words[word_2].count(word_1) == 1;
                            }
                        }

                        if (flag)
                            cout << "YES" << endl;
                        else
                            cout << "NO" << endl;
                    }                    
                }                
            }            
        }
    }

    return 0;
}