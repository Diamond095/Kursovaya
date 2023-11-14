//
// Created by Ivan Basov on 16.09.23.
//

#include "Trip.h"
#include "Persons/Workers/Driver.h"
namespace Trip {
    void Trip::SetDriver(Workers::Driver *driver) {
        this->driver=driver;
    }
    Trip::Trip(char start, char finish, char departure, char arravial) :
    start(start), finish(finish), departure_point(departure), arrival_point(arravial) {};

    void Trip::SetBus(Transport::Bus *bus) {
        this->bus=bus;
    }
} // Trip