#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int div=5, zeroes=0;
	long long int n;
	printf("Problem 1: Given a number n, the program will print the number of rightmost 0's of n!.\n");
	printf("Please enter input n: ");
	scanf("%lld", &n);
	while(div<=n){
		zeroes=zeroes+(n/div);
		div=div*5;
	}
	printf("The output is: %lld! has %d rightmost 0's.\n", n, zeroes);
}