
#include "VectorLengthException.h"
#include <cstring>

VectorLengthException::VectorLengthException(const char message[]) {
    strncpy(msg, message, strlen(message));
}

char* VectorLengthException::what_msg() {
    return msg;
}

VectorLengthException::~VectorLengthException() {}
