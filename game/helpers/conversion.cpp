#include "conversion.hpp"

#include <cmath>

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

    pair<int, int> transx(const pair<int, int>& _pair, int _x) {
        if(_x < 0) {
            return make_pair(_pair.first - abs(_x), _pair.second);
        } else if(_x > 0) {
            return make_pair(_pair.first + _x, _pair.second);
        } else {
            return _pair;
        }
    } 

    pair<int, int> transy(const pair<int, int>& _pair, int _y) {
        if(_y < 0) {
            return make_pair(_pair.first, _pair.second - abs(_y));
        } else if(_y > 0) {
            return make_pair(_pair.first, _pair.second + _y);
        } else {
            return _pair;
        }
    } 
}
