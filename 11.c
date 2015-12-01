#include <stdio.h>

//find the largest egyptian fraction that can subtract from the current value
//of real
//repeat until real ~= 0
void main(){
  double real;
  printf("Problem 11: Egyptian fraction sum with least operands of real number \n");
  scanf("%lf", &real);
  int i = 2;
  double remover;
  while (real > 0 && real > 0.0001f){
    remover = 1 / (float) i;
    if (remover <= real){
      real -= remover;
      printf("1/%d", i);
      if (real > 0.0001f && real > 0) printf(", ");
    }
    i++;
  }
}
