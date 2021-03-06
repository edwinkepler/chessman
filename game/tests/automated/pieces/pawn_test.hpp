/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PAWN_TEST_HPP
#define PAWN_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>
#include <memory>

#include "pieces/pawn.hpp"
#include "board.hpp"

#define BOOST_TEST_MAIN

#include "../includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Chessman;
using namespace Chessboard;

#define VTUPLE vector<tuple<int, int, int>>

BOOST_AUTO_TEST_CASE(pawn_white)
{
    Debug::Log::test_func_head("pawn_white");
    shared_ptr<Pawn> pawn {new Pawn(Chessman::WHITE, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::TYPE::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, pawn->owner());
    Debug::Log::test_func_foot("pawn_white");
}

BOOST_AUTO_TEST_CASE(pawn_black)
{
    Debug::Log::test_func_head("pawn_black");
    shared_ptr<Pawn> pawn {new Pawn(Chessman::BLACK, make_pair(1, 1))};
    BOOST_REQUIRE_EQUAL(Chessman::TYPE::PAWN, pawn->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, pawn->owner());
    Debug::Log::test_func_foot("pawn_black");
}

BOOST_AUTO_TEST_CASE(pawn_archive_move)
{
    Debug::Log::test_func_head("pawn_archive_move");
    shared_ptr<Pawn> pawn {new Pawn(Chessman::WHITE, make_pair(1, 1))};
    pawn->add_move(make_pair(1, 2));
    BOOST_REQUIRE_EQUAL(1, pawn->last_move().first);
    BOOST_REQUIRE_EQUAL(2, pawn->last_move().second);
    BOOST_REQUIRE_EQUAL(true, pawn->moved());
    Debug::Log::test_func_foot("pawn_archive_move");
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_1_rank)
{
    Debug::Log::test_func_head("pawn_valid_move_1_rank");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 3), test_board->board()));
    Debug::Log::test_func_foot("pawn_valid_move_1_rank");
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_2_ranks)
{
    Debug::Log::test_func_head("pawn_valid_move_2_ranks");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 4), test_board->board()));
    Debug::Log::test_func_foot("pawn_valid_move_2_ranks");
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_1_rank_black)
{
    Debug::Log::test_func_head("pawn_valid_move_1_rank_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(1, 7))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 6), test_board->board()));
    Debug::Log::test_func_foot("pawn_valid_move_1_rank_black");
}

BOOST_AUTO_TEST_CASE(pawn_valid_move_2_ranks_black)
{
    Debug::Log::test_func_head("pawn_valid_move_2_ranks_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(1, 7))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::VALID,
        test_piece->identify_move(make_pair(1, 5), test_board->board()));
    Debug::Log::test_func_foot("pawn_valid_move_2_ranks_black");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_1_rank)
{
    Debug::Log::test_func_head("pawn_invalid_move_1_rank");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 3))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 3), test_board->board()));
    Debug::Log::test_func_foot("pawn_invalid_move_1_rank");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks)
{
    Debug::Log::test_func_head("pawn_invalid_move_2_ranks");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 4))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 4), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 4), test_board->board()));
    Debug::Log::test_func_foot("pawn_invalid_move_2_ranks");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks_2)
{
    Debug::Log::test_func_head("pawn_invalid_move_2_ranks_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 3))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 4), test_board->board()));

    Debug::Log::test_func_foot("pawn_invalid_move_2_ranks_2");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_after_moved)
{
    Debug::Log::test_func_head("pawn_invalid_move_2_after_moved");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_piece->add_move(make_pair(1, 3));
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 5), test_board->board()));
    Debug::Log::test_func_foot("pawn_invalid_move_2_after_moved");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_1_rank_black)
{
    Debug::Log::test_func_head("pawn_invalid_move_1_rank_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(1, 7))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(1, 6))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(1, 6), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 6), test_board->board()));
    Debug::Log::test_func_foot("pawn_invalid_move_1_rank_black");
}

BOOST_AUTO_TEST_CASE(pawn_invalid_move_2_ranks_black)
{
    Debug::Log::test_func_head("pawn_invalid_move_2_ranks_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(1, 7))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(1, 5))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(1, 5), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::INVALID,
        test_piece->identify_move(make_pair(1, 5), test_board->board()));
    Debug::Log::test_func_foot("pawn_invalid_move_2_ranks_black");
}

BOOST_AUTO_TEST_CASE(pawn_capture)
{
    Debug::Log::test_func_head("pawn_capture");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(5, 2))};
    shared_ptr<Pawn> test_piece_black {new Pawn(Chessman::BLACK, make_pair(6, 3))};
    test_board->place_piece(make_pair(5, 2), test_piece);
    test_board->place_piece(make_pair(6, 3), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(6, 3), test_board->board()));
    Debug::Log::test_func_foot("pawn_capture");
}

BOOST_AUTO_TEST_CASE(pawn_capture_2)
{
    Debug::Log::test_func_head("pawn_capture_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(5, 2))};
    shared_ptr<Pawn> test_piece_black {new Pawn(Chessman::BLACK, make_pair(4, 3))};
    test_board->place_piece(make_pair(5, 2), test_piece);
    test_board->place_piece(make_pair(4, 3), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 3), test_board->board()));
    Debug::Log::test_func_foot("pawn_capture_2");
}

BOOST_AUTO_TEST_CASE(pawn_capture_black)
{
    Debug::Log::test_func_head("pawn_capture_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(5, 7))};
    shared_ptr<Pawn> test_piece_black {new Pawn(Chessman::WHITE, make_pair(6, 6))};
    test_board->place_piece(make_pair(5, 7), test_piece);
    test_board->place_piece(make_pair(6, 6), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(6, 6), test_board->board()));
    Debug::Log::test_func_foot("pawn_capture_black");
}

