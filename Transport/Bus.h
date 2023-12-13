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
       std::string fname;
       static std::string fileOfBus;
    public:
       Bus(std::string fname, std::string model, double fueltank, int rows, int columns,int levels) ;
       static std::string SetAndGetFileWithBuses();
       std::string getFile();
    };


} // Transport

#endif //КУРСОВАЯ_BUS_H
