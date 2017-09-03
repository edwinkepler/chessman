/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef GAMECONTROLLER_TEST_HPP
#define GAMECONTROLLER_TEST_HPP

#include <utility>
#include <vector>

#include "gamecontroller.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(init_standard_piece_w_1_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_1_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,
        test_game->chessboard()->point_piece(make_pair(1, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,
        test_game->chessboard()->point_piece(make_pair(1, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_1_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_2_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_2_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0,
        test_game->chessboard()->point_piece(make_pair(2, 2))->type());
    BOOST_REQUIRE_EQUAL(0,
        test_game->chessboard()->point_piece(make_pair(2, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_2_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_3_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_3_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0,
        test_game->chessboard()->point_piece(make_pair(3, 2))->type());
    BOOST_REQUIRE_EQUAL(0,
        test_game->chessboard()->point_piece(make_pair(3, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_3_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_4_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_4_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(4, 2))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(4, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_4_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_5_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_5_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(5, 2))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(5, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_5_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_6_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_6_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(6, 2))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(6, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_6_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_7_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_7_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(7, 2))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(7, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_7_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_8_2)
{
    Debug::Log::test_func_head("init_standard_piece_w_8_2");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(8, 2))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(8, 2))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_8_2");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_1_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_1_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(1, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_1_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_2_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_2_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, 
        test_game->chessboard()->point_piece(make_pair(2, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(2, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_2_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_3_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_3_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, 
        test_game->chessboard()->point_piece(make_pair(3, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(3, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_3_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_4_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_4_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(4, 
        test_game->chessboard()->point_piece(make_pair(4, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(4, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_4_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_5_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_5_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(5, 
        test_game->chessboard()->point_piece(make_pair(5, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(5, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_5_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_6_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_6_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, 
        test_game->chessboard()->point_piece(make_pair(6, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(6, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_6_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_7_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_7_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, 
        test_game->chessboard()->point_piece(make_pair(7, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(7, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_7_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_w_8_1)
{
    Debug::Log::test_func_head("init_standard_piece_w_8_1");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(8, 1))->type());
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(8, 1))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_w_8_1");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_1_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_1_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(1, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(1, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_1_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_2_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_2_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(2, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(2, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_2_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_3_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_3_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(3, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(3, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_3_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_4_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_4_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(4, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(4, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_4_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_5_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_5_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(5, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(5, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_5_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_6_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_6_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(6, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(6, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_6_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_7_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_7_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(7, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(7, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_7_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_8_7)
{
    Debug::Log::test_func_head("init_standard_piece_b_8_7");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, 
        test_game->chessboard()->point_piece(make_pair(8, 7))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(8, 7))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_8_7");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_1_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_1_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(1, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(1, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_1_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_2_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_2_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, 
        test_game->chessboard()->point_piece(make_pair(2, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(2, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_2_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_3_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_3_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, 
        test_game->chessboard()->point_piece(make_pair(3, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(3, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_3_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_4_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_4_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(4, 
        test_game->chessboard()->point_piece(make_pair(4, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(4, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_4_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_5_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_5_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(5, 
        test_game->chessboard()->point_piece(make_pair(5, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(5, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_5_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_6_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_6_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(3, 
        test_game->chessboard()->point_piece(make_pair(6, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(6, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_6_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_7_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_7_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(2, 
        test_game->chessboard()->point_piece(make_pair(7, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(7, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_7_8");
}

BOOST_AUTO_TEST_CASE(init_standard_piece_b_8_8)
{
    Debug::Log::test_func_head("init_standard_piece_b_8_8");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(8, 8))->type());
    BOOST_REQUIRE_EQUAL(1, 
        test_game->chessboard()->point_piece(make_pair(8, 8))->owner());
    delete test_game;
    Debug::Log::test_func_foot("init_standard_piece_b_8_8");
}

BOOST_AUTO_TEST_CASE(return_white_player)
{
    Debug::Log::test_func_head("return_white_player");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->player(0)->side());
    delete test_game;
    Debug::Log::test_func_foot("return_white_player");
}

BOOST_AUTO_TEST_CASE(return_black_player)
{
    Debug::Log::test_func_head("return_black_player");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(1, test_game->player(1)->side());
    delete test_game;
    Debug::Log::test_func_foot("return_black_player");
}

BOOST_AUTO_TEST_CASE(return_player_throw_if_argument_out_of_range)
{
    Debug::Log::test_func_head("return_player_throw_if_argument_out_of_range");
    Game::GameController* test_game = new Game::GameController;
    BOOST_CHECK_THROW(test_game->player(5), std::invalid_argument);
    delete test_game;
    Debug::Log::test_func_foot("return_player_throw_if_argument_out_of_range");
}

BOOST_AUTO_TEST_CASE(current_player_white)
{
    Debug::Log::test_func_head("current_player_white");
    Game::GameController* test_game = new Game::GameController;
    BOOST_REQUIRE_EQUAL(0, test_game->current_player());
    delete test_game;
    Debug::Log::test_func_foot("current_player_white");
}

BOOST_AUTO_TEST_CASE(make_a_move)
{
    Debug::Log::test_func_head("make_a_move");
    Game::GameController* test_game = new Game::GameController;
    test_game->move(make_pair(1, 2), make_pair(1, 3));
    BOOST_REQUIRE_EQUAL(false, 
        test_game->chessboard()->is_sqr_empty(make_pair(1, 3)));
    delete test_game;
    Debug::Log::test_func_foot("make_a_move");
}

BOOST_AUTO_TEST_CASE(make_a_char_int)
{
    Debug::Log::test_func_head("make_a_char_int");
    Game::GameController* test_game = new Game::GameController;
    test_game->move(make_pair('a', 2), make_pair('a', 3));
    BOOST_REQUIRE_EQUAL(false, 
        test_game->chessboard()->is_sqr_empty(make_pair(1, 3)));
    delete test_game;
    Debug::Log::test_func_foot("make_a_char_int");
}

BOOST_AUTO_TEST_CASE(make_a_move_invalid_argument_out_of_limits)
{
    Debug::Log::test_func_head("make_a_move_invalid_argument_out_of_limits");
    Game::GameController* test_game = new Game::GameController;
    BOOST_CHECK_THROW(test_game->move(make_pair(1, 2), make_pair(1, 9)),
        std::invalid_argument);
    delete test_game;
    Debug::Log::test_func_foot("make_a_move_invalid_argument_out_of_limits");
}

BOOST_AUTO_TEST_CASE(make_a_move_invalid_argument_empty_square)
{
    Debug::Log::test_func_head("make_a_move_invalid_argument_empty_square");
    Game::GameController* test_game = new Game::GameController;
    BOOST_CHECK_THROW(test_game->move(make_pair(1, 3), make_pair(1, 4)),
        std::invalid_argument);
    delete test_game;
    Debug::Log::test_func_foot("make_a_move_invalid_argument_empty_square");
}

BOOST_AUTO_TEST_CASE(current_player_black)
{
    Debug::Log::test_func_head("current_player_black");
    Game::GameController* test_game = new Game::GameController;
    test_game->move(make_pair(1, 2), make_pair(1, 3));
    BOOST_REQUIRE_EQUAL(1, test_game->current_player());
    delete test_game;
    Debug::Log::test_func_foot("current_player_black");
}

BOOST_AUTO_TEST_CASE(get_moves_history)
{
    Debug::Log::test_func_head("get_moves_history");
    Game::GameController* test_game = new Game::GameController;
    test_game->move(make_pair(7, 2), make_pair(7, 4));
    vector<string> test = {"1. g4"};
    auto result = test_game->moves_history();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    delete test_game;
    Debug::Log::test_func_foot("get_moves_history");
}

BOOST_AUTO_TEST_CASE(series_of_moves)
{
    Debug::Log::test_func_head("series_of_moves");
    Game::GameController* test_game = new Game::GameController;

    test_game->move(make_pair(5, 2), make_pair(5, 4));
    test_game->move(make_pair(1, 7), make_pair(1, 6));
    test_game->move(make_pair(6, 1), make_pair(4, 3));
    test_game->move(make_pair(2, 7), make_pair(2, 6));
    test_game->move(make_pair(7, 1), make_pair(6, 3));
    test_game->move(make_pair(3, 7), make_pair(3, 6));

    // test_game->move(make_pair(5, 1), make_pair(7, 1));

    delete test_game;
    Debug::Log::test_func_foot("series_of_moves");
}

#endif // GAMECONTROLLER_TEST_HPP
