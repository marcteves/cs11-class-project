#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	long long int i, n, j, temp;
	int count1=0, count2=0; //i is the prime number
	printf("Problem 3: Given an input n, the program will print out its prime factorization.\n");
	printf("Please enter input n: ");
	scanf("%lld", &n);
	temp=2;
	printf("The output is: %lld = ", n);
	for(i=2; (i<100000); i++)
	{
		for(j=2; j<=(i/j); j++)
		{
			if(!(i%j)) 
			{
				break;
			}
		}
		if(j>(i/j)) 
		{
			while(n>0){
				if(n%i!=0){
					break;
				}
				else{
					if(temp==i){
						while(n%i==0){
							count1++;
							n=n/i;
						}
						if(count2==0){
							printf("%lld", i);
							count2++;
						}
						if(count1>1){
							printf("^%d", count1);
						}
					}
					else{							
						count1=0;
						temp=i;
						count2=0;
						printf(" x ");
						continue;
						
					}
				}
			}
		}
	}
	printf("\n");
}