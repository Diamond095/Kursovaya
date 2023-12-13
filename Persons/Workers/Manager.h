//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_MANAGER_H
#define КУРСОВАЯ_MANAGER_H
#include "Worker.h"
#include "../Person.h"
#include "../../Transport/Bus.h"
#include "Driver.h"
#include"iostream"
#include "fstream"

namespace Workers {

    class Manager : public Worker{
    private:
       std::string fname;
       std::string const fileWithTrip="/Users/ivanbasov/fileWithTrips.txt";
       static std::string  fileWithManagers;
    public:
         void addDriver();
         void createTrip();
        void removeDriver();
        static void ShowMenu();
        Manager(std::string fname,std::string fio, std::string date_of_birth, int middletimeWork, std::string password);
        void choiseInMenu(int choise);
        void showAllDrivers();
        void showAllUsers();
        static void exit();
        void showInfoAboutUsers(int id);
        void addNewTrip();
        static bool checkPassword(std:: string fio, std::string password);
        static std::string SetAndGetFileWithManagers();
        static std::string getDateOfBirth(std::string fio);
        static int getMiddleHourWork(std::string fio);
        static std::string getFileWorkers(std::string fio);
        void setNewBus();
        Driver* findDriverByName(std::string driverName);
        Transport::Bus* findBusByModel(std::string modalName);
    };

} // Workers

#endif //КУРСОВАЯ_MANAGER_H
