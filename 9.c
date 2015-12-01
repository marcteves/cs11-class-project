#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int pastval; //represents value in the last level
  int val; //represents value after updating to the current level
  struct node *next;
} element;

void printList(element *);
void countElems(element *);
void freeNodes(element *);

void main(){
  printf("Problem 9: Level of Pascal's Triangle given level n=");
  int level;
  scanf("%d", &level);
  element *head = NULL;
  head = malloc(sizeof(element)); //create the first level.
  head -> val = 1;
  head -> next = NULL;
  if (level == 1){
    printList(head);
  } else {
    int i = 1;
    while (i < level){
      element* traverser = head;
      while (traverser != NULL){ //store past values
        traverser -> pastval = traverser -> val;
        traverser = traverser -> next;
      }
      traverser = head; //move back tot the top of the linked list
      while (traverser -> next != NULL){ //update to current level
        (traverser -> next) -> val += traverser -> pastval; //see below
        traverser = traverser -> next;
      }
      traverser -> next = malloc(sizeof(element)); //to match elements to level
      (traverser -> next) -> val = 1; //last element is always 1!!!!!!!!!!!!!1!
      (traverser -> next) -> next = NULL;
      i++;
    }
  }
  printList(head);
  freeNodes(head);
}
/*
1
1 1
1 2 1
1 3 3  1
1 4 6  4  1
1 5 10 10 5  1
1 6 15 20 15 6  1
past:
1 7 21 35 35 21 7  1
current:
1 8 28 56 70 56 28 8 1
0 1 2  3  4  5  6  7 8
Basically, to get the current level, add PAST value of 0 to 1, 1 to 2, and so on
*/

void freeNodes(element *head){
  while (head -> next != NULL){ //free memory because i'm nice
    element *tofree = head;
    head = head -> next;
    free(tofree);
  }
}

void printList(element *head){
  while (head != NULL){
    printf("%d", head -> val);
    if (head -> next != NULL) printf(", ");
    head = head -> next;
  }
}
