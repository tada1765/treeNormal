#ifndef _TREENORMAL_H
#define _TREENORMAL_H
#include <stdio.h>
#include <stdlib.h>
// normal tree, recursion not apply: PreOrder
/*
 *		   1
 *		  / \
 *	   2   3
 *	  / \ / \
 *	 4  5 6  7
 *   |  | |  |
 *	 -----------nuLL
 */
typedef struct BinaryTreeNode BinaryTreeNode;
struct BinaryTreeNode{
	int data;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};
typedef struct DynArrayStack DynArrayStack;
struct DynArrayStack{
	int top;
	int capacity;
	char * array;
};
int IsEmptyStack( DynArrayStack *S);
int IsFullStack( DynArrayStack * S);
void Push( DynArrayStack *S, int data);
int Pop( DynArrayStack *S);
DynArrayStack *CreateStack();
int Top( DynArrayStack *S);
void DoubleStack( DynArrayStack *S);
void DeleteStack(DynArrayStack *S);
int * PreOrder(BinaryTreeNode *root);
BinaryTreeNode*  createNode(int data);

#endif // _TREENORMAL_H
