#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main()
{
	struct node *head = NULL;

	head = (struct node *)malloc(sizeof(struct node));
	head->data = 10;
	head->next = NULL;

	struct node *second = (struct node *)malloc(sizeof(struct node));
	second->data = 20;
	second->next = NULL;
	head->next = second;

	struct node *third = (struct node *)malloc(sizeof(struct node));
	third->data = 30;
	third->next = NULL;
	second->next = third;
	

	printf("Linked list is :\n");
	display(head);


}