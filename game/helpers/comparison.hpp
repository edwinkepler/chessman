/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "debug/log.hpp"

using namespace std;

namespace Helper
{
    /**
     * @brief Helper method to check if tuple of three integers (pair of moves 
     *        and third integer as a move indicator - result of 
     *        Chessman::Piece::list_moves()) contains pair of moves (second 
     *        argument). 
     * @param Vector of tuples, result of Chessman::Piece::list_moves().
     * @param Pair of coordinates of a move.
     * @return True if contains, false if not.
     */
    bool contains(const vector<tuple<int, int, int>>&, const pair<int, int>&);

    /**
     * @brief Checks if coord x is greater in LH argument then x of RH argument.
     * @param Pair of coordinates of a move.
     * @param Pair of coordinates of a move.
     * @return True if greater, false if not.
     */
    bool greaterx(const pair<int, int>&, const pair<int, int>&);
    /**
     * @brief Checks if coord y is greater in LH argument then y of RH argument.
     * @param Pair of coordinates of a move.
     * @param Pair of coordinates of a move.
     * @return True if greater, false if not.
     */
    bool greatery(const pair<int, int>&, const pair<int, int>&);
}

#endif // COMPARISON_HPP
