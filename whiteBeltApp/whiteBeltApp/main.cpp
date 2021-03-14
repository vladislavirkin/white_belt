//Реализуйте систему хранения автобусных маршрутов.Вам нужно обрабатывать следующие запросы :
//
//NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count 
//остановками с названиями stop1, stop2, ...
//
//BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
//
//STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, 
//на которые можно пересесть на каждой из остановок.
//
//ALL_BUSES — вывести список всех маршрутов с остановками.
//
//Формат ввода
//
//В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.
//
//Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.
//
//Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, 
//количество остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, 
//причём все названия в каждом списке различны.
//Формат вывода
//
//Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него :
//
//На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, 
//в том порядке, в котором они создавались командами NEW_BUS.Если остановка stop не существует, выведите No stop.
//
//На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, 
//в котором они были заданы в соответствующей команде NEW_BUS.
//Описание каждой остановки stop должно иметь вид Stop stop : bus1 bus2 ..., где bus1 bus2 ... — 
//список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, 
//за исключением исходного маршрута bus.Если через остановку stop не проезжает ни один автобус, кроме bus, 
//вместо списка автобусов для неё выведите no interchange.Если маршрут bus не существует, выведите No bus.
//
//На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
//Описание каждого маршрута bus должно иметь вид Bus bus : stop1 stop2 ..., где stop1 stop2 ... 
//— список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS.
//Если автобусы отсутствуют, выведите No buses.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printMap(const map<string, vector<string>>& m, const string& title = "", const string& check = "") {
    for (const auto& item : m) {
        if (title != "")
            cout << title << " " << item.first << ": ";

        if (check != "") {
            bool flag = false;
            for (const auto& el : item.second) {
                if (el != check) {
                    flag = true;
                    cout << el << " ";
                }             
                if (!flag) {
                    cout << "no interchange";
                }
            }
        }
        else {
            for (const auto& el : item.second) {
                cout << el << " ";
            }
        }        
    }
    cout << endl;
}

map<string, vector<string>> buildReversedMap(const map<string, vector<string>>& m) {
    map<string, vector<string>> result;

    for (const auto& item : m) {
        for (const auto& stop : item.second) {            
            result[stop].push_back(item.first);
        }        
    }

    return result;
}

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> buses;    
    map<string, vector<string>> stops;
    string cmd;    
    string bus;
    int stop_count;
    string stop;

    for (int i = 0; i < q; ++i) {        
        cin >> cmd;

        if (cmd == "ALL_BUSES") {                   
            if (!buses.empty()) {                
                printMap(buses, "bus");
            }    
            else {
                cout << "No buses" << endl;
            }
        }
        else {
            if (cmd == "BUSES_FOR_STOP") {                
                cin >> stop;                                                          

                if (stops.count(stop) == 1)
                    printMap(stops);
                else
                    cout << "No stop" << endl;
            }
            else {
                if (cmd == "NEW_BUS") {
                    cin >> bus >> stop_count;

                    if (buses.count(bus) != 0) {
                        for (int i = 0; i < stop_count; ++i) {
                            cin >> stop;
                            buses[bus].push_back(stop);
                        }                        
                    }                    
                    stops.clear();
                    stops = buildReversedMap(buses);
                }
                else {
                    if (cmd == "STOPS_FOR_BUS") {
                        cin >> bus;

                        if (buses.count(bus) == 0) {
                            cout << "No bus" << endl;
                        }
                        else {                            
                            printMap(stops, "Stop", bus);
                        }
                    }
                }
            }
            
        }
    }

    return 0;
}