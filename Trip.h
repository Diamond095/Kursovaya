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
        char departure_point;
        char arrival_point;
        char start;
        char finish;
        Transport::Bus *bus;
        bool status;
        Workers::Driver* driver=nullptr;
    public:
        void SetDriver(Workers::Driver *driver);
        void SetBus(Transport::Bus *bus);
        Trip(char start, char finish, char departure, char arrival);
    };

} // Trip

#endif //КУРСОВАЯ_TRIP_H
