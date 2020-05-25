#include "VectorLengthException.h"

VectorLengthException::VectorLengthException(char * message) : msg(message) {}

char* VectorLengthException::what_msg() const {
    return msg;
}