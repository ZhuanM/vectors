#pragma once
#include "Vector.h"
#include <stdexcept>


class VectorLengthException : public std::exception {

public:
    VectorLengthException(char * message = "Vector length is 0!");
	char* what_msg() const;
private:
    char * msg;
};