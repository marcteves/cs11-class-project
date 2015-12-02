#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX20 1000

void checker1(float x1, float y1, float x2, float y2, float *hcheckerx1, float *hcheckery1, float *lcheckerx1, float *lcheckery1){
	if(x1>x2){
		*hcheckerx1=x1;
		*hcheckery1=y1;
		*lcheckerx1=x2;
		*lcheckery1=y2;
	}
	else{
		*hcheckerx1=x2;
		*hcheckery1=y2;
		*lcheckerx1=x1;
		*lcheckery1=y1;
	}
}

void vchecker1(float x1, float y1, float x2, float y2, float *hcheckerx1, float *hcheckery1, float *lcheckerx1, float *lcheckery1){
	if(y1>y2){
		*hcheckerx1=x1;
		*hcheckery1=y1;
		*lcheckerx1=x2;
		*lcheckery1=y2;
	}
	else{
		*hcheckerx1=x2;
		*hcheckery1=y2;
		*lcheckerx1=x1;
		*lcheckery1=y1;
	}
}

void vchecker2(float x3, float y3, float x4, float y4, float *hcheckerx2, float *hcheckery2, float *lcheckerx2, float *lcheckery2){
	if(y3>y4){
		*hcheckerx2=x3;
		*hcheckery2=y3;
		*lcheckerx2=x4;
		*lcheckery2=y4;
	}
	else{
		*hcheckerx2=x4;
		*hcheckery2=y4;
		*lcheckerx2=x3;
		*lcheckery2=y3;
	}
}

void checker2(float x3, float y3, float x4, float y4, float *hcheckerx2, float *hcheckery2, float *lcheckerx2, float *lcheckery2){
	if(x3>x4){
		*hcheckerx2=x3;
		*hcheckery2=y3;
		*lcheckerx2=x4;
		*lcheckery2=y4;
	}
	else{
		*hcheckerx2=x4;
		*hcheckery2=y4;
		*lcheckerx2=x3;
		*lcheckery2=y3;
	}
}

void hline(float *hcheckerx1, float *hcheckery1, float *lcheckerx1, float *lcheckery1, float *hcheckerx2, float *hcheckery2, float *lcheckerx2, float *lcheckery2){
	if(*hcheckerx2>*hcheckerx1){
		float tempx1=*hcheckerx1, tempy1=*hcheckery1, tempx2=*lcheckerx1, tempy2=*lcheckery1;
		*hcheckerx1=*hcheckerx2;
		*hcheckerx2=tempx1;
		*hcheckery1=*hcheckery2;
		*hcheckery2=tempy1;
		*lcheckerx1=*lcheckerx2;
		*lcheckerx2=tempx2;
		*lcheckery1=*lcheckery2;
		*lcheckery2=tempy2;
	}
}

void hvline(float *hcheckerx1, float *hcheckery1, float *lcheckerx1, float *lcheckery1, float *hcheckerx2, float *hcheckery2, float *lcheckerx2, float *lcheckery2){
	if(*hcheckery2>*hcheckery1){
		float tempx1=*hcheckerx1, tempy1=*hcheckery1, tempx2=*lcheckerx1, tempy2=*lcheckery1;
		*hcheckerx1=*hcheckerx2;
		*hcheckerx2=tempx1;
		*hcheckery1=*hcheckery2;
		*hcheckery2=tempy1;
		*lcheckerx1=*lcheckerx2;
		*lcheckerx2=tempx2;
		*lcheckery1=*lcheckery2;
		*lcheckery2=tempy2;
	}
}

struct node14{
	int data;
	struct node14 *next_node;
};

struct node14* add_num14(struct node14 *head, struct node14 *current, int rem){
	current=malloc(sizeof(struct node14));
	current->data=rem;
	current->next_node=head;
	head=current;
	return head;
}

struct node15{
	int num;
	struct node15 *next_node;
};

