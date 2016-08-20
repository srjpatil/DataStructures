#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void append(struct node **headRef, int num)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next = NULL;

	if (*headRef == NULL)
	{
		*headRef = newnode;
	}
	else
	{
		// go to the last node of the list
		struct node *temp = *headRef;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

}

void push(struct node **headRef, int num)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next = *headRef;
	*headRef = newnode;
}

void display(struct node *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void insertAfter(struct node **headRef, int num, int pos)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;

	struct node *temp = *headRef;
	if (pos == 0)
	{
		newnode->next = *headRef;
		*headRef = newnode;
		return;
	}
	int count = 1;
	while (temp != NULL && count < pos)
	{
		temp = temp->next;
		count++;
	}

	if (count <= pos && temp == NULL)
	{
		printf("There are less nodes in the list than %d. Returning...\n", pos);
		return;
	}

	newnode->next = temp->next;
	temp->next = newnode;
}

int main()
{
	struct node *head = NULL;
	//appending elements at the end of the list.
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	printf("Linked list :\n");
	display(head);

	//adding elements at the start of the list.
	struct node *head1 = NULL;
	push(&head1, 10);
	push(&head1, 20);
	push(&head1, 30);
	push(&head1, 40);
	push(&head1, 50);
	printf("Linked list :\n");
	display(head1);

	int num, pos;
	printf("Enter a new node and new position to add the node :\n");
	scanf_s("%d%d", &num, &pos);

	insertAfter(&head, num, pos);

	printf("Modified first linked list :\n");
	display(head);

}