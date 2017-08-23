/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KNIGHT_TEST_HPP
#define KNIGHT_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/knight.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(knight_white)
{
    Chessman::Knight* knight = new Chessman::Knight(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, knight->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, knight->owner());
    delete knight;
}

BOOST_AUTO_TEST_CASE(knight_black)
{
    Chessman::Knight* knight = new Chessman::Knight(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, knight->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, knight->owner());
    delete knight;
}

BOOST_AUTO_TEST_CASE(knight_archive_move)
{
    Chessman::Knight* knight = new Chessman::Knight(Chessman::WHITE, make_pair(1, 1));
    knight->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, knight->last_move().first);
    BOOST_REQUIRE_EQUAL(2, knight->last_move().second);
    BOOST_REQUIRE_EQUAL(true, knight->moved());
    delete knight;
}

#endif // KNIGHT_TEST_HPP