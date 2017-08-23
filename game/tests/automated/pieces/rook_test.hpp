/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef ROOK_TEST_HPP
#define ROOK_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/rook.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(rook_white)
{
    Chessman::Rook* rook = new Chessman::Rook(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, rook->owner());
    delete rook;
}

BOOST_AUTO_TEST_CASE(rook_black)
{
    Chessman::Rook* rook = new Chessman::Rook(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, rook->owner());
    delete rook;
}

BOOST_AUTO_TEST_CASE(rook_archive_move)
{
    Chessman::Rook* rook = new Chessman::Rook(Chessman::WHITE, make_pair(1, 1));
    rook->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, rook->last_move().first);
    BOOST_REQUIRE_EQUAL(2, rook->last_move().second);
    BOOST_REQUIRE_EQUAL(true, rook->moved());
    delete rook;
}

#endif // ROOK_TEST_HPP
