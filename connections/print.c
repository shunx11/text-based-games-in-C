// This program provides functions to print game board

#include "print.h"
#include <stdio.h>

// === Constants ==============================================================
static const int boardwidth = 7;
static const int boardheight = 5;

// printrow(board, row) prints the idividual rows of the game board
static void printrow(const char board[], const int row) {
  for (int i = 0; i < boardwidth; ++i) {
    printf("|");
    if (board[row * boardwidth + i] != 'e') {
      printf("%c", board[row * boardwidth + i]);
    } else {
      printf("_");
    }
  }
  printf("|\n");
}

// see print.h for documentation
void print(const char board[]) {
  for (int r = boardheight; r >= 0; --r) {
    printrow(board, r);
  }
  printf(" %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6);
}