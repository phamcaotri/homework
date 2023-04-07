// Piece.h

#ifndef PIECE_H
#define PIECE_H

class Piece {
    private:
        char color; // W: white, B: black
        char type; // (K, Q, R, B, N, P) for (King, Queen, Rock, Bishop, Knight, Pawn)
    public:
    // constructor
        Piece(char color, char type) {
            this -> color = color;
            this -> type = type;
        }
        char get_color() {
            return this -> color;
        }
        char get_type() {
            return this -> type;
        }
        bool can_move(int src_row, int src_col, int des_row, int des_col);

};

#endif