#include "king.hpp"

#include <cmath>
#include <algorithm>

namespace Chessman
{
    King::King(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::KING;
        c_unicode = _owner ? "\u265A" : "\u2654";

        log.piece_func_head("King::King()", 
            type(), owner(), v_history.back());
    }

    const int King::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*>>& vb)
    {
        log.piece_func_head("King::identify_move()", 
            type(), owner(), last_move()).coords(last_move(), to).n();

        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        if((abs(x1 - x2) == 1 && abs(y1 - y2) < 1) ||
           (abs(y1 - y2) == 1 && abs(x1 - x2) < 1) ||
           (abs(x1 - x2) == 1 && abs(y1 - y2) == 1))
        {
            log.t().l(__LINE__);
            log.info("Normal move. Checking if in capturing zone...").n();
            vector<tuple<int, int, int>> vp;
            // Prevent moving into capturing zone. First we need to find all
            // moves of enemy pieces.
            for(int i = 1; i <= vb.size(); i++) {
                for(int j = 1; j <= vb.at(0).size(); j++) {
                    if(vb[j - 1][vb.size() - i] != nullptr) {
                        if(vb[j - 1][vb.size() - i]->owner() != owner()) {
                            auto tv = vb[j - 1][vb.size() - i]->list_moves(vb);
                            sort(tv.begin(), tv.end());
                            merge(vp.begin(), vp.end(),
                                  tv.begin(), tv.end(),
                                  back_inserter(vp));
                        }
                    }
                }
            }
            // Check if desired move is not in a path of capturing.
            for(auto const& t : vp) {
                if(get<0>(t) == x2 && get<1>(t) == y2) {
                    log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                    return Chessman::MOVES::INVALID;
                }
            }
            log.t().l(__LINE__).info("Path clear, move VALID.").n();
            return Chessman::MOVES::VALID;
        //
        // Check for castling
        //
        } else if(y1 == y2 && abs(x1 - x2) == 2 && !moved()) {
            log.t().l(__LINE__);
            log.info("Castling. Checking if in capturing zone...").n();
            vector<tuple<int, int, int>> vp;
            // Prevent moving into capturing zone. First we need to find all
            // moves of enemy pieces.
            for(int i = 1; i <= vb.size(); i++) {
                for(int j = 1; j <= vb.at(0).size(); j++) {
                    if(vb[j - 1][vb.size() - i] != nullptr) {
                        if(vb[j - 1][vb.size() - i]->owner() != owner()) {
                            auto tv = vb[j - 1][vb.size() - i]->list_moves(vb);
                            sort(tv.begin(), tv.end());
                            merge(vp.begin(), vp.end(),
                                  tv.begin(), tv.end(),
                                  back_inserter(vp));
                        }
                    }
                }
            }
            // Check if desired move is not in a path of capturing.
            for(auto const& t : vp) {
                for(int i = 1; i <= abs(x2 - x1); i++) {
                    int tmp = 0;
                    int mod = -1;
                    (x2 > x1) ? tmp += i : tmp -= i;
                    (x2 > x1) ? tmp *= -1 : mod *= 1;
                    if(
                        (get<0>(t) == x2 && get<1>(t) == y2) ||
                        (get<0>(t) == x2 + (mod * 1) && 
                            get<1>(t) == y2 && owner() == 1) ||
                        (get<0>(t) == x2 + (mod * -1) && 
                            get<1>(t) == y2 && owner() == 0)) 
                    {
                        log.t().l(__LINE__);
                        log.info("Path taken, move INVALID.").n();
                        return Chessman::MOVES::INVALID;
                    }
                }
            }
            // Check if rooks moved and valid
            auto rrook = vb[y1 - 1][0];
            auto lrook = vb[y1 - 1][vb.size() - 1];
            if(x2 > x1 && rrook != nullptr) {
                if(rrook->type() == 1 &&
                   !rrook->moved() &&
                   rrook->owner() == owner())
                {
                    log.t().l(__LINE__);
                    log.info("Path clear, Rook can castle, short CASTLING.").n();
                    return Chessman::MOVES::CASTLING;
                }
            } else if(x2 < x1 && lrook != nullptr) {
                if(lrook->type() == 1 &&
                   !lrook->moved() &&
                   lrook->owner() == owner())
                {
                    log.t().l(__LINE__);
                    log.info("Path clear, Rook can castle, short CASTLING.").n();
                    return Chessman::MOVES::CASTLING;
                }
            } else {
                log.t().l(__LINE__);
                log.info("Rook can't castle, move INVALID.").n();
                return Chessman::MOVES::INVALID;
            }
        } else {
            log.t().l(__LINE__).info("Move INVALID.").n();
            return Chessman::MOVES::INVALID;
        }
    }

    const vector<tuple<int, int, int>> King::list_moves(
        const vector<vector<Chessman::Piece*>>& vb) 
    {
        log.piece_func_head("King::list_moves()", 
            type(), owner(), v_history.back()).n();

        vector<tuple<int, int, int>> vp;
        for(int i = 1; i <= vb.size(); i++) {
            for(int j = 1; j <= vb.at(0).size(); j++) {
                int m = identify_move(make_pair(i, j), vb);
                if(m != Chessman::MOVES::INVALID) {
                    log << "\t" << "found move type " << m << " at " 
                        << "(" << i << ", " << j << ")\n";
                    vp.push_back(make_tuple(i, j, m));
                }
            }
        }
        return vp;
    }
}
