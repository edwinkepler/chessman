/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef QUEEN_TEST_HPP
#define QUEEN_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include <vector>
#include <utility>
#include <tuple>
#include <memory>

#include "pieces/queen.hpp"
#include "pieces/rook.hpp"
#include "board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(queen_white)
{
    Debug::Log::test_func_head("queen_white");
    shared_ptr<Queen> queen {new Queen(Chessman::WHITE, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, queen->owner());
    Debug::Log::test_func_foot("queen_white");
}

BOOST_AUTO_TEST_CASE(queen_black)
{
    Debug::Log::test_func_head("queen_black");
    shared_ptr<Queen> queen {new Queen(Chessman::BLACK, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, queen->owner());
    Debug::Log::test_func_foot("queen_black");
}

BOOST_AUTO_TEST_CASE(queen_archive_move)
{
    Debug::Log::test_func_head("queen_archive_move");
    shared_ptr<Queen> queen {new Queen(Chessman::WHITE, make_pair(1, 1))};
    queen->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, queen->last_move().first);
    BOOST_REQUIRE_EQUAL(2, queen->last_move().second);
    BOOST_REQUIRE_EQUAL(true, queen->moved());
    Debug::Log::test_func_foot("queen_archive_move");
}

BOOST_AUTO_TEST_CASE(queen_valid_move)
{
    Debug::Log::test_func_head("queen_valid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(7, 7), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_2)
{
    Debug::Log::test_func_head("queen_valid_move_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(3, 3), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_2");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_3)
{
    Debug::Log::test_func_head("queen_valid_move_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 7), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_3");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_4)
{
    Debug::Log::test_func_head("queen_valid_move_4");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(6, 2), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_4");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_5)
{
    Debug::Log::test_func_head("queen_valid_move_5");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 4), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_5");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_6)
{
    Debug::Log::test_func_head("queen_valid_move_6");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(5, 4), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_6");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_7)
{
    Debug::Log::test_func_head("queen_valid_move_7");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 1), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_7");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_8)
{
    Debug::Log::test_func_head("queen_valid_move_8");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 8), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_8");
}

BOOST_AUTO_TEST_CASE(queen_invalid_move)
{
    Debug::Log::test_func_head("queen_invalid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(1, 1))};
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(2, 4), test_board->board()));
    Debug::Log::test_func_foot("queen_invalid_move");
}

BOOST_AUTO_TEST_CASE(queen_valid_move_capture)
{
    Debug::Log::test_func_head("queen_valid_move_capture");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(4, 6))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 6), test_board->board()));
    Debug::Log::test_func_foot("queen_valid_move_capture");
}

BOOST_AUTO_TEST_CASE(queen_list_legal_moves)
{
    Debug::Log::test_func_head("queen_list_legal_moves");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Queen> test_piece {new Queen(Chessman::WHITE, make_pair(6, 6))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(5, 5))};
    shared_ptr<Rook> test_piece_3 {new Rook(Chessman::WHITE, make_pair(6, 4))};
    test_board->place_piece(make_pair(6, 6), test_piece);
    test_board->place_piece(make_pair(5, 5), test_piece_2);
    test_board->place_piece(make_pair(6, 4), test_piece_3);
    VTUPLE v = {make_tuple(6, 8, 1), make_tuple(6, 7, 1), make_tuple(7, 6, 1),
                make_tuple(8, 6, 1), make_tuple(7, 7, 1), make_tuple(8, 8, 1),
                make_tuple(5, 7, 1), make_tuple(4, 8, 1), make_tuple(6, 5, 1),
                make_tuple(1, 6, 1), make_tuple(2, 6, 1), make_tuple(3, 6, 1),
                make_tuple(4, 6, 1), make_tuple(5, 6, 1), make_tuple(5, 5, 2),
                make_tuple(7, 5, 1), make_tuple(8, 4, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("queen_list_legal_moves");
}

#endif // QUEEN_TEST_HPP
