#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Ex1.
 8AM-8PM timeblock
 [==================]
 sched
   [=]  [===]  [==]
 break
 [=] [=]    [==]  [=]
 Ex2.
 8AM-8PM timeblock
 [==================]
 sched
 [=] [=]   [==]  [==]
 break
   [=] [===]  [==]

Program:
 1. Find breaks using sched
 2. Add every break to break list, and also to sched
 3. Repeat 1-2 until no breaks are found (occurs if breakstart is found to be MAXTIME)
Finding a break:
 breakstart=MINTIME;
 breakend=MAXTIME;
 Find the least possible value of breakstart and breakend
 How to:
  Breakstart:
    1. See if breakstart is in between the start and end of a schedule node
       OR if it is larger than the end of a a schedule node
      1. If true, set breakstart at the end of the schedule node.
    2. Repeat 1 until end of schedule list

  Breakend:
    1. See if the start of a schedule note is between breakstart and breakend
      1. If True, set breakend to the start of the schedule node
*/

#define MINTIME 480 //8am
#define MAXTIME 1200 //8pm

typedef struct node{
  int start;
  int end;
  struct node *next;
} timeblock;

int charToDigit(char);
timeblock* parseTimeblockInput(timeblock *, char *);
void printTimeblockList(timeblock *);
timeblock* createTimeblockNode();
timeblock* isBetweenList(timeblock *, int);
timeblock* isBetweenBreak(timeblock *, int, int);
timeblock* getBreaks(timeblock *, timeblock *);
void appendToList(timeblock *, timeblock *);
void printSched(timeblock *);

void main(){
  char input[1000];
  printf("Problem 19: Timeblocks and breaks.\n Input: ");
  scanf("%s", input);
  timeblock *heads = NULL; //list of schedules
  timeblock *headb = NULL; //list of breaks
  heads = parseTimeblockInput(heads, input);
  headb = getBreaks(headb, heads);
  printSched(headb);
}

timeblock* parseTimeblockInput(timeblock *head, char *input){
  if (head == NULL){ //create list if empty
    head = createTimeblockNode(0,0);
  }
  char *end = input + strlen(input) - 1;
  timeblock *traverser = head;
  int hour = 1;
  int start = 1;
  int adder = 0;
  while (input <= end){
    if (charToDigit(*input) > -1){
      adder *= 10;
      if (hour == 1){
        adder += charToDigit(*input) * 60;
      } else {
        adder += charToDigit(*input);
      }
    } else {
      if (*input == 'p'){
        adder += 720;
      } else if (*input == ':'){
        if (start == 1){
          traverser -> start += adder;
        } else {
          traverser -> end += adder;
        }
        adder = 0; //set the adder to 0 because it has added already
        hour = 0;
      } else if (*input == '-'){
        traverser -> start += adder;
        adder = 0;
        start = 0;
        hour = 1;
      } else if (*input == ','){
        traverser -> end += adder;
        traverser -> next = createTimeblockNode(0,0);
        traverser = traverser -> next;
        //reset parser parameters
        hour = 1;
        start = 1;
        adder = 0;
      }
    }
    input++;
    if (input == end + 1){ //just to handle the 'end' of the last timeblock
      traverser -> end = adder;
      adder = 0;
    }
  }
  return head;
}

timeblock* getBreaks(timeblock *breaks, timeblock *schedule){
  int breakstart = MINTIME;
  int breakend = MAXTIME;
  timeblock *head;
  while (1){
    timeblock *intersect = isBetweenList(schedule, breakstart);
    while (intersect != NULL){
      breakstart = intersect -> end;
      intersect = isBetweenList(schedule, breakstart);
    }
    intersect = isBetweenBreak(schedule, breakstart, breakend);
    while (intersect!= NULL){
      breakend = intersect -> start;
      intersect = isBetweenBreak(schedule, breakstart, breakend);
    }
    //breakstart and breakend should be correctly defined before this
    if (breaks == NULL){
      breaks = createTimeblockNode(breakstart, breakend);
      head = breaks;
      appendToList(schedule, breaks); //append the break found to schedule list
    } else {
      breaks -> next = createTimeblockNode(breakstart, breakend);
      breaks = breaks -> next;
      appendToList(schedule, breaks); //append the break found to schedule list
    }
    //reposition start and end for the next optimization run
    breakstart = breaks -> end;
    breakend = MAXTIME;
    if (breakstart == MAXTIME) {
      break;
    }
  }
  return head;
}

//returns the pointer of the schedule node if time is between a schedule node
timeblock* isBetweenList(timeblock *schedule, int time){
  while (schedule != NULL){
    if (schedule -> start <= time && schedule -> end >  time){
      return schedule;
    }
    schedule = schedule -> next;
  }
  return schedule; //not between any node
}

timeblock* isBetweenBreak(timeblock *schedule, int start, int end){
  while (schedule != NULL){
    if (schedule -> start < end && schedule -> start > start){
      return schedule;
    }
    schedule = schedule -> next;
  }
  return schedule; //not between any node
}

void appendToList(timeblock *list, timeblock* item){
  while (list -> next != NULL){
    list = list -> next;
  }
  item = createTimeblockNode(item -> start, item -> end);
  list -> next = item;
}

timeblock* createTimeblockNode(int start, int end){
  timeblock *new = malloc(sizeof(timeblock));
  new -> start = start;
  new -> end = end;
  new -> next = NULL;
  return new;
}

int charToDigit(char intwannabe){
  if (intwannabe >= 48 && intwannabe <= 57){
    return intwannabe - 48;
  }
  return -1;
}

void printTimeblockList(timeblock *head){
  int i = 0;
  while (head != NULL){
    printf("Elem %d: ", i);
    printf("(%d - %d) ", head -> start, head -> end);
    if (head -> next != NULL) printf(", ");
    head = head -> next;
    i++;
  }
}

void printSched(timeblock *head){
  while (head != NULL){
    int start = head -> start;
    int end = head -> end;
    int pm = 0;
    //print start
    if (start > 720) {
      pm = 1;
      start -= 720;
    }
    printf("%d", start / 60); //hours
    start %= 60;
    if (start != 0) printf(":%d", start); //minutes
    if (pm == 1) {
      printf("p");
    } else {
      printf("a");
    }
    printf("-");
    //print end
    if (end > 720) {
      pm = 1;
      end -= 720;
    }
    printf("%d", end / 60); //hours
    end %= 60;
    if (end != 0) printf(":%d", end); //minutes
    if (pm == 1) {
      printf("p");
    } else {
      printf("a");
    }
    if (head -> next != NULL) printf(",");
    head = head -> next;
  }
}
