//
// Created by Ivan Basov on 16.09.23.
//
#include "fstream"
#include "Bus.h"
#include "../Exceptions/OpenFileException.h"

namespace Transport {

   Bus::Bus(std::string fname, std::string model, double fueltank, int rows, int columns, int levels) :
   fueltank(fueltank), model(model), rows(rows), columns(columns), levels(levels){
    this->fname="/Users/ivanbasov/"+fname;
    std::ifstream file1("/Users/ivanbasov/"+ fname);
    std::ofstream fileToChange("/Users/ivanbasov/"+fname);
       if (fileToChange.is_open()) {
           for (int k = 0; k < levels; k++) {
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
                   fileToChange << std::endl;
               }
           }
    } else {
        throw Exceptions::OpenFileException("/Users/ivanbasov/"+ fname);
    }
       std::ofstream file(SetAndGetFileWithBuses(), std::ios::app); // Открываем файл в режиме дозаписи

       if (file.is_open()) {
           file << "/Users/ivanbasov/"+ fname +","  << fueltank << "," << model + "," << rows << "," << columns <<","<< levels << std::endl; // Записываем информацию и название файла в новую строку
           file.close(); // Закрываем файл
           std::cout << "Информация успешно добавлена в файл!" << std::endl;
       } else {
           throw Exceptions::OpenFileException(SetAndGetFileWithBuses());
       }


   }
    std::string Bus::SetAndGetFileWithBuses() {
        Bus::fileOfBus="/Users/ivanbsov/fileWithBuses.txt";
        return fileOfBus;
    }
    std::string Bus::getFile(){
       return "/Users/ivanbasov/"+ fname;
   }
} // Transport