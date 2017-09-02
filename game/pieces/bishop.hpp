/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <utility>

#include "piece.hpp"

/**
 * @brief This namespace contains all chess pieces related classes.
 */
namespace Chessman
{
    /**
     * @brief Bishop piece class.
     */
    class Bishop : public Piece {
    public:
        /**
        * @brief Constructor.
        * @param owner Chessman::OWNER of the piece.
        * @param initial pair of coordinates.
        */
        Bishop(int, pair<int, int>);

        /**
        * @brief Checks if move is valid and if it is it will identify what kind
        *        of move it is (like capturing, castling etc).
        * @param pair of coordinates of destination.
        * @param pointer to the Chessboard::Board.
        * @return Chessman::MOVES ID of a move.
        */
        const int identify_move(
            const pair<int, int>&,
            const vector<vector<Chessman::Piece*>>&);
    };
}

#endif // BISHOP_HPP
