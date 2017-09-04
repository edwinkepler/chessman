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
        log.piece_func_head("Piece::add_move()",
            type(), owner(), v_history.back());
        log.t().info("return ").coords(c).n();

        v_history.push_back(c);
        if(v_history.back() != v_history.at(v_history.size() - 2)) {
            f_moved = true;
        }
    }

    const pair<int, int> Piece::last_move() {
        log.t().piece_func_head("Piece::last_move()", 
            type(), owner(), v_history.back());
        log.t().info("return ").coords(v_history.back()).n();
        return v_history.back();
    }

    const bool Piece::moved() {
        return f_moved;
    }

    const vector<pair<int, int>> Piece::history() {
        return v_history;
    }
}
