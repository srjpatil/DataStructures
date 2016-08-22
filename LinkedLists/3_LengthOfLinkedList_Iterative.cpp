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
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}

	return count;
}

int main()
{
	struct node *head = NULL;

	push(&head, 50);
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);

	printf("Linked list is :\n");
	display(head);
	printf("Length of the linked list is : %d\n", length(head));
}