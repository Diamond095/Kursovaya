//
// Created by Ivan Basov on 16.09.23.
//

#include "Person.h"
#include "iostream"

namespace Persons {
    using namespace std;

    void Person::SetPersonInfo(std::string fio, std::string date_of_birth,std::string pol) {
        this->fio=fio;
        this->date_of_birth=date_of_birth;
        this->pol=pol;
    }

   // void Person::PersonInfo(){
       // cout << "ФИО: " << fio << endl;
        //cout << "Дата рождения: " << date_of_birth << endl;
       // cout << "Пол: " << pol << endl;
   // }
    void Person::setNewPeople(Person *newPeople){
        next=newPeople;
    }
    Person* Person::getPerson(){
        return this->next;
    }
} // Persons