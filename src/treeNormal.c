#include "treeNormal.h"
/* DynArrayStack *CreateStack(){
	 DynArrayStack * S = ( DynArrayStack*)malloc(sizeof(DynArrayStack));
	if(!S)
		return NULL;
	S->capacity = 10;
	S->top =-1;
	S->array = malloc(S->capacity*sizeof(int));
	if(!S->array)
		return NULL;
	return S;
	
} */
/* int IsEmptyStack( DynArrayStack *S){
	return(S->top == -1); 
} */
/* int IsFullStack( DynArrayStack * S){
	return(S->top == S->capacity-1);
} */
/* void Push( DynArrayStack *S, int data){
	if(IsFullStack(S)){
		DoubleStack(S);
	}else{
	S->array[++S->top]=data;
	}
} */
/* int Top( DynArrayStack *S){
	if(IsEmptyStack(S))
		return 0;
	return S->array[S->top];
} */
/* int Pop( DynArrayStack *S){
	if(IsEmptyStack(S)){
		printf("Stack is Empty\n");
		return 1;
	}else
		return(S->array[S->top--]);
	
} */
/* void DoubleStack( DynArrayStack *S){
	S->capacity *= 2;
	S->array = realloc(S->array, S->capacity* sizeof(int));
} */
/* void DeleteStack(DynArrayStack *S){
	if(S){
		if(S->array)
			free(S->array);
		free(S);
	}
} */
/* void PreOrder(BinaryTreeNode *root){
	DynArrayStack *S = CreateStack();
	while(1){
		while(root){
			//process current node
			printf("%d",root->data);
			Push(S,root->data);
			//If left subtree exit, add to stackavail
			root=root->left;
		}
		if(IsEmptyStack(S))
			break;
		else{
		root->data=Pop(S);
		//Indicate completion of left subtree and current node, now go to right subtree
		root=root->right;	
		}
	}
	DeleteStack(S);
} */

static int buf[10];
int i = 0;
int * PreOrder(BinaryTreeNode *root){
	// char * error = xxxxx;
	// if(xxxx != yyyy){
		// throwError(1,"ERROR %d: '%s' is not ?????????.",1,(error));
	// }else{return xxxxx;}
	if(root){
		//printf("%d",root->data);
		buf[i] = root->data;
		i++;
		PreOrder(root->left);
		PreOrder(root->right);
		buf[i] = '\0';
		return buf;
	}
}

BinaryTreeNode*  createNode(int data){
	BinaryTreeNode * newNode = ( BinaryTreeNode*)malloc(sizeof( BinaryTreeNode));
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->data= data;
	return newNode;
}