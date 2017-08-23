/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PAWN_TEST_HPP
#define PAWN_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/pawn.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(pawn_white)
{
    Chessman::Pawn* pawn = new Chessman::Pawn(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, pawn->owner());
    delete pawn;
}

BOOST_AUTO_TEST_CASE(pawn_black)
{
    Chessman::Pawn* pawn = new Chessman::Pawn(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, pawn->owner());
    delete pawn;
}

BOOST_AUTO_TEST_CASE(pawn_archive_move)
{
    Chessman::Pawn* pawn = new Chessman::Pawn(Chessman::WHITE, make_pair(1, 1));
    pawn->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, pawn->last_move().first);
    BOOST_REQUIRE_EQUAL(2, pawn->last_move().second);
    BOOST_REQUIRE_EQUAL(true, pawn->moved());
    delete pawn;
}

#endif // PAWN_TEST_HPP
