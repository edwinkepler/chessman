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
#include "ai/kipp.hpp"
#include "debug/log.hpp"

using namespace std;

void print_board(shared_ptr<Chessboard::Board> b, vector<string> h) {
    cout << "\t ";
    vector<char> rank {'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    for(int i = 0; i < 8; ++i) {
        cout << rank.back();
        rank.pop_back();
    }
    cout << " " << endl;

    for(int i = 8; i > 0; --i) {
        cout << "\t" << i;
        for(int j = 1; j <= 8; ++j) {
            if(b->is_sqr_empty(make_pair(j, i))) {
                cout << ".";
            } else {
                cout << b->point_piece(make_pair(j, i))->unicode();
            }
        }
        cout << i << endl;
    }

    cout << "\t ";
    rank = {'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    for(int i = 0; i < 8; ++i) {
        cout << rank.back();
        rank.pop_back();
    }
    cout << " " << endl << endl;
}

void print_menu() {
    for(int i = 0; i < 3; ++i) {
        cout << endl;
    }

    cout << " Choose one:" << endl
         << " [1] Human vs. Human" << endl
         << " [2] Human vs. CPU" << endl
         << " [3] CPU vs. Human" << endl
         << " [4] CPU vs. CPU";

    for(int i = 0; i < 4; ++i) {
        cout << endl;
    }
}

void print_menu_footer() {
    cout << "===========================" << endl
         << "= Choose: ";
}

void print_header() {
    cout << "\033c" << endl << endl
         << "= CHESSMAN ================" << endl
         << "= v0.1.3 ==================" << endl << endl;
}

void print_footer(int _current) {
    if(_current == 0){
        cout << "= WHITE ===================" << endl;
    } else {
        cout << "= BLACK ===================" << endl;
    }
    cout <<     "= Move (x1 y1 x2 y2): ";
}

void humanvhuman() {
    unique_ptr<Game::GameController> game {new Game::GameController};

    do {
        int x1, y1, x2, y2;
        print_header();
        print_board(game->chessboard(), game->moves_history());
        print_footer(game->current_player());
        cin >> x1 >> y1 >> x2 >> y2;
        Debug::Log::verbose_file(true);
        game->move(make_pair(x1, y1), make_pair(x2, y2));
        Debug::Log::verbose_file(false);
    } while(1);
}

void cpuvcpu() {
    unique_ptr<Game::GameController> game {new Game::GameController};

    do {
        int x1, y1, x2, y2;
        print_header();
        print_board(game->chessboard(), game->moves_history());
        print_footer(game->current_player());
        auto move = AI::KIPP::compute_move(
            0, 
            game->current_player(), 
            0, 
            game->chessboard());
        game->move(
            make_pair(get<0>(move), get<1>(move)), 
            make_pair(get<2>(move), get<3>(move)));
    } while(1);
}

int main(int argc, char *argv[]) {
    Debug::Log::verbose_file(true);
    Debug::Log log;
    log.datetime_stamp().n();
    Debug::Log::verbose_file(false);

    do {
        int menu;
        print_header();
        print_menu();
        print_menu_footer();
        cin >> menu;

        switch(menu) {
            case 1:
                humanvhuman();
                break;
            case 4:
                cpuvcpu();
                break;
        }
    } while(1);

    return 0;
}
