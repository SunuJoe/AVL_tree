// bstree.h 
// binary search tree header.

#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "tree.h"

void Init(TREE** bstroot);

//getData();

// Search

TREE* Search(TREE* root, TDATA target);
// Insert

TREE* Insert(TREE** root, TDATA data);

// Delete

TREE* Delete(TREE** root, TDATA target);

#endif
