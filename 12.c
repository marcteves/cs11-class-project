#include <stdio.h>

int main(){
	double n, twenc, tenc, fivec, onec;
	int thou, five, thund, hund, fifth, twen, ten, fives, ones, i=0;
	printf("Enter a peso amount: ");
	scanf("%lf", &n);
	printf("The output is: %.2lf = ", n);
	if(n>=1000){
		thou=(int)n/1000;
		printf("(%d) 1000 ", thou);
		n=n-1000*thou;
		i++;
	}
	if(n>=500){
		five=(int)n/500;
		if(i==0){
			printf("(%d) 500 ", five);
			i++;
		}
		else{
			printf("+ (%d) 500 ", five);
		}
		n=n-500*five;
	}
	if(n>=200){
		thund=(int)n/200;
		if(i==0){
			printf("(%d) 200 ", thund);
			i++;
		}
		else{
			printf("+ (%d) 200 ", thund);
		}
		n=n-200*thund;
	}
	if(n>=100){
		hund=(int)n/100;
		if(i==0){
			printf("(%d) 100", hund);
			i++;
		}
		else{
			printf("+ (%d) 100 ", hund);
		}
		n=n-100*hund;
	}
	if(n>=50){
		fifth=(int)n/50;
		if(i==0){
			printf("(%d) 50 ", fifth);
			i++;
		}
		else{
			printf("+ (%d) 50 ", fifth);
		}
		n=n-50*fifth;
	}
	if(n>=20){
		twen=(int)n/20;
		if(i==0){
			printf("(%d) 20 ", twen);
			i++;
		}
		else{
			printf("+ (%d) 20 ", twen);
		}
		n=n-20*twen;
	}
	if(n>=10){
		ten=(int)n/10;
		if(i==0){
			printf("(%d) 10 ", ten);
			i++;
		}
		else{
			printf("+ (%d) 10 ", ten);
		}
		n=n-10*ten;
	}
	if(n>=5){
		fives=(int)n/5;
		if(i==0){
			printf("(%d) 5 ", fives);
			i++;
		}
		else{
			printf("+ (%d) 5 ", fives);
		}
		n=n-5*fives;
	}
	if(n>=1){
		ones=(int)n;
		if(i==0){
			printf("(%d) 1 ", ones);
			i++;
		}
		else{
			printf("+ (%d) 1 ", ones);
		}
		n=n-ones;
	}
	if(n>=0.25){
		twenc=n/0.25;
		if(i==0){
			printf("(%.0lf) 0.25 ", twenc);
			i++;
		}
		else{
			printf("+ (%.0lf) 0.25 ", twenc);
		}
		n=n-0.25*twenc;
	}
	if(n>=0.10){
		tenc=n/0.10;
		if(i==0){
			printf("(%.0lf) 0.10 ", tenc);
			i++;
		}
		else{
			printf("+ (%.0lf) 0.10 ", tenc);
		}
		n=n-0.10*tenc;
	}
	if(n>=0.05){
		fivec=n/0.05;
		if(i==0){
			printf("(%.0lf) 0.05 ", fivec);
			i++;
		}
		else{
			printf("+ (%.0lf) 0.05 ", fivec);
		}
		n=n-0.05*fivec;
	}
	if(n>=0.01){
		onec=n/0.01;
		if(i==0){
			printf("(%.0lf) 0.01 ", onec);
		}
		else{
			printf("+ (%.0lf) 0.01 ", onec);
		}
		n=n-0.01*onec;
	}
}