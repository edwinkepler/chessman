#include "gamecontroller.hpp"

namespace Game
{
    GameController::GameController() {
        board->place_piece(make_pair(1, 1), rook_w_1);
        board->place_piece(make_pair(2, 1), knight_w_1);
        board->place_piece(make_pair(3, 1), bishop_w_1);
        board->place_piece(make_pair(4, 1), queen_w);
        board->place_piece(make_pair(5, 1), king_w);
        board->place_piece(make_pair(6, 1), bishop_w_2);
        board->place_piece(make_pair(7, 1), knight_w_2);
        board->place_piece(make_pair(8, 1), rook_w_2);
        board->place_piece(make_pair(1, 2), pawn_w_1);
        board->place_piece(make_pair(2, 2), pawn_w_2);
        board->place_piece(make_pair(3, 2), pawn_w_3);
        board->place_piece(make_pair(4, 2), pawn_w_4);
        board->place_piece(make_pair(5, 2), pawn_w_5);
        board->place_piece(make_pair(6, 2), pawn_w_6);
        board->place_piece(make_pair(7, 2), pawn_w_7);
        board->place_piece(make_pair(8, 2), pawn_w_8);
        board->place_piece(make_pair(1, 8), rook_b_1);
        board->place_piece(make_pair(2, 8), knight_b_1);
        board->place_piece(make_pair(3, 8), bishop_b_1);
        board->place_piece(make_pair(4, 8), queen_b);
        board->place_piece(make_pair(5, 8), king_b);
        board->place_piece(make_pair(6, 8), bishop_b_2);
        board->place_piece(make_pair(7, 8), knight_b_2);
        board->place_piece(make_pair(8, 8), rook_b_2);
        board->place_piece(make_pair(1, 7), pawn_b_1);
        board->place_piece(make_pair(2, 7), pawn_b_2);
        board->place_piece(make_pair(3, 7), pawn_b_3);
        board->place_piece(make_pair(4, 7), pawn_b_4);
        board->place_piece(make_pair(5, 7), pawn_b_5);
        board->place_piece(make_pair(6, 7), pawn_b_6);
        board->place_piece(make_pair(7, 7), pawn_b_7);
        board->place_piece(make_pair(8, 7), pawn_b_8);

        i_curr_player = 0;
    }

    GameController::~GameController() {
        delete board;

        delete play_white;
        delete play_black;

        delete pawn_w_1;
        delete pawn_w_2;
        delete pawn_w_3;
        delete pawn_w_4;
        delete pawn_w_5;
        delete pawn_w_6;
        delete pawn_w_7;
        delete pawn_w_8;
        delete rook_w_1;
        delete rook_w_2;
        delete knight_w_1;
        delete knight_w_2;
        delete bishop_w_1;
        delete bishop_w_2;
        delete queen_w;
        delete king_w;

        delete pawn_b_1;
        delete pawn_b_2;
        delete pawn_b_3;
        delete pawn_b_4;
        delete pawn_b_5;
        delete pawn_b_6;
        delete pawn_b_7;
        delete pawn_b_8;
        delete rook_b_1;
        delete rook_b_2;
        delete knight_b_1;
        delete knight_b_2;
        delete bishop_b_1;
        delete bishop_b_2;
        delete queen_b;
        delete king_b;
    }

    Chessboard::Board* GameController::chessboard() {
        return board;
    }

    Chessplayer::Player* GameController::player(int _side) {
        if(_side > 1 || _side < 0) {
            throw invalid_argument(
                "GameController::player(): Argument out of range.");
        } else if(_side == 0) {
            return play_white;
        } else {
            return play_black;
        }
    }

    int GameController::current_player() {
        return i_curr_player;
    }
}
