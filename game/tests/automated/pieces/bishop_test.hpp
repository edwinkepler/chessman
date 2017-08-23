/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef BISHOP_TEST_HPP
#define BISHOP_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/bishop.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(bishop_white)
{
    Chessman::Bishop* bishop = new Chessman::Bishop(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, bishop->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, bishop->owner());
    delete bishop;
}

BOOST_AUTO_TEST_CASE(bishop_black)
{
    Chessman::Bishop* bishop = new Chessman::Bishop(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, bishop->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, bishop->owner());
    delete bishop;
}

BOOST_AUTO_TEST_CASE(bishop_archive_move)
{
    Chessman::Bishop* bishop = new Chessman::Bishop(Chessman::WHITE, make_pair(1, 1));
    bishop->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, bishop->last_move().first);
    BOOST_REQUIRE_EQUAL(2, bishop->last_move().second);
    BOOST_REQUIRE_EQUAL(true, bishop->moved());
    delete bishop;
}

#endif // BISHOP_TEST_HPP
