/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef DUMP_HPP
#define DUMP_HPP

#include <iostream>

#include "pieces/piece.hpp"
#include "board.hpp"

using namespace std;

class Board;
class Piece;

namespace Debug
{
    class Dump {
    public:
        /**
         * @brief Print all information about Chessboard::Board.
         * @param Pointer to Chessboard::Board object.
         */
        void board(shared_ptr<Chessboard::Board>);
        /**
         * @brief Print all information about Chessman::Piece.
         * @param Pointer to Chessman::Piece object.
         */
        void piece(shared_ptr<Chessman::Piece>);

        /**
         * @brief Print all information about Chessboard::Board.
         * @param Pointer to Chessboard::Board object.
         */
        void operator<<(shared_ptr<Chessboard::Board>);
        /**
         * @brief Print all information about Chessman::Piece.
         * @param Pointer to Chessman::Piece object.
         */
        void operator<<(shared_ptr<Chessman::Piece>);
    };
}

#endif // DUMP_HPP
