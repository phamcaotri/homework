// main.cpp
#include <iostream>
#include "Board.h"
#include "Piece.h"

using namespace std;

int main() {
  // Create a new board object
  Board board;
  // Display a welcome message
  cout << "Welcome to Chess Console Game!" << endl;
  // Loop until the user quits
  while (true) {
    // Display the board
    board.display();
    // Prompt for an action
    cout << "Enter an action (new/move/undo/save/load/quit): ";
    string action;
    cin >> action;
    // Handle different actions
    if (action == "new") {
      // Start a new game
      board.reset();
    } else if (action == "move") {
      // Prompt for a move
      cout << "Enter your move (e.g. e2e4): ";
      string move;
      cin >> move;
      // Try to make the move
      if (!board.MovePiece(move)) {
        // Invalid move
        cout << "Invalid move!" << endl;
      }
    } else if (action == "undo") {
      // Undo the last move
      if (!board.undoMove()) {
        // No moves to undo
        cout << "No moves to undo!" << endl;
      }
    } else if (action == "save") {
      // Prompt for a file name
      cout << "Enter a file name to save: ";
      string fileName;
      cin >> fileName;
      // Try to save the game
      if (!board.saveGame(fileName)) {
        // Save failed
        cout << "Save failed!" << endl;
      }
    } else if (action == "load") {
      

// Prompt for a file name
cout << "Enter a file name to load: ";
string fileName;
cin >> fileName;
// Try to load the game
if (!board.loadGame(fileName)) {
  // Load failed
  cout << "Load failed!" << endl;
}
} else if (action == "quit") {
// Quit the game
break;
} else {
// Invalid action
cout << "Invalid action!" << endl;
}
// Check for game over conditions
if (board.isCheckmate()) {
// Checkmate - display winner color and message 
cout << board.getTurnColor() << " wins by checkmate!" << endl; 
break; 
} else if (board.isStalemate()) { 
// Stalemate - display draw message 
cout << "Draw by stalemate!" << endl; 
break; 
} else if (board.isInsufficientMaterial()) { 
// Insufficient material - display draw message 
cout << "Draw by insufficient material!" << endl; 
break; 
} else if (board.isFiftyMoveRule()) { 
// Fifty-move rule - display draw message 
cout << "Draw by fifty-move rule!" << endl; 
break; 
} else if (board.isThreefoldRepetition()) { 
// Threefold repetition - display draw message 
cout <<"Draw by threefold repetition!"<<endl; break;}else{  	// Switch turn color  
	board.switchTurn();  
	}  
	}  
	return 0;}  

	// chess.h  
	#ifndef CHESS_H  
	#define CHESS_H  

	#include <string>  
	#include <vector>  

	using namespace std;

	// Define constants for colors and symbols  
	const char WHITE = 'W';  
	const char BLACK = 'B';  
	const char EMPTY = '.';  

	const char PAWN