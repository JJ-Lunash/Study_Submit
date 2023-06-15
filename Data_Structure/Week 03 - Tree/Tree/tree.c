# include "tree.h"


node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return (newNode);
}

node* insert(node* root,int data)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->right = root->left = NULL;
		root->data = data;
		return root;
	}
	else
	{
		if(data < root->data)
			root->left = insert(root->left,data);
		else
			root->right = insert(root->right,data);
	}
	return root;
}


node* findLowest(node* root)
{
	node* lowestNode = root;
	while(lowestNode->left!=NULL)
		lowestNode = lowestNode->left;
	return lowestNode;
}


node* delete(node* root,int data)
{
	node *tmproot = NULL;

	if(root == NULL)
		return NULL;

	if(data < root->data)
		root->left = delete(root->left,data);
	else if(data > root->data)
		root->right = delete(root->right,data);
	else
	{
		if(root -> left != NULL && root->right != NULL)
		{
			tmproot = findLowest(root->right);
			root->data = tmproot->data;
			root->right = delete(root->right,tmproot->data);
		}
		else
		{
			tmproot = (root->left == NULL) ? root->right : root->left;
			free(root);
			return tmproot;
		}
	}
	return root;
}

void printNode(node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root->data);
	print(root->left);
	print(root->right);
}


//전위 순회
void preorderPrint(node* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	printNode(root->left);
	printNode(root->right);
}


//중위 순회
void inorderPrint(node* root)
{
	if(root==NULL)
		return;
	printNode(root->left);
	printf("%d ",root->data);
	printNode(root->right);
}


//후위 순회
void postorderPrint(node* root)
{
	if(root==NULL)
		return;
	printNode(root->left);
	printNode(root->right);
	printf("%d ",root->data);
}


// 배운점
// 단순하고 반복되는 패턴의 경우 그 패턴을 찾아 재귀화하면 (처리해야 하는 수가 적당할 때) 훨씬 효율적
// 일정 수준을 넘어가기 전에 트리는 합리적인 자료구조임 -> 일정 수준 넘어가면 트리 나눠서 만들기