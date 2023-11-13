//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_WORKER_H
#define КУРСОВАЯ_WORKER_H
#include "../Person.h"
namespace Workers {

    class Worker : public Persons::Person{
    private:
        int salary;
        static const char requirmentOfTypeEducation[20];
        static const int requiremnetOfExpirience;
        static const int timeWork;
    };

} // Workers

#endif //КУРСОВАЯ_WORKER_H
