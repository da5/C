#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data;
	orderedListNode *left, *right;	
}orderedListNode;

typedef struct
{
	int data;
	orderedListNode *orderedListLink;
}arrayNode;

orderedListNode *orderedListHEAD = NULL;
orderedListNode *orderedListTAIL = NULL;

void orderedListInsert(orderedListNode *node)
{
	orderedListNode *curr;
	if(orderedListHEAD==NULL)
	{
		orderedListHEAD = node;
		orderedListTAIL = node;
	}
	else
	{
		for(curr = orderedListHEAD; curr!=NULL && curr.data<= node.data; curr = curr->right);
		if(curr==orderedListHEAD)
		{
			orderedListHEAD->left = node;
			node->right = orderedListHEAD;
			orderedListHEAD = node;
		}
		else if (curr==NULL)
		{
			orderedListTAIL->right = node;
			node->left = orderedListTAIL;
			orderedListTAIL = node;
		}
		else
		{
			node->right = curr->left->right
			node->left = curr->left;
			curr->left->right = node;
			curr->right->left = node;

		}
	}
}

void orderedListDelete(orderedListNode *node)
{
	if(node==orderedListHEAD)
	{
		if(orderedListTAIL == node)
		{
			orderedListTAIL = NULL
			orderedListHEAD = NULL;
		}
		else
		{
			orderedListHEAD->right->left = NULL;
			orderedListHEAD = orderedListHEAD->right;
		}

	}
	else
	{
		if(orderedListTAIL==node)
		{
			orderedListTAIL = node->left;
			orderedListTAIL->right = NULL;	
		}
		else
		{
			node->left->right = node->right;
			node->right->left = node->left;
		}
	}
	free(node);
}

void listInsert(listNode *node)
{
	orderedListNode *orderedNode = (orderedListNode*)malloc(sizeof(orderedListNode));
	orderedNode.data = node.data;
	node->orderedListLink = orderedNode;
	orderedListInsert(orderedNode);
	if(listHEAD==NULL)
	{
		listHEAD = node;
	}
	else
	{
		listTAIL->right = node;
		node->left = listTAIL;
	}
	listTAIL = node;
}

void listDelete()
{
	listNode *x = listTAIL;
	orderedListDelete(x->orderedListLink);
	if(listHEAD->right == NULL)
	{
		listHEAD = NULL;
		listTAIL = NULL;
	}
	else
	{
		x->left->right = NULL
		listTAIL = x->left;
	}
	free(x);
}

void query1(int data)
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	node.data = data;
	listInsert(node);
}

void query2

int main()
{
	int t, attr1, attr2, attr3, attr4;
	arrayNode *array = (arrayNode*)malloc(sizeof(arrayNode)*500000);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d",&attr1, &attr2, &attr3, &attr4);
		if(attr1==0)
		{
			query1(attr2);	
		}
		else if(attr1==1)
		{

		}
		else if(attr1==2)
		{

		}
		else if(attr1==3)
		{

		}
		else if(attr1==4)
		{

		}

	}
	return 0;
}

