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

struct node* insert(struct node *root, int key)
{
	if (root == NULL)
		return newNode(key);

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

struct node *getMinValueNode(struct node *root)
{
	struct node *temp = root;
	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}

struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		struct node *temp = getMinValueNode(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

int main()
{
	struct node *root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("Inorder traversal:\n");
	inorder(root);

	/*printf("Enter the element to delete\n");
	int num;
	scanf_s("%d", &num);
	*/
	printf("Delete 20\n");
	root = deleteNode(root, 20);
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);


}