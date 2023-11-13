//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_MANAGER_H
#define КУРСОВАЯ_MANAGER_H
#include "Worker.h"
#include "../Person.h"

#include"iostream"
namespace Workers {

    class Manager : public Worker{
    private:
       Persons::Person* drivers;
    public:
        void addDriver();
        void createTrip();
        void removeDriver();
        static void ShowMenu();
        Manager(std::string fname);
        static void choiseInMenu(int choise);
        static void exit();
    };

} // Workers

#endif //КУРСОВАЯ_MANAGER_H
