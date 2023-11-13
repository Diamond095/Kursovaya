//
// Created by Ivan Basov on 16.09.23.
//

#include "Trip.h"
#include "Persons/Workers/Driver.h"
namespace Trip {
    void Trip::SetDriver(Workers::Driver *driver) {
        this->driver=driver;
    }
} // Trip