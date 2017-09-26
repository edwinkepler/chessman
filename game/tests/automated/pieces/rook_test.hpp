/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef ROOK_TEST_HPP
#define ROOK_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>
#include <memory>

#include "pieces/rook.hpp"
#include "board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(rook_white)
{
    Debug::Log::test_func_head("rook_white");
    shared_ptr<Rook> rook {new Rook(Chessman::WHITE, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, rook->owner());
    Debug::Log::test_func_foot("rook_white");
}

BOOST_AUTO_TEST_CASE(rook_black)
{
    Debug::Log::test_func_head("rook_black");
    shared_ptr<Rook> rook {new Rook(Chessman::BLACK, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, rook->owner());
    Debug::Log::test_func_foot("rook_black");
}

BOOST_AUTO_TEST_CASE(rook_archive_move)
{
    Debug::Log::test_func_head("rook_archive_move");
    shared_ptr<Rook> rook {new Rook(Chessman::WHITE, make_pair(1, 1))};
    rook->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, rook->last_move().first);
    BOOST_REQUIRE_EQUAL(2, rook->last_move().second);
    BOOST_REQUIRE_EQUAL(true, rook->moved());
    Debug::Log::test_func_foot("rook_archive_move");
}

BOOST_AUTO_TEST_CASE(rook_valid_move)
{
    Debug::Log::test_func_head("rook_valid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::OWNER::WHITE, make_pair(1, 1))};
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 8), test_board->board()));
    Debug::Log::test_func_foot("rook_valid_move");
}

BOOST_AUTO_TEST_CASE(rook_valid_move_2)
{
    Debug::Log::test_func_head("rook_valid_move_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(1, 1))};
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(8, 1), test_board->board()));
    Debug::Log::test_func_foot("rook_valid_move_2");
}

BOOST_AUTO_TEST_CASE(rook_valid_move_3)
{
    Debug::Log::test_func_head("rook_valid_move_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 5), test_board->board()));
    Debug::Log::test_func_foot("rook_valid_move_3");
}

BOOST_AUTO_TEST_CASE(rook_invalid_move)
{
    Debug::Log::test_func_head("rook_invalid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(5, 5), test_board->board()));
    Debug::Log::test_func_foot("rook_invalid_move");
}

BOOST_AUTO_TEST_CASE(rook_valid_move_capture)
{
    Debug::Log::test_func_head("rook_valid_move_capture");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(4, 6))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 6), test_board->board()));
    Debug::Log::test_func_foot("rook_valid_move_capture");
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves)
{
    Debug::Log::test_func_head("rook_list_legal_moves");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(1, 1))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(1, 8))};
    shared_ptr<Rook> test_piece_3 {new Rook(Chessman::WHITE, make_pair(5, 1))};
    test_board->place_piece(make_pair(1, 1), test_piece);
    test_board->place_piece(make_pair(1, 8), test_piece_2);
    test_board->place_piece(make_pair(5, 1), test_piece_3);
    VTUPLE v = {make_tuple(1, 2, 1), make_tuple(1, 3, 1), make_tuple(1, 4, 1),
                make_tuple(1, 5, 1), make_tuple(1, 6, 1), make_tuple(1, 7, 1),
                make_tuple(1, 8, 2), make_tuple(2, 1, 1), make_tuple(3, 1, 1),
                make_tuple(4, 1, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("rook_list_legal_moves");
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves_2)
{
    Debug::Log::test_func_head("rook_list_legal_moves_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(2, 2))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(2, 3))};
    shared_ptr<Rook> test_piece_3 {new Rook(Chessman::WHITE, make_pair(3, 2))};
    test_board->place_piece(make_pair(2, 2), test_piece);
    test_board->place_piece(make_pair(2, 3), test_piece_2);
    test_board->place_piece(make_pair(3, 2), test_piece_3);
    VTUPLE v = {make_tuple(1, 2, 1), make_tuple(2, 1, 1), make_tuple(2, 3, 2)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("rook_list_legal_moves_2");
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves_3)
{
    Debug::Log::test_func_head("rook_list_legal_moves_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Rook> test_piece {new Rook(Chessman::WHITE, make_pair(6, 5))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(4, 5))};
    shared_ptr<Rook> test_piece_3 {new Rook(Chessman::WHITE, make_pair(6, 6))};
    test_board->place_piece(make_pair(5, 6), test_piece);
    test_board->place_piece(make_pair(4, 5), test_piece_2);
    test_board->place_piece(make_pair(6, 6), test_piece_3);
    VTUPLE v = {make_tuple(7, 5, 1), make_tuple(8, 5, 1), make_tuple(5, 5, 1),
                make_tuple(4, 5, 2), make_tuple(6, 4, 1), make_tuple(6, 3, 1),
                make_tuple(6, 2, 1), make_tuple(6, 1, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("rook_list_legal_moves_3");
}

#endif // ROOK_TEST_HPP
