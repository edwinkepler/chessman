/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef COMPARE_BOARD_HPP
#define COMPARE_BOARD_HPP

#include <vector>

#include "board.hpp"

#include <boost/test/unit_test.hpp>

using namespace std;

void TEST_BOARD_IF_NOT_EQUAL(vector<vector<Chessman::Piece*>> _lb, vector<vector<Chessman::Piece*>> _rb) {
    bool equal = true;
    for(int i = 0; i < _lb.size(); ++i) {
        for(int j = 0; j < _lb.size(); ++j) {
            if(_lb[i][j] != _rb[i][j]) {
                equal = false;
            }
        }
    }
    if(!equal) {
        BOOST_CHECK(true);
    } else {
        BOOST_FAIL("LH != RH");
    }
}

#endif // COMPARE_BOARD_HPP
