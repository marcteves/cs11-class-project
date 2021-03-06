#include <stdio.h>

/*
 The basic idea is that a powerset of a set of n elements contains
 2^n elements.
 This implies that there is a binary digit corresponding to the elements
 contained in the elements of the powerset.

 Flow:
 1. Get input n
 2. Loop while the binary representation is less than 2^n + 1
  1. Print subset - Loop through binrep
   1. Print index + 1 if binrep[index] == 1
  2. Add one bit - loop through binrep
   1. If binrep[i] = 0, then make it 1 and end loop, else if it's
      1, continue and make it 0.
 3. end
*/
void addOneBit(int *, int);
void printSubset(int *, int);
int highestBin(int *, int);

void main(){
  /*
   Collection of bits depicting a 2^n number.
  */
  int binrep[1000];
  int ix;
  for (ix = 0; ix < 1000; ix++){
    binrep[ix] = 0;
  }
  int input;
  printf("Problem 4: Prints the powerset of the set containing integers 1 - n");
  printf("\n 1 < n < 1000: ");
  scanf("%d", &input);
  while (highestBin(binrep, input) == 0){
    printSubset(binrep, input);
    printf(", ");
    addOneBit(binrep, input);
  }
}

void addOneBit(int *binrep, int limit){
  //cascading addition
  int i;
  limit += 1; //this allows the function to add up to 2^n
  for (i = 0; i < limit; i ++){
    if (*(binrep + sizeof(int) * i) == 1){
      *(binrep + sizeof(int) * i) = 0;
    } else {
      *(binrep + sizeof(int) * i) = 1;
      break;
    }
  }
}

void printSubset(int *binrep, int limit){
  int i;
  printf("{");
  for (i = 0; i < limit; i++){ //prints all elements in the specific subset
    if (*(binrep + sizeof(int) * i) == 1){
      printf("%d, ", i + 1); // i + 1 represents a number from 1 to 1000
    }
  }
  printf("}");
}

//Returns 1 if the binary digit is 2^n, 0 otherwise
int highestBin(int *binrep, int n){
  if (*(binrep + sizeof(int) * n) == 1) return 1;
  return 0;
}
