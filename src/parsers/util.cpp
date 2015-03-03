
#include "util.hpp";

namespace util {
    bool isWhitespaceTrash(char c) {
        switch(c) {
            case ' ':
            case '\n':
            case '\r':
                return true;
            default:
                return false;
        }
    };
};