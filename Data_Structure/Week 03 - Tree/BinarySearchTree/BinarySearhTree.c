#include "BinarySearchTree.h"

Node *searchBST(Node *root, int key) {
		Node *p = root; // 간단한 표기를 위하여

		while (p != NULL) {
				if (p->data == key)
						return p;
				else if (p->data < key)
						p = p->right;
				else
						p = p->left;
		}
		return (NULL);
}

Node *insertBST(Node * root, char c) {
		Node *p == root;
		Node *parent == NULL;

		while (p != NULL) {
				parent = p;
				if (p->key == c) {
						printf("\nexist same key\n");
						return p;
				}
				else if (p->key < c)
						p = p->right;
				else
						p = p->left;
		}
		
		// 새 노드 할당
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->key = c;
		newNode->left = newNode->right = NULL;

		//parent의 자식으로 새 노드 붙이기
		if (parent != NULL) {
				if (parent->key < newNode->key)
						parent->right = newNode;
				else
						parent->left = newNode;
		}

		return (NULL);
}


Node *deleteBST(Node * root, char c) {
		Node *p == root;
		Node *parent == NULL;

		while ((p != NULL) && (p->key != c)) {
				parent = p;
				if (p->key < c)
						p = p->right;
				else
						p = p->left;
		}
		if (p == NULL) {
				printf("\nno key found\n");
				return root; // 받은 그대로 반환

		// 차수가 0인 경우 (무조건 단말 노드인 경우)
		if ((p->left == NULL) && (p->right == NULL)) {
				//찾고자 하는 값이 root의 값인 경
				if (parent == NULL) // 찾고자 하는 c가 root의 값이라면 while문을 돌지 않아 parent가 NULL 그대로이기 때문에 'parent == NULL'이다라는 말은 찾고자 하는 값이 root의 값이다라는 말과 동일시 할 수 있음 
						root = NULL;
				// 찾고자 하는 값이 root가 아닌 노드의 값인 경
				else {
						if (parent->left == p)
								parent->left == NULL;
						else
								parent->right == NULL;
		}

		// 차수가 1인 경우 (자식을 하나만 가지고 있는 경우)
		else if (p->left == NULL || p->right == NULL) {
				Node *child = (p->left != NULL) ? p->left : p->right;
				if (parent == NULL)
						root = child;
				else {
						if (parent->left == p)
								parent->left = child;
						else
								parent->right = child;
						}
		}

		// 차수가 2인 경우
		else {
				Node *succParent = p; // succParent는 후계자
				Node *succ = p->right;
				while (succ->left = succ) {
						succParent = succ;
						succ = succ->left;
				}
				p->key = succ->key;
				if (succParent->left == succ)
						succParent->left = succ->right;
				else
						succParent->right = succ->right;
				p = succ;
				}

		free(p);

		return (root);
}