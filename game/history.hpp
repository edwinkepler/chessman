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
        PROCAPT // promotion and capturing at once
    };
    /**
     * @brief Modifications for moves.
     */
    enum MODIFICATION {
        NONE,
        CHECK,
        MATE,
        CASTLING_LONG,
        CASTLING_SHORT,
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
         * @details Takes all needed informations in predefined fashion in order
         *          to be able to convert these information to more advanced
         *          notations. Positions of arguments is very important.
         * @param Game::STATE.
         * @param Starting X coord of a moved piece.
         * @param Starting Y coord of a moved piece.
         * @param Ending X coord of a moved piece.
         * @param Ending Y coord of a moved piece.
         * @param Game::TYPE (same as Chessman::TYPE) of a moved piece.
         * @param X coord of a piece effected by moved piece.
         * @param Y coord of a piece effected by moved piece.
         * @param Game::TYPE (same as Chessman::TYPE) of a piece effected by 
         *        moved piece.
         */
        Move(int, int, int, int, int, int, int, int, int);
        /**
         * @brief Deconstructor.
         */
        ~Move();

        /** Game::STATE - what kind of a move is this. */
        int state;
        /** Game::MOD - modification to move like check, kind of castling.*/
        int mod;
        /** Starting X coord of a moved piece. */
        int x1;
        /** Starting Y coord of a moved piece. */
        int y1;
        /** Ending X coord of a moved piece. */
        int x2;
        /** Ending Y coord of a moved piece. */
        int y2;
        /** Game::TYPE (same as Chessman::TYPE) of a moved piece. */
        int type1;
        /** 
         * @brief Game::TYPE (same as Chessman::TYPE) of a piece effected by 
         *        moved piece.
         */
        int type2;
        /** Game::TYPE (same as Chessman::TYPE) piece promoted to. */
        int promo;
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
        vector<Move> moves_list();

        /**
         * @brief Creates Algebraic Notation of moves stored in 
         *        vector<Move> mv_list.
         * @return Vector of string with AN moves.
         */
        vector<string> moves_list_an();

        /**
         * @brief Returns how many plays (tourns when white and black player
         *        already moved) passed.
         * @return Number of plays.
         */
        int n_of_plays();

    private:
        /** Y coord of a piece effected by moved piece */
        vector<Move> mv_list;
        /** Number of turns (plays) passed. */
        int plays = 1;
    };
}

#endif // HISTORY_HPP
