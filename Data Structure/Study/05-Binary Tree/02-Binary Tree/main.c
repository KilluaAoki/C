#include "Binary Tree.h"

void Test_BinaryTree_01()
{
	printf("******************************01******************************\n");
	BTNode* root = Create_BinaryTreeNode(1);
	root->left = Create_BinaryTreeNode(2);
	root->right = Create_BinaryTreeNode(4);
	root->left->left = Create_BinaryTreeNode(3);
	root->right->left = Create_BinaryTreeNode(5);
	root->right->right = Create_BinaryTreeNode(6);

	Preorder_Traversals(root);
	printf("\n");
	Inorder_Traversals(root);
	printf("\n");
	Postorder_Traversals(root);
	printf("\n");

	printf("%zu\n", Size_BinaryTree(root));
	printf("%zu\n", Size_Leaf_BinaryTree(root));
	printf("%zu\n", Size_OneSpend_BinaryTree(root));
	printf("%zu\n", Height_BinaryTree(root));
	printf("%zu\n", K_Layer_BinaryTree(root, 1));
	printf("%zu\n", K_Layer_BinaryTree(root, 2));
	printf("%zu\n", K_Layer_BinaryTree(root, 3));

	if (Find_BinaryTree(root, 4) == root->right)
	{
		printf("Good Luck!\n");
	}
	else
	{
		printf("Oops!\n");
	}

	Level_Traversals(root);

	Destroy_BinaryTree(root);
	root = NULL;
	printf("*****************************EXIT*****************************\n\n");
}

void Test_BinaryTree_02()
{
	printf("******************************02******************************\n");
	BTNode* root = Create_BinaryTreeNode(1);
	root->left = Create_BinaryTreeNode(2);
	root->right = Create_BinaryTreeNode(3);
	root->left->left = Create_BinaryTreeNode(4);
	root->left->right = Create_BinaryTreeNode(5);
	root->right->left = Create_BinaryTreeNode(6);
	root->right->right = Create_BinaryTreeNode(7);
	root->left->left->left = Create_BinaryTreeNode(8);

	Preorder_Traversals(root);
	printf("\n");
	Inorder_Traversals(root);
	printf("\n");
	Postorder_Traversals(root);
	printf("\n");

	printf("%zu\n", Size_BinaryTree(root));
	printf("%zu\n", Size_Leaf_BinaryTree(root));
	printf("%zu\n", Size_OneSpend_BinaryTree(root));
	printf("%zu\n", Height_BinaryTree(root));
	printf("%zu\n", K_Layer_BinaryTree(root, 1));
	printf("%zu\n", K_Layer_BinaryTree(root, 2));
	printf("%zu\n", K_Layer_BinaryTree(root, 3));
	printf("%zu\n", K_Layer_BinaryTree(root, 4));

	if (Find_BinaryTree(root, 8) == root->left->left->left)
	{
		printf("Good Luck!\n");
	}
	else
	{
		printf("Oops!\n");
	}

	Level_Traversals(root);

	Destroy_BinaryTree(root);
	root = NULL;
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_BinaryTree_01();
	Test_BinaryTree_02();
	return 0;
}