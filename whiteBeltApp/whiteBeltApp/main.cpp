//���������� ������� �������� ���������� ���������.��� ����� ������������ ��������� ������� :
//
//NEW_BUS bus stop_count stop1 stop2 ... � �������� ������� �������� � ��������� bus � stop_count 
//����������� � ���������� stop1, stop2, ...
//
//BUSES_FOR_STOP stop � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
//
//STOPS_FOR_BUS bus � ������� �������� ���� ��������� �������� bus �� ������� ���������, 
//�� ������� ����� ��������� �� ������ �� ���������.
//
//ALL_BUSES � ������� ������ ���� ��������� � �����������.
//
//������ �����
//
//� ������ ������ ����� ���������� ���������� �������� Q, ����� � Q ������� ������� �������� ��������.
//
//�������������, ��� ��� �������� ��������� � ��������� ������� ���� �� ��������� ����, ���� � ������ �������������.
//
//��� ������� ������� NEW_BUS bus stop_count stop1 stop2 ... �������������, ��� ������� bus �����������, 
//���������� ��������� ������ 0, � ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, 
//������ ��� �������� � ������ ������ ��������.
//������ ������
//
//��� ������� �������, ����� NEW_BUS, �������� ��������������� ����� �� ���� :
//
//�� ������ BUSES_FOR_STOP stop �������� ����� ������ ������ ���������, ����������� ����� ��� ���������, 
//� ��� �������, � ������� ��� ����������� ��������� NEW_BUS.���� ��������� stop �� ����������, �������� No stop.
//
//�� ������ STOPS_FOR_BUS bus �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, 
//� ������� ��� ���� ������ � ��������������� ������� NEW_BUS.
//�������� ������ ��������� stop ������ ����� ��� Stop stop : bus1 bus2 ..., ��� bus1 bus2 ... � 
//������ ���������, ����������� ����� ��������� stop, � �������, � ������� ��� ����������� ��������� NEW_BUS, 
//�� ����������� ��������� �������� bus.���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, 
//������ ������ ��������� ��� �� �������� no interchange.���� ������� bus �� ����������, �������� No bus.
//
//�� ������ ALL_BUSES �������� �������� ���� ��������� � ���������� �������.
//�������� ������� �������� bus ������ ����� ��� Bus bus : stop1 stop2 ..., ��� stop1 stop2 ... 
//� ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS.
//���� �������� �����������, �������� No buses.

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