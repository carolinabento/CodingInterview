#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.c"


void createEmptyTreeTest(){

	Node* root = newTree();

	assert(root == NULL);
}

void lookupTest(){
	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);

	assert(lookup(root,1) == 1);
	assert(lookup(root,2) == 1);
	assert(lookup(root,3) == 1);

	assert(lookup(root,4) == 0);
}

void insertTest(){
	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);

	assert(root->number == 1);
	assert(root->right->number == 2);
	assert(root->right->right->number == 3);
}

void sizeTestI(){

	Node* root = newTree();

	assert(root == NULL);
	assert(size(root) == 0);
}

void sizeTestII(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 0);
	root = insert(root, 3);

	assert(root != NULL);

	assert(root->number == 1);
	assert(root->right->number == 2);
	assert(root->right->right->number == 3);
	assert(root->left->number == 0);

	assert(size(root) == 4);
}

void sizeTestIII(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);

	assert(root != NULL);

	assert(size(root) == 3);
}


void maxDepthTestI(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);

	assert(root != NULL);

	assert(maxDepth(root) == 3);

	root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 0);

	assert(root != NULL);

	assert(maxDepth(root) == 3);
}

void maxDepthTestII(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(maxDepth(root) == 3);
}

void minValueTest(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(minValue(root) == 1);
}

void minValueTestII(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);

	assert(minValue(root) == 1);
}

void printTreeTest(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, -1);

	printTree(root);
	printf("%s\n", "");
}

void printTreeTestI(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 0);

	printTree(root);
	printf("%s\n", "");
}

void printTreeTestII(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	printTree(root);
	printf("%s\n", "");
}


void printTreePostOrderTest(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, -1);

	printTreePostOrder(root);
	printf("%s\n", "");
}

void printTreePostOrderTestI(){

	Node* root = newTree();

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 0);

	printTreePostOrder(root);
	printf("%s\n", "");
}

void printTreePostOrderTestII(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(root->number == 4);
	assert(root->left->number == 2);
	assert(root->right->number == 5);

	assert(root->left->left->number == 1);
	assert(root->left->right->number == 3);
	
	printTreePostOrder(root);
	printf("%s\n", "");
}

void numberOfLeavesTest(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(root->number == 4);
	assert(root->left->number == 2);
	assert(root->right->number == 5);

	assert(root->left->left->number == 1);
	assert(root->left->right->number == 3);
	
	assert(numberOfLeaves(root) == 3);
}


void hasPathSumTest(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	
	assert(hasPathSum(root,7) == true);
	assert(hasPathSum(root,9) == true);
	assert(hasPathSum(root,10) == false);
}


void hasPathSumTestI(){

	Node* root = newTree();
	
	assert(hasPathSum(root,0) == false);
}


void hasPathSumTestII(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 3);

	
	assert(hasPathSum(root,9) == true);
	assert(hasPathSum(root,7) == true);
	assert(hasPathSum(root,10) == false);
	assert(hasPathSum(root,17) == true);
}



void printPathTest(){

	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 3);

	printPaths(root);
}

void mirrorTest(){
	Node* root = newTree();

	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(root->number == 4);
	assert(root->left->number == 2);
	assert(root->right->number == 5);

	assert(root->left->left->number == 1);
	assert(root->left->right->number == 3);

	mirror(root);

	assert(root->number == 4);
	assert(root->left->number == 5);
	assert(root->right->number == 2);

	assert(root->right->right->number == 1);
	assert(root->right->left->number == 3);
}


void doubleTreeTest(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);


	assert(root->number == 2);
	assert(root->left->number == 1);
	assert(root->right->number == 3);

	doubleTree(root);

	assert(root->number == 2);
	assert(root->left->number == 2);
	assert(root->right->number == 3);

	assert(root->left->left->number == 1);
	assert(root->left->left->left->number == 1);

	assert(root->right->left->number == 3);
	assert(root->right->left->left == NULL);
	assert(root->right->left->right == NULL);

}



void sameTreeTest(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);


	assert(root->number == 2);
	assert(root->left->number == 1);
	assert(root->right->number == 3);

	Node* root1 = newTree();

	root1 = insert(root1, 2);
	root1 = insert(root1, 1);
	root1 = insert(root1, 3);


	assert(root1->number == 2);
	assert(root1->left->number == 1);
	assert(root1->right->number == 3);

	assert(sameTree(root,root1) == 1);
}

void sameTreeTestI(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);


	assert(root->number == 2);
	assert(root->left->number == 1);
	assert(root->right->number == 3);

	Node* root1 = newTree();

	root1 = insert(root1, 4);
	root1 = insert(root1, 2);
	root1 = insert(root1, 5);
	root1 = insert(root1, 1);
	root1 = insert(root1, 3);

	assert(sameTree(root,root1) == 0);
}


void sameTreeTestII(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);


	assert(root->number == 2);
	assert(root->left->number == 1);
	assert(root->right->number == 3);

	Node* root1 = newTree();

	root1 = insert(root1, 2);
	root1 = insert(root1, 0);
	root1 = insert(root1, 3);

	assert(sameTree(root,root1) == 0);
}




void isBSTTest(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(isBST(root) == 1);
}

