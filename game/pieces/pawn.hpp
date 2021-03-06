/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PAWN_HPP
#define PAWN_HPP

#include "piece.hpp"

/**
 * @brief This namespace contains all chess pieces related classes.
 */
namespace Chessman
{
    /**
     * @brief Pawn piece class.
     */
    class Pawn : public Piece {
    public:
        /**
         * @brief Constructor
         * @param Chessman::OWNER of the piece.
         * @param initial pair of coordinates of piece.
         */
        Pawn(int, pair<int, int>);

        /**
         * @brief Checks if move is valid and if it is it will identify what kind
         *        of move it is (like capturing, castling etc).
         * @param pair of coordinates of destination.
         * @param pointer to the Chessboard::Board.
         * @return Chessman::MOVES ID of a move.
         */
        const int identify_move(
            const pair<int, int>&,
            const vector<vector<shared_ptr<Chessman::Piece>>>&);
        /**
         * @brief Finds all legal moves for this piece.
         * @param pointer to the Chessboard::Board.
         * @return Vector of tuples of all moves except invalids moves. Every
         *         tuple contains coordinates (x, y) as a first pair of ints and
         *         type of a move (Chessman::MOVES) as a third int.
         */
        const vector<tuple<int, int, int>> list_moves(
            const vector<vector<shared_ptr<Chessman::Piece>>>& vb);

    private:
        /** Holds if pawn was promoted. Initially equals false. */
        bool f_promoted;
    };
}

#endif // PAWN_HPP
