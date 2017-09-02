#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <array>

namespace Helper
{
        const static std::array<char, 8> arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
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
}

#endif // CONVERSION_HPP
