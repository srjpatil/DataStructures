#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->left = newnode->right = NULL;

	return newnode;
}

struct node *insert(struct node *root, int key)
{
	if (root == NULL)
	{
		return newNode(key);
	}

	if (key < root->data)
	{
		root->left = insert(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = insert(root->right, key);
	}

	return root;
}

void inorder(struct node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}

void iterative_insert(struct node **root, int key)
{
	struct node *temp = *root;
	struct node *parent = NULL;
	while (temp != NULL)
	{
		parent = temp;
		if (key < temp->data)
			temp = temp->left;
		else if (key > temp->data)
			temp = temp->right;
	}

	if (parent == NULL)
		*root = newNode(key);
	else if (key < parent->data)
		parent->left = newNode(key);
	else
		parent->right = newNode(key);
	//temp = newNode(key);
}

int main()
{
	struct node *root = NULL;
	iterative_insert(&root, 12);
	iterative_insert(&root, 5);
	iterative_insert(&root, 18);
	iterative_insert(&root, 2);
	iterative_insert(&root, 9);
	iterative_insert(&root, 15);
	iterative_insert(&root, 19);
	iterative_insert(&root, 13);
	iterative_insert(&root, 17);

	iterative_insert(&root, 14);

	printf("Inorder traversal:\n");
	inorder(root);

}