//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_DRIVER_H
#define КУРСОВАЯ_DRIVER_H
#include "fstream"
#include "Worker.h"
namespace Workers {

    class Driver : public  Worker {
    private:
        bool status=0;
    public:
        Driver(char fio,char date_of_birth, int middletimeWork);
    };

} // Workers

#endif //КУРСОВАЯ_DRIVER_H
