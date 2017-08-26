#include "king.hpp"

#include <cmath>
#include <algorithm>

namespace Chessman
{
    King::King(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::KING;
        c_unicode = _owner ? "\u265A" : "\u2654";
    }

    const int King::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        if((abs(x1 - x2) == 1 && abs(y1 - y2) < 1) ||
           (abs(y1 - y2) == 1 && abs(x1 - x2) < 1) ||
           (abs(x1 - x2) == 1 && abs(y1 - y2) == 1))
        {
            vector<tuple<int, int, int> > vp;

            for(int i = 1; i <= vb.size(); i++) {
                for(int j = 1; j <= vb.at(0).size(); j++) {

                    if(vb[j - 1][vb.size() - i] != nullptr) {
                        if(vb[j - 1][vb.size() - i]->owner() != owner()) {
                            auto tv = vb[j - 1][vb.size() - i]->list_moves(vb);
                            sort(tv.begin(), tv.end());
                            merge(vp.begin(), vp.end(),
                                  tv.begin(), tv.end(),
                                  back_inserter(vp));
                        }
                    }
                }
            }
            for(auto const& t : vp) {
                if(get<0>(t) == x2 && get<1>(t) == y2) {
                    return Chessman::MOVES::INVALID;
                }
            }
            return Chessman::MOVES::VALID;
        }
        return Chessman::MOVES::INVALID;
    }
}
