#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node14{
	int data;
	struct node14 *next_node;
};

struct node14* add_num14(struct node14 *head, struct node14 *current, int rem){
	current=malloc(sizeof(struct node14));
	current->data=rem;
	current->next_node=head;
	head=current;
	return head;
}

int main(){
	struct node14 *head=NULL, *current;
	int base, n, rem;
	printf("Enter number: ");
	scanf("%d", &n);
	printf("Enter base: ");
	scanf("%d", &base);
	
	while(n!=0){
		rem=n%base;
		head=add_num14(head, current, rem);
		n=n/base;
	}
	current=head;
	while(current){
		printf("%d", current->data);
		current=current->next_node;
	}
}