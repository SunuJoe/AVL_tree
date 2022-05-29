// func_bstree.c 
// define functions of binary search tree.

#include <stdlib.h>
#include "bstree.h"
#include "AVLtree.h"

void Init(TREE** bstroot)
{
  *bstroot = NULL;
}

TREE* Search(TREE* root, TDATA target)
{
  TREE* cNode = root;

  while(cNode != NULL)
  {
    if(target ==  getData(cNode))
      return cNode;
    else if(target < getData(cNode))
      cNode = getLeftSubTree(cNode);
    else
      cNode = getRightSubTree(cNode);
  }
  return cNode;
}

// rebalancing Insert.

TREE* Insert(TREE** root, TDATA data)
{
  if(*root == NULL)
  {
    *root = makeNode();
    setData(*root, data);
  }

  else if(data < getData(*root))
  {
    Insert(&((*root)->left), data);
    //*root = rebalancing(root);
    rebalancing(root);
  }
  else if(data > getData(*root))
  {
    Insert(&((*root)->right), data);
    //*root = rebalancing(root);
    rebalancing(root);
  }
  else
  {
    return NULL;
  }

  return *root;
}

/*
void Insert(TREE** root, TDATA data)
{
  TREE* pNode = NULL;
  TREE* cNode = *root;
  TREE* nNode;

  while(cNode != NULL)
  {
    pNode = cNode;

    if(data == getData(cNode))
      return;
    else if(data < getData(cNode))
      cNode = getLeftSubTree(cNode);
    else
      cNode = getRightSubTree(cNode);
  }

  nNode = makeNode();
  setData(nNode, data);
  
  if(pNode != NULL)
  {
    if(data < getData(pNode))
      makeLeftSubTree(pNode, nNode);
    else
      makeRightSubTree(pNode, nNode);
  }
  else
    *root = nNode;
}
*/
TREE* Delete(TREE** root, TDATA target)
{
  TREE* vRoot = makeNode();
  TREE* pNode = *root;
  TREE* cNode = pNode;
  TREE* Temp;

  changeRightSubTree(vRoot, *root);

  while(cNode != NULL && getData(cNode) != target)
  {
    pNode = cNode;
    if(target < getData(cNode))
      cNode = getLeftSubTree(cNode);
    else
      cNode = getRightSubTree(cNode);
  }

  if(cNode == NULL)
    return NULL;
  //delete node is leaf node. 
  //there's no sub child node.
  if(getLeftSubTree(cNode) == NULL && getRightSubTree(cNode) == NULL)
  {
    if(getLeftSubTree(pNode) == cNode)
      Temp = removeLeftSubTree(pNode);
    else
      Temp = removeRightSubTree(pNode);
  }
  
  //Delete node has one sub child tree.
  else if(getLeftSubTree(cNode) == NULL || getRightSubTree(cNode) == NULL)
  {
    Temp = cNode;
    TREE* subTemp; //save sub child node pointer.

    if(getLeftSubTree(cNode) != NULL)
    {
      subTemp = getLeftSubTree(cNode);
    }
    else
    {
      subTemp = getRightSubTree(cNode);
    }
    
    if(target == getData(getLeftSubTree(pNode)))
    {
      changeLeftSubTree(pNode, subTemp);
    }
    else
    {
      changeRightSubTree(pNode, subTemp);
    }
  }

  //Delete node has two sub child trees.
  else
  {
    TREE* tpNode = cNode;
    TREE* tNode = getRightSubTree(cNode);

    while(getLeftSubTree(tNode) != NULL)
    {
      tpNode = tNode;
      tNode = getLeftSubTree(tNode);
    }
    
    Temp = tNode;
    setData(cNode, getData(tNode));

    if(getLeftSubTree(tpNode) == tNode)
    {
      changeLeftSubTree(tpNode, getRightSubTree(tNode));
    }
    else
    {
      changeRightSubTree(tpNode, getRightSubTree(tNode));
    }
  }

  if(getRightSubTree(vRoot) != *root)
  {
    *root = getRightSubTree(vRoot);
  }

  free(vRoot);
  rebalancing(root);
  return Temp;
}



























