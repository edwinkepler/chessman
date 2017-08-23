/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KING_TEST_HPP
#define KING_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/king.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(king_white)
{
    Chessman::King* king = new Chessman::King(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KING, king->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, king->owner());
    delete king;
}

BOOST_AUTO_TEST_CASE(king_black)
{
    Chessman::King* king = new Chessman::King(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KING, king->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, king->owner());
    delete king;
}

BOOST_AUTO_TEST_CASE(king_archive_move)
{
    Chessman::King* king = new Chessman::King(Chessman::WHITE, make_pair(1, 1));
    king->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, king->last_move().first);
    BOOST_REQUIRE_EQUAL(2, king->last_move().second);
    BOOST_REQUIRE_EQUAL(true, king->moved());
    delete king;
}

#endif // KING_TEST_HPP