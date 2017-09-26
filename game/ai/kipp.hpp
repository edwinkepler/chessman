/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KIPP_HPP
#define KIPP_HPP

#include <tuple>
#include <vector>
#include <utility>
#include <random>
#include <algorithm>

#include "debug/log.hpp"
#include "pieces/piece.hpp"
#include "board.hpp"

using namespace std;

/**
 * @brief This namespace contains everything AI related.
 */
namespace AI
{
    /**
     * @brief Simple chess engine.
     */
    class KIPP {
    public:
        /**
         * @brief Compute move.
         * @param Depth of a moves.
         * @param Side.
         * @param Time left in miliseconds.
         * @param Chessboard.
         * @return x1, y1, x2, y2 of a computed move.
         */
        static const tuple<int, int, int, int> compute_move(int, int, int, shared_ptr<Chessboard::Board>);
    };
}

#endif // KIPP_HPP
