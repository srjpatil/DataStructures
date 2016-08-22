#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node **headRef, int num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
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

int length(struct node *head)
{
	if (head == NULL)
		return 0;
	else
		return 1 + length(head->next);
}

int main()
{
	struct node *head = NULL;

	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Linked list is :\n");
	display(head);

	printf("Length of the linked list : %d\n", length(head));
}