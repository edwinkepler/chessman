#include "bishop.hpp"

#include <cmath>

namespace Chessman
{
    Bishop::Bishop(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::BISHOP;
        c_unicode = _owner ? "\u265D" : "\u2657";
    }

    // https://math.stackexchange.com/a/1566144
    const int Bishop::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >&)
    {
        // if(
        //     abs(to.first - getLastMove().first) == abs(to.second - getLastMove().second) &&
        //     abs(to.first - getLastMove().first) > 0 &&
        //     abs(to.second - getLastMove().second) > 0)
        // {
        //     int n = abs(to.first - getLastMove().first);
        //     int xd = (to.first - getLastMove().first) / abs(to.first - getLastMove().first);
        //     int yd = (to.second - getLastMove().second) / abs(to.second - getLastMove().second);
        //     for(int i = 1; i <= n; i++) {
        //         int ixd = getLastMove().first + (i * xd);
        //         int iyd = getLastMove().second + (i * yd);
        //         if(!b->isSquareEmpty(make_pair(ixd, iyd))) {
        //             if(i == n && b->getPiece(make_pair(ixd, iyd))->getOwner() != getOwner()) {
        //                 return Chessman::MOVES::CAPTURE;
        //             } else {
        //                 return Chessman::MOVES::INVALID;
        //             }
        //         }
        //     }
        //     return Chessman::MOVES::VALID;
        // } else {
        //     Chessman::MOVES::INVALID;
        // }
    }
}
