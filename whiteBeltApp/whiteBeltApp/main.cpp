//В этом задании вам предстоит написать две небольшие программы.Каждый пункт - отдельная задача, 
//решение отправляйте в поле с соответствующим номером.
//
//Часть 1
//
//Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
//Гарантируется, что содержимое файла input.txt заканчивается переводом строки.
//
//Часть 2
//
//Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt.
//Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    // part 1

    ifstream input("input.txt");    
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }

    //part 2

    /*ifstream input("input.txt");
    ofstream output("output.txt");
    if (input) {
        while (getline(input, line)) {
            output << line << endl;
        }
    }*/
    
    return 0;
}