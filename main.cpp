#include <iostream>
#include "Transport/Bus.h"
#include "Persons/Workers/Manager.h"
#include "./Exceptions/FileException.h"
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
    cout << "******** Добро пожаловать в ИС транспортной компании! ***" << endl;
    cout << "********* 1. Завершить сеанс **************************" << endl;
    cout << "********* 2. Войти как менеджер ********************" << endl;
    cout << "********* 3. Купить билет на рейс *********************" << endl;
    cout << "******************************************************" << endl;
    cout << endl;
    cin>>choise;
    while(true) {
        switch (choise) {
            case 1:
                exit();
                break;
            case 2:
            {
                std::string fio;
                std::string password;
                int middlehousrOfWork;
                cout << "Введите имя фамилию отвечтво ваше" << endl;
                cin >> fio;
                cout << "Введите пароль для доступа к вашему аккаунту менеджера" << endl;
                cin >> password;
                if (Workers::Manager::checkPassword(fio, password)) {
                    try {
                        Workers::Manager *manager = new Workers::Manager(Workers::Manager::getFileWorkers(fio), fio,
                                                                         Workers::Manager::getDateOfBirth(fio),
                                                                         Workers::Manager::getMiddleHourWork(fio),
                                                                         password);
                        int choiseManager;
                        Workers::Manager::ShowMenu();
                        cin >> choiseManager;
                        manager->choiseInMenu(choiseManager);
                    }
                    catch (Exceptions::FileException *e) {
                        e->Message();
                    }
                }
        }
            case 3:
                std::string fio_person;
                std::string pol;
                std::string date_birth;
                int choice;
                cout<<"Введите имя фамилию и отчество";
                cin>> fio_person;
                cout<<"Введите пол";
                cin>> pol;
                cout<<"Ввведите дату рождения";
                cin>>date_birth;
                Persons::Person *person = new Persons::Person();
                person->SetPersonInfo(fio_person, date_birth, pol);
                Persons::Person::ShowMenu();
                cin >> choice;
                person->makeChoice(choice);

        }
    }
    return 0;
}
