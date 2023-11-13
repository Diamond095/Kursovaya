//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_BUS_H
#define КУРСОВАЯ_BUS_H
#include<fstream>

namespace Transport {

    class Bus {
    protected:
       double fueltank;
       std::string model;
       const int rows=4;
       const  int columns=9;
       const int levels=1;
       std::string fileName;
    public:
       Bus(std::string fname, std::string model, double fueltank) ;
    };


} // Transport

#endif //КУРСОВАЯ_BUS_H
