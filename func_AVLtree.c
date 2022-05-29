// func_AVLtree.c //
// define functions of AVL tree.

#include <stdio.h>
#include "AVLtree.h"
#include "tree.h"
//#include "bstree.h"

int getHeight(TREE* root)
{
  int left, right;

  if(root == NULL)
    return 0;

  left = getHeight(getLeftSubTree(root));
  right = getHeight(getRightSubTree(root));

  if(left > right)
    return left + 1;
  else
    return right + 1;
}

int getHeightDiff(TREE* root)
{
  int left, right;

  left = getHeight(getLeftSubTree(root));
  right = getHeight(getRightSubTree(root));

  return left - right;
}

TREE* rotateLL(TREE* root)
{
  TREE* pNode = root;
  TREE* cNode = getLeftSubTree(root);

  changeLeftSubTree(pNode, getRightSubTree(cNode));
  changeRightSubTree(cNode, pNode);

  return cNode;
}

TREE* rotateRR(TREE* root)
{
  TREE* pNode = root;
  TREE* cNode = getRightSubTree(root);

  changeRightSubTree(pNode, getLeftSubTree(cNode));
  changeLeftSubTree(cNode, pNode);

  return cNode;
}

TREE* rotateLR(TREE* root)
{
  TREE* pNode = root;
  TREE* cNode = getLeftSubTree(root);

  changeLeftSubTree(pNode, rotateRR(cNode));
  
  return rotateLL(pNode);
}

TREE* rotateRL(TREE* root)
{
  TREE* pNode = root;
  TREE* cNode = getRightSubTree(root);

  changeRightSubTree(pNode, rotateLL(cNode));

  return rotateRR(pNode);
}

TREE* rebalancing(TREE** root)
{
  int diff = getHeightDiff(*root);

  if(diff > 1)
  {
    if(getHeightDiff(getLeftSubTree(*root)) > 0 )
    {
      *root =  rotateLL(*root);
    }
    else
    {
      *root = rotateLR(*root);
    }
  }

  if(diff < -1)
  {
    if(getHeightDiff(getRightSubTree(*root)) < 0 )
    {
      *root = rotateRR(*root);    
    }
    else
    {
      *root = rotateRL(*root);
    }
  }

  return *root;
}
