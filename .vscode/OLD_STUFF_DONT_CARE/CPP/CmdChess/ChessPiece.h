// ChessPiece.h
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

enum Color {WHITE, BLACK};

class ChessPiece {
    private:
        Color color; // W: white, B: black
        int value;

    public:
    // constructor
        ChessPiece(Color color, int value);
        virtual ~ChessPiece();
        Color GetColor();
        int GetValue();
        virtual bool can_move(int src_row, int src_col, int des_row, int des_col) = 0;

};

#endif