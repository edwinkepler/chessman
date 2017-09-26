#include "bishop.hpp"

#include <cmath>

namespace Chessman
{
    Bishop::Bishop(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::BISHOP;
        c_unicode = _owner ? "\u265D" : "\u2657";
    }

    const int Bishop::identify_move(
        const pair<int, int>& to,
        const vector<vector<shared_ptr<Chessman::Piece>>>& vb)
    {
        log.piece_func_head("Bishop::identify_move", 
        type(), owner(), last_move()).coords(last_move(), to).n();

        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        return check_diagonal_lines(x1, y1, x2, y2, vb);
    }

    const vector<tuple<int, int, int>> Bishop::list_moves(
        const vector<vector<shared_ptr<Chessman::Piece>>>& vb) 
    {
        log.piece_func_head("Bishop::list_moves()", 
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
