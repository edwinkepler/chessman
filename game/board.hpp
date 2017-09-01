/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <utility>

#include <exception>

#include "debug/log.hpp"

#include "pieces/piece.hpp"

using namespace std;

/**
 * @brief This namespace contains all board related classes and logic.
 */
namespace Chessboard
{
    /**
     * @brief   Chess board class.
     * @details This class hold methods for manageing pieces on a chess board.
     *
     *          You can access pieces (for moving by movePiece()) by passing
     *          x and y value (in Cartesian coordinate system manner) of
     *          a square where piece currently is and x and y value (Cartesian
     *          again) of a square where you want piece to be placed.
     */
    class Board {
    public:
        /**
        * @brief   Constructor
        * @details This will prepare 2d vector for holding pieces.
        */
        Board();

        /**
        * @brief Returns pointer to Chessman::Piece at given square.
        * @param Pair of coordinates (x, y).
        * @return Pointer to Chessman::Piece.
        */
        Chessman::Piece* point_piece(const pair<int, int>&);

        /**
        * @brief   Will move piece.
        * @details This will use putPiece() with destination coordinates for a
        *          square and nullify by nullifySquare() a square from where
        *          piece was moved.
        *
        *          If any of these functions can't be done (e.g. because of
        *          invalid parameters invalid_argument will be thrown).
        * @param &from is a pair of coordinates (x, y) as a integers.
        * @param &to is a pair of destination (x, y) as a integers.
        * @throw   invalid_argument if coords are out of board borders or when
        *          piece can't be moved (e.g. destination square is already
        *          occupied, or user want's to move from empty square).
        */
        void move_piece(const pair<int, int>&, const pair<int, int>&);

        /**
        * @brief putPiece
        * @param Pair of coordinates (x, y) as a integers.
        * @param Chessman::Piece pointer.
        * @throw invalid_argument if given coordinates are out of board border.
        */
        void place_piece(const pair<int, int>&, Chessman::Piece*);

        /**
        * @brief Checks if given square is empty.
        * @param Pair of coordinates (x, y) as a integers.
        * @return Boolean TRUE if given square is empty (equals nullptr) or 
        *         FALSE otherwise.
        * @throw invalid_argument if given coordinates are out of board border.
        */
        bool is_sqr_empty(const pair<int, int>&);
        /**
        * @brief Returns 2d vector of a board.
        * @return vector<vector<Chessman::Piece*>> v_board.
        */
        const vector<vector<Chessman::Piece*>> board();

    private:
        /**
        * @brief Checks if given pair of coordinates is within board limits.
        * @param Pair of coordinates (x, y) as a integers.
        * @return Boolean TRUE if given coords are in within limits or FALSE 
        *         otherwise.
        */
        bool is_within_limit(const pair<int, int>&);
        /**
        * @brief Will set a pointer at given square to NULL (empty it).
        * @param &c is a pair of coordinates (x, y) as a integers.
        * @throw invalid_argument if given coordinates are out of board border
        *        or when pointer at given square is already NULL.
        */
        void nullify(const pair<int, int>&);

        /**
        * @brief 2d vector that holds all pointers for chess pieces.
        */
        vector<vector<Chessman::Piece*>> v_board;

        Debug::Log log;
    };
}

#endif // BOARD_HPP
