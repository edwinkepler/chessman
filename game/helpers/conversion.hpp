/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <array>
#include <utility>

#include "debug/log.hpp"

using namespace std;

namespace Helper
{
        const static array<char, 8> arr = {'a','b','c','d','e','f','g','h'};
        /**
         * @brief Helper method to convert characters to integers for chessboard
         * notation.
         * @param Character you want to convert.
         * @return Integer converted from given character.
         */
        int ctoi(char);
        /**
         * @brief Helper method to convert integers to characters for chessboard
         * notation.
         * @param Integer you want to convert.
         * @return Character converted from given integer.
         */
        char itoc(int);

        /**
         * @brief Helper method to add a value to x coord of a pair.
         * @param Pair of coordinates.
         * @param Integer value you want to change by.
         * @return Translated pair.
         */
        pair<int, int> transx(const pair<int, int>&, int);
        /**
         * @brief Helper method to add a value to y coord of a pair.
         * @param Pair of coordinates.
         * @param Integer value you want to change by.
         * @return Translated pair.
         */
        pair<int, int> transy(const pair<int, int>&, int);
}

#endif // CONVERSION_HPP
