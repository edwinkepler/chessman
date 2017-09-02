/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef KING_TEST_HPP
#define KING_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>

#include "board.hpp"
#include "pieces/king.hpp"
#include "pieces/rook.hpp"

#include "debug/log.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(king_white)
{
    Debug::Log::test_func_head("king_white");
    King* king = new King(Chessman::WHITE, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KING, king->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, king->owner());
    delete king;
    Debug::Log::test_func_foot("king_white");
}

BOOST_AUTO_TEST_CASE(king_black)
{
    Debug::Log::test_func_head("king_white");
    King* king = new King(Chessman::BLACK, make_pair(1, 1));
    BOOST_REQUIRE_EQUAL(Chessman::KING, king->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, king->owner());
    delete king;
    Debug::Log::test_func_foot("king_white");
}

BOOST_AUTO_TEST_CASE(king_archive_move)
{
    Debug::Log::test_func_head("king_archive_move");
    King* king = new King(Chessman::WHITE, make_pair(1, 1));
    king->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, king->last_move().first);
    BOOST_REQUIRE_EQUAL(2, king->last_move().second);
    BOOST_REQUIRE_EQUAL(true, king->moved());
    delete king;
    Debug::Log::test_func_foot("king_white");
}

BOOST_AUTO_TEST_CASE(king_valid_move)
{
    Debug::Log::test_func_head("king_valid_move");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(4, 5), test_board->board()));
    delete test_board;
    delete test_piece;
    Debug::Log::test_func_foot("king_valid_move");
}

BOOST_AUTO_TEST_CASE(king_valid_move_2)
{
    Debug::Log::test_func_head("king_valid_move_2");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(3, 3), test_board->board()));
    delete test_board;
    delete test_piece;
    Debug::Log::test_func_foot("king_valid_move_2");
}

BOOST_AUTO_TEST_CASE(king_invalid_move)
{
    Debug::Log::test_func_head("king_invalid_move");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(4, 4));
    test_board->place_piece(make_pair(4, 4), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(2, 5), test_board->board()));
    delete test_board;
    delete test_piece;
    Debug::Log::test_func_foot("king_invalid_move");
}

BOOST_AUTO_TEST_CASE(king_castling_right)
{
    Debug::Log::test_func_head("king_castling_right");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(5, 1));
    Rook* test_piece_2 = new Rook(Chessman::WHITE, make_pair(8, 1));
    test_board->place_piece(make_pair(5, 1), test_piece);
    test_board->place_piece(make_pair(8, 1), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CASTLING,
        test_piece->identify_move(make_pair(7, 1), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    Debug::Log::test_func_foot("king_castling_right");
}

BOOST_AUTO_TEST_CASE(king_castling_left)
{
    Debug::Log::test_func_head("king_castling_left");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(5, 1));
    Rook* test_piece_2 = new Rook(Chessman::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(5, 1), test_piece);
    test_board->place_piece(make_pair(1, 1), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CASTLING,
        test_piece->identify_move(make_pair(3, 1), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    Debug::Log::test_func_foot("king_castling_left");
}

BOOST_AUTO_TEST_CASE(king_castling_left_blocked)
{
    Debug::Log::test_func_head("king_castling_left_blocked");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(5, 1));
    Rook* test_piece_2 = new Rook(Chessman::WHITE, make_pair(1, 1));
    Rook* test_piece_3 = new Rook(Chessman::BLACK, make_pair(4, 4));
    test_board->place_piece(make_pair(5, 1), test_piece);
    test_board->place_piece(make_pair(1, 1), test_piece_2);
    test_board->place_piece(make_pair(4, 4), test_piece_3);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(3, 1), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
    Debug::Log::test_func_foot("king_castling_left_blocked");
}

BOOST_AUTO_TEST_CASE(king_castling_right_black_blocked)
{
    Debug::Log::test_func_head("king_castling_right_black_blocked");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::BLACK, make_pair(5, 8));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(8, 8));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(6, 3));
    test_board->place_piece(make_pair(5, 8), test_piece);
    test_board->place_piece(make_pair(8, 8), test_piece_2);
    test_board->place_piece(make_pair(6, 3), test_piece_3);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(7, 8), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
    Debug::Log::test_func_foot("king_castling_left_black");
}