BOOST_AUTO_TEST_CASE(pawn_capture_black_2)
{
    Debug::Log::test_func_head("pawn_capture_black_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(5, 7))};
    shared_ptr<Pawn> test_piece_black {new Pawn(Chessman::WHITE, make_pair(4, 6))};
    test_board->place_piece(make_pair(5, 7), test_piece);
    test_board->place_piece(make_pair(4, 6), test_piece_black);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::CAPTURE,
        test_piece->identify_move(make_pair(4, 6), test_board->board()));
    Debug::Log::test_func_foot("pawn_capture_black_2");
}

BOOST_AUTO_TEST_CASE(pawn_promotion)
{
    Debug::Log::test_func_head("pawn_promotion");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 7))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROMOTION,
        test_piece->identify_move(make_pair(1, 8), test_board->board()));
    Debug::Log::test_func_foot("pawn_promotion");
}

BOOST_AUTO_TEST_CASE(pawn_promotion_with_capture)
{
    Debug::Log::test_func_head("pawn_promotion_with_capture");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 7))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(2, 8))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROCAPT,
        test_piece->identify_move(make_pair(2, 8), test_board->board()));
    Debug::Log::test_func_foot("pawn_promotion_with_capture");
}

BOOST_AUTO_TEST_CASE(pawn_promotion_black)
{
    Debug::Log::test_func_head("pawn_promotion_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(1, 2))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::PROMOTION,
        test_piece->identify_move(make_pair(1, 1), test_board->board()));
    Debug::Log::test_func_foot("pawn_promotion_black");
}

BOOST_AUTO_TEST_CASE(pawn_en_passant)
{
    Debug::Log::test_func_head("pawn_en_passant");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(2, 5))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(1, 7))};
    test_board->place_piece(make_pair(2, 5), test_piece);
    test_board->place_piece(make_pair(1, 7), test_piece_2);
    test_board->move_piece(make_pair(1, 7), make_pair(1, 5));
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::EN_PASSANT,
        test_piece->identify_move(make_pair(1, 6), test_board->board()));
    Debug::Log::test_func_foot("pawn_en_passant");
}

BOOST_AUTO_TEST_CASE(pawn_en_passant_black)
{
    Debug::Log::test_func_head("pawn_en_passant_black");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(2, 4))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(2, 4), test_piece);
    test_board->place_piece(make_pair(1, 2), test_piece_2);
    test_board->move_piece(make_pair(1, 2), make_pair(1, 4));
    BOOST_REQUIRE_EQUAL(Chessman::MOVES::EN_PASSANT,
        test_piece->identify_move(make_pair(1, 3), test_board->board()));
    Debug::Log::test_func_foot("pawn_en_passant_black");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves)
{
    Debug::Log::test_func_head("pawn_list_legal_moves");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    VTUPLE v = {make_tuple(1, 3, 1), make_tuple(1, 4, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_2)
{
    Debug::Log::test_func_head("pawn_list_legal_moves_2");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 3))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(1, 3), test_piece_2);
    VTUPLE v = {};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves_2");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_3)
{
    Debug::Log::test_func_head("pawn_list_legal_moves_3");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(2, 3))};
    test_board->place_piece(make_pair(1, 2), test_piece);
    test_board->place_piece(make_pair(2, 3), test_piece_2);
    VTUPLE v = {make_tuple(1, 3, 1), make_tuple(1, 4, 1), make_tuple(2, 3, 2)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves_3");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_4)
{
    Debug::Log::test_func_head("pawn_list_legal_moves_4");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(1, 7))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(2, 8))};
    test_board->place_piece(make_pair(1, 7), test_piece);
    test_board->place_piece(make_pair(2, 8), test_piece_2);
    VTUPLE v = {make_tuple(1, 8, 5), make_tuple(2, 8, 6)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves_4");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_5)
{
    Debug::Log::test_func_head("pawn_list_legal_moves_5");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::BLACK, make_pair(2, 5))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::WHITE, make_pair(1, 2))};
    test_board->place_piece(make_pair(2, 5), test_piece);
    test_board->place_piece(make_pair(1, 2), test_piece_2);
    test_board->move_piece(make_pair(1, 2), make_pair(1, 4));
    test_board->move_piece(make_pair(2, 5), make_pair(2, 4));
    VTUPLE v = {make_tuple(1, 3, 3), make_tuple(2, 3, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves_5");
}

BOOST_AUTO_TEST_CASE(pawn_list_legal_moves_6)
{
    Debug::Log::test_func_head("pawn_list_legal_moves_6");
    shared_ptr<Board> test_board {new Board};
    shared_ptr<Pawn> test_piece {new Pawn(Chessman::WHITE, make_pair(5, 4))};
    shared_ptr<Pawn> test_piece_2 {new Pawn(Chessman::BLACK, make_pair(4, 7))};
    test_board->place_piece(make_pair(5, 4), test_piece);
    test_board->place_piece(make_pair(4, 7), test_piece_2);
    test_board->move_piece(make_pair(4, 7), make_pair(4, 5));
    test_board->move_piece(make_pair(5, 4), make_pair(5, 5));
    VTUPLE v = {make_tuple(4, 6, 3), make_tuple(5, 6, 1)};
    VTUPLE t = test_piece->list_moves(test_board->board());
    TEST_VECTORS_OF_TUPLES_3(v, t);
    Debug::Log::test_func_foot("pawn_list_legal_moves_6");
}

#endif // PAWN_TEST_HPP
