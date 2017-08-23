#include "king.hpp"

#include <cmath>
#include <algorithm>

namespace Chessman
{
    King::King(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::KING;
        c_unicode = _owner ? "\u265A" : "\u2654";
    }

    const int King::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >&)
    {
        // int x1 = getLastMove().first;
        // int y1 = getLastMove().second;
        // int x2 = to.first;
        // int y2 = to.second;
        // if(abs(x1 - x2) == 1 || abs(y1 - y2) == 1) {
        //     vector<tuple<int, int, int> > vp;
        //     for(int i = 1; i <= b->getBoard().size(); i++) {
        //         for(int j = 1; j <= b->getBoard().at(0).size(); j++) {
        //             if(!b->isSquareEmpty(make_pair(i, j))) {
        //                 if(b->getPiece(make_pair(i, j))->getOwner() != getOwner()) {
        //                     vector<tuple<int, int, int> > tmpv;
        //                     auto tmpo = b->getPiece(make_pair(i, j));
        //                     tmpv = tmpo->legalMoves();
        //                     sort(tmpv.begin(), tmpv.end());
        //                     merge(vp.begin(), vp.end(), tmpv.begin(), tmpv.end(), back_inserter(vp));
        //                 }
        //             }
        //         }
        //     }
        //     return Chessman::MOVES::VALID;
        // }
        // return Chessman::MOVES::INVALID;
    }
}
