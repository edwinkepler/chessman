/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PAWN_TEST_HPP
#define PAWN_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "pieces/pawn.hpp"
#include "board/board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int> >

BOOST_AUTO_TEST_CASE(pawn_white)
{
    Pawn* pawn = new Pawn(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::TYPE::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, pawn->owner());
    delete pawn;
}

BOOST_AUTO_TEST_CASE(pawn_black)
{
    Pawn* pawn = new Pawn(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::TYPE::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, pawn->owner());
    delete pawn;
}

BOOST_AUTO_TEST_CASE(pawn_archive_move)
{
    Pawn* pawn = new Pawn(Chessman::WHITE, make_pair(1, 1));
    pawn->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, pawn->last_move().first);
    BOOST_REQUIRE_EQUAL(2, pawn->last_move().second);
    BOOST_REQUIRE_EQUAL(true, pawn->moved());
    delete pawn;
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_1_rank)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(1, 3), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_2_ranks)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(1, 4), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_1_rank_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(1, 7));
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(1, 6), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_2_ranks_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(1, 7));
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID, test_piece->identify_move(make_pair(1, 5), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_1_rank)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    Pawn* test_piece_2 = new Pawn(Chessman::WHITE, make_pair(1, 3));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 3), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    Pawn* test_piece_2 = new Pawn(Chessman::WHITE, make_pair(1, 4));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 4), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 4), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks_2)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    Pawn* test_piece_2 = new Pawn(Chessman::WHITE, make_pair(1, 3));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 4), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_after_moved)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_piece->add_move(make_pair(1, 3));
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 5), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_1_rank_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(1, 7));
    Pawn* test_piece_2 = new Pawn(Chessman::BLACK, make_pair(1, 6));
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(1, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 6), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(1, 7));
    Pawn* test_piece_2 = new Pawn(Chessman::BLACK, make_pair(1, 5));
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(1, 5), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID, test_piece->identify_move(make_pair(1, 5), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_capture)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(5, 2));
    Pawn* test_piece_black = new Pawn(Chessman::BLACK, make_pair(6, 3));
    test_board->place_piece(make_pair(5, 2), test_piece);
    test_board->place_piece(make_pair(6, 3), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE, test_piece->identify_move(make_pair(6, 3), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_black;
}

BOOST_AUTO_TEST_CASE(pawn_capture_2)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(5, 2));
    Pawn* test_piece_black = new Pawn(Chessman::BLACK, make_pair(4, 3));
    test_board->place_piece(make_pair(5, 2), test_piece);
    test_board->place_piece(make_pair(4, 3), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE, test_piece->identify_move(make_pair(4, 3), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_black;
}

BOOST_AUTO_TEST_CASE(pawn_capture_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(5, 7));
    Pawn* test_piece_black = new Pawn(Chessman::WHITE, make_pair(6, 6));
    test_board->place_piece(make_pair(5, 7), test_piece);
    test_board->place_piece(make_pair(6, 6), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE, test_piece->identify_move(make_pair(6, 6), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_black;
}

BOOST_AUTO_TEST_CASE(pawn_capture_black_2)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(5, 7));
    Pawn* test_piece_black = new Pawn(Chessman::WHITE, make_pair(4, 6));
    test_board->place_piece(make_pair(5, 7), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE, test_piece->identify_move(make_pair(4, 6), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_black;
}

BOOST_AUTO_TEST_CASE(pawn_promotion)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 7));
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROMOTION, test_piece->identify_move(make_pair(1, 8), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_promotion_with_capture)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 7));
    Pawn* test_piece_2 = new Pawn(Chessman::BLACK, make_pair(2, 8));
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROCAPT, test_piece->identify_move(make_pair(2, 8), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_promotion_black)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::BLACK, make_pair(1, 2));
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROMOTION, test_piece->identify_move(make_pair(1, 1), test_board->board()));
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    test_board->place_piece(make_pair(1, 2), test_piece);
    VTUPLE v = {make_tuple(1, 3, 1), make_tuple(1, 4, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_2)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    Pawn* test_piece_2 = new Pawn(Chessman::WHITE, make_pair(1, 3));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    VTUPLE v = {};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_3)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 2));
    Pawn* test_piece_2 = new Pawn(Chessman::BLACK, make_pair(2, 3));
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(2, 3), test_piece_2);
    VTUPLE v = {make_tuple(1, 3, 1), make_tuple(1, 4, 1), make_tuple(2, 3, 2)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_4)
{
    Board* test_board = new Board;
    Pawn* test_piece = new Pawn(Chessman::WHITE, make_pair(1, 7));
    Pawn* test_piece_2 = new Pawn(Chessman::BLACK, make_pair(2, 8));
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    VTUPLE v = {make_tuple(1, 8, 5), make_tuple(2, 8, 6)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
}

#endif // PAWN_TEST_HPP
