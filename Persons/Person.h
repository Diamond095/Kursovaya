//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_PERSON_H
#define КУРСОВАЯ_PERSON_H
#include"fstream"

namespace Persons {

    class Person {
    protected:
        std::string fio;
        std::string date_of_birth;
        std::string pol;
        static std::string fileWithAllUsers;
    public:
        void SetPersonInfo(std::string fio,std::string date_of_birth,std::string pol);

        virtual void PersonInfo();
        static void ShowMenu();
        static std::string setAndGetfileWithUsers();
        void makeChoice(int choise);
        static void exit();
        void showAllTrip();
        void buyTicket(const std::string& start, const std::string& end, const std::string& startTime, int level, int row, int column);
    };
}
// Persons

#endif //КУРСОВАЯ_PERSON_H
