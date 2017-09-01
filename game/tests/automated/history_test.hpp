/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef HISTORY_TEST_HPP
#define HISTORY_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "history.hpp"

#define BOOST_TEST_MAIN

#include "includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Game;

#define VTUPLE7 vector<tuple<int, int, int, int, int, int, int>>

BOOST_AUTO_TEST_CASE(add_move)
{
    Debug::Log::test_func_head("add_move");
    History hist;
    hist.add_move(Move(2, 5, 2, 0, 4, 3, 1));
    VTUPLE7 test;
    test.push_back(make_tuple(2, 5, 2, 0, 4, 3, 1));
    TEST_VECTORS_OF_TUPLES_7(test, hist.moves_list());
    Debug::Log::test_func_foot("add_move");
}

BOOST_AUTO_TEST_CASE(add_move_2)
{
    Debug::Log::test_func_head("add_move_2");
    History hist;
    hist.add_move(Move(2, 5, 2, 0, 4, 3, 1));
    hist.add_move(Move(2, 5, 2, 0, 4, 3, 1));
    VTUPLE7 test;
    test.push_back(make_tuple(2, 5, 2, 0, 4, 3, 1));
    test.push_back(make_tuple(2, 5, 2, 0, 4, 3, 1));
    TEST_VECTORS_OF_TUPLES_7(test, hist.moves_list());
    Debug::Log::test_func_foot("add_move_2");
}

#endif // HISTORY_TEST_HPP
