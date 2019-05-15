#include "unity.h"
#include "treeNormal.h"
#include "Error.h"
#include 	<Exception.h>
#include 	"Exception.h"
#include 	"CException.h"
#include	<malloc.h>
#include	<stdlib.h>
void setUp(void)
{}
void tearDown(void)
{}


/* tree created as:
 *		   1
 *	  	/ \
 *	   2   3
 *	  / \ / \
 *	 4  5 6  7
 *   |  | |  |
 *	 -----------nuLL
 */
BinaryTreeNode* node1;

void test_createNode_left_and_root_existence_expected_no_error_as_desire_setting(void){
	node1 = createNode(1);  //create main root node 
	
	node1->right = createNode(3);			//..
	node1->left = createNode(2);			//create left node 
	node1->left->left = createNode(4);		//create left left node 
	node1->left->right = createNode(5);		//..
	node1->right->right = createNode(7);	//..
	node1->right->left = createNode(6);		//..
	
	TEST_ASSERT_NOT_NULL(node1);
	TEST_ASSERT_NOT_NULL(node1->right);
	TEST_ASSERT_NOT_NULL(node1->left);
	TEST_ASSERT_NOT_NULL(node1->left->left);
	TEST_ASSERT_NOT_NULL(node1->left->right);
	TEST_ASSERT_NOT_NULL(node1->right->right);
	TEST_ASSERT_NOT_NULL(node1->right->left);
	TEST_ASSERT_NULL(node1->right->left->right);
	TEST_ASSERT_NULL(node1->right->left->left);
}

void test_createNode_again_for_ensure_node1_tree_can_be_use_on_other_test(void){
	TEST_ASSERT_NOT_NULL(node1);
	TEST_ASSERT_NOT_NULL(node1->right);
	TEST_ASSERT_NOT_NULL(node1->left);
	TEST_ASSERT_NOT_NULL(node1->left->left);
	TEST_ASSERT_NOT_NULL(node1->left->right);
	TEST_ASSERT_NOT_NULL(node1->right->right);
	TEST_ASSERT_NOT_NULL(node1->right->left);
	TEST_ASSERT_NULL(node1->right->left->right);
	TEST_ASSERT_NULL(node1->right->left->left);
}

/* expected result: 
 *	1 2 4 5 3 6 7
 */
void test_PreOrder_test_output_of_preOrder_ecpected_1245367(void){
	TEST_ASSERT_NOT_NULL(node1); //test present of tree
	CEXCEPTION_T e;
	int expectedResult[] = {1,2,4,5,3,6,7};
	int *result = PreOrder(node1);
	size_t size = sizeof(result);// / sizeof(result[0]);
	for(int i = 0 ; i < size-0 ; i++){
		//printf("%d\n",result[i]);
		//printf("%d\n",expectedResult[i]);
		TEST_ASSERT_EQUAL_INT(expectedResult[i],result[i]);
		/* Try {
			//TEST_ASSERT_EQUAL_INT(expected, actual)
			//TEST_ASSERT_EQUAL_INT(expectedResult[i],result[i]);
			TEST_FAIL_MESSAGE("Expect DATA_NOT_FOUND. But no exception thrown.");
		} Catch(e){
			printf(e->errorMsg);
			TEST_ASSERT_EQUAL(DATA_NOT_FOUND, e->errorCode);
			freeError(e);
		} */
	}
}