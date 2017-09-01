#include "conversion.hpp"

namespace Helper
{
    int ctoi(char _c) {
        char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for(int i = 0; i < 8; ++i) {
            if(arr[i] == _c) {
                return i + 1;
            }
        }
        return 0;
    }
}
