/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <vector>
#include <utility>
#include <tuple>

using namespace std;

/**
 * @brief This namespace contains main interface for game of chess.
 */
namespace Game {
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
     * @brief Type of moves.
     */
    enum STATE {
        EMPTY,
        VALID,
        CAPTURE,
        EN_PASSANT,
        CASTLING,
        PROMOTION,
        PROCAPT, // promotion and capturing at once
        CHECK,
        MATE,
        STALE,
        WHITE_WIN,
        BLACK_WIN,
        DRAW
    };

    /**
     * @brief Class storing move sets.
     */
    class Move {
    public:
        /**
         * @brief Constructor.
         * @param Game::STATE.
         * @param X coord of a moved piece.
         * @param Y coord of a moved piece.
         * @param Game::TYPE (same as Chessman::TYPE) of a moved piece.
         * @param X coord of a piece effected by moved piece.
         * @param Y coord of a piece effected by moved piece.
         * @param Game::TYPE (same as Chessman::TYPE) of a piece effected by 
         *        moved piece.
         */
        Move(int, int, int, int, int, int, int);
        /**
         * @brief Deconstructor.
         */
        ~Move();

        /** Game::STATE */
        int state;
        /** X coord of a moved piece */
        int x1;
        /** Y coord of a moved piece */
        int y1;
        /** Game::TYPE (same as Chessman::TYPE) of a moved piece */
        int type1;
        /** X coord of a piece effected by moved piece */
        int x2;
        /** Y coord of a piece effected by moved piece */
        int y2;
        /** 
         * @brief Game::TYPE (same as Chessman::TYPE) of a piece effected by 
         *        moved piece.
         */
        int type2;
    };

    /**
     * @brief Class storing move history.
     */
    class History {
    public:
        /**
         * @brief Constructor.
         */
        ~History();

        /**
         * @brief Adds move to history.
         * @param Game::Move object to store.
         */
        const void add_move(Move);

        /**
         * @brief Returns list of moves in a form of tuples of integers.
         * @return List of moves in a form of tuples of integers.
         */
        vector<tuple<int, int, int, int, int, int, int>> moves_list();

        /** TODO */
        int n_of_plays();
        /** TODO */
        vector<string> to_an();
    private:
        /** Y coord of a piece effected by moved piece */
        vector<Move> mv_list;
        /** Number of turns (plays) passed. */
        int play = 1;
    };
}

#endif // HISTORY_HPP
