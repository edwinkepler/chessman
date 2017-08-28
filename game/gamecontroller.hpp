#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <utility>
#include <vector>

#include <exception>

#include "pieces/pawn.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

#include "player.hpp"

#include "board.hpp"

namespace Game
{
    class GameController {
    public:
        GameController();
        ~GameController();

        Chessboard::Board* chessboard();
        Chessplayer::Player* player(int);
        int current_player();
        void move(const pair<int, int>&, const pair<int, int>&);
        void move(const pair<char, int>&, const pair<char, int>&);

    private:
        int i_curr_player = 0;

        Chessboard::Board* board = new Chessboard::Board();

        Chessplayer::Player* play_white = new Chessplayer::Player("Player1", 0);
        Chessplayer::Player* play_black = new Chessplayer::Player("Player2", 1);

        Chessman::Pawn* pawn_w_1 = new Chessman::Pawn(0, make_pair(1, 2));
        Chessman::Pawn* pawn_w_2 = new Chessman::Pawn(0, make_pair(2, 2));
        Chessman::Pawn* pawn_w_3 = new Chessman::Pawn(0, make_pair(3, 2));
        Chessman::Pawn* pawn_w_4 = new Chessman::Pawn(0, make_pair(4, 2));
        Chessman::Pawn* pawn_w_5 = new Chessman::Pawn(0, make_pair(5, 2));
        Chessman::Pawn* pawn_w_6 = new Chessman::Pawn(0, make_pair(6, 2));
        Chessman::Pawn* pawn_w_7 = new Chessman::Pawn(0, make_pair(7, 2));
        Chessman::Pawn* pawn_w_8 = new Chessman::Pawn(0, make_pair(8, 2));
        Chessman::Rook* rook_w_1 = new Chessman::Rook(0, make_pair(1, 1));
        Chessman::Rook* rook_w_2 = new Chessman::Rook(0, make_pair(8, 1));
        Chessman::Knight* knight_w_1 = new Chessman::Knight(0, make_pair(2, 1));
        Chessman::Knight* knight_w_2 = new Chessman::Knight(0, make_pair(7, 1));
        Chessman::Bishop* bishop_w_1 = new Chessman::Bishop(0, make_pair(3, 1));
        Chessman::Bishop* bishop_w_2 = new Chessman::Bishop(0, make_pair(6, 1));
        Chessman::Queen* queen_w = new Chessman::Queen(0, make_pair(4, 1));
        Chessman::King* king_w = new Chessman::King(0, make_pair(5, 1));

        Chessman::Pawn* pawn_b_1 = new Chessman::Pawn(1, make_pair(1, 7));
        Chessman::Pawn* pawn_b_2 = new Chessman::Pawn(1, make_pair(2, 7));
        Chessman::Pawn* pawn_b_3 = new Chessman::Pawn(1, make_pair(3, 7));
        Chessman::Pawn* pawn_b_4 = new Chessman::Pawn(1, make_pair(4, 7));
        Chessman::Pawn* pawn_b_5 = new Chessman::Pawn(1, make_pair(5, 7));
        Chessman::Pawn* pawn_b_6 = new Chessman::Pawn(1, make_pair(6, 7));
        Chessman::Pawn* pawn_b_7 = new Chessman::Pawn(1, make_pair(7, 7));
        Chessman::Pawn* pawn_b_8 = new Chessman::Pawn(1, make_pair(8, 7));
        Chessman::Rook* rook_b_1 = new Chessman::Rook(1, make_pair(1, 8));
        Chessman::Rook* rook_b_2 = new Chessman::Rook(1, make_pair(8, 8));
        Chessman::Knight* knight_b_1 = new Chessman::Knight(1, make_pair(2, 8));
        Chessman::Knight* knight_b_2 = new Chessman::Knight(1, make_pair(7, 8));
        Chessman::Bishop* bishop_b_1 = new Chessman::Bishop(1, make_pair(3, 8));
        Chessman::Bishop* bishop_b_2 = new Chessman::Bishop(1, make_pair(6, 8));
        Chessman::Queen* queen_b = new Chessman::Queen(1, make_pair(4, 8));
        Chessman::King* king_b = new Chessman::King(1, make_pair(5, 8));

        int ctoi(char);
    };
}

#endif // GAMECONTROLLER_HPP
