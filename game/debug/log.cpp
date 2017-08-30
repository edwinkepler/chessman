#include "log.hpp"

namespace Debug
{
    Log& Log::log_i(string s) {
        cout << s;
        return *this;
    }

    Log& Log::n() {
        cout << endl;
        return *this;
    }

    Log& Log::t() {
        cout << "\t";
        return *this;
    }

    Log& Log::log_coords(pair<int, int>& c) {
        cout << "Coords: (" << c.first << ", " << c.second << ")";
        return *this;
    }

    Log& Log::log_coords(pair<int, int>& c1, pair<int, int>& c2) {
        cout << "Coords: (" << c1.first << ", " << c1.second << "), ("
                            << c2.first << ", " << c2.second << ")";
        return *this;
    }

    void Log::dump_board(Chessboard::Board* b) {
        cout << endl << "Board dump: " << endl << endl << "\t ";
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

        cout << " " << endl << endl << "Pieces dump: " << endl << endl << "\t ";
        for(int i = 8; i > 0; --i) {
            cout << "\t" << i;
            for(int j = 1; j <= 8; ++j) {
                if(!b->is_sqr_empty(make_pair(j, i))) {
                    dump_piece(b->point_piece(make_pair(j, i)));
                }
            }
            cout << i << endl;
        }
    }

    void Log::dump_piece(Chessman::Piece* p) {
        auto pos = p->last_move();
        auto hist = p->history();
        cout << endl << "Piece type: " << p->type()
                        << ", owner: " << p->owner()
                        << ", pos: (" << pos.first << ", " << pos.second << ")"
                        << ", moved:" << p->moved();
        cout << endl << "History (from first to last): ";
        for(int i = 0; i < hist.size(); i++) {
            cout << "\t" << i + 1 << ". " << get<0>(hist[i]) << ", "
                                          << get<1>(hist[i]);
        }

        cout << endl;
    }

    void Log::operator<<(string s) {
        log_i(s);
    }

    void Log::operator<<(Chessboard::Board* b) {
        dump_board(b);
    }

    void Log::operator<<(Chessman::Piece* p) {
        dump_piece(p);
    }
}