struct node15* create_list15(struct node15 *head, struct node15 *current, char temp[]){
	current=malloc(sizeof(struct node15));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

struct node15* add_num15(struct node15 *head, struct node15 *current, char temp[]){
	current=malloc(sizeof(struct node15));
	current->num=atoi(temp);
	current->next_node=head;
	head=current;
	return head;
}

void print_list15(struct node15 *current){
	while(current){
		printf("%d\n", current->num);
		current=current->next_node;
	}
}

struct node15* delete15(struct node15 *c, struct node15 *head){
	if(c->num==head->num){
			c=c->next_node;
			head=c;
			return head;
		}
		else{
			if(c->next_node==NULL){
				struct node15 *temp1=head->next_node;
				struct node15 *temp2=head;
				while(temp1->next_node){
					temp1=temp1->next_node;
					temp2=temp2->next_node;
				}
				temp2->next_node=(struct node15*)NULL;
				free(temp1);
				return head;
			}
			else{
				struct node15 *prev=head;
				while(prev->next_node!=c){
					prev=prev->next_node;
				}
				prev->next_node=c->next_node;
				free(c);
				return head;
			}
		}
}

struct node15* getLowest15(struct node15 *head, struct node15 *current){
	struct node15 *c=current;
	static int i=0;
	int currentLowest=current->num;
		while(current->next_node){
			
			current=current->next_node;
			if(current->num < currentLowest){
				currentLowest=current->num;
				c=current;
			}
		}if(i==0){
			printf("%d", c->num);
			i++;
		}
		else{
			printf(", %d", c->num);
		}
		return delete15(c, head);
}

struct node20{
	char str[MAX20];
	struct node20 *next_node;
};

struct node201{
	char str[MAX20];
	int num;
	struct node201 *next_node;
};


struct node20* create_list20(struct node20 *head, struct node20 *current, char temp[]){
	current=malloc(sizeof(struct node20));
	strcpy(current->str, temp);
	current->next_node=head;
	head=current;
	return head;
}

struct node20* add_list20(struct node20 *head, struct node20 *current, char temp[]){
	current=malloc(sizeof(struct node20));
	strcpy(current->str, temp);
	current->next_node=head;
	head=current;
	return head;
}


//Gets the unique words
struct node201* compare_list20(struct node20 *head, struct node20 *current, struct node201 *head1, struct node201 *current1){
	char temp[MAX20];
	while(current){
		memset(temp, 0, sizeof(temp));
		strcpy(temp, current->str);
		if(head1==NULL){
			current1=malloc(sizeof(struct node201));
			strcpy(current1->str, temp);
			current1->next_node=head1;
			head1=current1;
			current=current->next_node;
		}
		else{
			current1=head1;
			while(current1){
				if(strcasecmp(current1->str, temp)==0){
					current=current->next_node;
					break;
				}
				else if(current1->next_node==NULL){
					current1=malloc(sizeof(struct node201));
					strcpy(current1->str, temp);
					current1->next_node=head1;
					head1=current1;
					current=current->next_node;
					break;
				}
				current1=current1->next_node;
			}
		}
	}
	return head1;
}

//Counts the frequency of each word
void frequency20(struct node20 *head, struct node20 *current, struct node201 *head1, struct node201 *current1){
	while(current){
		if(current1==NULL){
			current1=head1;
			continue;
		}
		else{
			if(strcasecmp(current->str, current1->str)==0){
				current1->num++;
				current=current->next_node;
			}
			else{
				current1=current1->next_node;
			}
		}
	}
}

struct node201* delete20(struct node201 *c, struct node201 *head1){
	if(c->str==head1->str){
			c=c->next_node;
			head1=c;
			return head1;
		}
		else{
			if(c->next_node==NULL){
				struct node201 *temp1=head1->next_node;
				struct node201 *temp2=head1;
				while(temp1->next_node){
					temp1=temp1->next_node;
					temp2=temp2->next_node;
				}
				temp2->next_node=(struct node201*)NULL;
				free(temp1);
				return head1;
			}
			else{
				struct node201 *prev=head1;
				while(prev->next_node!=c){
					prev=prev->next_node;
				}
				prev->next_node=c->next_node;
				free(c);
				return head1;
			}
		}
}

struct node201* getHighest20(struct node201 *current1, struct node201 *head1){
	struct node201 *c=current1;
	static int j=0;
	int currentHighest=current1->num;
		while(current1->next_node){
			
			current1=current1->next_node;
			if(current1->num > currentHighest){
				currentHighest=current1->num;
				c=current1;
			}
		}if(j==0){
			printf("%s %d", c->str, c->num);
			j++;
		}
		else{
			printf(", %s %d", c->str, c->num);
		}
		return delete20(c, head1);;
}

void Problem1(){
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

void Problem2(){
	float x1, x2, x3, x4, y1, y2, y3, y4, m1, m2, b1, b2, interx, intery, first, second;
	float lcheckerx1, hcheckerx1, lcheckery1, hcheckery1;
	float lcheckerx2, hcheckerx2, lcheckery2, hcheckery2;
	char string[1000], temp[1000]="";
	float x[8]; 
	int k=0, i;
	printf("Problem 2: Given 4 points ((x1,y1), (x2,y2), (x3,y3), (x4,y4)), \nthe program will determine the intersection of the line segments formed by \n(x1,y1), (x2,y2) and (x3,y3), (x4,y4).\n");
	printf("Enter x1,y1,x2,y2,x3,y3,x4,y4: ");
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	for(i=0; i<strlen(string); i++){
		for(i; string[i]!=',' && i<strlen(string); i++){
			strncat(temp, &string[i], 1);
		}
		x[k]=atof(temp);
		k++;
		memset(&temp[0], 0, sizeof(temp));
	}
	x1=x[0];
	y1=x[1];
	x2=x[2];
	y2=x[3];
	x3=x[4];
	y3=x[5];
	x4=x[6];
	y4=x[7];
	printf("The output is: ");
	if((x2-x1)==0){
		if((x4-x3)==0){
			vchecker1(x1, y1, x2, y2, &hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1);
			vchecker2(x3, y3, x4, y4, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
			hvline(&hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
			if(hcheckerx1==hcheckerx2){
				if(lcheckery1==hcheckery2){
					printf("The lines will intersect at (%.3f, %.3f).\n", lcheckerx1, lcheckery1);
				}
				else if((lcheckery1>=lcheckery2)&&(lcheckery1<=hcheckery2)){
					printf("The lines are coinciding.\n");
				}
				else{
					printf("No intersection.\n");
				}
			}
			else{
				printf("No intersection.\n");
			}
		}
		else{
			vchecker1(x1, y1, x2, y2, &hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1);
			checker2(x3, y3, x4, y4, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
			float high1, low1;
			if(hcheckery2<lcheckery2){
				high1=lcheckery2, low1=hcheckery2;
			}
			else{
				high1=hcheckery2, low1=lcheckery2;
			}
			m2=(y4-y3)/(x4-x3);
			b2=(y3)-(m2*x3);
			interx=hcheckerx1;
			intery=(m2*(interx))+(b2);
			if((intery>=lcheckery1 && intery<=hcheckery1) && (interx>=lcheckerx2 && interx<=hcheckerx2) && (intery<=high1 && intery>=low1)){
				printf("The lines will intersect at (%.3f, %.3f).\n", interx, intery);
			}
			else{
				printf("No intersection.\n");
			}
		}
	}
	else if((x4-x3)==0){
		checker1(x1, y1, x2, y2, &hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1);
		vchecker2(x3, y3, x4, y4, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
		float high, low;
		if(hcheckery1<lcheckery1){
			high=lcheckery1, low=hcheckery1;
		}
		else{
			high=hcheckery1, low=lcheckery1;
		}
		m1=(y2-y1)/(x2-x1);
		b1=(y1)-(m1*x1);
		interx=hcheckerx2;
		intery=(m1*(interx))+(b1);
		if((intery>=lcheckery2 && intery<=hcheckery2) && (interx>=lcheckerx1 && interx<=hcheckerx1) && (intery<=high && intery>=low)){
			printf("The lines will intersect at (%.3f, %.3f).\n", interx, intery);
		}
		else{
			printf("No intersection.\n");
		}
	}
	else{
		m1=(y2-y1)/(x2-x1);
		m2=(y4-y3)/(x4-x3);
		b1=(y1)-(m1*x1);
		b2=(y3)-(m2*x3);
		checker1(x1, y1, x2, y2, &hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1);
		checker2(x3, y3, x4, y4, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
		hline(&hcheckerx1, &hcheckery1, &lcheckerx1, &lcheckery1, &hcheckerx2, &hcheckery2, &lcheckerx2, &lcheckery2);
		if(m1==m2){
			if(b1==b2){
				if((lcheckerx1==hcheckerx1) && (lcheckery1==hcheckery2)){
					printf("The lines will intersect at (%.3f, %.3f).\n", lcheckerx1, lcheckery1);
				}
				else if((lcheckerx1>=lcheckerx2)&&(lcheckerx1<=hcheckerx2)){
					printf("The lines are coinciding.\n");
				}
				else{
					printf("No intersection.\n");
				}	
			}
			else{
				printf("No intersection.\n");
			}
		}		
		else{
			interx=(b2-b1)/(m1-m2);
			intery=(m1*(interx))+(b1);
			float high, low, high1, low1;
			if(hcheckery1<lcheckery1){
				high=lcheckery1, low=hcheckery1;
			}
			else{
				high=hcheckery1, low=lcheckery1;
			}
			if(hcheckery2<lcheckery2){
				high1=lcheckery2, low1=hcheckery2;
			}
			else{
				high1=hcheckery2, low1=lcheckery2;
			}
			if(x1>x2){
				first=x1;
				second=x2;
			}
			else{
				first=x2;
				second=x1;
			}
			if(((interx<=hcheckerx1) && (interx>=lcheckerx1) && (interx<=hcheckerx2) && (interx>=lcheckerx2))
			&& ((intery<=high) && (intery>=low) && (intery<=high1) && (intery>=low1))){
				printf("The lines will intersect at (%.3f,%.3f).\n", interx, intery);
			}
			else{
				printf("No intersection.\n");
			}
		}
	}
}

void Problem3(){
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

void Problem7(){
	int n, temp, i, j, arr[1000], k=0, ix, jx, tempo[1000], tempor;
	printf("Problem 7: Given a number n, all the fractions less than 1, such that n is the denominator, is printed (in lowest terms).\n");
	printf("Enter n: ");
	scanf("%d", &n);
	for(i=2; i<100000; i++)
	{
		for(j=2; j<=(i/j); j++)
		{
			if(!(i%j)) 
			{
				break;
			}
		}
		if(j>(i/j)){
			if(n%i==0){
				arr[k]=i;
				k++;
			}
		}
	}
	temp=k;
	tempor=2;
	for(i=0; i<n-2; i++){
		tempo[i]=tempor;
		tempor++;
	}
	printf("The output is: 1/%d", n);
	for(i=0; i<n-2; i++){
		for(k=0; k<temp; k++){
			if(tempo[i]%arr[k]==0){
				break;
			}
			if(k+1==temp){
				printf(", %d/%d", tempo[i], n);
			}
			
		}
	}
	printf("\n");
}

void Problem10(){
	int n, temp, count=1;
	double powe;
	printf("Problem 10: Given n, print its resulting roman numeral equivalence.\n");
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
	printf("\n");
}

void Problem12(){
	double n, twenc, tenc, fivec, onec;
	int thou, five, thund, hund, fifth, twen, ten, fives, ones, i=0;
	printf("Problem 12: Given a peso amount, print out its equivalent standard peso currency using the least number of denominations.\n");
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
	printf("\n");
}

void Problem14(){
	struct node14 *head=NULL, *current;
	int base, n, rem;
	printf("Problem 14: Given a number in decimal, the program will print out its equivalent number in base b.\n");
	printf("Enter number: ");
	scanf("%d", &n);
	printf("Enter base: ");
	scanf("%d", &base);
	printf("The output is: ");
	while(n!=0){
		rem=n%base;
		head=add_num14(head, current, rem);
		n=n/base;
	}
	current=head;
	while(current){
		printf("%d", current->data);
		current=current->next_node;
	}
	printf("\n");
}

void Problem15(){
	int n, i;
	char string[1000], temp[1000]="";
	struct node15 *head=NULL, *current;
	printf("Problem 15: Given n numbers, the program will print out the sorted numbers in increasing order.\n");
	printf("Input n: ");
	scanf("%d", &n);
	getchar();
	printf("Input %d numbers (separated by a comma): ", n);
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		for(i; string[i]!=',' && i<strlen(string); i++){
			strncat(temp, &string[i], 1);
		}
		if(head==NULL){
			head=create_list15(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
		else{
			head=add_num15(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
	}
	while(head){
		current=head;
		head=getLowest15(head, current);
	}
	printf("\n");
}

void Problem18(){
	char string[1000];
	int i, ascii;
	printf("Problem 18: Given a string, the program will print out its keypad press equivalent.\n");
	printf("Enter a sentence: ");
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		if(string[i]==' '){
			printf("0");
			continue;
		}
		ascii=(int)string[i];
		if(ascii>=97 && ascii<=99){
			ascii=ascii-96;
			while(ascii!=0){
				printf("2");
				ascii--;
			}
			continue;
		}
		else if(ascii>=100 && ascii<=102){
			ascii=ascii-99;
			while(ascii!=0){
				printf("3");
				ascii--;
			}
			continue;
		}
		else if(ascii>=103 && ascii<=105){
			ascii=ascii-102;
			while(ascii!=0){
				printf("4");
				ascii--;
			}
			continue;
		}
		else if(ascii>=106 && ascii<=108){
			ascii=ascii-105;
			while(ascii!=0){
				printf("5");
				ascii--;
			}
			continue;
		}
		else if(ascii>=109 && ascii<=111){
			ascii=ascii-108;
			while(ascii!=0){
				printf("6");
				ascii--;
			}
			continue;
		}
		else if(ascii>=112 && ascii<=115){
			ascii=ascii-111;
			while(ascii!=0){
				printf("7");
				ascii--;
			}
			continue;
		}
		else if(ascii>=116 && ascii<=118){
			ascii=ascii-115;
			while(ascii!=0){
				printf("8");
				ascii--;
			}
			continue;
		}
		else if(ascii>=119 && ascii<=122){
			ascii=ascii-118;
			while(ascii!=0){
				printf("9");
				ascii--;
			}
			continue;
		}
	}
	printf("\n");
}

void Problem20(){
	struct node20 *head=NULL, *current;
	struct node201 *head1=NULL, *current1;
	char string[MAX20], temp[MAX20]="";
	int i, num;
	printf("Problem 20: Given a sequence of words, the program will sort and print the words with respect to frequency.\n");
	printf("Enter a series of words: ");
	fgets(string, 1000, stdin);
	string[strlen(string)-1]='\0';
	printf("The output is: ");
	for(i=0; i<strlen(string); i++){
		while(string[i]!=' ' && i<strlen(string)){
			strncat(temp, &string[i], 1);
			i++;
		}
		if(head==NULL){
			head=create_list20(head, current, temp);
			memset(temp, 0, sizeof(temp));
			continue;
		}
		else{
			head=add_list20(head, current, temp);
			memset(temp, 0, sizeof(temp));
		}
	}
	current=head;
	head1=compare_list20(head, current, head1, current1);
	current1=head1;
	frequency20(head, current, head1, current1);
	while(head1){
		current1=head1;
		head1=getHighest20(current1, head1);
	}
	printf("\n");
}

int main(){
	int test, exit=0;
	while(exit==0){
		printf("Please enter a program number to test: ");
		scanf("%d", &test);
		getchar();
		if(test==1){
			Problem1();
		}
		else if(test==2){
			Problem2();
		}
		else if(test==3){
			Problem3();
		}
		else if(test==7){
			Problem7();
		}
		else if(test==10){
			Problem10();
		}
		else if(test==12){
			Problem12();
		}
		else if(test==14){
			Problem14();
		}
		else if(test==15){
			Problem15();
		}
		else if(test==18){
			Problem18();
		}
		else if(test==20){
			Problem20();
		}
	}
	
}