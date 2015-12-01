#include <stdio.h>
#include <string.h>

void parseDigits(int *, char*);
void printResult(int *);
int charToDigit(char);

void main(){
  int digits[21];
  int i = 0;
  while (i < 21){ //so we can add to the digit ARRAY right AWAY
    digits[i++] = 0;
  }
  char input[20];
  printf("Problem 13: Big ints.\n");
  printf("Enter first digit: ");
  scanf("%s", input);
  parseDigits(digits, input);
  printf("Enter second digit: ");
  scanf("%s", input);
  parseDigits(digits, input);
  printf("Result: ");
  printResult(digits);
}

//interprets the string and adds the value to the current value of the big int
void parseDigits(int* digits, char *string){
  char *end = string + strlen(string) - 1;
  int i;
  for (i = 0; i < strlen(string); i++, end--){
    int *digit = digits + i;
    printf("%d", *digit);
    *digit += charToDigit(*end);
    printf("%d", charToDigit(*end));
    if (*digit >= 10){ //carry one
      *digit -= 10;
      digit++;
      *digit += 1;
    }
  }
}

int charToDigit(char intwannabe){
  if (intwannabe >= 48 && intwannabe <= 57){
    return intwannabe - 48;
  }
  return -1;
}

void printResult(int *digits){
  int i = 21 - 1;
  while (i >= 0){
    if (*(digits + i) != 0) printf("%d", *(digits + i));
    i--;
  }
}
