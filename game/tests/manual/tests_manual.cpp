/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <chrono>
#include <tuple>
#include <algorithm>

#include "board.hpp"
#include "pieces/pawn.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/knight.hpp"
#include "pieces/queen.hpp"
#include "pieces/rook.hpp"

using namespace std;

void print_commands() {
    cout << "Avaible commands:" << endl;
    cout << "add \t- a [type] [owner] [coords]" << endl;
    cout << "remove \t- r [coords]" << endl;
    cout << "info \t- i [coords]" << endl;
    cout << "compute - c" << endl << endl;
}

void print_board(Chessboard::Board* b) {
    cout << " ";
    vector<char> rank {'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    for(int i = 0; i < 8; ++i) {
        cout << rank.back();
        rank.pop_back();
    }
    cout << " " << endl;

    for(int i = 8; i > 0; --i) {
        cout << i;
        for(int j = 1; j <= 8; ++j) {
            if(b->is_sqr_empty(make_pair(j, i))) {
                cout << ".";
            } else {
                cout << b->point_piece(make_pair(j, i))->unicode();
            }
        }
        cout << i << endl;
    }

    cout << " ";
    rank = {'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    for(int i = 0; i < 8; ++i) {
        cout << rank.back();
        rank.pop_back();
    }
    cout << " " << endl << endl;
}

void add(string s, Chessboard::Board* b) {
    int t = (int)s[2] - 48;
    int o = (int)s[4] - 48;
    int x = (int)s[6] - 48;
    int y = (int)s[7] - 48;
    if(t == 0) {
        Chessman::Pawn* piece = new Chessman::Pawn(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), piece);
    } else if(t == 1) {
        Chessman::Rook* rook = new Chessman::Rook(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), rook);
    } else if(t == 2) {
        Chessman::Knight* knight = new Chessman::Knight(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), knight);
    } else if(t == 3) {
        Chessman::Bishop* bishop = new Chessman::Bishop(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), bishop);
    } else if(t == 4) {
        Chessman::Queen* queen = new Chessman::Queen(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), queen);
    } else if(t == 5) {
        Chessman::King* king = new Chessman::King(o, make_pair(x, y));
        b->place_piece(make_pair(x, y), king);
    } else {
        cout << "Wrong piece type." << endl << endl;
    }
}

void compute(Chessboard::Board* b) {
    auto t1 = chrono::high_resolution_clock::now();
    vector<Chessman::Piece*> vw;
    vector<Chessman::Piece*> vb;

    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            if(!b->is_sqr_empty(make_pair(i, j))) {
                if(b->point_piece(make_pair(i, j))->owner() == 0) {
                    auto tmp = b->point_piece(make_pair(i, j));
                    vw.push_back(tmp);
                } else {
                    auto tmp = b->point_piece(make_pair(i, j));
                    vb.push_back(tmp);
                }
            }
        }
    }

    int w_moves = 0;
    if(vw.size() > 0) {
        cout << "White: " << endl;
        for(auto i : vw) {
            cout << i->unicode() << " ";
            auto moves = i->list_moves(b->board());
            for(auto j : moves) {
                cout << "(" << get<0>(j) << ", " 
                            << get<1>(j) << ", " << get<2>(j) << "), ";
                w_moves++;
            }
            cout << endl << endl;
        }
    }

    int b_moves = 0;
    if(vb.size() > 0) {
        cout << "Black: " << endl;
        for(auto i : vb) {
            cout << i->unicode() << " ";
            auto moves = i->list_moves(b->board());
            for(auto j : moves) {
                cout << "(" << get<0>(j) << ", " 
                            << get<1>(j) << ", " << get<2>(j) << "), ";
                b_moves++;
            }
            cout << endl << endl;
        }
    }

    auto t2 = chrono::high_resolution_clock::now();
    cout << "Moves for white: " << w_moves << ", for black: " << b_moves
         << endl << endl << "Computed in: "
         << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
         << " milliseconds" << endl << endl;
}

int main() {
    Chessboard::Board* board = new Chessboard::Board();
    while(1) {
        string ln;
        print_commands();
        print_board(board);
        getline(cin, ln);
        if(ln[0] == 'a' && ln.size() == 8) {
            add(ln, board);
        } else if(ln[0] == 'c' && ln.size() == 1) {
            compute(board);
        } else if(ln[0] == 'q' && ln.size() == 1) {
            return 0;
        } else {
            cout << "Wrong input." << endl << endl;
        }
    }
    return 0;
}