#include "knight.hpp"

#include "cmath"

namespace Chessman
{
    Knight::Knight(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::KNIGHT;
        c_unicode = _owner ? "\u265E" : "\u2658";
    }

    const int Knight::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        if((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) ||
            (abs(y1 - y2) == 2 && abs(x1 - x2) == 1))
        {
            if(vb[y2 - 1][vb.size() - x2] != nullptr) {
                if(vb[y2 - 1][vb.size() - x2]->owner() != owner()) {
                    return Chessman::MOVES::CAPTURE;
                } else {
                    return Chessman::MOVES::INVALID;
                }
            } else {
                return Chessman::MOVES::VALID;
            }
        }
        return Chessman::MOVES::INVALID;
    }
}
