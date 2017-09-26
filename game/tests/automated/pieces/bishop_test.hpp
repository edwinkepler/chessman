/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef BISHOP_TEST_HPP
#define BISHOP_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>
#include <memory>

#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(bishop_white)
{
    Debug::Log::test_func_head("bishop_white");
    shared_ptr<Bishop> bishop {new Bishop(Chessman::WHITE, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, bishop->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, bishop->owner());
    Debug::Log::test_func_foot("bishop_white");
}

BOOST_AUTO_TEST_CASE(bishop_black)
{
    Debug::Log::test_func_head("bishop_black");
    shared_ptr<Bishop> bishop {new Bishop(Chessman::BLACK, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, bishop->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, bishop->owner());
    Debug::Log::test_func_foot("bishop_black");
}

BOOST_AUTO_TEST_CASE(bishop_archive_move)
{
    Debug::Log::test_func_head("bishop_archive_move");
    shared_ptr<Bishop> bishop {new Bishop(Chessman::WHITE, make_pair(1, 1))};
    bishop->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, bishop->last_move().first);
    BOOST_REQUIRE_EQUAL(2, bishop->last_move().second);
    BOOST_REQUIRE_EQUAL(true, bishop->moved());
    Debug::Log::test_func_foot("bishop_archive_move");
}

BOOST_AUTO_TEST_CASE(bishop_valid_move)
{
    Debug::Log::test_func_head("bishop_valid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(5, 5), test_board->board()));
    Debug::Log::test_func_foot("bishop_valid_move");
}

BOOST_AUTO_TEST_CASE(bishop_valid_move_2)
{
    Debug::Log::test_func_head("bishop_valid_move_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(8, 8), test_board->board()));
    Debug::Log::test_func_foot("bishop_valid_move_2");
}

BOOST_AUTO_TEST_CASE(bishop_valid_move_3)
{
    Debug::Log::test_func_head("bishop_valid_move_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 1), test_board->board()));
    Debug::Log::test_func_foot("bishop_valid_move_3");
}

BOOST_AUTO_TEST_CASE(bishop_valid_move_4)
{
    Debug::Log::test_func_head("bishop_valid_move_4");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 7), test_board->board()));
    Debug::Log::test_func_foot("bishop_valid_move_4");
}

BOOST_AUTO_TEST_CASE(bishop_valid_move_5)
{
    Debug::Log::test_func_head("bishop_valid_move_5");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(7, 1), test_board->board()));
    Debug::Log::test_func_foot("bishop_valid_move_5");
}

BOOST_AUTO_TEST_CASE(bishop_capture)
{
    Debug::Log::test_func_head("bishop_capture");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(6, 6))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(6, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(6, 6), test_board->board()));
    Debug::Log::test_func_foot("bishop_capture");
}

BOOST_AUTO_TEST_CASE(bishop_capture_2)
{
    Debug::Log::test_func_head("bishop_capture_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(3, 5))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(3, 5), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(3, 5), test_board->board()));
    Debug::Log::test_func_foot("bishop_capture_2");
}

BOOST_AUTO_TEST_CASE(bishop_capture_3)
{
    Debug::Log::test_func_head("bishop_capture_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(1, 1))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(1, 1), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(1, 1), test_board->board()));
    Debug::Log::test_func_foot("bishop_capture_3");
}

BOOST_AUTO_TEST_CASE(bishop_invalid_move)
{
    Debug::Log::test_func_head("bishop_invalid_move");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(4, 1), test_board->board()));
    Debug::Log::test_func_foot("bishop_invalid_move");
}

BOOST_AUTO_TEST_CASE(bishop_list_legal_moves)
{
    Debug::Log::test_func_head("bishop_list_legal_moves");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(5, 5))};
    test_board->place_piece(make_pair(5, 5), test_piece);
    VTUPLE v = {make_tuple(4, 4, 1), make_tuple(3, 3, 1), make_tuple(2, 2, 1),
                make_tuple(1, 1, 1), make_tuple(6, 4, 1), make_tuple(7, 3, 1),
                make_tuple(8, 2, 1), make_tuple(6, 6, 1), make_tuple(7, 7, 1),
                make_tuple(8, 8, 1), make_tuple(4, 6, 1), make_tuple(3, 7, 1),
                make_tuple(2, 8, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("bishop_list_legal_moves");
}

BOOST_AUTO_TEST_CASE(bishop_list_legal_moves_2)
{
    Debug::Log::test_func_head("bishop_list_legal_moves_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Bishop> test_piece {new Bishop(Chessman::WHITE, make_pair(5, 5))};
    shared_ptr<Rook> test_piece_2 {new Rook(Chessman::BLACK, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_3 {new Rook(Chessman::WHITE, make_pair(6, 6))};
    test_board->place_piece(make_pair(5, 5), test_piece);
    test_board->place_piece(make_pair(4, 4), test_piece_2);
    test_board->place_piece(make_pair(6, 6), test_piece_3);
    VTUPLE v = {make_tuple(4, 4, 2), make_tuple(6, 4, 1), make_tuple(7, 3, 1),
                make_tuple(8, 2, 1), make_tuple(4, 6, 1), make_tuple(3, 7, 1),
                make_tuple(2, 8, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("bishop_list_legal_moves_2");
}

#endif // BISHOP_TEST_HPP
