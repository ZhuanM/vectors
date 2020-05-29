
#pragma once
#include "Vector.h"
#include <stdexcept>


class VectorLengthException : public std::exception {

public:
    VectorLengthException(char message[] = "Vector length is 0!");
	char* what_msg();
    ~VectorLengthException();
private:
    char msg[20+1];
};
