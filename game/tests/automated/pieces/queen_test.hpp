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

#define VTUPLE vector<tuple<int, int, int> >

BOOST_AUTO_TEST_CASE(queen_white)
{
    Queen* queen = new Queen(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, queen->owner());
    delete queen;
}

BOOST_AUTO_TEST_CASE(queen_black)
{
    Queen* queen = new Queen(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, queen->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, queen->owner());
    delete queen;
}

BOOST_AUTO_TEST_CASE(queen_archive_move)
{
    Queen* queen = new Queen(Chessman::WHITE, make_pair(1, 1));
    queen->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, queen->last_move().first);
    BOOST_REQUIRE_EQUAL(2, queen->last_move().second);
    BOOST_REQUIRE_EQUAL(true, queen->moved());
    delete queen;
}

BOOST_AUTO_TEST_CASE(queen_valid_move)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(7, 7), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_2)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(3, 3), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_3)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 7), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_4)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(6, 2), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_5)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 4), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_6)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(5, 4), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_7)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 1), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_8)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 8), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_invalid_move)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(2, 4), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(queen_valid_move_capture)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(4, 4));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(4, 6));
    test_board->place_piece(make_pair(4, 4), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 6), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(queen_list_legal_moves)
{
    Board* test_board = new Board;
    Queen* test_piece = new Queen(Chessman::WHITE, make_pair(6, 6));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(5, 5));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(6, 4));
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
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
}

#endif // QUEEN_TEST_HPP
