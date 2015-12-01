#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n, temp, count=1;
	double powe;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("The output is: ");
	if(n>=100){
		if(n/100==9){
			printf("CM");
		}
		else if(n/100>=5){
			printf("D");
			if(n/100>5 && n/100<9){
				temp=n/100-5;
				for(count=1; count<=temp; count++){
					printf("C");
				}
			}
		}
		else if(n/100==4){
			printf("CD");
		}
		else if(n/100>=1){
			temp=n/100;
			for(count=1; count<=temp; count++){
				printf("C");
			}
		}
		n=n%100;
	}
	if(n>=10){
		if(n/10==9){
			printf("XC");
		}
		else if(n/10>=5){
			printf("L");
			if(n/10>5 && n/10<9){
				temp=n/10-5;
				for(count=1; count<=temp; count++){
					printf("X");
				}
			}
		}
		else if(n/10==4){
			printf("XL");
		}
		else if(n/10>=1){
			temp=n/10;
			for(count=1; count<=temp; count++){
				printf("X");
			}
		}
		n=n%10;
	}
	if(n>=1){
		if(n==9){
			printf("IX");
		}
		else if(n>=5){
			printf("V");
			if(n>5 && n<9){
				temp=n-5;
				for(count=1; count<=temp; count++){
					printf("I");
				}
			}
		}
		else if(n==4){
			printf("IV");
		}
		else if(n>=1){
			temp=n;
			for(count=1; count<=temp; count++){
				printf("I");
			}
		}
	}
}