/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KIPP_TEST_HPP
#define KIPP_TEST_HPP

#include "gamecontroller.hpp"
#include "ai/kipp.hpp"
#include "debug/log.hpp"

#include <memory>

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(random_move)
{
    Debug::Log::test_func_head("random_move");
    unique_ptr<Game::GameController> game {new Game::GameController};
    AI::KIPP::compute_move(0, 0, 0, game->chessboard());
    Debug::Log::test_func_foot("random_move");
}

#endif // KIPP_TEST_HPP
