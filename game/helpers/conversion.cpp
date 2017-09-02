#include "conversion.hpp"

namespace Helper
{
    int ctoi(char _c) {
        for(int i = 0; i < 8; ++i) {
            if(arr[i] == _c) {
                return i + 1;
            }
        }
        return 0;
    }

    char itoc(int _i) {
        return arr[_i - 1];
    }
}
