#include "comparison.hpp"

namespace Helper
{
    bool contains(const vector<tuple<int, int, int>>& vm, const pair<int, int>& p) {
        for(auto const& i : vm) {
            if(get<0>(i) == p.first && get<1>(i) == p.second) {
                return true;
            }
        }
        return false;
    }
}