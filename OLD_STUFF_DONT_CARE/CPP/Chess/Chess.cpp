#include <bits/stdc++.h>
    using namespace std;
#define EMPTY_CELL ' '
#define B_PAWN 'p'
#define B_ROCK 'r'
#define B_KNIGHT 'n'
#define B_BISHOP 'b'
#define B_QUEEN 'q'
#define B_KING 'k'
#define W_PAWN 'P'
#define W_ROCK 'R'
#define W_KNIGHT 'N'
#define W_BISHOP 'B'
#define W_QUEEN 'Q'
#define W_KING 'K'
#define S_CASTLE "0-0"
#define L_CASTLE "0-0-0"
char board[8][8];


bool start_menu()
{
    char user_input;
    bool is_quiting = false;
    cout << "welcome to chess! type h for help." << '\n';
    do
    {
        cin >> user_input;
        if (user_input == 'h')
        {
            cout << "1: play" << '\n' << "0: quit" << '\n';
        }
        else if (user_input == '0')
        {
            is_quiting = true;
        }
        else if (user_input == '1')
        {
            return 1;
        }
        else
        {
            cout << "not a valid input, try again!" << '\n';
        }
    } while (not is_quiting);
    cout << "Goodbye!";
    return 0;
    
}

void creating_board()
{
    for (int row = 0; row < 8; row ++)
        for (int column = 0; column <  8; column ++)
        {
            board[row][column] = EMPTY_CELL;
        }
    for (int column = 0; column < 8; column ++)
    {
        board[1][column] = B_PAWN;
        board[6][column] = W_PAWN;
    }
    board[0][0] = B_ROCK; board[0][7] = B_ROCK; board[7][0] = W_ROCK; board[7][7] = W_ROCK;
    board[0][1] = B_KNIGHT; board[0][6] = B_KNIGHT; board[7][1] = W_KNIGHT; board[7][6] = W_KNIGHT;
    board[0][2] = B_BISHOP; board[0][5] = B_BISHOP; board[7][2] = W_BISHOP; board[7][5] = W_BISHOP;
    board[0][3] = B_QUEEN; board[0][4] = B_KING; board[7][3] = W_QUEEN; board[7][4] = W_KING;


}

void output()
{
    for (int row = 0; row < 8; row ++)
    {   
        cout << 8-row << ' ';
        for (int column = 0; column <  8; column ++)
        {
            cout << board[row][column] << ' ';
        }
        cout << '\n';
    }
    cout << "  a b c d e f g h" << '\n';
}

bool illegal_input(string input)
{
    
    if (input == S_CASTLE or input == L_CASTLE)
        return 0;
    if (input.length() != 4)
        return 1;
    if (not (input[0] >= 'a' and input[0] <= 'h'))
        return 1;
    if (not (input[1] >= '1' and input[1] <= '9'))
        return 1;
    if (not (input[2] >= 'a' and input[2] <= 'h'))
        return 1;
    if (not (input[3] >= '1' and input[3] <= '9'))
        return 1;
    return 0;
}

void move(string input, bool is_white_move)
{
   
    if (is_white_move)
    {
        //code nhap thanh loi quan trang vs quan den
        if (input == S_CASTLE)
        {
            board[0][4] = EMPTY_CELL; board[0][7] = EMPTY_CELL;
            board[0][6] = W_KING; board[0][5] = W_ROCK;
            return;
        }
        if (input == L_CASTLE)
        {
            board[0][4] = EMPTY_CELL; board[0][0] = EMPTY_CELL;
            board[0][2] = W_KING; board[0][3] = W_ROCK;   
            return;         
        }

    }
    else
    {
        if (input == S_CASTLE)
        {
            board[7][4] = EMPTY_CELL; board[7][7] = EMPTY_CELL;
            board[7][6] = B_KING; board[7][5] = B_ROCK;
            return;
        }
        if (input == L_CASTLE)
        {
            board[7][4] = EMPTY_CELL; board[7][0] = EMPTY_CELL;
            board[7][2] = B_KING; board[7][3] = B_ROCK;
            return;            
        }
    }
    int row1 = 0, column1 = 0, row2 = 0, column2 = 0;
    row1 = 8 - input[1] + 48;
    column1 = input[0] - 97;
    row2 = 8 - input[3] + 48;
    column2 = input[2] - 97;

    board[row2][column2] = board[row1][column1];
    board[row1][column1] = EMPTY_CELL;
}
void white_move()
{
    string white_input;
    bool already_move = false;
    
    do
    {
        cin >> white_input;
        if (illegal_input(white_input))
        {
            cout << "not a legal input, try again!" << '\n';
        }
        else
        {
            move(white_input,true);
            already_move = true;

        }
    }
    while (not already_move);
}

void black_move()
{
    string black_input;
    bool already_move = false;
    
    do
    {
        cin >> black_input;
        if (illegal_input(black_input))
        {
            cout << "not a legal input, try again!" << '\n';
        }
        else
        {
            move(black_input,false);
            already_move = true;

        }
    }
    while (not already_move);
}

int main()
{
    if (start_menu() == 0)
        return 0;
    else
    {
        
        creating_board();
        output();
        while (true)
        {
            white_move();
            output();
            black_move();
            output();
        }
        
    }


    return 0;
}