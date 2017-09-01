#include "history.hpp"

namespace Game
{
    Move::Move(int _state,
        int _x1, int _y1, int _type1, 
        int _x2, int _y2, int _type2)
    :   state(_state),
        x1(_x1),
        y1(_y1),
        type1(_type1),
        x2(_x2),
        y2(_y2),
        type2(_type2)
    {}

    Move::~Move() {}

    History::~History() {}

    const void History::add_move(Move mv) {
        mv_list.push_back(mv);
        if(mv_list % 2 == 0)
            play++;
    }

    vector<tuple<int, int, int, int, int, int, int>> History::moves_list() {
        vector<tuple<int, int, int, int, int, int, int>> ret;
        for(auto const& i :mv_list) {
            ret.push_back(
                make_tuple(i.state, i.x1, i.y1, i.type1, i.x2, i.y2, i.type2));
        }
        return ret;
    }

    vector<string> History::to_an() {

    }
}
