#include "piece.hpp"

namespace Chessman
{
    Piece::Piece(int _owner, pair<int, int> _coords) {
        i_owner = _owner;
        v_history.push_back(_coords);
        f_moved = false;
    }

    const int Piece::owner() {
        return i_owner;
    }

    const int Piece::type() {
        return i_type;
    }

    const char* Piece::unicode() {
        return c_unicode;
    }

    const void Piece::add_move(const pair<int, int>& c) {
        v_history.push_back(c);
        if(v_history.back() != v_history.at(v_history.size() - 2)) {
            f_moved = true;
        }
    }

    const pair<int, int> Piece::last_move() {
        if(v_history.size() > 0) {
            return v_history.back();
        } else {
            return make_pair(0, 0);
        }
    }

    const bool Piece::moved() {
        return f_moved;
    }

    const vector<pair<int, int>> Piece::history() {
        return v_history;
    }

    const vector<tuple<int, int, int>> Piece::list_moves(
        const vector<vector<Chessman::Piece*>>& vb) 
    {
        vector<tuple<int, int, int>> vp;
        for(int i = 1; i <= vb.size(); i++) {
            for(int j = 1; j <= vb.at(0).size(); j++) {
                int m = identify_move(make_pair(i, j), vb);
                if(m != Chessman::MOVES::INVALID) {
                    vp.push_back(make_tuple(i, j, m));
                }
            }
        }
        return vp;
    }
}
