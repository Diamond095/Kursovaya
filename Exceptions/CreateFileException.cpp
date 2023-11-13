//
// Created by Ivan Basov on 13.11.23.
//

#include "CreateFileException.h"

namespace Exceptions {
    std::string CreateFileException::Message() const {
        return "Невозможно создать файл" + filename;
    }
} // Exceptions