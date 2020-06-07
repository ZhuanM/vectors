#pragma once
#include "Triangle.h"
#include <stdexcept>


class EqualPointException : public std::exception {

public:
    EqualPointException(char message[] = "There are equal points!");
	char* what_msg();
    ~EqualPointException();
private:
    char msg[23+1];
};
