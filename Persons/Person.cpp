//
// Created by Ivan Basov on 16.09.23.
//

#include "Person.h"
#include "iostream"
#include "../Exceptions/OpenFileException.h"
#include "string"
#include <sstream>
using namespace std;

namespace Persons {

    void Person::SetPersonInfo(std::string fio, std::string date_of_birth,std::string pol) {
        this->fio=fio;
        this->date_of_birth=date_of_birth;
        this->pol=pol;
    }

    void Person::PersonInfo(){
        std::cout << "ФИО: " << fio << std::endl;
        std::cout << "Дата рождения: " << date_of_birth << std::endl;
        std::cout << "Пол: " << pol << std::endl;
   }

    std::string Person::setAndGetfileWithUsers() {
        Person::fileWithAllUsers="/Users/ivanbasov/Users.txt";
        return Person::fileWithAllUsers;
    }
    void Person::ShowMenu() {
        cout << "****************************************************" << endl;
        cout << "********** Здраствуй, выбери что хочешь сделать!********" << endl;
        cout << "********* 1. Завершить сеанс************************" << endl;
        cout << "********* 2. Посмотреть все рейсы **************" << endl;
        cout << "********* 3. Купить билет ***********************" << endl;
        cout << endl;
    }

    void Person::exit() {
        cout << "Возвращайтесь снова!" << endl;
        system("pause");
        ::exit(0);

    }
    void Person::showAllTrip() {
        std::ifstream file("/Users/ivanbsov/fileWithTrips.txt");

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            throw Exceptions::OpenFileException("/Users/ivanbsov/fileWithTrips.txt");
        }
    }
    void buyTicket(const std::string& start, const std::string& end, const std::string& startTime, int level, int row, int column){
            std::ifstream file("/Users/ivanbsov/fileWithTrips.txt");
           std::string fileOfTrip;
        if (file.is_open()) {
            string line;
            std::vector<std::string> matchingFiles;

            while (std::getline(file, line)) {

                istringstream iss(line);

                std::string fileName, tripStartTime, tripEndTime, tripStart, tripEnd;
                iss >> fileName >> tripStartTime >> tripEndTime >> tripStart >> tripEnd;

                if (tripStart == start && tripEnd == end && tripStartTime == startTime) {
                    fileOfTrip=fileName;
                }
            }
            std::ifstream file2(fileOfTrip);

            if (file.is_open()) {
                std::string line;
                int currentLevel = 0;
                bool found = false;

                while (std::getline(file2, line)) {
                    std::istringstream iss(line);

                    int currentRow = 0;
                    std::string currentArray;

                    while (iss >> currentArray) {
                        if (currentLevel == level) {
                            if (currentRow == row && currentArray[column] == '0') {
                                found = true;

                                std::cout << "Поздравляем, вы успешно купили билет!" << std::endl;

                                // Записываем данные в определенный файл
                                std::ofstream resultFile("successful_purchase.txt");
                                if (resultFile.is_open()) {
                                    resultFile << "Данные любые" << std::endl;
                                    resultFile.close();
                                } else {
                                    throw Exceptions::OpenFileException(fileOfTrip);
                                }
                            } else if (currentRow == row && currentArray[column] == '1') {
                                std::cout << "Ошибка! Данное место уже занято." << std::endl;
                                return;
                            }
                        }

                        currentRow++;
                    }

                    currentLevel++;
                }

                file2.close();

                if (!found) {
                    std::cout << "Не найдено место с указанными параметрами." << std::endl;
                }
            } else {
                std::cout << "Не удалось открыть файл." << std::endl;
            }

            file.close();
        }

    }
    void Person::makeChoice(int choise){
      switch(choise){
          case 1:
            this->exit();
          case 2:
          this->showAllTrip();
          case 3:
              std::string startPlace;
              std::string endPlace;
              std::string timeStart;
              int row, column, level;
              cout<<"Введите место место отправления поездки";
              cin>>startPlace;
              cout<<"Введите место окончания поездки";
              cin>>endPlace;
              cout<<"Введите время начала поездки";
              cin>>timeStart;
              cout<<"Введите этаж на котором хотите купить билет";
              cin>>level;
              cout<<"Введите ряд в котором хотите купить билет";
              cin>>row;
              cout<<"Ввведите место в ряду на которое хотите купить билет";
              cin>>column;

              this->buyTicket(startPlace, endPlace,timeStart, level, row, column);
      }
    };

} // Persons