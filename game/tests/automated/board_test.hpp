/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef BOARD_TEST_HPP
#define BOARD_TEST_HPP

#include "board.hpp"

#include "pieces/pawn.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/bishop.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

#include "player.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(put_white_pawn_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Pawn* test_piece = new Chessman::Pawn(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::PAWN, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_pawn_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Pawn* test_piece = new Chessman::Pawn(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::PAWN, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_white_rook_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Rook* test_piece = new Chessman::Rook(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_rook_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Rook* test_piece = new Chessman::Rook(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::ROOK, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_white_knight_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Knight* test_piece = new Chessman::Knight(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_knight_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Knight* test_piece = new Chessman::Knight(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_white_bishop_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Bishop* test_piece = new Chessman::Bishop(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_bishop_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Bishop* test_piece = new Chessman::Bishop(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_white_queen_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Queen* test_piece = new Chessman::Queen(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_queen_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::Queen* test_piece = new Chessman::Queen(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_white_king_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::King* test_piece = new Chessman::King(Chessplayer::WHITE, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::KING, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_black_king_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    Chessman::King* test_piece = new Chessman::King(Chessplayer::BLACK, make_pair(1, 1));
    test_board->place_piece(make_pair(1, 1), test_piece);
    BOOST_REQUIRE_EQUAL(Chessman::KING, test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK, test_board->point_piece(make_pair(1, 1))->owner());
    delete test_board;
    delete test_piece;
}

