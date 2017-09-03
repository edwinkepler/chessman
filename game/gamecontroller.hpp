/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

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
#include "history.hpp"
#include "board.hpp"

/**
 * @brief This namespace contains main interface for game of chess.
 */
namespace Game
{    
    /**
     * @brief   Main inteerface for game of chess.
     * @details This class is a main interface, way of controlling game. It is
     *          keeping track of movement, state of current match and plays.
     */
    class GameController {
    public:
        /**
        * @brief   Constructor
        * @details Prepare all pieces by placing them on board.
        */
        GameController();
        /**
        * @brief   Decnstructor
        * @details Delete all pieces, board, players and any other objects
        *          created during playing the game.
        */
        ~GameController();

        /**
        * @brief Returns pointer to Chessman::Board.
        * @return Pointer to Chessman::Board.
        */
        Chessboard::Board* chessboard();
        /**
        * @brief Returns pointer to Chessplayer::Player of a given side.
        * @param Enum Chessplayer::SIDE.
        * @return Pointer to Chessplayer::Player.
        * @throw invalid_argument if argument is not one of Chessplayer::SIDE.
        */
        Chessplayer::Player* player(int);
        /**
        * @brief Returns Chessplayer::SIDE of a player that turn is currently in
        *        play.
        * @return Chessplayer::SIDE.
        */
        int current_player();
        /**
        * @brief Return history of moves.
        * @return Vector of strings containing history of moves.
        */
        vector<string> moves_history();
        /**
        * @brief   Will move piece.
        * @details Move will be identified and if anything but invalid move will
        *          happen. Pieces are moved on Chessboard::Board and board will
        *          check if arguments are valid (exception will be thrown if 
        *          not).
        * @param Pair of coordinates (x, y) as a integers of moved piece.
        * @param Pair of destination (x, y) as a integers of a destination.
        * @return Chessman::MOVE type of the move.
        */
        int move(const pair<int, int>&, const pair<int, int>&);
        /**
        * @brief   Will move piece.
        * @details Move will be identified and if anything but invalid move will
        *          happen. Pieces are moved on Chessboard::Board and board will
        *          check if arguments are valid (exception will be thrown if 
        *          not).
        * @param Pair of coordinates (x, y) as a char and int of moved piece.
        * @param Pair of destination (x, y) as a char and int of a destination.
        * @return Chessman::MOVE type of the move.
        */
        int move(const pair<char, int>&, const pair<char, int>&);
        /**
        * @brief  Checkmate check.
        * @return Game::MODIFICATION
        */
        const int checkmate();
        /** TODO */
        int promotion();


    private:
        const void add_moves_to_pieces(Chessboard::Board*, const Chessman::Piece*);
        /**
        * @brief Player currently playing his turn.
        */
        int i_curr_player = 0;

        History hist;

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
    };
}

#endif // GAMECONTROLLER_HPP
