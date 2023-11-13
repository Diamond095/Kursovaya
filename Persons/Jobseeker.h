

#ifndef КУРСОВАЯ_JOBSEEKER_H
#define КУРСОВАЯ_JOBSEEKER_H


#include "Person.h"
#include <iostream>

namespace Persons {

    class Jobseeker : public Person {
    private:
        std::string typeEducation;
        int expirience;
        bool typeEmployment;
        //1-полная занятось, 2-частичная
        std::string typeExpirience;
    public:
        void setInfoAboutJobSeeker(std::string typeEduc,int exp, bool typeEmpl, bool typeExpirience );


    };


} // Persons

#endif //КУРСОВАЯ_JOBSEEKER_H
