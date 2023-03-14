// Piece.h
#ifndef PIECE_H
#define PIECE_H

enum Color {WHITE, BLACK};

class Piece {
    private:
        Color color; // W: white, B: black
        int value;

    public:
    // constructor
        Piece(Color color, int value);
        virtual ~Piece();
        Color GetColor();
        int GetValue();
        virtual bool isValidMove(int src_row, int src_col, int des_row, int des_col) = 0;

};

#endif