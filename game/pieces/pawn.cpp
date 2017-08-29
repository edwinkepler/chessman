#include "pawn.hpp"

#include <cmath>

namespace Chessman
{
    Pawn::Pawn(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::PAWN;
        c_unicode = _owner ? "\u265F" : "\u2659";
        f_promoted = false;
    }

    // Good luck with that X_X
    const int Pawn::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        // If the same file but different rank and in limits of movement
        // restrictions
        // Checks for VALID move, normal moves
        if(x1 == x2 && abs(y2 - y1) <= 2 &&
           ((y1 < y2 && owner() == 0) || 
           (y1 > y2 && owner() == 1)))
        {
            // INVALID if already moved and move bigger then two ranks
            if(abs(y2 - y1) == 2 && moved())
            {
                return Chessman::MOVES::INVALID;
            }
            // INVALID if there is another piece on destination rank
            for(int i = 1; i <= abs(y2 - y1); i++) {
                int tmp = 0;
                (owner() == 0) ? tmp += i : tmp -= i;
                if(vb[y1 - 1 + tmp][vb.size() - x1] != nullptr) {
                    return Chessman::MOVES::INVALID;
                }
            }
            // Checks for PROMOTION
            if(
                (owner() == 0 &&
                vb[x2].size() == y2) ||
                (owner() == 1 &&
                y2 == 1))
            {
                return Chessman::MOVES::PROMOTION;
            }
            // If you are here, then move is VALID
            return Chessman::MOVES::VALID;
        // Checks for CAPTURING
        } else if(
            abs(x1 - x2) == 1 &&
            abs(y2 - y1) == 1 &&
            vb[y2 - 1][vb.size() - x2] != nullptr)
        {
            if(vb[y2 - 1][vb.size() - x2]->owner() != owner()) {
                // Checks for PROMOTION AND CAPTURING
                if( (owner() == 0 && vb[x2].size() == y2) ||
                    (owner() == 1 && y2 == 1))
                {
                    return Chessman::MOVES::PROCAPT;
                } else {
                    return Chessman::MOVES::CAPTURE;
                }
            } else {
                return Chessman::MOVES::INVALID;
            }
        // En passant white
        } else if(
            owner() == 0 &&
            y1 == 5 &&
            y1 < y2 &&
            abs(y1 - y2) == 1 &&
            abs(x1 - x2) == 1 &&
            vb[y1 - 1][vb.size() - x2] != nullptr)
        {
            // Because en passant must be after first move of enemy pawn it
            // means that only two moves are in history (initial placement and
            // first move).
            if(vb[y1 - 1][vb.size() - x2]->type() == 0) {
                auto hist = vb[y1 - 1][vb.size() - x2]->history();
                if(hist.front().second == 7 && hist.back().second == 5) {
                    return Chessman::MOVES::EN_PASSANT;
                }
            }
        // En passant black
        } else if(
            owner() == 1 &&
            y1 == 4 &&
            y1 > y2 &&
            abs(y1 - y2) == 1 &&
            abs(x1 - x2) == 1 &&
            vb[y1 - 1][vb.size() - x2] != nullptr)
        {
            // Because en passant must be after first move of enemy pawn it
            // means that only two moves are in history (initial placement and
            // first move).
            if(vb[y1 - 1][vb.size() - x2]->type() == 0) {
                auto hist = vb[y1 - 1][vb.size() - x2]->history();
                if(hist.front().second == 2 && hist.back().second == 4) {
                    return Chessman::MOVES::EN_PASSANT;
                }
            }
        } else {
            // If you are here, move is INVALID
            return Chessman::MOVES::INVALID;
        }
    }
}
