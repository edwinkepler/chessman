/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PIECE_HPP
#define PIECE_HPP

#include <utility>
#include <string>
#include <vector>
#include <tuple>

#include "debug/log.hpp"

using namespace std;

/**
 * @brief This namespace contains all chess pieces related classes.
 */
namespace Chessman
{
    /**
     * @brief Enum for easier setting pieces types while constructing.
     */
    enum TYPE {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };

    /**
     * @brief Enum for easier setting pieces colors while constructing.
     */
    enum OWNER {
        WHITE,
        BLACK
    };

    /**
     * @brief Type of moves.
     */
    enum MOVES {
        INVALID,
        VALID,
        CAPTURE,
        EN_PASSANT,
        CASTLING,
        PROMOTION,
        PROCAPT // promotion and capturing at once
    };

    /**
     * @brief Base class for pieces.
     */
    class Piece {
    public:
        /**
        * @brief Constructor.
        * @param owner (Chessman::OWNER) of the piece.
        * @param coords Starting coordinates.
        */
        Piece(int, pair<int, int>);
        /**
        * @brief Deconstructor.
        */
        virtual ~Piece() {};

        /**
        * @brief Returns owner id (Chessman::OWNER).
        */
        const int owner();

        /**
        * @brief Returns piece type (Chessman::TYPE).
        */
        const int type();
        /**
        * @brief Returns unicode character representing chess piece.
        */
        const char* unicode();
        /**
        * @brief Adds move coordinates to Piece::v_history vector.
        * @param pair of coordinates to archive.
        */
        const void add_move(const pair<int, int>&);
        /**
        * @brief Returns last move coordinates.
        * @return Last move coordinates.
        */
        const pair<int, int> last_move();
        /**
        * @brief Sets Piece::f_moved flag to true or false.
        * @param Defines if piece moved.
        */
        const bool moved();
        /**
        * @brief Returns Piece::v_history vector of pairs.
        */
        const vector<pair<int, int>> history();

        /**
        * @brief Checks if move is valid and if it is it will identify what kind
        *        of move it is (like capturing, castling etc).
        * @param pair of coordinates of destination.
        * @param pointer to the Chessboard::Board.
        * @return Chessman::MOVES ID of a move.
        */
        virtual const int identify_move(
            const pair<int, int>&,
            const vector<vector<Chessman::Piece*>>&) = 0;
        /**
        * @brief Finds all legal moves for this piece.
        * @param pointer to the Chessboard::Board.
        * @return Vector of tuples of all moves except invalids moves. Every
        *         tuple contains coordinates (x, y) as a first pair of ints and
        *         type of a move (Chessman::MOVES) as a third int.
        */
        virtual const vector<tuple<int, int, int>> list_moves(
            const vector<vector<Chessman::Piece*>>&) = 0;

        const int check_straight_lines(
            int, int, int, int, const vector<vector<Chessman::Piece*>>&);
        const int check_diagonal_lines(
            int, int, int, int, const vector<vector<Chessman::Piece*>>&);

    private:
        /**
        * @brief Holds owner id (Chessman::OWNER).
        */
        int i_owner;
        /**
        * @brief Flag that tells if piece have been moved.
        */
        bool f_moved;

    protected:
        /**
        * @brief Hold unicode char.
        */
        const char* c_unicode;
        /**
        * @brief Holds piece type (Chessman::TYPE).
        */
        int i_type;
        /**
        * @brief Vector of moves stored in FILO fashion.
        */
        vector<pair<int, int>> v_history;

        Debug::Log log;
    };
}

#endif // PIECE_HPP
