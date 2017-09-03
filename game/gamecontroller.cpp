#include "gamecontroller.hpp"
#include "helpers/conversion.hpp"
#include "helpers/comparison.hpp"

#include <algorithm>

namespace Game
{
    GameController::GameController() {
        board->place_piece(make_pair(1, 1), rook_w_1);
        board->place_piece(make_pair(2, 1), knight_w_1);
        board->place_piece(make_pair(3, 1), bishop_w_1);
        board->place_piece(make_pair(4, 1), queen_w);
        board->place_piece(make_pair(5, 1), king_w);
        board->place_piece(make_pair(6, 1), bishop_w_2);
        board->place_piece(make_pair(7, 1), knight_w_2);
        board->place_piece(make_pair(8, 1), rook_w_2);
        board->place_piece(make_pair(1, 2), pawn_w_1);
        board->place_piece(make_pair(2, 2), pawn_w_2);
        board->place_piece(make_pair(3, 2), pawn_w_3);
        board->place_piece(make_pair(4, 2), pawn_w_4);
        board->place_piece(make_pair(5, 2), pawn_w_5);
        board->place_piece(make_pair(6, 2), pawn_w_6);
        board->place_piece(make_pair(7, 2), pawn_w_7);
        board->place_piece(make_pair(8, 2), pawn_w_8);
        board->place_piece(make_pair(1, 8), rook_b_1);
        board->place_piece(make_pair(2, 8), knight_b_1);
        board->place_piece(make_pair(3, 8), bishop_b_1);
        board->place_piece(make_pair(4, 8), queen_b);
        board->place_piece(make_pair(5, 8), king_b);
        board->place_piece(make_pair(6, 8), bishop_b_2);
        board->place_piece(make_pair(7, 8), knight_b_2);
        board->place_piece(make_pair(8, 8), rook_b_2);
        board->place_piece(make_pair(1, 7), pawn_b_1);
        board->place_piece(make_pair(2, 7), pawn_b_2);
        board->place_piece(make_pair(3, 7), pawn_b_3);
        board->place_piece(make_pair(4, 7), pawn_b_4);
        board->place_piece(make_pair(5, 7), pawn_b_5);
        board->place_piece(make_pair(6, 7), pawn_b_6);
        board->place_piece(make_pair(7, 7), pawn_b_7);
        board->place_piece(make_pair(8, 7), pawn_b_8);

        i_curr_player = 0;
    }

    GameController::~GameController() {
        delete board;

        delete play_white;
        delete play_black;

        delete pawn_w_1;
        delete pawn_w_2;
        delete pawn_w_3;
        delete pawn_w_4;
        delete pawn_w_5;
        delete pawn_w_6;
        delete pawn_w_7;
        delete pawn_w_8;
        delete rook_w_1;
        delete rook_w_2;
        delete knight_w_1;
        delete knight_w_2;
        delete bishop_w_1;
        delete bishop_w_2;
        delete queen_w;
        delete king_w;

        delete pawn_b_1;
        delete pawn_b_2;
        delete pawn_b_3;
        delete pawn_b_4;
        delete pawn_b_5;
        delete pawn_b_6;
        delete pawn_b_7;
        delete pawn_b_8;
        delete rook_b_1;
        delete rook_b_2;
        delete knight_b_1;
        delete knight_b_2;
        delete bishop_b_1;
        delete bishop_b_2;
        delete queen_b;
        delete king_b;
    }

    Chessboard::Board* GameController::chessboard() {
        return board;
    }

    Chessplayer::Player* GameController::player(int _side) {
        if(_side > 1 || _side < 0) {
            throw invalid_argument(
                "GameController::player(): Argument out of range.");
        } else if(_side == 0) {
            return play_white;
        } else {
            return play_black;
        }
    }

    int GameController::current_player() {
        return i_curr_player;
    }

    vector<string> GameController::moves_history() {
        return hist.moves_list_an();
    }

