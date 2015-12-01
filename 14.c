#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_node;
};

struct node* add_num(struct node *head, struct node *current, int rem){
	current=malloc(sizeof(struct node));
	current->data=rem;
	current->next_node=head;
	head=current;
	return head;
}

int main(){
	struct node *head=NULL, *current;
	int base, n, rem;
	printf("Enter number: ");
	scanf("%d", &n);
	printf("Enter base: ");
	scanf("%d", &base);
	printf("The output is: ");
	while(n!=0){
		rem=n%base;
		head=add_num(head, current, rem);
		n=n/base;
	}
	current=head;
	while(current){
		printf("%d", current->data);
		current=current->next_node;
	}
}