BOOST_AUTO_TEST_CASE(king_castling_right_blocked)
{
    Debug::Log::test_func_head("king_castling_right_blocked");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(5, 1));
    Rook* test_piece_2 = new Rook(Chessman::WHITE, make_pair(8, 1));
    Rook* test_piece_3 = new Rook(Chessman::BLACK, make_pair(7, 4));
    test_board->place_piece(make_pair(5, 1), test_piece);
    test_board->place_piece(make_pair(8, 1), test_piece_2);
    test_board->place_piece(make_pair(7, 4), test_piece_3);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(7, 1), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
    Debug::Log::test_func_foot("king_castling_right_blocked");
}

BOOST_AUTO_TEST_CASE(king_castling_right_black)
{
    Debug::Log::test_func_head("king_castling_right_black");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::BLACK, make_pair(5, 8));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(8, 8));
    test_board->place_piece(make_pair(5, 8), test_piece);
    test_board->place_piece(make_pair(8, 8), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CASTLING,
        test_piece->identify_move(make_pair(7, 8), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    Debug::Log::test_func_foot("king_castling_right_black");
}

BOOST_AUTO_TEST_CASE(king_castling_left_black)
{
    Debug::Log::test_func_head("king_castling_left_black");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::BLACK, make_pair(5, 8));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(1, 8));
    test_board->place_piece(make_pair(5, 8), test_piece);
    test_board->place_piece(make_pair(1, 8), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CASTLING,
        test_piece->identify_move(make_pair(3, 8), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    Debug::Log::test_func_foot("king_castling_left_black");
}

BOOST_AUTO_TEST_CASE(king_castling_left_black_blocked)
{
    Debug::Log::test_func_head("king_castling_left_black_blocked");
    Chessboard::Board* test_board = new Chessboard::Board;
    King* test_piece = new King(Chessman::BLACK, make_pair(5, 8));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(1, 8));
    Rook* test_piece_3 = new Rook(Chessman::WHITE, make_pair(3, 3));
    test_board->place_piece(make_pair(5, 8), test_piece);
    test_board->place_piece(make_pair(1, 8), test_piece_2);
    test_board->place_piece(make_pair(3, 3), test_piece_3);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(3, 8), test_board->board()));
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
    Debug::Log::test_func_foot("king_castling_left_black_blocked");
}

BOOST_AUTO_TEST_CASE(king_list_legal_moves)
{
    Debug::Log::test_func_head("king_list_legal_moves");
    Board* test_board = new Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(1, 1));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(2, 8));
    test_board->place_piece(make_pair(1, 1), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    VTUPLE v = {make_tuple(1, 2, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    Debug::Log::test_func_foot("king_list_legal_moves");
}

BOOST_AUTO_TEST_CASE(king_list_legal_moves_2)
{
    Debug::Log::test_func_head("king_list_legal_moves_2");
    Board* test_board = new Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(1, 1));
    Rook* test_piece_2 = new Rook(Chessman::BLACK, make_pair(2, 8));
    Rook* test_piece_3 = new Rook(Chessman::BLACK, make_pair(8, 2));
    test_board->place_piece(make_pair(1, 1), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    test_board->place_piece(make_pair(8, 2), test_piece_3);
    VTUPLE v = {};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    delete test_piece_2;
    delete test_piece_3;
    Debug::Log::test_func_foot("king_list_legal_moves_2");
}

BOOST_AUTO_TEST_CASE(king_list_legal_moves_3)
{
    Debug::Log::test_func_head("king_list_legal_moves_3");
    Board* test_board = new Board;
    King* test_piece = new King(Chessman::WHITE, make_pair(2, 2));
    test_board->place_piece(make_pair(2, 2), test_piece);
    VTUPLE v = {make_tuple(1, 1, 1), make_tuple(1, 2, 1), make_tuple(1, 3, 1),
                make_tuple(2, 3, 1), make_tuple(3, 3, 1), make_tuple(3, 2, 1),
                make_tuple(3, 1, 1), make_tuple(2, 1, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    delete test_board;
    delete test_piece;
    Debug::Log::test_func_foot("king_list_legal_moves_3");
}

#endif // KING_TEST_HPP
