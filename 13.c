#include <stdio.h>
#include <string.h>

void parseDigits(int *, char*);
void printResult(int *);
int charToDigit(char);

void main(){
  int digits[21];
  int i;
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
  printResult(digits);
}

//interprets the string and adds the value to the current value of the big int
void parseDigits(int* digits, char *string){
  char *end = string + strlen(string) -1;
  int i;
  for (i = 0; i < strlen(string) - 1; i++, end--){
    int *digit = digits + i;
    printf("%d", *digit);
    *digit += charToDigit(*end);
    if (*digit >= 10){ //carry one
      *digit -= 10;
      digit++;
      *digit += 1;
    }
  }
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

void printResult(int *digits){
  int i = 21 - 1;
  while (i >= 0){
    printf("%d", digits + i--);
  }
}
