// AVLtree.h //
// add function define for making AVL tree. 

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "tree.h"

// Helper functions for getting Balance factor.
// return value is not for using real tree's height. it's bigger than real.
/*

// it's not necessary to define functions. 
// cause user dont  using each functions.

int getHeight(TREE* root);

int getHeightDiff(TREE* root);

//Rotation Status.

TREE* rotateLL(TREE* root);
TREE* rotateRR(TREE* root);
TREE* rotateLR(TREE* root);
TREE* rotateRL(TREE* root);
*/

// check return type and parameter value.
TREE* rebalancing(TREE** root);

#endif
