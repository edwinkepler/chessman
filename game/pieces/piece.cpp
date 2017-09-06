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

    // https://math.stackexchange.com/a/1566144
    const int Piece::check_diagonal_lines(
        int x1, int y1, 
        int x2, int y2, 
        const vector<vector<Chessman::Piece*>>& vb) 
    {
        if(x1 == x2 && y1 == y2) {
            // Just to be sure, invalid from the square piece is standing on
            return Chessman::MOVES::INVALID;
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

    const int Piece::check_straight_lines(
        int x1, int y1, 
        int x2, int y2, 
        const vector<vector<Chessman::Piece*>>& vb)
    {
        if(x1 == x2 && y1 != y2) {
            for(int i = 1; i <= abs(y1 - y2); i++) {
                int yi = (y2 - y1) < 0 ? y1 - i : y1 + i;
                if(vb[yi - 1][vb.size() - x1] != nullptr && i == abs(y1 - y2)) {
                    if(vb[yi - 1][vb.size() - x1]->owner() != owner()) {
                        log.t().l(__LINE__).info("Move valid, CAPTURING.").n();
                        return Chessman::MOVES::CAPTURE;
                    } else {
                        log.t().l(__LINE__);
                        log.info("Square taken, move INVALID.").n();
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
                        log.t().l(__LINE__);
                        log.info("Square taken, move INVALID.").n();
                        return Chessman::MOVES::INVALID;
                    }
                } else if(vb[y2 - 1][vb.size() - xi] != nullptr) {
                    log.t().l(__LINE__).info("Path taken, move INVALID.").n();
                    return Chessman::MOVES::INVALID;
                }
            }
            log.t().l(__LINE__).info("Path clear, move VALID.").n();
            return Chessman::MOVES::VALID;
        } else {
            log.t().l(__LINE__).info("Move INVALID.").n();
            return Chessman::MOVES::INVALID;
        }
    }
}
