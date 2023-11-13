//
// Created by Ivan Basov on 16.09.23.
//
#include "fstream"
#include "Bus.h"
#include "../Exceptions/OpenFileException.h"

namespace Transport {

   Bus::Bus(std::string fname, std::string model, double fueltank) :
   fueltank(fueltank), model(model){
    std::ifstream file1("/Users/ivanbasov/"+ fname);
    std::ofstream fileToChange("/Users/ivanbasov/"+fname);
       if (fileToChange.is_open()) {
           // Создаем двумерный массив и заполняем его нулями
           int array[rows][columns];
           for (int i = 0; i < rows; i++) {
               for (int j = 0; j < columns; j++) {
                   array[i][j] = 0;
               }
           }

           // Записываем массив в файл
           for (int i = 0; i < rows; i++) {
               for (int j = 0; j < columns; j++) {
                   fileToChange << array[i][j] << " ";
               }
               fileToChange<< std::endl;
           }

           std::cout << "Файл успешно создан." << std::endl;
    } else {
        throw Exceptions::OpenFileException(fileName);
    }

}
} // Transport