## [Unreleased]

### Added

- Add Debug::Log class
- Add Game::History class
- Add function to get algebraic notation from Game::History class

### Fixed

- king_castling_right_black_blocked test fails #9

## [0.1.1] 2017-08-30

### Added

- GameController::chessboard method
- GameController::player method
- GameController::current_player method
- GameController::move method (for numbers and char+number - Portable Game Notation)

### Changed

- Initialisation of pieces, players and board objects moved from constructor to definition of GameController

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
