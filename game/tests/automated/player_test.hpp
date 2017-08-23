/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PLAYER_TEST_HPP
#define PLAYER_TEST_HPP

#include "player/player.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(new_player_white)
{
    Chessplayer::Player* test_player = new Chessplayer::Player("Player1", Chessplayer::SIDE::WHITE);
    BOOST_REQUIRE_EQUAL(Chessplayer::SIDE::WHITE, test_player->side());
    BOOST_REQUIRE_EQUAL("Player1", test_player->name());
    delete test_player;
}

BOOST_AUTO_TEST_CASE(new_player_black)
{
    Chessplayer::Player* test_player = new Chessplayer::Player("Player2", Chessplayer::SIDE::BLACK);
    BOOST_REQUIRE_EQUAL(Chessplayer::SIDE::BLACK, test_player->side());
    BOOST_REQUIRE_EQUAL("Player2", test_player->name());
    delete test_player;
}

#endif // PLAYER_TEST_HPP