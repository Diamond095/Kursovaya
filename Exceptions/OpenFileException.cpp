//
// Created by Ivan Basov on 13.11.23.
//

#include "OpenFileException.h"

namespace Exceptions {
    std::string OpenFileException::Message() const {
        return "Ошибка при открытии файла: " + filename;
    }
} // Exceptions