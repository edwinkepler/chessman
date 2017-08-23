#include "rook.hpp"

#include <cmath>

namespace Chessman
{
    Rook::Rook(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::ROOK;
        c_unicode = _owner ? "\u265C" : "\u2656";
    }

    const int Rook::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >&)
    {
        // if(
        //     getLastMove().first == to.first &&
        //     getLastMove().second != to.second)
        // {
        //     for(int i = 1; i <= abs(getLastMove().second - to.second); i++) {
        //         int y = (to.second - getLastMove().second) < 0 ? getLastMove().second - i : getLastMove().second + i;
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
        //         int x = (to.first - getLastMove().first) < 0 ? getLastMove().first - i : getLastMove().first + i;
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
        // } else {
        //     return Chessman::MOVES::INVALID;
        // }
    }
}
