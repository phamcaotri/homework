// ChessBoard.cpp

#include "ChessBoard.h"
#include "Rook.h"

ChessBoard::ChessBoard() {
    turn == true;
    enPassant = -1;
    castling[0] = true; // white short
    castling[1] = true; // white long
    castling[2] = true; // black short
    castling[3] = true; // black long
    halfmoveClock = 0;
    fullmoveNumber = 1;

    board[0][0] = new Rook(false);
    board[0][1] = new Knight(false);
    board[0][2] = new Bishop(false);
    board[0][3] = new Queen(false);
    board[0][4] = new King(false);
    board[0][5] = new Bishop(false);
    board[0][6] = new Knight(false);
    board[0][7] = new Rook(false);
}