#include "tree.h"

int main()
{
	root = insert(root,5);
	root = insert(root,1);
	root = insert(root,9);

	printf("preorder : ");
	preorderPrint(root);
	printf("\n");
	printf("inorder : ");
	inorderPrint(root);
	printf("\n");
	printf("postorder : ");
	postorderPrint(root);
	printf("\n\n");


	printf("preorder : ");
	preorderPrint(root);
	printf("\n");

	printf("delete : 9\n");
	root = delete(root,9);

	preorderPrint(root);
	printf("\n");

	root = insert(root,9);

	printf("delete : 1\n");
	root = delete(root,1);

	preorderPrint(root);
	printf("\n");

	root = insert(root,1);

	printf("delete : 5\n");
	root = delete(root,5);

	preorderPrint(root);
	printf("\n");
}