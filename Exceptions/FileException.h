//
// Created by Ivan Basov on 13.11.23.
//

#ifndef КУРСОВАЯ2_FILEEXCEPTION_H
#define КУРСОВАЯ2_FILEEXCEPTION_H
#include "fstream"
namespace Exceptions {

    class FileException {
    protected:
        std::string filename;
    public:
        FileException(const std::string fname) : filename(fname) {};
        virtual std::string Message() const = 0;
    };
    };

 // Exceptions

#endif //КУРСОВАЯ2_FILEEXCEPTION_H