void isBSTTestI(){
	Node* root = newTree();


	Node* n1 = (Node*) malloc(sizeof (Node));
	Node* n2 = (Node*) malloc(sizeof (Node));
	Node* n3 = (Node*) malloc(sizeof (Node));

	n1->number = 5;
	n1->left = NULL;
	n1->right = NULL;

	n2->number = 6;
	n2->left = NULL;
	n2->right = NULL;

	n3->number = 7;
	n3->left = NULL;
	n3->right = NULL;

	root = n1;
	root->left = n2;
	root->right = n3;

	assert(isBST(root) == 0);
}


void isBSTTestII(){
	Node* root = newTree();


	Node* n1 = (Node*) malloc(sizeof (Node));
	Node* n2 = (Node*) malloc(sizeof (Node));
	Node* n3 = (Node*) malloc(sizeof (Node));
	Node* n4 = (Node*) malloc(sizeof (Node));

	n1->number = 5;
	n1->left = NULL;
	n1->right = NULL;

	n2->number = 2;
	n2->left = NULL;
	n2->right = NULL;

	n3->number = 7;
	n3->left = NULL;
	n3->right = NULL;

	n4->number = 1;
	n4->left = NULL;
	n4->right = NULL;


	root = n1;
	root->left = n2;
	root->right = n3;
	root->left->left = n4;

	assert(isBST(root) == 1);
}

void isBalancedTest(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);

	assert(isBalanced(root) == 1);
}

void isBalancedTestI(){
	Node* root = newTree();

	root = insert(root, 2);
	root = insert(root, 1);

	assert(isBalanced(root) == 1);
}


void isBalancedTestII(){
	Node* root = newTree();


	Node* n1 = (Node*) malloc(sizeof (Node));
	Node* n2 = (Node*) malloc(sizeof (Node));
	Node* n3 = (Node*) malloc(sizeof (Node));

	n1->number = 5;
	n1->left = NULL;
	n1->right = NULL;

	n2->number = 2;
	n2->left = NULL;
	n2->right = NULL;

	n3->number = 1;
	n3->left = NULL;
	n3->right = NULL;

	root = n1;
	root->left = n2;
	root->left->left = n3;

	assert(isBalanced(root) == 0);
}


void isBalancedTestIII(){
	Node* root = newTree();


	Node* n1 = (Node*) malloc(sizeof (Node));
	Node* n2 = (Node*) malloc(sizeof (Node));
	Node* n3 = (Node*) malloc(sizeof (Node));
	Node* n4 = (Node*) malloc(sizeof (Node));
	Node* n5 = (Node*) malloc(sizeof (Node));
	Node* n6 = (Node*) malloc(sizeof (Node));
	Node* n7 = (Node*) malloc(sizeof (Node));
	Node* n8 = (Node*) malloc(sizeof (Node));
	Node* n9 = (Node*) malloc(sizeof (Node));

	n1->number = 8;
	n1->left = NULL;
	n1->right = NULL;

	n2->number = 5;
	n2->left = NULL;
	n2->right = NULL;

	n3->number = 10;
	n3->left = NULL;
	n3->right = NULL;

	n4->number = 4;
	n4->left = NULL;
	n4->right = NULL;

	n5->number = 6;
	n5->left = NULL;
	n5->right = NULL;

	n6->number = 9;
	n6->left = NULL;
	n6->right = NULL;

	n7->number = 11;
	n7->left = NULL;
	n7->right = NULL;

	n8->number = 3;
	n8->left = NULL;
	n8->right = NULL;

	n9->number = 12;
	n9->left = NULL;
	n9->right = NULL;

	root = n1;
	root->left = n2;
	root->right = n3;
	root->left->left = n4;
	root->left->right = n5;
	root->left->left->left = n8;

	root->right->left = n6;
	root->right->right = n7;
	root->right->right->right = n9;

	assert(isBalanced(root) == 0);
}


void getNodesDepthTest(){
	Node* root = newTree();

	root = insert(root, 5);
	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 6);
	root = insert(root, 8);


	assert(root->number == 5);
	assert(root->left->number == 4);
	assert(root->right->number == 7);

	NodeList *list = newLinkedlist();
	list = getNodesN(root,1);
	
	assert(list->value == 7);
	assert(list->next->value == 4);
}



int main(){

	createEmptyTreeTest();
	lookupTest();
	insertTest();
	sizeTestI();
	sizeTestII();
	sizeTestIII();
	maxDepthTestI();
	maxDepthTestII();
	minValueTest();
	minValueTestII();
	printTreeTest();
	printTreeTestI();
	printTreeTestII();
	printTreePostOrderTest();
	printTreePostOrderTestI();
	printTreePostOrderTestII();
	numberOfLeavesTest();
	hasPathSumTest();
	hasPathSumTestI();
	hasPathSumTestII();
	printPathTest();
	mirrorTest();
	doubleTreeTest();
	sameTreeTest();
	sameTreeTestI();
	sameTreeTestII();
	isBSTTest();
	isBSTTestI();
	isBalancedTest();
	isBalancedTestI();
	isBalancedTestII();
	isBalancedTestIII();
	getNodesDepthTest();
return 0;
}