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
        const vector<vector<Chessman::Piece*> >&)
    {
        // if(
        //     (abs(getLastMove().first - to.first) == 2 &&
        //     abs(getLastMove().second - to.second) == 1) ||
        //         (abs(getLastMove().second - to.second) == 2 &&
        //         abs(getLastMove().first - to.first) == 1))
        // {
        //     if(!b->isSquareEmpty(to)) {
        //         if(b->getPiece(to)->getOwner() != getOwner()) {
        //             return Chessman::MOVES::CAPTURE;
        //         } else {
        //             return Chessman::MOVES::INVALID;
        //         }
        //     } else {
        //         return Chessman::MOVES::VALID;
        //     }
        // }
        // return Chessman::MOVES::INVALID;
    }
}
