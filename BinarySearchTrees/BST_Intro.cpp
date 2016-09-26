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
		return newNode(key);

	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);

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

struct node *search(struct node *root, int key)
{
	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else if (key > root->data)
		return search(root->right, key);
}

int main()
{
	struct node *root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 60);
	insert(root, 80);
	insert(root, 40);
	insert(root, 70);
	
	//insert(root, 30);

	printf("Inorder traversal of tree :\n");
	inorder(root);

	int num;
	printf("Enter the element to search:\n");
	scanf_s("%d", &num);
	struct node *search_result = search(root, num);
	if (search_result != NULL)
		printf("Element found %d\n", search_result->data);
	else
		printf("Element not found\n");
}