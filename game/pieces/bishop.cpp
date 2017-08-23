#include "bishop.hpp"

#include <cmath>

namespace Chessman
{
    Bishop::Bishop(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::BISHOP;
        c_unicode = _owner ? "\u265D" : "\u2657";
    }

    const int Bishop::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >&)
    {
    }
}
