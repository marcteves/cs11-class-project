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
  printf("made it");
  printList(head);
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
    if (charToDigit(*input) > -1){ //just add the digit to the monomial node
      int i, adder = charToDigit(*input);
      for (i = 0; i < tenpow; i++){ //since we started at the end we have to account for this
        adder *= 10;
      }
      traverser -> val += adder;
      tenpow++;
    } else {
      if (*input == ','){ //prepare for the next monomial value
        degree++;
        tenpow = 0;
        traverser -> next = createNode(degree);
        traverser = traverser -> next;
      }
    }
    end--;
  }
}

mono* createNode(int degree){
  mono *new = malloc(sizeof(mono));
  new -> degree = degree;
  new -> val = 0;
  new -> next = NULL;
  return new;
}

mono* multiply(mono *head1, mono *head2t, mono *head){
  mono *tail, *head2;
  printf("crash here");
  while (head1 != NULL){
    head2 = head2t;
    printf("or here");
    while (head2 != NULL){
      int degree = (head1 -> degree) + (head2 -> degree);
        printf("%d", degree);
      if (head == NULL){
        printf("case 1");
        head = createNode(degree);
        tail = head;
        head -> val += head1 -> val * (head2 -> val);
      } else if (degreeExists(head, degree) != NULL){
        printf("case 2");
        degreeExists(head, degree) -> val += head1 -> val * (head2 -> val);
      } else { //crashes here
        printf("case 3");
        tail -> next = createNode(degree);
        tail = tail -> next;
        tail -> val += head1 -> val * (head2 -> val);
      }
      head2 = head2 -> next;
        printf("maybe here");

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
  //TODO: make this use ASCII
  switch (intwannabe){
    case '0':
    return 0;
    break;
    case '1':
    return 1;
    break;
    case '2':
    return 2;
    break;
    case '3':
    return 3;
    break;
    case '4':
    return 4;
    break;
    case '5':
    return 5;
    break;
    case '6':
    return 6;
    break;
    case '7':
    return 7;
    break;
    case '8':
    return 8;
    break;
    case '9':
    return 9;
    break;
    default:
    printf("ERROR");
    return -1;
    break;
  }
}

void printList(mono *head){
  while (head != NULL){
    printf("%d", head -> val);
    if (head -> next != NULL) printf(", ");
    head = head -> next;
  }
}
