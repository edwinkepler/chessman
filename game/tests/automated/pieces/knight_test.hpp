/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KNIGHT_TEST_HPP
#define KNIGHT_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>
#include <memory>

#include "pieces/knight.hpp"
#include "pieces/rook.hpp"
#include "board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(knight_white)
{
    Debug::Log::test_func_head("knight_white");
    shared_ptr<Knight> knight {new  Knight(Chessman::WHITE, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, knight->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, knight->owner());
    Debug::Log::test_func_foot("knight_white");
}

BOOST_AUTO_TEST_CASE(knight_black)
{
    Debug::Log::test_func_head("knight_black");
    shared_ptr<Knight> knight {new  Knight(Chessman::BLACK, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, knight->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, knight->owner());
    Debug::Log::test_func_foot("knight_black");
}

BOOST_AUTO_TEST_CASE(knight_archive_move)
{
    Debug::Log::test_func_head("knight_archive_move");
    shared_ptr<Knight> knight {new  Knight(Chessman::WHITE, make_pair(1, 1))};
    knight->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, knight->last_move().first);
    BOOST_REQUIRE_EQUAL(2, knight->last_move().second);
    BOOST_REQUIRE_EQUAL(true, knight->moved());
    Debug::Log::test_func_foot("knight_archive_move");
}

BOOST_AUTO_TEST_CASE(knight_valid_move)
{
    Debug::Log::test_func_head("knight_valid_move");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(4, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(2, 3), test_board->board()));
    Debug::Log::test_func_foot("knight_valid_move");
}

BOOST_AUTO_TEST_CASE(knight_valid_move_2)
{
    Debug::Log::test_func_head("knight_valid_move_2");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new  Chessman::Rook(Chessman::BLACK, make_pair(3, 4))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(3, 4), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(2, 3), test_board->board()));
    Debug::Log::test_func_foot("knight_valid_move_2");
}

BOOST_AUTO_TEST_CASE(knight_valid_move_capture)
{
    Debug::Log::test_func_head("knight_valid_move_capture");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(4, 4))};
    shared_ptr<Rook> test_piece_2 {new  Chessman::Rook(Chessman::BLACK, make_pair(2, 3))};
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(2, 3), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE, test_piece->identify_move(make_pair(2, 3), test_board->board()));
    Debug::Log::test_func_foot("knight_valid_move_capture");
}

BOOST_AUTO_TEST_CASE(knight_list_legal_moves)
{
    Debug::Log::test_func_head("knight_list_legal_moves");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(5, 5))};
    test_board->place_piece(make_pair(5, 5), test_piece);
    vector<tuple<int, int, int>> v = {make_tuple(3, 4, 1), make_tuple(3, 6, 1),
                                       make_tuple(4, 3, 1), make_tuple(6, 3, 1),
                                       make_tuple(7, 4, 1), make_tuple(7, 6, 1),
                                       make_tuple(4, 7, 1), make_tuple(6, 7, 1)};
    vector<tuple<int, int, int>> t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("knight_list_legal_moves");
}

BOOST_AUTO_TEST_CASE(knight_list_legal_moves_2)
{
    Debug::Log::test_func_head("knight_list_legal_moves_2");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(5, 5))};
    shared_ptr<Rook> test_piece_2 {new  Chessman::Rook(Chessman::BLACK, make_pair(4, 3))};
    shared_ptr<Rook> test_piece_3 {new  Chessman::Rook(Chessman::WHITE, make_pair(6, 7))};
    test_board->place_piece(make_pair(5, 5), test_piece);
    test_board->place_piece(make_pair(4, 3), test_piece_2);
    test_board->place_piece(make_pair(6, 7), test_piece_3);
    vector<tuple<int, int, int>> v = {make_tuple(3, 4, 1), make_tuple(3, 6, 1),
                                       make_tuple(4, 3, 2), make_tuple(6, 3, 1),
                                       make_tuple(7, 4, 1), make_tuple(7, 6, 1),
                                       make_tuple(4, 7, 1)};
    vector<tuple<int, int, int>> t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("knight_list_legal_moves_2");
}

BOOST_AUTO_TEST_CASE(knight_list_legal_moves_3)
{
    Debug::Log::test_func_head("knight_list_legal_moves_3");
    shared_ptr<Chessboard::Board> test_board {new  Chessboard::Board};
    shared_ptr<Knight> test_piece {new  Knight(Chessman::WHITE, make_pair(5, 5))};
    shared_ptr<Rook> test_piece_2 {new  Chessman::Rook(Chessman::BLACK, make_pair(6, 3))};
    shared_ptr<Rook> test_piece_3 {new  Chessman::Rook(Chessman::WHITE, make_pair(6, 4))};
    test_board->place_piece(make_pair(5, 5), test_piece);
    test_board->place_piece(make_pair(6, 3), test_piece_2);
    test_board->place_piece(make_pair(6, 4), test_piece_3);
    vector<tuple<int, int, int>> v = {make_tuple(3, 4, 1), make_tuple(3, 6, 1),
                                       make_tuple(4, 3, 1), make_tuple(6, 3, 2),
                                       make_tuple(7, 4, 1), make_tuple(7, 6, 1),
                                       make_tuple(4, 7, 1), make_tuple(6, 7, 1)};
    vector<tuple<int, int, int>> t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("knight_list_legal_moves_3");
}

#endif // KNIGHT_TEST_HPP