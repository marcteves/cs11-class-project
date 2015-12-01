#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

//one struct for saving all the inputs
//another struct for saving the unique inputs, and frequency
//and then compare

struct node{
	char str[MAX];
	struct node *next_node;
};

struct node1{
	char str[MAX];
	int num;
	struct node1 *next_node;
};


struct node* create_list(struct node *head, struct node *current, char temp[]){
	current=malloc(sizeof(struct node));
	strcpy(current->str, temp);
	current->next_node=head;
	head=current;
	return head;
}

struct node* add_list(struct node *head, struct node *current, char temp[]){
	current=malloc(sizeof(struct node));
	strcpy(current->str, temp);
	current->next_node=head;
	head=current;
	return head;
}


//Gets the unique words
struct node1* compare_list(struct node *head, struct node *current, struct node1 *head1, struct node1 *current1){
	char temp[MAX];
	while(current){
		memset(temp, 0, sizeof(temp));
		strcpy(temp, current->str);
		if(head1==NULL){
			current1=malloc(sizeof(struct node1));
			strcpy(current1->str, temp);
			current1->next_node=head1;
			head1=current1;
			current=current->next_node;
		}
		else{
			current1=head1;
			while(current1){
				if(strcasecmp(current1->str, temp)==0){
					current=current->next_node;
					break;
				}
				else if(current1->next_node==NULL){
					current1=malloc(sizeof(struct node1));
					strcpy(current1->str, temp);
					current1->next_node=head1;
					head1=current1;
					current=current->next_node;
					break;
				}
				current1=current1->next_node;
			}
		}
	}
	return head1;
}

//Counts the frequency of each word
void frequency(struct node *head, struct node *current, struct node1 *head1, struct node1 *current1){
	while(current){
		if(current1==NULL){
			current1=head1;
			continue;
		}
		else{
			if(strcasecmp(current->str, current1->str)==0){
				current1->num++;
				current=current->next_node;
			}
			else{
				current1=current1->next_node;
			}
		}
	}
}

struct node1* delete(struct node1 *c, struct node1 *head1){
	if(c->str==head1->str){
			c=c->next_node;
			head1=c;
			return head1;
		}
		else{
			if(c->next_node==NULL){
				struct node1 *temp1=head1->next_node;
				struct node1 *temp2=head1;
				while(temp1->next_node){
					temp1=temp1->next_node;
					temp2=temp2->next_node;
				}
				temp2->next_node=(struct node1*)NULL;
				free(temp1);
				return head1;
			}
			else{
				struct node1 *prev=head1;
				while(prev->next_node!=c){
					prev=prev->next_node;
				}
				prev->next_node=c->next_node;
				free(c);
				return head1;
			}
		}
}

struct node1* getHighest(struct node1 *current1, struct node1 *head1){
	struct node1 *c=current1;
	static int i=0;
	int currentHighest=current1->num;
		while(current1->next_node){
			
			current1=current1->next_node;
			if(current1->num > currentHighest){
				currentHighest=current1->num;
				c=current1;
			}
		}if(i==0){
			printf("%s %d", c->str, c->num);
			i++;
		}
		else{
			printf(", %s %d", c->str, c->num);
		}
		return delete(c, head1);;
}

int main(){
	struct node *head=NULL, *current;
	struct node1 *head1=NULL, *current1;
	char string[MAX], temp[MAX]="";
	int i, num;
	printf("Enter a series of words: ");
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		while(string[i]!=' ' && i<strlen(string)){
			strncat(temp, &string[i], 1);
			i++;
		}
		if(head==NULL){
			head=create_list(head, current, temp);
			memset(temp, 0, sizeof(temp));
			continue;
		}
		else{
			head=add_list(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
	}
	current=head;
	head1=compare_list(head, current, head1, current1);
	current1=head1;
	frequency(head, current, head1, current1);
	while(head1){
		current1=head1;
		head1=getHighest(current1, head1);
	}
	
}