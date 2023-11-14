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

        static std::string setAndGetfileWithUsers();
    };
}
// Persons

#endif //КУРСОВАЯ_PERSON_H
