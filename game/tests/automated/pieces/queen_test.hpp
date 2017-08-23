/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef QUEEN_TEST_HPP
#define QUEEN_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/queen.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(queen_white)
{
    Chessman::Queen* queen = new Chessman::Queen(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, queen->owner());
    delete queen;
}

BOOST_AUTO_TEST_CASE(queen_black)
{
    Chessman::Queen* queen = new Chessman::Queen(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, queen->owner());
    delete queen;
}

BOOST_AUTO_TEST_CASE(queen_archive_move)
{
    Chessman::Queen* queen = new Chessman::Queen(Chessman::WHITE, make_pair(1, 1));
    queen->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, queen->last_move().first);
    BOOST_REQUIRE_EQUAL(2, queen->last_move().second);
    BOOST_REQUIRE_EQUAL(true, queen->moved());
    delete queen;
}

#endif // QUEEN_TEST_HPP
