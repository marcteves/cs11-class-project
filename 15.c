#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node15{
	int num;
	struct node15 *next_node;
};

struct node15* create_list15(struct node15 *head, struct node15 *current, char temp[]){
	current=malloc(sizeof(struct node15));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

struct node15* add_num15(struct node15 *head, struct node15 *current, char temp[]){
	current=malloc(sizeof(struct node15));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

void print_list15(struct node15 *current){
	while(current){
		printf("%d\n", current->num);
		current=current->next_node;
	}
}

struct node15* delete15(struct node15 *c, struct node15 *head){
	if(c->num==head->num){
			c=c->next_node;
			head=c;
			return head;
		}
		else{
			if(c->next_node==NULL){
				struct node15 *temp1=head->next_node;
				struct node15 *temp2=head;
				while(temp1->next_node){
					temp1=temp1->next_node;
					temp2=temp2->next_node;
				}
				temp2->next_node=(struct node15*)NULL;
				free(temp1);
				return head;
			}
			else{
				struct node15 *prev=head;
				while(prev->next_node!=c){
					prev=prev->next_node;
				}
				prev->next_node=c->next_node;
				free(c);
				return head;
			}
		}
}

struct node15* getLowest15(struct node15 *head, struct node15 *current){
	struct node15 *c=current;
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
		return delete15(c, head);
}

int main(){
	int n, i;
	char string[1000], temp[1000]="";
	struct node15 *head=NULL, *current;
	printf("Input n: ");
	scanf("%d", &n);
	getchar();
	printf("Input %d numbers (separated by a comma): ", n);
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		for(i; string[i]!=',' && i<strlen(string); i++){
			strncat(temp, &string[i], 1);
		}
		if(head==NULL){
			head=create_list15(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
		else{
			head=add_num15(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
	}
	while(head){
		current=head;
		head=getLowest15(head, current);
	}
}