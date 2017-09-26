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
        const vector<vector<shared_ptr<Chessman::Piece>>>& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        auto diag = check_diagonal_lines(x1, y1, x2, y2, vb);
        if(diag != Chessman::MOVES::INVALID) {
            return diag;
        } else {
            return check_straight_lines(x1, y1, x2, y2, vb);
        }
    }

    const vector<tuple<int, int, int>> Queen::list_moves(
        const vector<vector<shared_ptr<Chessman::Piece>>>& vb) 
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
