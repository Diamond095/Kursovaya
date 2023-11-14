//
// Created by Ivan Basov on 16.09.23.
//

#ifndef КУРСОВАЯ_BUS_H
#define КУРСОВАЯ_BUS_H
#include<fstream>

namespace Transport {

    class Bus {
    private:
       double fueltank;
       std::string model;
       int rows;
       int columns;
       int levels;
       std::string fileName;
    public:
       Bus(std::string fname, std::string model, double fueltank) ;
    };


} // Transport

#endif //КУРСОВАЯ_BUS_H
