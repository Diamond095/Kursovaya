//
// Created by Ivan Basov on 16.09.23.
//

#include "Manager.h"
#include "../Person.h"
#include "iostream"
#include "fstream"
#include "Driver.h"
#include "string"
#include <sstream>
#include "../../Exceptions/CreateFileException.h"
#include "../../Exceptions/OpenFileException.h"
#include "../../Trip.h"

using namespace std;
namespace Workers {
    Manager::Manager(string fname, string fio, string date_of_birth, int middletimeWork, string password) : Worker(fio,
                                                                                                                   date_of_birth,
                                                                                                                   middletimeWork) {
        this->fname = "/Users/ivanbasov/" + fname;
        ofstream file(this->fname);
        if (file) {
            cout << "Файл успешно создан: " << this->fname << endl;
        } else {
            throw Exceptions::CreateFileException(this->fname);
        }

        file.close();
        ifstream fileWithManagers(this->fileWithManagers);
        if (fileWithManagers.is_open()) {
            file << fname << " " << fio << " " << date_of_birth << " " << middletimeWork << " " << password << endl;
            file.close();
            cout << "Пользователь добавлен в файл." << endl;
        } else {
            throw Exceptions::OpenFileException(fname);
        };
    }

    void Manager::addDriver() {
        std::string fio;
        std::string date_birth;
        int middleTimeWork;
        cout << "Введите фамилию имя и отчество водителя" << endl;
        cin >> fio;
        cout << "Введите день рождения водителя" << endl;
        cin >> date_birth;
        cout << "Введите среднне рабочее время в день у водителя" << endl;
        cin >> middleTimeWork;
        Workers::Driver *driver = new Workers::Driver(fio, date_birth, middleTimeWork);
        fstream file;
        file.open(fname, ios::out | ios::app);

        // Получаем текущую длину файла, чтобы использовать в качестве индекса
        file.seekg(0, ios::end);
        int index = file.tellg() / sizeof(Driver) + 1;

        // Добавляем индекс и данные в файл
        file << index << " " << driver->getFio() << " " << driver->getDateOfBirth() << " "
             << driver->getmiddletimeWork() << endl;

        file.close();

    }

    void Manager::ShowMenu() {
        cout << "****************************************************" << endl;
        cout << "********** Здраствуйте, ! ********" << endl;
        cout << "********* 1. Завершить сеанс************************" << endl;
        cout << "********* 2. Добавить нового водителя **************" << endl;
        cout << "********* 3. Вывести полный список водителей *******" << endl;
        cout << "********* 4. Уволить водителя **********************" << endl;
        cout << "********* 5. Вывести информацию о всех пользователей" << endl;
        cout << "********* 6. Добавить новый автобус ****************" << endl;
        cout << "********* 7. Добавить новую поездку ****************" << endl;
        cout << "****************************************************" << endl;
        cout << endl;

    }

    void Manager::exit() {
        cout << "Возвращайтесь снова!" << endl;
        system("pause");
        ::exit(0);

    }

    void Manager::choiseInMenu(int choise) {
        switch (choise) {
            case 1:
                Manager::exit();
            case 2:
                this->addDriver();
            case 3:
                this->showAllDrivers();
            case 4:
                this->removeDriver();
            case 5:
                this->showAllUsers();
            case 6:
                this->setNewBus();
            case 7:
                this->addNewTrip();

        }
    }

    void Manager::removeDriver() {
        ifstream inputFile(fname);
        if (!inputFile) {
            throw Exceptions::OpenFileException(fname);
            return;
        }
        string name;
        cout << "Введите фамилию имя и отчества водителя" << endl;
        cin >> name;
        const int maxDrivers = 100; // Максимальное количество водителей
        int driversIndexes[maxDrivers];
        string driversNames[maxDrivers];
        int numDrivers = 0;
        int maxIndex = -1;

        // Чтение данных из файла и поиск максимального индекса
        string line;
        while (getline(inputFile, line)) {
            int index = stoi(line.substr(0, line.find(',')));
            string driverName = line.substr(line.find(',') + 1);

            if (driverName == name) {
                // Пропускаем запись с указанным именем
                continue;
            }

            driversIndexes[numDrivers] = index;
            driversNames[numDrivers] = driverName;
            numDrivers++;

            if (index > maxIndex) {
                maxIndex = index;
            }
        }
        inputFile.close();

        if (numDrivers == 0) {
            cout << "Водитель с указанным именем не найден." << endl;
            return;
        }

        ofstream outputFile(fname);
        if (!outputFile) {
            throw Exceptions::OpenFileException(fname);
            return;
        }

        // Запись данных в файл с обновленными индексами
        for (int i = 0; i < numDrivers; i++) {
            if (driversIndexes[i] > maxIndex) {
                // Уменьшаем индекс водителя, если он был создан после удаленного водителя
                driversIndexes[i]--;
            }
            outputFile << driversIndexes[i] << "," << driversNames[i] << endl;
        }
        outputFile.close();

        cout << "Водитель с именем " << name << " успешно удален из файла." << endl;

    }

