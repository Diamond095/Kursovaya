//
// Created by Ivan Basov on 16.09.23.
//

#include "Trip.h"
#include "Persons/Workers/Driver.h"
#include "./Exceptions/OpenFileException.h"
namespace Trip {
    void Trip::SetDriver(Workers::Driver *driver) {
        this->driver=driver;
    }
    Trip::Trip(char start, char finish, char departure, char arravial ,Workers::Driver *driver, Transport::Bus *bus) :
    start(start), finish(finish), departure_point(departure), arrival_point(arravial) {
        this->SetDriver(driver);
        this->SetBus(bus);
        std::ofstream file("/Users/ivanbsov/fileWithTrips.txt", std::ios::app);

        if (file.is_open()) {
            file << bus->getFile() << " " << start << " " << finish << " " << departure << " " << arravial;
            file.close();
        } else {
            throw Exceptions::OpenFileException(fileName);
        }
    };
    void Trip::SetBus(Transport::Bus *bus) {
        this->bus=bus;
    }
} // Trip