//Два слова называются синонимами друг друга, если они имеют похожие значения.
//Реализуйте следующие операции над словарём синонимов :
//
//ADD word1 word2 — добавить в словарь пару синонимов(word1, word2).
//COUNT word — узнать количество синонимов слова word.
//CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
//Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один 
//запрос ADD word1 word2 или ADD word2 word1.
//
//Замечание
//
//Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, 
//если A - синоним B, а B - синоним C, то из этого НЕ следует, что A - синоним C.
//
//Формат ввода
//
//Сначала вводится количество запросов Q, затем Q строк с описаниями запросов.
//Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны.
//Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода
//
//Для каждого запроса в соответствующей строке выведите ответ на него :
//
//В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
//В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, 
//и NO в противном случае.

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