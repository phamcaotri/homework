// Pawn.cpp
#include "Pawn.h"

Pawn::Pawn(char color) : Piece(color, 'P') {
    this -> is_first_move = true;
}

