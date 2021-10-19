/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS (v2)

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
//
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff, which you do not have to mention)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from and/or collaborated with:

// * None

// Name: Yu Xiao
// login ID: y243xiao
/////////////////////////////////////////////////////////////////////////////

// this program solves mazes with the right-hand wall follower method

#include <assert.h>
#include <stdlib.h>
#include "maze.h"

// === HELPER FUNCTION ========================================================
// next(m, d1, d2, d3, d4) returns the direction for the next step of maze m
// requires: d1 to be one of UP, DOWN, LEFT or RIGHT
//           d1, d2, d3, d4 must be in ccw order
//           none of UP, DOWN, LEFT or RIGHT can be repeated
int next(const struct maze *m,
         const int d1, const int d2, const int d3, const int d4) {
  assert(d1 == UP || d1 == DOWN || d1 == LEFT || d1 == RIGHT);
  assert(d2 == UP || d2 == DOWN || d2 == LEFT || d2 == RIGHT);
  assert(d3 == UP || d3 == DOWN || d3 == LEFT || d3 == RIGHT);
  assert(d4 == UP || d4 == DOWN || d4 == LEFT || d4 == RIGHT);
  assert(d1 != d2 && d1 != d3 && d1 != d4);
  assert(d2 != d3 && d2 != d4);
  assert(d3 != d4);
  
  int final = 0;
  if (is_wall(m, d1) == 0) {
    final = d1;
  } else if (is_wall(m, d2) == 0) {
    final = d2;
  } else if (is_wall(m, d3) == 0) {
    final = d3;
  } else if (is_wall(m, d4) == 0) {
    final = d4;
  }
  return final;
}

int main(void) {
  struct maze *maze = read_maze();
  int d = DOWN;
  while (1) {
    if (d == LEFT) {
      d = next(maze, UP, LEFT, DOWN, RIGHT);
    } else if (d == DOWN) {
      d = next(maze, LEFT, DOWN, RIGHT, UP);
    } else if (d == RIGHT) {
      d = next(maze, DOWN, RIGHT, UP, LEFT);
    } else if (d == UP) {
      d = next(maze, RIGHT, UP, LEFT, DOWN);
    }
    move(maze, d);
  }
  return EXIT_SUCCESS;
}
