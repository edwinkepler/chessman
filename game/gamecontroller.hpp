#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <utility>
#include <vector>

#include "pieces/pawn.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

#include "player/player.hpp"

#include "board/board.hpp"

namespace Game
{
    class GameController {
    public:
        GameController();
        ~GameController();

        void setup(int);
        Chessboard::Board* chessboard();
        Chessplayer::Player* player(int);

    private:
        Chessboard::Board* board;

        Chessman::Pawn* pawn_w_1;
        Chessman::Pawn* pawn_w_2;
        Chessman::Pawn* pawn_w_3;
        Chessman::Pawn* pawn_w_4;
        Chessman::Pawn* pawn_w_5;
        Chessman::Pawn* pawn_w_6;
        Chessman::Pawn* pawn_w_7;
        Chessman::Pawn* pawn_w_8;
        Chessman::Rook* rook_w_1;
        Chessman::Rook* rook_w_2;
        Chessman::Knight* knight_w_1;
        Chessman::Knight* knight_w_2;
        Chessman::Bishop* bishop_w_1;
        Chessman::Bishop* bishop_w_2;
        Chessman::Queen* queen_w;
        Chessman::King* king_w;

        Chessman::Pawn* pawn_b_1;
        Chessman::Pawn* pawn_b_2;
        Chessman::Pawn* pawn_b_3;
        Chessman::Pawn* pawn_b_4;
        Chessman::Pawn* pawn_b_5;
        Chessman::Pawn* pawn_b_6;
        Chessman::Pawn* pawn_b_7;
        Chessman::Pawn* pawn_b_8;
        Chessman::Rook* rook_b_1;
        Chessman::Rook* rook_b_2;
        Chessman::Knight* knight_b_1;
        Chessman::Knight* knight_b_2;
        Chessman::Bishop* bishop_b_1;
        Chessman::Bishop* bishop_b_2;
        Chessman::Queen* queen_b;
        Chessman::King* king_b;

        Chessplayer::Player* player_white;
        Chessplayer::Player* player_black;
    };
}

#endif // GAMECONTROLLER_HPP