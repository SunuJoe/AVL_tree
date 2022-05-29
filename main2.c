// main2.c //
// using AVL tree 

#include <stdio.h>
#include "AVLtree.h"
#include "bstree.h"

void show(int data)
{
  printf("%d\n", data);
}

int main(int argc, char* argv[])
{
  TREE* avtree;
  Init(&avtree);

  TREE* Temp;

  Insert(&avtree, 1);
  Insert(&avtree, 2);
  Insert(&avtree, 3);
  Insert(&avtree, 4);
  Insert(&avtree, 5);
  Insert(&avtree, 6);
  Insert(&avtree, 7);
  Insert(&avtree, 8);

  postTraversal(avtree, show);

  return 0;
}


