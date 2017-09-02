/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef HISTORY_TEST_HPP
#define HISTORY_TEST_HPP

#include <vector>
#include <utility>
#include <tuple>
#include <string>
#include <iostream>
#include "history.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace Game;

void TEST_VECTORS_OF_MOVES(
    vector<Move> lh,
    vector<Move> rh)
{
    if(lh.size() != rh.size()) {
        BOOST_FAIL("LH != RH");
    }
    for(int i = 0; i < lh.size(); i++) {
        BOOST_REQUIRE_EQUAL(lh[i].state, rh[i].state);
        BOOST_REQUIRE_EQUAL(lh[i].mod, rh[i].mod);
        BOOST_REQUIRE_EQUAL(lh[i].x1, rh[i].x1);
        BOOST_REQUIRE_EQUAL(lh[i].y1, rh[i].y1);
        BOOST_REQUIRE_EQUAL(lh[i].x2, rh[i].x2);
        BOOST_REQUIRE_EQUAL(lh[i].y2, rh[i].y2);
        BOOST_REQUIRE_EQUAL(lh[i].type1, rh[i].type1);
        BOOST_REQUIRE_EQUAL(lh[i].type2, rh[i].type2);
        BOOST_REQUIRE_EQUAL(lh[i].promo, rh[i].promo);
    }
}

BOOST_AUTO_TEST_CASE(add_move)
{
    Debug::Log::test_func_head("add_move");
    History hist;
    vector<Move> test;
    test.push_back(Move(2, 0, 5, 2, 4, 4, 0, 0, 1));
    hist.add_move(test[0]);
    BOOST_REQUIRE_EQUAL(test.size(), hist.moves_list().size());
    Debug::Log::test_func_foot("add_move");
}

BOOST_AUTO_TEST_CASE(add_move_are_equal)
{
    Debug::Log::test_func_head("add_move_are_equal");
    History hist;
    vector<Move> test;
    test.push_back(Move(2, 0, 5, 2, 4, 4, 0, 0, 1));
    hist.add_move(test[0]);
    TEST_VECTORS_OF_MOVES(test, hist.moves_list());
    Debug::Log::test_func_foot("add_move_are_equal");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_pawn)
{
    Debug::Log::test_func_head("algebraic_notation_pawn");
    History hist;
    hist.add_move(Move(1, 0, 7, 2, 7, 4, 0, 0, 1));
    vector<string> test = {"1. g4"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_pawn");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_rook)
{
    Debug::Log::test_func_head("algebraic_notation_rook");
    History hist;
    hist.add_move(Move(1, 0, 1, 1, 1, 5, 1, 0, 1));
    vector<string> test = {"1. Ra5"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_rook");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_knight)
{
    Debug::Log::test_func_head("algebraic_notation_knight");
    History hist;
    hist.add_move(Move(1, 0, 2, 1, 3, 3, 2, 0, 1));
    vector<string> test = {"1. Nc3"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_knight");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_bishop)
{
    Debug::Log::test_func_head("algebraic_notation_bishop");
    History hist;
    hist.add_move(Move(1, 0, 3, 1, 8, 6, 3, 0, 1));
    vector<string> test = {"1. Bh6"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_pawn");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_queen)
{
    Debug::Log::test_func_head("algebraic_notation_queen");
    History hist;
    hist.add_move(Move(1, 0, 4, 1, 4, 4, 4, 0, 1));
    vector<string> test = {"1. Qd4"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_queen");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_king)
{
    Debug::Log::test_func_head("algebraic_notation_king");
    History hist;
    hist.add_move(Move(1, 0, 4, 1, 3, 1, 5, 0, 1));
    vector<string> test = {"1. Kc1"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_king");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_capture)
{
    Debug::Log::test_func_head("algebraic_notation_capture");
    History hist;
    hist.add_move(Move(2, 0, 3, 8, 7, 4, 3, 0, 1));
    vector<string> test = {"1. Bxg4"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_capture");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_check)
{
    Debug::Log::test_func_head("algebraic_notation_check");
    History hist;
    hist.add_move(Move(1, 1, 3, 8, 7, 4, 3, 0, 1));
    vector<string> test = {"1. Bg4+"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_check");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_capture_check)
{
    Debug::Log::test_func_head("algebraic_notation_capture_check");
    History hist;
    hist.add_move(Move(2, 1, 3, 8, 7, 4, 3, 0, 1));
    vector<string> test = {"1. Bxg4+"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_capture_check");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_castling_long)
{
    Debug::Log::test_func_head("algebraic_notation_castling_long");
    History hist;
    hist.add_move(Move(0, 3, 0, 0, 0, 0, 0, 0, 0));
    vector<string> test = {"1. O-O-O"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_castling_long");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_castling_short)
{
    Debug::Log::test_func_head("algebraic_notation_castling_short");
    History hist;
    hist.add_move(Move(0, 4, 0, 0, 0, 0, 0, 0, 0));
    vector<string> test = {"1. O-O"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_castling_short");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_moves)
{
    Debug::Log::test_func_head("algebraic_notation_moves");
    History hist;
    hist.add_move(Move(1, 0, 0, 0, 7, 4, 0, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 4, 6, 0, 0, 0));
    vector<string> test = {"1. g4 d6"};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_moves");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_moves_odd)
{
    Debug::Log::test_func_head("algebraic_notation_moves_odd");
    History hist;
    hist.add_move(Move(1, 0, 0, 0, 7, 4, 0, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 4, 6, 0, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 8, 3, 3, 0, 0));
    vector<string> test = {("1. g4 d6"), ("2. Bh3")};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_moves_odd");
}

BOOST_AUTO_TEST_CASE(algebraic_notation_moves_2)
{
    Debug::Log::test_func_head("algebraic_notation_moves_2");
    History hist;
    hist.add_move(Move(1, 0, 0, 0, 7, 4, 0, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 4, 6, 0, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 8, 3, 3, 0, 0));
    hist.add_move(Move(2, 0, 0, 0, 7, 4, 3, 0, 0));
    hist.add_move(Move(2, 0, 0, 0, 7, 4, 3, 0, 0));
    hist.add_move(Move(1, 0, 0, 0, 4, 7, 4, 0, 0));
    hist.add_move(Move(2, 1, 0, 0, 4, 7, 3, 0, 0));
    hist.add_move(Move(2, 0, 0, 0, 4, 7, 2, 0, 0));
    vector<string> test = {("1. g4 d6"), ("2. Bh3 Bxg4"), ("3. Bxg4 Qd7"),
                           ("4. Bxd7+ Nxd7")};
    auto result = hist.moves_list_an();
    BOOST_CHECK_EQUAL_COLLECTIONS(test.begin(), test.end(),
                                    result.begin(), result.end());
    Debug::Log::test_func_foot("algebraic_notation_moves_2");
}

#endif // HISTORY_TEST_HPP
