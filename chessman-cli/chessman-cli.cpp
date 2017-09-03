/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "gamecontroller.hpp"

using namespace std;

void print_board(Chessboard::Board* b, vector<string> h) {
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

void print_header() {
    cout << "\033c" << endl << endl;
    cout << "================== CHESSMAN ==================" << endl;
    cout << "== v0.1.3 ================= by Edwin Kepler ==" << endl << endl;
}

void print_footer(int _current) {
    if(_current == 0){
        cout << "=================== WHITE ====================" << endl;
    } else {
        cout << "=================== BLACK ====================" << endl;
    }
    cout <<     "== Your move (x1 y1 x2 y2): ";
}

int main(int argc, char *argv[]) {
    unique_ptr<Game::GameController> game {new Game::GameController};

    do {
        int x1, y1, x2, y2;
        print_header();
        print_board(game->chessboard(), game->moves_history());
        print_footer(game->current_player());
        cin >> x1 >> y1 >> x2 >> y2;
        game->move(make_pair(x1, y1), make_pair(x2, y2));
    } while(1);

    return 0;
}
