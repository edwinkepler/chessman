## [Unreleased]

### Added

- Add Debug::Log class
- Add Game::History class
- Add function to get algebraic notation from Game::History class
- Add state (check, mate, stalemate) to GameController class #4

### Fixed

- king_castling_right_black_blocked test fails #9
>>>>>>> dev

## [0.1.1] 2017-08-30

### Added

- GameController::chessboard method
- GameController::player method
- GameController::current_player method
- GameController::move method (for numbers and char+number - Portable Game Notation)
- Castling checked for Chessman::King
- En passant move check for Chessman::Pawn

### Changed

- Initialisation of pieces, players and board objects moved from constructor to definition of GameController

### Fixed

- Vector of tuples is testing LH with LH ending with auto pass in automated tests
- queen_list_legal_moves test fails
- move_piece() method of class Board not updating piece move history

## [0.1.0] 2017-08-27

### Added

- Chessman::Piece class
- Chessman::Bishop class
- Chessman::King class
- Chessman::Knight class
- Chessman::Pawn class
- Chessman::Queen class
- Chessman::Rook class
- Chessplayer::Player class
- Chessboard::Board class
- Game::GameController class
