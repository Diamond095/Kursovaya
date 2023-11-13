#include <iostream>
#include "Transport/Bus.h"
#include "Persons/Workers/Manager.h"
using namespace Transport;
using namespace std;

void exit(){
        setlocale(LC_ALL, "rus");
        cout << "Возвращайтесь снова!" << endl;
        system("pause");
        exit(0);
    }

int main() {
    int choise;
    cout << "******************************************************" << endl;
    cout << "******** Добро пожаловать в ИС транспортной компании! ********" << endl;
    cout << "********* 1. Завершить сеанс **************************" << endl;
    cout << "********* 2. Войти как менеджер ********************" << endl;
    cout << "********* 3. Купить билет на рейс *******" << endl;
    cout << "********* 4. Устроиться на работу **********************" << endl;
    cout << "******************************************************" << endl;
    cout << endl;
    cin>>choise;
    while(true) {
        switch (choise) {
            case 1:
                exit();
            case 2:



        }
    }
    std::string name = "Юки";
    std::string file="text.txt";
    Bus *bus=new Bus(file, name, 10);
    Workers::Manager *manager= new Workers::Manager("employers");
    return 0;
}