BOOST_AUTO_TEST_CASE(put_8_white_pawns_at_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;

    Chessman::Piece* pawn_w_1    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(1, 2));
    Chessman::Piece* pawn_w_2    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(2, 2));
    Chessman::Piece* pawn_w_3    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(3, 2));
    Chessman::Piece* pawn_w_4    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(4, 2));
    Chessman::Piece* pawn_w_5    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(5, 2));
    Chessman::Piece* pawn_w_6    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(6, 2));
    Chessman::Piece* pawn_w_7    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(7, 2));
    Chessman::Piece* pawn_w_8    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(8, 2));

    test_board->place_piece(make_pair(1, 1), pawn_w_1);
    test_board->place_piece(make_pair(2, 1), pawn_w_2);
    test_board->place_piece(make_pair(3, 1), pawn_w_3);
    test_board->place_piece(make_pair(4, 1), pawn_w_4);
    test_board->place_piece(make_pair(5, 1), pawn_w_5);
    test_board->place_piece(make_pair(6, 1), pawn_w_6);
    test_board->place_piece(make_pair(7, 1), pawn_w_7);
    test_board->place_piece(make_pair(8, 1), pawn_w_8);

    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(1, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(2, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(2, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(3, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(3, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(4, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(4, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(5, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(5, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(6, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(6, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(7, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(7, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(8, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(8, 1))->owner());

    delete test_board;

    delete pawn_w_1;
    delete pawn_w_2;
    delete pawn_w_3;
    delete pawn_w_4;
    delete pawn_w_5;
    delete pawn_w_6;
    delete pawn_w_7;
    delete pawn_w_8;
}

BOOST_AUTO_TEST_CASE(put_8_black_pawns_at_chessboard)
{
    Chessman::Piece* pawn_b_1    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(1, 2));
    Chessman::Piece* pawn_b_2    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(2, 2));
    Chessman::Piece* pawn_b_3    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(3, 2));
    Chessman::Piece* pawn_b_4    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(4, 2));
    Chessman::Piece* pawn_b_5    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(5, 2));
    Chessman::Piece* pawn_b_6    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(6, 2));
    Chessman::Piece* pawn_b_7    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(7, 2));
    Chessman::Piece* pawn_b_8    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(8, 2));

    Chessboard::Board* test_board = new Chessboard::Board;

    test_board->place_piece(make_pair(1, 7), pawn_b_1);
    test_board->place_piece(make_pair(2, 7), pawn_b_2);
    test_board->place_piece(make_pair(3, 7), pawn_b_3);
    test_board->place_piece(make_pair(4, 7), pawn_b_4);
    test_board->place_piece(make_pair(5, 7), pawn_b_5);
    test_board->place_piece(make_pair(6, 7), pawn_b_6);
    test_board->place_piece(make_pair(7, 7), pawn_b_7);
    test_board->place_piece(make_pair(8, 7), pawn_b_8);

    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(1, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(1, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(2, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(2, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(3, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(3, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(4, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(4, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(5, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(5, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(6, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(6, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(7, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(7, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(8, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(8, 7))->owner());

    delete test_board;

    delete pawn_b_1;
    delete pawn_b_2;
    delete pawn_b_3;
    delete pawn_b_4;
    delete pawn_b_5;
    delete pawn_b_6;
    delete pawn_b_7;
    delete pawn_b_8;
}

BOOST_AUTO_TEST_CASE(manually_setup_chessboard)
{
    Chessboard::Board* test_board = new Chessboard::Board;

    Chessman::Piece* pawn_w_1    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(1, 2));
    Chessman::Piece* pawn_w_2    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(2, 2));
    Chessman::Piece* pawn_w_3    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(3, 2));
    Chessman::Piece* pawn_w_4    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(4, 2));
    Chessman::Piece* pawn_w_5    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(5, 2));
    Chessman::Piece* pawn_w_6    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(6, 2));
    Chessman::Piece* pawn_w_7    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(7, 2));
    Chessman::Piece* pawn_w_8    = new Chessman::Pawn(   Chessplayer::WHITE, make_pair(8, 2));
    Chessman::Piece* rook_w_1    = new Chessman::Rook(   Chessplayer::WHITE, make_pair(1, 1));
    Chessman::Piece* rook_w_2    = new Chessman::Rook(   Chessplayer::WHITE, make_pair(8, 1));
    Chessman::Piece* knight_w_1  = new Chessman::Knight( Chessplayer::WHITE, make_pair(2, 1));
    Chessman::Piece* knight_w_2  = new Chessman::Knight( Chessplayer::WHITE, make_pair(7, 1));
    Chessman::Piece* bishop_w_1  = new Chessman::Bishop( Chessplayer::WHITE, make_pair(3, 1));
    Chessman::Piece* bishop_w_2  = new Chessman::Bishop( Chessplayer::WHITE, make_pair(6, 1));
    Chessman::Piece* queen_w     = new Chessman::Queen(  Chessplayer::WHITE, make_pair(4, 1));
    Chessman::Piece* king_w      = new Chessman::King(   Chessplayer::WHITE, make_pair(5, 1));

    Chessman::Piece* pawn_b_1    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(1, 7));
    Chessman::Piece* pawn_b_2    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(2, 7));
    Chessman::Piece* pawn_b_3    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(3, 7));
    Chessman::Piece* pawn_b_4    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(4, 7));
    Chessman::Piece* pawn_b_5    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(5, 7));
    Chessman::Piece* pawn_b_6    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(6, 7));
    Chessman::Piece* pawn_b_7    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(7, 7));
    Chessman::Piece* pawn_b_8    = new Chessman::Pawn(   Chessplayer::BLACK, make_pair(8, 7));
    Chessman::Piece* rook_b_1    = new Chessman::Rook(   Chessplayer::BLACK, make_pair(1, 8));
    Chessman::Piece* rook_b_2    = new Chessman::Rook(   Chessplayer::BLACK, make_pair(8, 8));
    Chessman::Piece* knight_b_1  = new Chessman::Knight( Chessplayer::BLACK, make_pair(2, 8));
    Chessman::Piece* knight_b_2  = new Chessman::Knight( Chessplayer::BLACK, make_pair(7, 8));
    Chessman::Piece* bishop_b_1  = new Chessman::Bishop( Chessplayer::BLACK, make_pair(3, 8));
    Chessman::Piece* bishop_b_2  = new Chessman::Bishop( Chessplayer::BLACK, make_pair(6, 8));
    Chessman::Piece* queen_b =   new Chessman::Queen(    Chessplayer::BLACK, make_pair(4, 8));
    Chessman::Piece* king_b =    new Chessman::King(     Chessplayer::BLACK, make_pair(5, 8));

    test_board->place_piece(make_pair(1, 1), rook_w_1);
    test_board->place_piece(make_pair(2, 1), knight_w_1);
    test_board->place_piece(make_pair(3, 1), bishop_w_1);
    test_board->place_piece(make_pair(4, 1), queen_w);
    test_board->place_piece(make_pair(5, 1), king_w);
    test_board->place_piece(make_pair(6, 1), bishop_w_2);
    test_board->place_piece(make_pair(7, 1), knight_w_2);
    test_board->place_piece(make_pair(8, 1), rook_w_2);
    test_board->place_piece(make_pair(1, 2), pawn_w_1);
    test_board->place_piece(make_pair(2, 2), pawn_w_2);
    test_board->place_piece(make_pair(3, 2), pawn_w_3);
    test_board->place_piece(make_pair(4, 2), pawn_w_4);
    test_board->place_piece(make_pair(5, 2), pawn_w_5);
    test_board->place_piece(make_pair(6, 2), pawn_w_6);
    test_board->place_piece(make_pair(7, 2), pawn_w_7);
    test_board->place_piece(make_pair(8, 2), pawn_w_8);

    test_board->place_piece(make_pair(1, 8), rook_b_1);
    test_board->place_piece(make_pair(2, 8), knight_b_1);
    test_board->place_piece(make_pair(3, 8), bishop_b_1);
    test_board->place_piece(make_pair(4, 8), queen_b);
    test_board->place_piece(make_pair(5, 8), king_b);
    test_board->place_piece(make_pair(6, 8), bishop_b_2);
    test_board->place_piece(make_pair(7, 8), knight_b_2);
    test_board->place_piece(make_pair(8, 8), rook_b_2);
    test_board->place_piece(make_pair(1, 7), pawn_b_1);
    test_board->place_piece(make_pair(2, 7), pawn_b_2);
    test_board->place_piece(make_pair(3, 7), pawn_b_3);
    test_board->place_piece(make_pair(4, 7), pawn_b_4);
    test_board->place_piece(make_pair(5, 7), pawn_b_5);
    test_board->place_piece(make_pair(6, 7), pawn_b_6);
    test_board->place_piece(make_pair(7, 7), pawn_b_7);
    test_board->place_piece(make_pair(8, 7), pawn_b_8);

    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(1, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(1, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(2, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(2, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(3, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(3, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(4, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(4, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(5, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(5, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(6, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(6, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(7, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(7, 2))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(8, 2))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(8, 2))->owner());

    BOOST_REQUIRE_EQUAL(Chessman::ROOK,     test_board->point_piece(make_pair(1, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(1, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT,   test_board->point_piece(make_pair(2, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(2, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP,   test_board->point_piece(make_pair(3, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(3, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN,    test_board->point_piece(make_pair(4, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(4, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KING,     test_board->point_piece(make_pair(5, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(5, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP,   test_board->point_piece(make_pair(6, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(6, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT,   test_board->point_piece(make_pair(7, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(7, 1))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::ROOK,     test_board->point_piece(make_pair(8, 1))->type());
    BOOST_REQUIRE_EQUAL(Chessman::WHITE,    test_board->point_piece(make_pair(8, 1))->owner());

    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(1, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(1, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(2, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(2, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(3, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(3, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(4, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(4, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(5, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(5, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(6, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(6, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(7, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(7, 7))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::PAWN,     test_board->point_piece(make_pair(8, 7))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(8, 7))->owner());

    BOOST_REQUIRE_EQUAL(Chessman::ROOK,     test_board->point_piece(make_pair(1, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(1, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT,   test_board->point_piece(make_pair(2, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(2, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP,   test_board->point_piece(make_pair(3, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(3, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::QUEEN,    test_board->point_piece(make_pair(4, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(4, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KING,     test_board->point_piece(make_pair(5, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(5, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::BISHOP,   test_board->point_piece(make_pair(6, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(6, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::KNIGHT,   test_board->point_piece(make_pair(7, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(7, 8))->owner());
    BOOST_REQUIRE_EQUAL(Chessman::ROOK,     test_board->point_piece(make_pair(8, 8))->type());
    BOOST_REQUIRE_EQUAL(Chessman::BLACK,    test_board->point_piece(make_pair(8, 8))->owner());

    delete test_board;

    delete pawn_w_1;
    delete pawn_w_2;
    delete pawn_w_3;
    delete pawn_w_4;
    delete pawn_w_5;
    delete pawn_w_6;
    delete pawn_w_7;
    delete pawn_w_8;
    delete rook_w_1;
    delete rook_w_2;
    delete knight_w_1;
    delete knight_w_2;
    delete bishop_w_1;
    delete bishop_w_2;
    delete queen_w;
    delete king_w;

    delete pawn_b_1;
    delete pawn_b_2;
    delete pawn_b_3;
    delete pawn_b_4;
    delete pawn_b_5;
    delete pawn_b_6;
    delete pawn_b_7;
    delete pawn_b_8;
    delete rook_b_1;
    delete rook_b_2;
    delete knight_b_1;
    delete knight_b_2;
    delete bishop_b_1;
    delete bishop_b_2;
    delete queen_b;
    delete king_b;
}

BOOST_AUTO_TEST_CASE(point_piece_invalid_x_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 1)), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(point_piece_invalid_y_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(1, 9)), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(point_piece_invalid_x_y_parameterers)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 9)), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(point_piece_invalid_x_y_parameterers2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(0, 0)), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(owner_invalid_x_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 1))->owner(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(owner_invalid_y_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(1, 9))->owner(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(owner_invalid_x_y_parameterers)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 9))->owner(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(owner_invalid_x_y_parameterers2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(0, 0))->owner(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(type_invalid_x_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 1))->type(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(type_invalid_y_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(1, 9))->type(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(type_invalid_x_y_parameterers)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 9))->type(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(type_invalid_x_y_parameterers2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(0, 0))->type(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(unicode_invalid_x_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 1))->unicode(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(unicode_invalid_y_parameterer)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(1, 9))->unicode(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(unicode_invalid_x_y_parameterers)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(9, 9))->unicode(), std::invalid_argument);
    delete test_board;
}

BOOST_AUTO_TEST_CASE(unicode_invalid_x_y_parameterers2)
{
    Chessboard::Board* test_board = new Chessboard::Board;
    BOOST_CHECK_THROW(test_board->point_piece(make_pair(0, 0))->unicode(), std::invalid_argument);
    delete test_board;
}

#endif // BOARD_TEST_HPP
