/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef GAMECONTROLLER_TEST_HPP
#define GAMECONTROLLER_TEST_HPP

#include "gamecontroller.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(init_standard_piece_w_1_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(Chessman::PAWN, test_game->chessboard()->point_piece(make_pair(1, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_game->chessboard()->point_piece(make_pair(1, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_2_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(2, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(2, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_3_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(3, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(3, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_4_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(4, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(4, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_5_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(5, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(5, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_6_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(6, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(6, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_7_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(7, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(7, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_8_2)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(8, 2))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(8, 2))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_1_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(1, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_2_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, test_game->chessboard()->point_piece(make_pair(2, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(2, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_3_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, test_game->chessboard()->point_piece(make_pair(3, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(3, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_4_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(4, test_game->chessboard()->point_piece(make_pair(4, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(4, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_5_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(5, test_game->chessboard()->point_piece(make_pair(5, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(5, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_6_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, test_game->chessboard()->point_piece(make_pair(6, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(6, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_7_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, test_game->chessboard()->point_piece(make_pair(7, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(7, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_8_1)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(8, 1))->type());
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(8, 1))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_1_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(1, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(1, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_2_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(2, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(2, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_3_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(3, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(3, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_4_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(4, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(4, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_5_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(5, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(5, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_6_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(6, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(6, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_7_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(7, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(7, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_8_7)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->chessboard()->point_piece(make_pair(8, 7))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(8, 7))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_1_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(1, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(1, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_2_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, test_game->chessboard()->point_piece(make_pair(2, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(2, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_3_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, test_game->chessboard()->point_piece(make_pair(3, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(3, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_4_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(4, test_game->chessboard()->point_piece(make_pair(4, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(4, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_5_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(5, test_game->chessboard()->point_piece(make_pair(5, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(5, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_6_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, test_game->chessboard()->point_piece(make_pair(6, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(6, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_7_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, test_game->chessboard()->point_piece(make_pair(7, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(7, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_8_8)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(8, 8))->type());
    BOOST_REQUIRE_EQUAL(1, test_game->chessboard()->point_piece(make_pair(8, 8))->owner());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(return_white_player)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->player(0)->side());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(return_black_player)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->player(1)->side());
    delete test_game;
}

BOOST_AUTO_TEST_CASE(return_player_throw_if_argument_out_of_range)
{
    Game::GameController* test_game = new Game::GameController;
    BOOST_CHECK_THROW(test_game->player(5), std::invalid_argument);
    delete test_game;
}

#endif // GAMECONTROLLER_TEST_HPP
