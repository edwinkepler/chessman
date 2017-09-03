#include "comparison.hpp"

namespace Helper
{
    bool contains(
        const vector<tuple<int, int, int>>& _vm, const pair<int, int>& _p)
    {
        for(auto const& i : _vm) {
            if(get<0>(i) == _p.first && get<1>(i) == _p.second) {
                return true;
            }
        }
        return false;
    }

    bool greaterx(const pair<int, int>& _c1, const pair<int, int>& _c2) {
        return (_c1.first > _c2.first) ? true : false;
    }

    bool greatery(const pair<int, int>& _c1, const pair<int, int>& _c2) {
        return (_c1.second > _c2.second) ? true : false;
    }
}