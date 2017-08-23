#include "queen.hpp"

#include <cmath>

namespace Chessman
{
    Queen::Queen(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::QUEEN;
        c_unicode = _owner ? "\u265B" : "\u2655";
    }

    const int Queen::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >&)
    {
        // if(
        //     getLastMove().first == to.first &&
        //     getLastMove().second != to.second)
        // {
        //     for(int i = 1; i <= abs(getLastMove().second - to.second); i++) {
        //         int y = (to.second - getLastMove().second) < 0 
        //                 ? getLastMove().second - i 
        //                 : getLastMove().second + i;
        //         if(
        //             !b->isSquareEmpty(make_pair(to.first, y)) &&
        //             i == abs(getLastMove().second - to.second))
        //         {
        //             if(b->getPiece(make_pair(to.first, y))->getOwner() != getOwner()) {
        //                 return Chessman::MOVES::CAPTURE;
        //             } else {
        //                 return Chessman::MOVES::INVALID;
        //             }
        //         } else if(!b->isSquareEmpty(make_pair(to.first, y))) {
        //             return Chessman::MOVES::INVALID;
        //         }
        //     }
        //     return Chessman::MOVES::VALID;
        // } else if(
        //     getLastMove().second == to.second &&
        //     getLastMove().first != to.first)
        // {
        //     for(int i = 1; i <= abs(getLastMove().first - to.first); i++) {
        //         int x = (to.first - getLastMove().first) < 0 
        //                 ? getLastMove().first - i 
        //                 : getLastMove().first + i;
        //         if(
        //             !b->isSquareEmpty(make_pair(x, to.second)) &&
        //             i == abs(getLastMove().first - to.first))
        //         {
        //             if(b->getPiece(make_pair(x, to.second))->getOwner() != getOwner()) {
        //                 return Chessman::MOVES::CAPTURE;
        //             } else {
        //                 return Chessman::MOVES::INVALID;
        //             }
        //         } else if(!b->isSquareEmpty(make_pair(x, to.second))) {
        //             return Chessman::MOVES::INVALID;
        //         }
        //     }
        //     return Chessman::MOVES::VALID;
        // } else if(
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
