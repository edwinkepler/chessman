#include "board.hpp"

namespace Chessboard
{
    Board::Board() {
        for(int i = 0; i < 8; i++) {
            vector<shared_ptr<Chessman::Piece>> row;
            row.resize(8);
            v_board.push_back(row);
        }

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                v_board[i][j] = nullptr;
            }
        }
    }

    Board::~Board()
    {}

    shared_ptr<Chessman::Piece> Board::point_piece(const pair<int, int> &_coords) {
        log.board_func_head("Board::point_piece", _coords);

        if(!is_within_limit(_coords)) {
            throw invalid_argument("Board::point_piece(): Coords out of range.");
        } else if(v_board[_coords.second - 1][v_board.size() - _coords.first] == nullptr) {
            throw invalid_argument("Board::getOwner(): Square is empty.");
        } else {
            return shared_ptr<Chessman::Piece>(v_board[_coords.second - 1][v_board.size() - _coords.first]);
        }
    }

    void Board::move_piece(
        const pair<int, int>& from,
        const pair<int, int>& to)
    {
        log.board_func_head("Board::move_piece", from, to);

        if(is_sqr_empty(from)) {
            throw invalid_argument("Board::move_piece(): Square is empty.");
        } else if(!is_sqr_empty(to)) {
            throw invalid_argument("Board::move_piece(): Square not empty.");
        } else {
            place_piece(to, point_piece(from));
            point_piece(from)->add_move(to);
            nullify(from);
        }
    }

    void Board::place_piece(const pair<int, int>& c, shared_ptr<Chessman::Piece> piece) {
        log.board_func_head("Board::place_piece", c);

        if(!is_within_limit(c)) {
            throw invalid_argument("Board::place_piece(): Coords out of range.");
        } else {
            v_board[c.second - 1][v_board.size() - c.first] = piece;
        }
    }

    bool Board::is_sqr_empty(const pair<int, int>& c) {
        log.board_func_head("Board::is_sqr_empty", c);

        if(!is_within_limit(c)) {
            throw invalid_argument(
                "Board::is_sqr_empty(): Coords out of range.");
        } else if(v_board[c.second - 1][v_board.size() - c.first] == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool Board::is_within_limit(const pair<int, int> &c) {
        log.board_func_head("Board::is_within_limit", c);

        if(
            c.first >= 1 &&
            c.first <= v_board.size() &&
            c.second >= 1 &&
            c.second <= v_board.size())
        {
            return true;
        } else {
            return false;
        }
    }

    const vector<vector<shared_ptr<Chessman::Piece>>> Board::board() {
        return v_board;
    }

    void Board::nullify(const pair<int, int> &c) {
        log.board_func_head("Board::nullify", c);

        if(!is_within_limit(c)) {
            throw invalid_argument(
                "Board::nullifySquare(): Coords out of range.");
        } else if(v_board[c.second - 1][v_board.size() - c.first] == nullptr) {
            throw invalid_argument(
                "Board::nullifySquare(): Square allready NULL.");
        } else {
            v_board[c.second - 1][v_board.size() - c.first] = nullptr;
        }
    }
}
