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

// *None

// Name: Yu Xiao
// login ID: y243xiao
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "board.h"

// === Snakes & Ladders Board Field ==========================================

// the number of fields on a snl board
const int fields = 100;

// represents no ladder/snake
const int none = -1;

// the number of fields per row
const int row = 10;

// node represents a field in the board
struct node {
  int field;
  int lad_dst;
  int sk_dst;
  struct node *next;
};

// ncreate(field)
static struct node *ncreate(const int field) {
  assert(1 <= field && field <= fields);
  struct node *f = malloc(sizeof(struct node));
  assert(f);
  f->field = field;
  f->lad_dst = none;
  f->sk_dst = none;
  f->next = NULL;
  return f;
}

// === Snakes & Ladders Board ================================================


struct board {
  struct node *first;
};

////////update this
static struct board *bcreate() {
  struct board *snl = malloc(sizeof(struct board));
  snl->first = NULL;
  return snl;
}

///////update this
static void add_front(int field, struct board *snl) {
  struct node *new = ncreate(field);
  new->next = snl->first;
  snl->first = new;
}

////////
static void update(struct node *f, const int fld, const int lad, const int sk) {
  struct node *node = f;
  while (node) {
    if (node->field == fld) {
      node->field = fld;
      node->lad_dst = lad;
      node->sk_dst = sk;
      break;
    } else {
      node = node->next;
    }
  }
}

// See board.h for documentation
struct board *board_read() {
  struct board *snl = bcreate();
  for (int i = fields; 0 < i; --i) {
    add_front(i, snl);
  }
  int fld = 0;
  int lad = 0;
  int sk = 0;
  while (scanf("%d %d %d", &fld, &lad, &sk) == 3) {
    update(snl->first, fld, lad, sk);
  }
  return snl;
}

// See board.h for documentation
void board_destroy(struct board *snl) {
  struct node *cur = snl->first;
  struct node *nextnode = NULL;
  while (cur) {
    nextnode = cur->next;
    free(cur);
    cur = nextnode;
  }
  free(snl);
}

// See board.h for documentation
int board_next(const struct board *snl, int start, int roll) {
  if (start + roll > fields) {
    return fields;
  } else {
    struct node *node = snl->first;
    while (node) {
      if (node->field == start + roll) {
        if (node->lad_dst != none) {
          return node->lad_dst;
        } else if (node->sk_dst != none) {
          return node->sk_dst;
        } else {
          return node->field;
        }
      } else {
        node = node->next;
      }
    }
  }
  return 0;
}

// See board.h for documentation
void board_print(const struct board *snl) {
  const struct node *node = snl->first;
  while (node) {
    if (node->lad_dst != none) {
      printf("[%03d (%02d>)] => ", node->field, node->lad_dst);
    } else if (node->sk_dst != none) {
      printf("[%03d (<%02d)] => ", node->field, node->sk_dst);
    } else if (node->field == fields) {
      printf("[   %03d   ]", node->field);
    } else {
      printf("[   %03d   ] => ", node->field);
    }
    if (node->field >= row && node->field % row == 0) {
      printf("\n");
    }
    node = node->next;
  }
}