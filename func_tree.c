// func_tree.c 
// define functions of tree.

#include <stdlib.h>
//#include <stdio.h>
#include "tree.h"

TREE* makeNode(void)
{
  TREE* newNode = (TREE*)malloc(sizeof(TREE));
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void setData(TREE* root, TDATA data)
{
  root->data = data;
}

TDATA getData(TREE* root)
{
  return root->data;
}

void Traversal(TREE* root)
{
  if(root == NULL)
    return;
  
  Traversal(root->left);
  Traversal(root->right);
  free(root);
}

void makeLeftSubTree(TREE* root, TREE* sub)
{
  if(root->left != NULL)
    Traversal(root->left);
  
  root->left = sub;
}

void makeRightSubTree(TREE* root, TREE* sub)
{
  if(root->right != NULL)
    Traversal(root->right);
  
  root->right = sub;
}

void changeLeftSubTree(TREE* root, TREE* sub)
{
  root->left = sub;
}

void changeRightSubTree(TREE* root, TREE* sub)
{
  root->right = sub;
}

TREE* getLeftSubTree(TREE* root)
{
  return root->left;
}

TREE* getRightSubTree(TREE* root)
{
  return root->right;
}

TREE* removeLeftSubTree(TREE* root)
{
  TREE* temp = getLeftSubTree(root);
  root->left = NULL;
  return temp;
}

TREE* removeRightSubTree(TREE* root)
{
  TREE* temp = getRightSubTree(root);
  root->right = NULL;
  return temp;
}

void postTraversal(TREE* root, Func_React action)
{
  if(root == NULL)
    return;
  
  postTraversal(root->left, action);
  postTraversal(root->right, action);
  action(root->data);
}
