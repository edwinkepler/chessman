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
        const vector<vector<Chessman::Piece*>>& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        if(x1 == x2 && y1 == y2) {
            return Chessman::MOVES::INVALID;
        } else if(x1 == x2 && y1 != y2) {
            for(int i = 1; i <= abs(y1 - y2); i++) {
                int yi = (y2 - y1) < 0 ? y1 - i : y1 + i;
                if(vb[yi - 1][vb.size() - x1] != nullptr && i == abs(y1 - y2)) {
                    if(vb[yi - 1][vb.size() - x1]->owner() != owner()) {
                        log.t().l(__LINE__).info("Move valid, CAPTURING.").n();
                        return Chessman::MOVES::CAPTURE;
                    } else {
                        log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                        return Chessman::MOVES::INVALID;
                    }
                } else if(vb[yi - 1][vb.size() - x1] != nullptr) {
                    log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                    return Chessman::MOVES::INVALID;
                }
            }
            return Chessman::MOVES::VALID;
        } else if(y1 == y2 && x1 != x2) {
            for(int i = 1; i <= abs(x1 - x2); i++) {
                int xi = (x2 - x1) < 0 ? x1 - i : x1 + i;
                if(vb[y2 - 1][vb.size() - xi] != nullptr && i == abs(x1 - x2)) {
                    if(vb[y2 - 1][vb.size() - xi]->owner() != owner()) {
                        log.t().l(__LINE__).info("Move valid, CAPTURING.").n();
                        return Chessman::MOVES::CAPTURE;
                    } else {
                        log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                        return Chessman::MOVES::INVALID;
                    }
                } else if(vb[y2 - 1][vb.size() - xi] != nullptr) {
                    log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                    return Chessman::MOVES::INVALID;
                }
            }
            return Chessman::MOVES::VALID;
        } else if(abs(x2 - x1) == abs(y2 - y1) && abs(x2 - x1) > 0 && abs(y2 - y1) > 0) {
            int n = abs(x2 - x1);
            int xd = (x2 - x1) / abs(x2 - x1);
            int yd = (y2 - y1) / abs(y2 - y1);
            for(int i = 1; i <= n; i++) {
                int ixd = x1 + (i * xd);
                int iyd = y1 + (i * yd);
                if(vb[iyd - 1][vb.size() - ixd] != nullptr) {
                    if(i == n && vb[iyd - 1][vb.size() - ixd]->owner() != owner()) {
                        log.t().l(__LINE__).info("Move valid, CAPTURING.").n();
                        return Chessman::MOVES::CAPTURE;
                    } else {
                        log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                        return Chessman::MOVES::INVALID;
                    }
                }
            }
            log.t().l(__LINE__).info("Path clear, move VALID.").n();
            return Chessman::MOVES::VALID;
        } else {
            log.t().l(__LINE__).info("Move INVALID.").n();
            return Chessman::MOVES::INVALID;
        }
    }

    const vector<tuple<int, int, int>> Queen::list_moves(
        const vector<vector<Chessman::Piece*>>& vb) 
    {
        log.piece_func_head("Queen::list_moves()", 
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
