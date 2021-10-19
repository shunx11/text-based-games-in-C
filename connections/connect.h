#include <stdbool.h>

// full(board, slot) returns true if the slot is full and false otherwise
bool full(const char board[], int slot);

// draw(board) returns true if the game is a draw and false otherwise
bool draw(const char board[]);

// update(board, player, slot) updates the gameboard with the players chip at 
//   the apropriate slot
// requires: player must be X or O
//           slot must be non-negative and less than 7
// effects: modifies board
void update(char board[], char player, int slot);

// finished(board) returns the player that won, or no one else if drawn, or
//   nothing if the game is still running
char finished(const char board[]);