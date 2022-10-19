#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//重命名二叉树数据元素类型
typedef int BTDataType;

//定义结构体类型(普通二叉树(除创建一个二叉树节点，其余都为递归实现))
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
} BTNode;

//创建一个二叉树节点
BTNode* Create_BinaryTreeNode(BTDataType data);

//以先序(头左右)遍历二叉树
void Preorder_Traversals(BTNode* root);

//以中序(左头右)遍历二叉树
void Inorder_Traversals(BTNode* root);

//以后序(左右头)遍历二叉树
void Postorder_Traversals(BTNode* root);

//按层遍历二叉树(由队列实现)
void Level_Traversals(BTNode* root);

//获取二叉树的节点个数
size_t Size_BinaryTree(BTNode* root);

//获取二叉树的叶子节点个数
size_t Size_Leaf_BinaryTree(BTNode* root);

//获取二叉树的高度
size_t Height_BinaryTree(BTNode* root);

//获取二叉树第"K"层节点的个数
size_t K_Layer_BinaryTree(BTNode* root, size_t k);

//查找二叉树节点
BTNode* Find_BinaryTree(BTNode* root, BTDataType data);

//销毁二叉树
void Destroy_BinaryTree(BTNode* root);