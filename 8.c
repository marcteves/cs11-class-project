#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
  double x;
  double y;
  struct node *next;
} point;

point *createNode(point*, double, double);
double getDistance(point*, point*);
void printList(point*);

void main(){
  printf("Problem 8: Pair of points with the shortest distance.\n");
  double x, y;
  int input;
  point *head = NULL;
  point *tail = NULL;
  do { //input phase
    printf("Enter x coordinate: ");
    scanf("%lf", &x);
    printf("Enter y coordinate: ");
    scanf("%lf", &y);
    if (head == NULL) {
      head = createNode(head, x, y);
      tail = head;
    } else {
      tail = createNode(tail, x, y);
    }
    printf("Add one more coordinate? Type 0 if no.");
    scanf("%d", &input);
  } while (input != 0);
  double least = -1;
  point *p1 = head;
  point *p2;
  point *sp1,*sp2; //pointers to the shortest pair of points
  while (p1 -> next != NULL){ //a nested loop that iterates over all the possible pairs
    p2 = p1 -> next;
    while (p2 != NULL){
      double currentdist = getDistance(p1,p2);
      if (currentdist <= least || least == -1){
        least = currentdist;
        sp1 = p1;
        sp2 = p2;
      }
      p2 = p2 -> next;
    }
    p1 = p1 -> next;
  }
  printf("Pair with the least distance is (%f, %f) and (%f, %f), with a distance %f",
  sp1 -> x, sp1 -> y, sp2 -> x, sp2 -> y, least);
  while (head -> next != NULL){ //free memory because i'm nice
    point *tofree = head;
    head = head -> next;
  }
}

//simply creates a new list (if there is no list) or appends a node to the list
point* createNode(point *appendto, double x, double y){
  point *new = malloc(sizeof(point));
  new -> x = x;
  new -> y = y;
  new -> next = NULL;
  if (appendto != NULL) appendto -> next = new;
  return new;
}

//uses the distance formula to determine the distance
double getDistance(point* p1, point* p2){
  double dist;
  double x1,x2,y1,y2;
  x1 = p1 -> x;
  x2 = p2 -> x;
  y1 = p1 -> y;
  y2 = p2 -> y;
  dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  return dist;
}
