#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

#define bool int
#define true 1
#define false 0

Node* newTree(){
	Node* tree = NULL;

return tree;
}

int lookup(Node* root, int target){
int res = 0;

	if(root == NULL){
		res = 0;
	}else{
		if(root->number == target){
			res = 1;
		}else{
			if((root->left != NULL) && (target <= root->left->number)){
				res = lookup(root->left, target);
			}else{
				if(root->right != NULL){
					res = lookup(root->right, target);
				}
			}
		}
	}
return res;
}

Node* insert(Node* node, int number){

	if(node == NULL){
		Node* node = (Node*) malloc (sizeof (Node));
		node->number = number;
		node->left = NULL;
		node->right = NULL;
		return node;
	}else{
		if(number <= node->number){
			node->left = insert(node->left, number);
		}else{
			node->right = insert(node->right, number);
		}
	}
return node;
}

int size(Node* node){
		if(node == NULL){
			return 0;
		}else{
			return size(node->left) + size(node->right) + 1;
		}
}

int getMax(int a, int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}
}

int getMin(int a, int b){
	if(a <= b){
		return a;
	}else{
		return b;
	}
}

int maxDepth(Node* node){
		if(node == NULL){
			return 0;
		}else{
			return getMax((maxDepth(node->left) + 1), (maxDepth(node->right) + 1));
		}
}

int minValue(Node* node){
		if(node->left == NULL){
			return node->number;
		}else{
			return getMin(node->number, minValue(node->left));
		}
}

int maxValue(Node* node){
		if(node->right == NULL){
			return node->number;
		}else{
			return getMax(node->number, maxValue(node->right));
		}
}

int numberOfLeaves(Node* node){
	if(node == NULL){
		return 0;
	}else{
		if(node->left == NULL && node->right == NULL){
			return 1;
		}
		return numberOfLeaves(node->left) + numberOfLeaves(node->right);;
	}

}

void printTree(Node* node){
	if(node == NULL){
		return;
	}else{
		printTree(node->left);
		printf("%d ", node->number);
		printTree(node->right);
	}
}

void printTreePostOrder(Node* node){
	if(node == NULL){
		return;
	}else{
		printTreePostOrder(node->left);
		printTreePostOrder(node->right);
		printf("%d ", node->number);
	}
}


bool hasPathSum(Node* node, int sum){
	
	if(node == NULL){
		return false;
	}else{
		if(node->left == NULL && node->right == NULL){
			if((sum - node->number) == 0){
				return true;
			}else{
				return false;
			}
		}else{
			return (hasPathSum(node->left, sum - node->number)) || (hasPathSum(node->right, sum - node->number));
		}
	}
}

void printArray(char array[], int len){
	
	for(int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void recursiveFunction(Node* node, char string[], int index){

	if(node == NULL){
		return;
	}else{
		string[index] = node->number;
		index++;
		recursiveFunction(node->left,string,index);
		recursiveFunction(node->right,string,index);

		if(node->left == NULL && node->right == NULL){
			printArray(string, index);
		}
	}
}

void printPaths(Node* node){
	char string[maxDepth(node)];
	recursiveFunction(node,string,0);
}


void mirror(Node* node){

	if(node->left == NULL && node->right == NULL){
		return;
	}else{
		Node* left = node->left;
		Node* right = node->right;
		
		node->left = right;
		node->right = left;

		mirror(node->left);
		mirror(node->right);
	}
}

void doubleTree(Node* node){
	if(node == NULL){
		return;
	}else{
		Node* left = node->left;
		Node* right = node->right;

		Node* newNode = (Node*) malloc (sizeof(Node));
		newNode->number = node->number; 

		node->left = newNode;
		newNode->left = left;
		node->right = right;

		doubleTree(left);
		doubleTree(right);
	}
}

int sameTree(Node* a, Node* b){

	if((a == NULL && b != NULL) || (a != NULL && b == NULL)){
		return 0;
	}else{
		if(a == NULL && b == NULL){
			return 1;
		}else{
			if(a->number == b->number){
				return 1 && (sameTree(a->left,b->left) && sameTree(a->right,b->right));
			}else{
				return 0;
			}
		}
	}
}

int recursiveFunctionBST(Node* node, int value, int branchFlag,int fatherValue){
	if(node != NULL){
		if(branchFlag == 0){
				if(node->number <= fatherValue && fatherValue >= value){
					if(node->left != NULL && node->right != NULL){
						return 1 && recursiveFunctionBST(node->left,minValue(node),0,node->number) && recursiveFunctionBST(node->right,maxValue(node),1,node->number);
					}else{
						return 1;
					}
				}else{
					return 0;
				}		
		}else{
			//branch flag == 1
			if(node->number > fatherValue && fatherValue <= value){
				if(node->left != NULL && node->right != NULL){
					return 1 && recursiveFunctionBST(node->left,minValue(node),0,node->number) && recursiveFunctionBST(node->right,maxValue(node),1,node->number);
				}else{
					return 1;
				}
			}else{
				return 0;
			}	
		}
	}else{
		return 1;
	}
}


int isBST(Node* node){

	if(node != NULL){
		if(node->number >= node->left->number && node->number < node->right->number){
			return recursiveFunctionBST(node->left,minValue(node),0,node->number) && recursiveFunctionBST(node->right,maxValue(node),1,node->number);		
		}else{
			return recursiveFunctionBST(node,minValue(node),0,node->number) && recursiveFunctionBST(node,maxValue(node),1,node->number);		
		}
	}else{
		return 0;
	}
}


int recursiveFunctionIsBalanced(Node* node){

	if(node == NULL){
		return 0;
	}else{
		if(node->left == NULL && node->right == NULL){
			return 1;
		}else{
			if(node->left != NULL && node->right != NULL){
				return (recursiveFunctionIsBalanced(node->left) + 1) - (recursiveFunctionIsBalanced(node->right) +1);
			}else{
				if(node->left != NULL && node->right == NULL){
					return recursiveFunctionIsBalanced(node->left) + 1;
				}else{
					return recursiveFunctionIsBalanced(node->right) + 1;
				}
			}
				
		}
	}

}

int isBalanced(Node* node){
	if(node != NULL){
		if(abs(recursiveFunctionIsBalanced(node->left) - recursiveFunctionIsBalanced(node->right)) <= 1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}	
}