//
// Created by Ivan Basov on 13.11.23.
//

#ifndef КУРСОВАЯ2_OPENFILEEXCEPTION_H
#define КУРСОВАЯ2_OPENFILEEXCEPTION_H
#include "iostream"
#include "FileException.h"
namespace Exceptions {

    class OpenFileException : public FileException {
    public:
        OpenFileException(const std::string fname) : FileException(fname) {}
        std::string Message() const override;
    };

} // Exceptions

#endif //UNTITLED2_OPENFILEEXCEPTION_H