    int GameController::move(
            const pair<int, int>& from,
            const pair<int, int>& to)
    {
        auto piece = board->point_piece(from);
        auto move_type = piece->identify_move(to, board->board());
        // Valid move, not effecting other pieces
        switch(move_type) {
            // Normal move, not effecting other pieces
            case 1: {
                board->move_piece(from, to);

                hist.add_move(
                    Move(move_type, 
                        0,
                        from.first, 
                        from.second, 
                        to.first, 
                        to.second, 
                        piece->type(), 
                        0, 0));

                add_moves_to_pieces(board, piece);
                i_curr_player == 0 ? i_curr_player = 1 : i_curr_player = 0;
                return move_type;
                break;
            }
            // Valid move, capture, effecting other piece
            case 2: {
                board->nullify(to);
                board->move_piece(from, to);

                auto piece_to = board->point_piece(to);
                hist.add_move(
                    Move(move_type, 
                        2,
                        from.first, 
                        from.second, 
                        to.first, 
                        to.second, 
                        piece->type(), 
                        piece_to->type(), 
                        0));

                add_moves_to_pieces(board, piece);
                i_curr_player == 0 ? i_curr_player = 1 : i_curr_player = 0;
                return move_type;
                break;
            }
            // Valid move, en passant, effecting other piece
            case 3: {
                board->nullify(to); // WRONG!!!!! TRANSLATE THIS!!!!!
                board->move_piece(from, to);

                auto piece_to = board->point_piece(to);
                hist.add_move(
                    Move(move_type, 
                        3,
                        from.first, 
                        from.second, 
                        to.first, 
                        to.second, 
                        piece->type(), 
                        piece_to->type(), 
                        0));

                add_moves_to_pieces(board, piece);
                i_curr_player == 0 ? i_curr_player = 1 : i_curr_player = 0;
                return move_type;
                break;
            }
            // Valid move, castling, effecting other piece
            case 4: {
                // Find Rook, move it
                // White
                // if(Helper::greater(to, from, 0) && piece->owner() == 0) {
                    // board->move_piece(make_pair(8, 1), make_pair(6, 1));
                // }

                board->move_piece(from, to);

                auto piece_to = board->point_piece(to);
                hist.add_move(
                    Move(move_type, 
                        4,
                        from.first, 
                        from.second, 
                        to.first, 
                        to.second, 
                        piece->type(), 
                        piece_to->type(), 
                        0));

                add_moves_to_pieces(board, piece);
                i_curr_player == 0 ? i_curr_player = 1 : i_curr_player = 0;
                return move_type;
                break;
            }
            // Just to trigger exception throw from board
            default: {
                board->move_piece(from, to);
            }             
        }
    }

    int GameController::move(
        const pair<char, int>& from,
        const pair<char, int>& to)
    {
        int x1 = Helper::ctoi(get<0>(from));
        int x2 = Helper::ctoi(get<0>(to));
        return move(make_pair(x1, get<1>(from)), make_pair(x2, get<1>(to)));
    }

    const int GameController::checkmate() {        
        auto vb = chessboard()->board();
        vector<Chessman::Piece*> vp;
        bool cant_move = false;
        int kx, ky;
        // find king
        for(int i = 1; i <= vb.size(); i++) {
            for(int j = 1; j <= vb.at(0).size(); j++) {
                auto tested = vb[j - 1][vb.size() - i];
                if(tested != nullptr) {
                    // add to vector of enemy pieces (needed later)
                    if(tested->owner() != i_curr_player) {
                        vp.push_back(tested);
                    }
                    if(tested->type() == 5 && tested->owner() == i_curr_player) {
                        // king can't move
                        if(tested->list_moves(vb).size() == 0) {
                            cant_move = true;
                            kx = tested->last_move().first;
                            ky = tested->last_move().second;
                        }                            
                    }
                }
            }
        }

        vector<tuple<int, int, int>> vm;
        auto kxy = make_pair(kx, ky);
        // If cant move find out if any enemy piece can capture, if so then
        // it's check mate.
        if(cant_move) {
            for(const auto& i : vp) {
                auto temp = i->list_moves(vb);
                sort(temp.begin(), temp.end());
                merge(vm.begin(), vm.end(),
                      temp.begin(), temp.end(),
                      back_inserter(vm));
            }
            if(Helper::contains(vm, kxy)) {}
                return Game::CHECKMATE;
        } else {
            for(const auto& i : vp) {
                auto temp = i->list_moves(vb);
                sort(temp.begin(), temp.end());
                merge(vm.begin(), vm.end(),
                      temp.begin(), temp.end(),
                      back_inserter(vm));
            }
            if(Helper::contains(vm, kxy)) {}
                return Game::CHECK;
        }
        return Game::NONE;
    }

    int GameController::promotion() {
        // todo
        i_curr_player == 0 ? i_curr_player = 1 : i_curr_player = 0;
    }

    const void GameController::add_moves_to_pieces(
        Chessboard::Board* b, const Chessman::Piece* p) 
    {
        auto v_board = b->board();
        for(int i = 0; i < v_board.size(); ++i) {
            for(int j = 0; j < v_board[0].size(); j++) {
                if(v_board[i][j] != nullptr) {
                    auto piece = v_board[i][j];
                    if(piece != p) {
                        piece->add_move(piece->last_move());
                    }
                }
            }
        }
    }
}
