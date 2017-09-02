#include "history.hpp"

#include <string>

#include "helpers/conversion.hpp"

namespace Game
{
    Move::Move(int _state, int _mod,
        int _x1, int _y1, int _x2, int _y2, 
        int _type1, int _promo, int _type2)
    :   state(_state),
        mod(_mod),
        x1(_x1),
        y1(_y1),
        x2(_x2),
        y2(_y2),
        type1(_type1),
        type2(_type2),
        promo(_promo)
    {}

    Move::~Move() {}

    History::~History() {}

    const void History::add_move(Move mv) {
        mv_list.push_back(mv);
        if(mv_list.size() % 2 == 0)
            plays++;
    }

    vector<Move> History::moves_list() {
        return mv_list;
    }

    vector<string> History::moves_list_an() {
        vector<string> an;
        string play;
        for(const auto& mv : mv_list) {
            play = "";
            // castling got it's own special notation
            if(mv.mod == 3 || mv.mod == 4) {
                if(mv.mod == 3) {
                    play += "O-O-O";
                } else if(mv.mod == 4) {
                    play += "O-O";
                }
            } else {
                // pieces
                switch(mv.type1) {
                    case(1):
                        play += "R";
                        break;
                    case(2):
                        play += "N";
                        break;
                    case(3):
                        play += "B";
                        break;
                    case(4):
                        play += "Q";
                        break;
                    case(5):
                        play += "K";
                        break;
                }
                // if capture
                if(mv.state == 2) {
                    play += "x";
                }
                // add coordinates
                play += Helper::itoc(mv.x2) + to_string(mv.y2);
                
                if(mv.mod == 1) {
                    play += "+";
                }
            }
            an.push_back(play);
        }
        vector<string> ret;
        string temp = "";
        for(int i = 1; i <= an.size(); i++) {            
            if(i == 1 && an.size() == 1) {
                temp += "1. ";
                temp += an[i - 1];
                ret.push_back(temp);
            } else if(i == 1 && an.size() > 1) {
                temp += "1. ";
                temp += an[i - 1];
            } else if(i % 2 == 0) {
                temp += " " + an[i - 1];
                ret.push_back(temp);
                temp = "";
            } else if(i == an.size() && an.size() % 2 != 0) {
                temp += to_string((i / 2) + (i % 2));
                temp += ". ";
                temp += an[i - 1];
                ret.push_back(temp);
            } else {
                temp += to_string((i / 2) + (i % 2));
                temp += ". ";
                temp += an[i - 1];
            }
        }
        return ret;
    }

    int History::n_of_plays() {
        return plays;
    }
}
