#include "player.hpp"

namespace Chessplayer
{
    Player::Player(string _name, int _side)
        : s_name(_name)
        , i_side(_side)
    {}

    string Player::name() {
        return s_name;
    }

    int Player::side() {
        return i_side;
    }
}
