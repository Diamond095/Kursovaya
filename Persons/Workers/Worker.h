//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_WORKER_H
#define КУРСОВАЯ_WORKER_H
#include "../Person.h"
#include "fstream"
namespace Workers {

    class Worker{
    private:
        std::string fio;
        std::string date_of_birth;
        static const std::string requirementOfTypeEducation;
        static const std::string requirementOfExperience;
        const int middletimeWork;
    public:
       std::string getFio();
       std::string getDateOfBirth();
       int getmiddletimeWork();
       Worker(std::string fio,std::string date_of_birth, int middletimeWork);
    };

} // Workers

#endif //КУРСОВАЯ_WORKER_H
