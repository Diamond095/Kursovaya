//
// Created by Ivan Basov on 16.09.23.
//

#include "Jobseeker.h"
#include "iostream"
#include "fstream"
using namespace std;

namespace Persons {
  void Jobseeker::setInfoAboutJobSeeker(std::string typeEduc, int exp,bool typeEmpl, bool typeExpirience) {
      this->typeEducation=typeEduc;
     this->expirience=exp;
      this->typeEmployment=typeEmpl;
     this->typeExpirience=typeExpirience;
  }

} // Persons