/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using namespace std;

/**
 * @brief This namespace contains all player related classes.
 */
namespace Chessplayer
{
    /**
     * @brief Enum for defining player side.
     */
    enum SIDE {
        WHITE,
        BLACK
    };

    /**
     * @brief Player class.
     */
    class Player {
    public:
        /**
        * @brief Constructor.
        * @param name of the player.
        * @param side (Chessplayer::SIDE) of the player.
        */
        Player(string, int);

        /**
        * @brief Returns name of the player.
        */
        string name();
        /**
        * @brief Returns side (Chessplayer::SIDE) of the player.
        */
        int side();

    private:
        /**
        * @brief Holds name of the player.
        */
        string s_name;
        /**
        * @brief Holds side (Chessplayer::SIDE) of the player.
        */
        int i_side;
    };
}

#endif // PLAYER_HPP
