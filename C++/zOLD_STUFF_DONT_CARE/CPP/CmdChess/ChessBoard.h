// ChessBoard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "ChessPiece.h"

class ChessBoard {
    private:
        ChessPiece* board[8][8];
        bool turn; // true: white, false: black
        int enPassant;
        bool castling[4];
        int halfmoveClock;
        int fullmoveNumber;
    public:
        ChessBoard();
        ChessPiece* GetPiece(int row, int col);
        bool MovePiece(int fromRow, int fromCol, int toRow, int toCol);
        bool CheckMate();
};

#endif