// Rook.h

#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
    public:
        Rook(Color color);
        ~Rook();
        bool can_move(int src_row, int src_col, int des_row, int des_col);
};

#endif