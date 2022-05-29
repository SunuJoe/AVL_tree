// tree. h
// basic tree header.

#ifndef __TREE_H__
#define __TREE_H__

typedef int TDATA;
typedef struct __treeNode
{
  TDATA data;
  struct __treeNode* left;
  struct __treeNode* right;
} TREE;

//basic functions.
TREE* makeNode(void);
void setData(TREE* root, TDATA data);
TDATA getData(TREE* root);

// using free sub tree. 
void Traversal(TREE* root);

void makeLeftSubTree(TREE* root, TREE* sub);
void makeRightSubTree(TREE* root, TREE* sub);

// not using free. just connect sub trees.
void changeLeftSubTree(TREE* root, TREE* sub);
void changeRightSubTree(TREE* root, TREE* sub);

// get sub tree.
TREE* getLeftSubTree(TREE* root);
TREE* getRightSubTree(TREE* root);

// Remove sub tree.
TREE* removeLeftSubTree(TREE* root);
TREE* removeRightSubTree(TREE* root);

// print trees 
typedef void (*Func_React)(TDATA data);

void postTraversal(TREE* root, Func_React action);

#endif
