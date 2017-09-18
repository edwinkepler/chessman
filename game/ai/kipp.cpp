#include "kipp.hpp"

namespace AI
{
    const tuple<int, int, int, int> KIPP::compute_move(
        int _depth,
        int _side,
        int _time_left,
        Chessboard::Board* _board)
    {
        // If depth equals zero then just random some move but prefer capturing. 
        if(_depth == 0) {
            // x1, y1, x2, y2, move type
            vector<tuple<int, int, int, int, int>> vm;
            // List all enemy pieces
            for(int i = 1; i <= _board->board().size(); i++) {
                for(int j = 1; j <= _board->board().size(); j++) {
                    if(!_board->is_sqr_empty(make_pair(i, j))) {
                        auto piece = _board->point_piece(make_pair(i, j));
                        // add to vector of enemy pieces
                        if(piece->owner() != _side) {
                            auto tmp = piece->list_moves(_board->board());
                            for(auto const& i : tmp) {
                                vm.push_back(make_tuple(
                                    piece->last_move().first,
                                    piece->last_move().second,
                                    get<0>(i),
                                    get<1>(i),
                                    get<2>(i)));
                            }
                        }
                    }
                }
            }
            // Look for captures
            vector<tuple<int, int, int, int, int>> vc;
            for(auto const& c : vm) {
                if(get<4>(c) == 2) {
                    vc.push_back(c);
                }
            }
            // No capture moves, randomize move and return it
            random_device rd;
            mt19937 eng(rd());
            if(vc.size() == 0) {
                uniform_int_distribution<> distr(0, vm.size() - 1);
                auto ret = vm.at(distr(eng));
                return make_tuple(
                    get<0>(ret),
                    get<1>(ret),
                    get<2>(ret),
                    get<3>(ret));
            } else {
                uniform_int_distribution<> distr(0, vc.size() - 1);
                auto ret = vc.at(distr(eng));
                return make_tuple(
                    get<0>(ret),
                    get<1>(ret),
                    get<2>(ret),
                    get<3>(ret));
            }
        }
    }
}
