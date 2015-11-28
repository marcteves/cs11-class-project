#include <stdio.h>

#define true 1
#define false 0

void main(){
 long bulbs;
 int i;
 int state = false; //I assumed all the bulbs are initially on.
 //At walk 1, the bulb will be off
 printf("Problem 6: How many bulbs (0 < n <1 000 000 000) are present, Mr. Mabu?");
 scanf("%ld", &bulbs);
 for (i = 2; i <= bulbs; i++){
  if (bulbs % i == 0){ //flip the switch
   if (state){ //if it's on
    state = false;
   } else { //if it's off
    state = true;
   }
  }
 }
 if (state){
  printf("Bulb %d is on.", bulbs);
 } else {
  printf("Blub %d is off.", bulbs);
 }
}