#include "board.hpp"

namespace Chessboard
{
    Board::Board() {
        for(int i = 0; i < 8; i++) {
            vector<Chessman::Piece*> row;
            row.resize(8);
            v_board.push_back(row);
        }

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                v_board[i][j] = nullptr;
            }
        }
    }

    Chessman::Piece* Board::point_piece(const pair<int, int> &c) {
        if(!is_within_limit(c)) {
            throw invalid_argument("Board::point_piece(): Coords out of range.");
        } else if(v_board[c.second - 1][v_board.size() - c.first] == nullptr) {
            throw invalid_argument("Board::getOwner(): Square is empty.");
        } else {
            return v_board[c.second - 1][v_board.size() - c.first];
        }
    }

    void Board::move_piece(
        const pair<int, int>& from,
        const pair<int, int>& to)
    {
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

    void Board::place_piece(const pair<int, int>& c, Chessman::Piece* piece) {
        if(!is_within_limit(c)) {
            throw invalid_argument("Board::place_piece(): Coords out of range.");
        } else {
            v_board[c.second - 1][v_board.size() - c.first] = piece;
        }
    }

    bool Board::is_sqr_empty(const pair<int, int>& c) {
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

    const vector<vector<Chessman::Piece*>> Board::board() {
        return v_board;
    }

    void Board::nullify(const pair<int, int> &c) {
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
