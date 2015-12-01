#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int num;
	struct node *next_node;
};

struct node* create_list(struct node *head, struct node *current, char temp[]){
	current=malloc(sizeof(struct node));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

struct node* add_num(struct node *head, struct node *current, char temp[]){
	current=malloc(sizeof(struct node));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

void print_list(struct node *current){
	while(current){
		printf("%d\n", current->num);
		current=current->next_node;
	}
}

struct node* delete(struct node *c, struct node *head){
	if(c->num==head->num){
			c=c->next_node;
			head=c;
			return head;
		}
		else{
			if(c->next_node==NULL){
				struct node *temp1=head->next_node;
				struct node *temp2=head;
				while(temp1->next_node){
					temp1=temp1->next_node;
					temp2=temp2->next_node;
				}
				temp2->next_node=(struct node*)NULL;
				free(temp1);
				return head;
			}
			else{
				struct node *prev=head;
				while(prev->next_node!=c){
					prev=prev->next_node;
				}
				prev->next_node=c->next_node;
				free(c);
				return head;
			}
		}
}

struct node* getLowest(struct node *head, struct node *current){
	struct node *c=current;
	static int i=0;
	int currentLowest=current->num;
		while(current->next_node){
			
			current=current->next_node;
			if(current->num < currentLowest){
				currentLowest=current->num;
				c=current;
			}
		}if(i==0){
			printf("%d", c->num);
			i++;
		}
		else{
			printf(", %d", c->num);
		}
		return delete(c, head);
}

int main(){
	int n, i;
	char string[1000], temp[1000]="";
	struct node *head=NULL, *current;
	printf("Input n: ");
	scanf("%d", &n);
	getchar();
	printf("Input %d numbers: ", n);
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		for(i; string[i]!=',' && i<strlen(string); i++){
			strncat(temp, &string[i], 1);
		}
		if(head==NULL){
			head=create_list(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
		else{
			head=add_num(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
	}
	while(head){
		current=head;
		head=getLowest(head, current);
	}
}