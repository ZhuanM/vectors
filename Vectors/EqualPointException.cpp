#include "EqualPointException.h"
#include <cstring>

EqualPointException::EqualPointException(const char message[]) {
    strncpy(msg, message, strlen(message));
}

char* EqualPointException::what_msg() {
    return msg;
}

EqualPointException::~EqualPointException() {}
