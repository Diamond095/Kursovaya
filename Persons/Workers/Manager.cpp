//
// Created by Ivan Basov on 16.09.23.
//

#include "Manager.h"
#include "../Person.h"
#include "iostream"
#include "fstream"
using namespace std;
namespace Workers {
    Manager::Manager(std::string fname) {
        std::string path = "/Users/ivanbasov/" + fname;
        std::ofstream file(path);

        if (file) {
            std::cout << "Файл успешно создан: " << path << std::endl;
        } else {
            std::cerr << "Ошибка: Невозможно создать файл!" << std::endl;
        }

        file.close();
    }
    void Manager::addDriver() {
        }
        void Manager::ShowMenu() {
            cout << "******************************************************" << endl;
            cout << "******** Здраствуйте, ! ********" << endl;
            cout << "********* 1. Завершить сеанс**************************" << endl;
            cout << "********* 2. Добавить нового водителя ********************" << endl;
            cout << "********* 3. Вывести полный список водителей *******" << endl;
            cout << "********* 4. Уволить водителя **********************" << endl;
            cout << "********* 5. Вывести информацию о всех пользователей *********" << endl;
            cout << "********* 6. Добавить новый *********" << endl;
            cout << "******************************************************" << endl;
            cout << endl;

    }
    void Manager::exit(){
            setlocale(LC_ALL, "rus");
            cout << "Возвращайтесь снова!" << endl;
            system("pause");
            ::exit(0);

    }
    void Manager::choiseInMenu(int choise) {
        switch(choise){
            case 1:
                Manager::exit();
            case 2:
                std::string fio;
                cout<<"Введите имя фамилию отчество водителя";
                cin>>fio;
                
                Manager::addDriver();


        }
    }


};


 // Workers