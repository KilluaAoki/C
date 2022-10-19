//引用二叉树头文件
#include "Binary Tree.h"

//引用队列头文件
#include "Queue/Queue.h"

//创建一个二叉树节点
BTNode* Create_BinaryTreeNode(BTDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		perror("Create_BinaryTreeNode");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//以先序(头左右)遍历二叉树
void Preorder_Traversals(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	Preorder_Traversals(root->left);
	Preorder_Traversals(root->right);
}

//以中序(左头右)遍历二叉树
void Inorder_Traversals(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder_Traversals(root->left);
	printf("%d ", root->data);
	Inorder_Traversals(root->right);
}

//以后序(左右头)遍历二叉树
void Postorder_Traversals(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder_Traversals(root->left);
	Postorder_Traversals(root->right);
	printf("%d ", root->data);
}

//按层遍历二叉树(由队列实现)
void Level_Traversals(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue help;
	Init_Queue(&help);
	Push_Queue(&help, root);
	while (!Empty_Queue(&help))
	{
		BTNode* cur = Front_Queue(&help);
		printf("%d ", cur->data);
		Pop_Queue(&help);
		if (cur->left != NULL)
		{
			Push_Queue(&help, cur->left);
		}
		if (cur->right != NULL)
		{
			Push_Queue(&help, cur->right);
		}
	}
	printf("\n");
	Destroy_Queue(&help);
}

//获取二叉树的节点个数
size_t Size_BinaryTree(BTNode* root)
{
	return root == NULL ? 0 : Size_BinaryTree(root->left) + Size_BinaryTree(root->right) + 1;
}

//获取二叉树的叶子节点个数
size_t Size_Leaf_BinaryTree(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return Size_Leaf_BinaryTree(root->left) + Size_Leaf_BinaryTree(root->right);
}

//获取二叉树的高度
size_t Height_BinaryTree(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size_t leftHeight = Height_BinaryTree(root->left);
	size_t rightHeight = Height_BinaryTree(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//获取二叉树第"K"层节点的个数
size_t K_Layer_BinaryTree(BTNode* root, size_t k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return K_Layer_BinaryTree(root->left, k - 1) + K_Layer_BinaryTree(root->right, k - 1);
}

//查找二叉树节点
BTNode* Find_BinaryTree(BTNode* root, BTDataType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	BTNode* left = Find_BinaryTree(root->left, data);
	if (left)
	{
		return left;
	}
	BTNode* right = Find_BinaryTree(root->right, data);
	if (right)
	{
		return right;
	}
	return NULL;
}

//销毁二叉树
void Destroy_BinaryTree(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Destroy_BinaryTree(root->left);
	Destroy_BinaryTree(root->right);
	free(root);
}