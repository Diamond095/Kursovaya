//
// Created by Ivan Basov on 16.09.23.
//

#include "Worker.h"
#include "iostream"
#include "fstream"
namespace Workers  {
    Worker::Worker(std::string fio,std::string date_of_birth, int middletimeWork) : fio(fio), date_of_birth(date_of_birth), middletimeWork(middletimeWork)
    {};
    std::string Worker::getDateOfBirth() {
        return this->date_of_birth;
    }
    std::string Worker::getFio(){
        return this->fio;
    }
    int Worker::getmiddletimeWork() {
        return this->middletimeWork;
    }
} // Workers