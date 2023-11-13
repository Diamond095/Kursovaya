//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_TRIP_H
#define КУРСОВАЯ_TRIP_H

#include "ctime"
#include "Transport/Bus.h"
#include "Persons/Workers/Driver.h"


namespace Trip {

    class Trip {
    private:
        char departure_point[20];
        char arrival_point[20];
        time_t start;
        time_t finish;
        Transport::Bus *bus;
        bool status;
        Workers::Driver* driver=nullptr;
    public:
        void SetDriver(Workers::Driver *driver);
    };

} // Trip

#endif //КУРСОВАЯ_TRIP_H
