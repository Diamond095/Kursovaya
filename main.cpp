#include <iostream>
#include "Transport/Bus.h"
#include "Persons/Workers/Manager.h"
using namespace Transport;
using namespace std;

void exit(){
        cout << "Возвращайтесь снова!" << endl;
        system("pause");
        exit(0);
    }

int main() {
    setlocale(LC_ALL, "russian");
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
                std::string fio;
                std::string password;
                int middlehousrOfWork;
                cout<<"Введите имя фамилию отвечтво ваше"<< endl;
                cin>>fio;
                cout<<"Введите пароль для доступа к вашему аккаунту менеджера"<< endl;
                cin>> password;
                if(Workers::Manager::checkPassword(fio, password)){
                    cout<<"Введите среднее время работы менеджера менеджера"<< endl;
                    cin >> middlehousrOfWork;
                    Workers::Manager *manager=new Workers::Manager(Workers::Manager::getFileWorkers(fio), fio, Workers::Manager::getDateOfBirth(fio),Workers::Manager::getMiddleHourWork(fio),password);
                    int choiseManager;
                    cin >> choiseManager;
                    manager->choiseInMenu(choiseManager);
                }
        }
    }
    return 0;
}
