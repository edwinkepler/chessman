/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef ROOK_TEST_HPP
#define ROOK_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

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
    Rook* rook = new Rook(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, rook->owner());
    delete rook;
}

BOOST_AUTO_TEST_CASE(rook_black)
{
    Rook* rook = new Rook(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, rook->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, rook->owner());
    delete rook;
}

BOOST_AUTO_TEST_CASE(rook_archive_move)
{
    Rook* rook = new Rook(Chessman::WHITE, make_pair(1, 1));
    rook->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, rook->last_move().first);
    BOOST_REQUIRE_EQUAL(2, rook->last_move().second);
    BOOST_REQUIRE_EQUAL(true, rook->moved());
    delete rook;
}

BOOST_AUTO_TEST_CASE(rook_valid_move)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::OWNER::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 8), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(rook_valid_move_2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(8, 1), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(rook_valid_move_3)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 5), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(rook_invalid_move)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(5, 5), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(rook_valid_move_capture)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(4, 4));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(4, 6));
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 6), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(1, 1));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(1, 8));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(5, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    test_board->place_piece(make_pair(1, 8), test_piece_2);
    test_board->place_piece(make_pair(5, 1), test_piece_3);
    VTUPLE v = {make_tuple(1, 2, 1), make_tuple(1, 3, 1), make_tuple(1, 4, 1),
                make_tuple(1, 5, 1), make_tuple(1, 6, 1), make_tuple(1, 7, 1),
                make_tuple(1, 8, 2), make_tuple(2, 1, 1), make_tuple(3, 1, 1),
                make_tuple(4, 1, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves_2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(2, 2));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(2, 3));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(3, 2));
    test_board->place_piece(make_pair(2, 2), test_piece);
    test_board->place_piece(make_pair(2, 3), test_piece_2);
    test_board->place_piece(make_pair(3, 2), test_piece_3);
    VTUPLE v = {make_tuple(1, 2, 1), make_tuple(2, 1, 1), make_tuple(2, 3, 2)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
}

BOOST_AUTO_TEST_CASE(rook_list_legal_moves_3)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Rook* test_piece = new Rook(Chessman::WHITE, make_pair(6, 5));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(4, 5));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(6, 6));
    test_board->place_piece(make_pair(5, 6), test_piece);
    test_board->place_piece(make_pair(4, 5), test_piece_2);
    test_board->place_piece(make_pair(6, 6), test_piece_3);
    VTUPLE v = {make_tuple(7, 5, 1), make_tuple(8, 5, 1), make_tuple(5, 5, 1),
                make_tuple(4, 5, 2), make_tuple(6, 4, 1), make_tuple(6, 3, 1),
                make_tuple(6, 2, 1), make_tuple(6, 1, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
}

#endif // ROOK_TEST_HPP
