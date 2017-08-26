#include "bishop.hpp"

#include <cmath>

namespace Chessman
{
    Bishop::Bishop(int _owner, pair<int, int> _coords) : Piece(_owner, _coords) {
        i_type = Chessman::BISHOP;
        c_unicode = _owner ? "\u265D" : "\u2657";
    }

    // https://math.stackexchange.com/a/1566144
    const int Bishop::identify_move(
        const pair<int, int>& to,
        const vector<vector<Chessman::Piece*> >& vb)
    {
        int x1 = last_move().first;
        int y1 = last_move().second;
        int x2 = to.first;
        int y2 = to.second;
        if(abs(x2 - x1) == abs(y2 - y1) && abs(x2 - x1) > 0 && abs(y2 - y1) > 0) {
            int n = abs(x2 - x1);
            int xd = (x2 - x1) / abs(x2 - x1);
            int yd = (y2 - y1) / abs(y2 - y1);
            for(int i = 1; i <= n; i++) {
                int ixd = x1 + (i * xd);
                int iyd = y1 + (i * yd);
                if(vb[iyd - 1][vb.size() - ixd] != nullptr) {
                    if(i == n && vb[iyd - 1][vb.size() - ixd]->owner() != owner()) {
                        return Chessman::MOVES::CAPTURE;
                    } else {
                        return Chessman::MOVES::INVALID;
                    }
                }
            }
            return Chessman::MOVES::VALID;
        } else {
            return Chessman::MOVES::INVALID;
        }
    }
}
