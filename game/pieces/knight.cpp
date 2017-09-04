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
        const vector<vector<Chessman::Piece*>>& vb)
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
                    log.t().l(__LINE__).info("Move valid, CAPTURING.").n();
                    return Chessman::MOVES::CAPTURE;
                } else {
                    log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                    return Chessman::MOVES::INVALID;
                }
            } else {
                log.t().l(__LINE__).info("Path clear, move VALID.").n();
                return Chessman::MOVES::VALID;
            }
        }
        log.t().l(__LINE__).info("Path taken, move INVALID.").n();
        return Chessman::MOVES::INVALID;
    }

    const vector<tuple<int, int, int>> Knight::list_moves(
        const vector<vector<Chessman::Piece*>>& vb) 
    {
        log.piece_func_head("Knight::list_moves()", 
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
