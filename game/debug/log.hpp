/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "board.hpp"
#include "player.hpp"
#include "pieces/piece.hpp"

using namespace std;

/**
 * @brief This namespace contains debug classes.
 */
namespace Debug
{
    /**
     * @brief Logging to stdout and dumping info about objects.
     */
    class Log {
    public:
        /**
        * @brief Log standard info to stdout. Can be chained.
        * @param String to print.
        * @return Log object to enable chaining.
        */
        Log& log_i(string);
        /**
        * @brief Print new line. Can be chained.
        * @return Log object to enable chaining.
        */
        Log& n();
        /**
        * @brief Print tab. Can be chained.
        * @return Log object to enable chaining.
        */
        Log& t();

        /**
        * @brief Print coordinates. Can be chained.
        * @param Pair of coordinates to print.
        * @return Log object to enable chaining.
        */
        Log& log_coords(pair<int, int>&);
        /**
        * @brief Print coordinates. Can be chained.
        * @param Pair of coordinates to print.
        * @param Pair of coordinates to print.
        * @return Log object to enable chaining.
        */
        Log& log_coords(pair<int, int>&, pair<int, int>&);

        /**
        * @brief Print all information about Chessboard::Board.
        * @param Pointer to Chessboard::Board object.
        */
        void dump_board(Chessboard::Board*);
        /**
        * @brief Print all information about Chessman::Piece.
        * @param Pointer to Chessman::Piece object.
        */
        void dump_piece(Chessman::Piece*);

        /**
        * @brief Log standard info to stdout.
        * @param String to print.
        */
        void operator<<(string);
        /**
        * @brief Print all information about Chessboard::Board.
        * @param Pointer to Chessboard::Board object.
        */
        void operator<<(Chessboard::Board*);
        /**
        * @brief Print all information about Chessman::Piece.
        * @param Pointer to Chessman::Piece object.
        */
        void operator<<(Chessman::Piece*);
    };
}

#endif // LOG_HPP