    void Manager::showAllDrivers() {
        ifstream inputFile(fname);
        if (!inputFile) {
            cout << "Ошибка при открытии файла." << endl;
            return;
        }
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }

        inputFile.close();

    }

    void Manager::showAllUsers() {
        ifstream inputFile(Persons::Person::setAndGetfileWithUsers());
        if (!inputFile) {
            throw Exceptions::OpenFileException(fname);
            return;
        }
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }

        inputFile.close();
    }

    void Manager::addNewTrip() {
        char start;
        char finish;
        char departure;
        char arrival;
        std::string modelName;
        std::string driverName;
        cout << "Введите время начала поездки";
        cin >> start;
        cout << "Введите время окончания поездки";
        cin >> finish;
        cout << "Введите место начала поездки";
        cin >> departure;
        cout << "Введите место окончания поездки";
        cin >> arrival;
        cout << "Введите модель автобуса" << endl;
        cin >> modelName;
        cout << "Введите имя, фамилию и отчество водителя" << endl;
        cin >> driverName;
        if(findDriverByName(driverName)==nullptr || findBusByModel(modelName)==nullptr) {
            cout<<"Введенный вами водитель или автобус не найден" << endl;
            return;
        }
        else{
            Trip::Trip *trip=new Trip::Trip(start, finish, departure, arrival, findDriverByName(driverName), findBusByModel(modelName));
        }

    }

    bool Manager::checkPassword(std::string fio, std::string password) {
        ifstream file(Manager::SetAndGetFileWithManagers());
        if (file.is_open()) {
            string line;
            while (getline(file, line)) { // Считываем файл построчно
                istringstream iss(line);
                vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());

                if (words.size() == 4 && words[0] == fio && words[4] == password) {
                    file.close();
                    return true; // Найден пользователь с указанными данными
                }
            }

            file.close();
        } else {
            throw Exceptions::OpenFileException(Manager::SetAndGetFileWithManagers());
        }

        return false; // Пользователь не найден
    }

    std::string Manager::SetAndGetFileWithManagers() {
        Manager::fileWithManagers = "/Users/ivanbsov/fileWithManagers.txt";
        return fileWithManagers;
    }

    std::string Manager::getDateOfBirth(std::string fio) {
        std::ifstream file(SetAndGetFileWithManagers());
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string fname, fio2, date_of_birth, middletimeWork, password;
            if (iss >> fname >> fio2 >> date_of_birth >> middletimeWork >> password) {
                if (fio == fio2) {
                    return date_of_birth;
                }
            }
        }
    }
void setNewBus(){
        double fueltank;
        int rows, columns, levels;
        string fname, model;
    cout << "Введите вместимость бака для бензина: ";
    cin >> fueltank;

    cout << "Введите количество рядов на этаже: ";
    cin >> rows;

    cout << "Введите количество мест на одном ряду: ";
    cin >> columns;

    cout << "Введите количество этжей автобуса: ";
    cin >> levels;

    cout << "Введите название файла для билетов на места: ";
    cin >> fname;

    cout << "Введите название модели автобуса: ";
    cin >> model;

}
    std::string Manager::getFileWorkers(std::string fio) {
        std::ifstream file(SetAndGetFileWithManagers());
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string fname, fio2, date_of_birth, middletimeWork, password;
            if (iss >> fname >> fio2 >> date_of_birth >> middletimeWork >> password) {
                if (fio == fio2) {
                    return fname;
                }
            }
        }
    }

    int Manager::getMiddleHourWork(std::string fio) {
        std::ifstream file(SetAndGetFileWithManagers());
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string fname, fio2, date_of_birth, password;
            int middletimeWork;
            if (iss >> fname >> fio2 >> date_of_birth >> middletimeWork >> password) {
                if (fio == fio2) {
                    return middletimeWork;
                }
            }
        }
    }

    Driver *Manager::findDriverByName(std::string driverName) {
        std::ifstream file(fname);
        if (!file) {
            throw Exceptions::OpenFileException(fname);
        }

        std::string line;
        while (std::getline(file, line)) {
            std::string name, dateOfBirth, middleTimeWork;
            std::istringstream iss(line);
            if (std::getline(iss, name, ',') && std::getline(iss, dateOfBirth, ',') &&
                std::getline(iss, middleTimeWork)) {

                if (name == driverName) {
                    return new Driver(name, dateOfBirth, std::stoi(middleTimeWork));
                }
            }
        }
        return nullptr;
    }

    Transport::Bus *Manager::findBusByModel(std::string modelName) {

        std::ifstream file(Transport::Bus::SetAndGetFileWithBuses());
        if (!file) {
            throw Exceptions::OpenFileException(fname);
        }

        std::string line;
        while (std::getline(file, line)) {
            std::string fname, fueltank, model, rows, columns, levels;
            std::istringstream iss(line);
            if (std::getline(iss, fname, ',') && std::getline(iss, model, ',') && std::getline(iss, rows, ',') &&
                std::getline(iss, columns)) {
                if (model == modelName) {
                    return new Transport::Bus(fname, model, std::stoi(fueltank), std::stoi(rows), std::stoi(columns),
                                              std::stoi(levels));
                }
            }
        }
        return nullptr;
    }

};
// Workers