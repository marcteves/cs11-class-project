#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//TODO: sort a link list

typedef struct node{
  int val;
  int degree;
  struct node *next;
} mono;

int charToDigit(char);
mono* parseInput(mono *, char *);
mono* createNode(int);
void  freeNodes(mono *);
mono* multiply(mono *, mono *, mono *);
mono* degreeExists(mono *, int);
void printList(mono *);

void main(){
  char input[100];
  printf("Problem 5: Multiplying polynomials.\n");
  mono *head1 = NULL, *head2 = NULL, *head = NULL; //input 1, 2, and answer respectively
  printf("Polynomial 1: ");
  scanf("%s", input);
  head1 = parseInput(head1, input);
  printf("Polynomial 2: ");
  scanf("%s", input);
  head2 = parseInput(head2, input);
  head = multiply(head1, head2, head);
  printf("Head 1: ");
  printList(head1);
  printf("\n");
  printf("Head 2: ");
  printList(head2);
  printf("\n");
  printf("made it to end.\n");
  printList(head);
  freeNodes(head);
  freeNodes(head1);
  freeNodes(head2);
}

mono* parseInput(mono *head, char *input){
  if (head == NULL){ //create list if empty
    head = createNode(0);
  }
  mono *traverser = head; //we need head later
  char *end = input + strlen(input) - 1; //we want to read from the end
  int degree = 0;
  int tenpow = 0;
  while (end >= input){
    if (charToDigit(*end) > -1){ //just add the digit to the monomial node
      int i, adder = charToDigit(*end);
      for (i = 0; i < tenpow; i++){ //since we started at the end we have to account for this
        adder *= 10;
      }
      traverser -> val += adder;
      tenpow++;
    } else {
      printf("ay lamo");
      if (*end == ','){ //prepare for the next monomial value
        degree++;
        tenpow = 0;
        traverser -> next = createNode(degree);
        traverser = traverser -> next;
      } else if (*end == '-'){
        traverser -> val *= -1;
      }
    }
    end--;
  }
  return head;
}

mono* createNode(int degree){
  mono *new = malloc(sizeof(mono));
  new -> degree = degree;
  new -> val = 0;
  new -> next = NULL;
  return new;
}

void freeNodes(mono *head){
  while (head -> next != NULL){ //free memory because i'm nice
    mono *tofree = head;
    head = head -> next;
    free(tofree);
  }
}
mono* multiply(mono *head1, mono *head2t, mono *head){
  mono *tail, *head2;
  while (head1 != NULL){
    head2 = head2t;
    while (head2 != NULL){
      int degree = (head1 -> degree) + (head2 -> degree);
        printf("%d", degree);
      if (head == NULL){
        head = createNode(degree);
        tail = head;
        head -> val += head1 -> val * (head2 -> val);
      } else if (degreeExists(head, degree) != NULL){
        degreeExists(head, degree) -> val += head1 -> val * (head2 -> val);
      } else { //crashes here
        tail -> next = createNode(degree);
        tail = tail -> next;
        tail -> val += head1 -> val * (head2 -> val);
      }
      head2 = head2 -> next;

    }
    head1 = head1 -> next;
  }
  return head;
}

//returns pointer if found, otherwise NULL
mono* degreeExists(mono *head, int degree){
  while (head != NULL){
    if (head -> degree == degree){
      return head;
    } else {
      head = head -> next;
    }
  }
  return NULL;
}

int charToDigit(char intwannabe){
  if (intwannabe >= 48 && intwannabe <= 57){
    return intwannabe - 48;
  }
  return -1;
}

void printList(mono *head){
  int i = 0;
  while (head != NULL){
    printf("Elem %d: ", i);
    printf("(%d, %d) ", head -> val, head -> degree);
    if (head -> next != NULL) printf(", ");
    head = head -> next;
    i++;
  }
}
