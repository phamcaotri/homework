// Board.h
#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

class Board {
    private:
        Piece* board[8][8];
        bool turn; // true: white, false: black
        int enPassant;
        bool castling[4];
        int halfmoveClock;
        int fullmoveNumber;
    public:
        Board();
        void display();
        void reset();
        void undo();
        Piece* GetPiece(int row, int col);
        bool MovePiece(int src_row, int src_col, int des_row, int des_col);
        bool CheckMate();
};

#endif