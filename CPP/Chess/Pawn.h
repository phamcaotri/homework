// Pawn.h

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece{
    private:
        bool is_first_move;
    public:
        Pawn(char color);
};


#endif