#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

typedef struct BinTreeNode
{
	char data;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BinTreeNode;

typedef BinTreeNode* BinTree;


BinTree CreatBinTree(const char *str, int* i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = str[*i];
	(*i)++;
	t->left = CreatBinTree(str, i);
	(*i)++;
	t->right = CreatBinTree(str, i);
	return t;
}

void InOrder(BinTree t)
{
	if (t != NULL)
	{
		InOrder(t->left);
		printf("%c ", t->data);
		InOrder(t->right);
	}
}

void DestroyBinTree(BinTree* t)
{
	if (*t != NULL)
	{
		DestroyBinTree(&((*t)->left));
		DestroyBinTree(&((*t)->right));
		free(*t);
		*t = NULL;
	}
}
int main()
{
	BinTree bt = NULL;
	char arr[100] = { 0 };
	while (scanf("%s", arr) != EOF)
	{
		int index = 0;
		bt = CreatBinTree(arr, &index);
		InOrder(bt);
		printf("\n");
		DestroyBinTree(&bt);
	}
	return 0;
}