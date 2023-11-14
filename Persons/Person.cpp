//
// Created by Ivan Basov on 16.09.23.
//

#include "Person.h"
#include "iostream"

namespace Persons {

    void Person::SetPersonInfo(std::string fio, std::string date_of_birth,std::string pol) {
        this->fio=fio;
        this->date_of_birth=date_of_birth;
        this->pol=pol;
    }

    void Person::PersonInfo(){
        std::cout << "ФИО: " << fio << std::endl;
        std::cout << "Дата рождения: " << date_of_birth << std::endl;
        std::cout << "Пол: " << pol << std::endl;
   }

    std::string Person::setAndGetfileWithUsers() {
        Person::fileWithAllUsers="/Users/ivanbasov/users.txt";
        return Person::fileWithAllUsers;
    }
} // Persons