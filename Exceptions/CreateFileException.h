//
// Created by Ivan Basov on 13.11.23.
//

#ifndef INC_2_CREATEFILEEXCEPTION_H
#define INC_2_CREATEFILEEXCEPTION_H
#include "FileException.h"
namespace Exceptions {

    class CreateFileException : public FileException{
    public:
        CreateFileException(const std::string fname) : FileException(fname) {}
        std::string Message() const override;
    };
    };

// Exceptions

#endif //INC_2_CREATEFILEEXCEPTION_H
