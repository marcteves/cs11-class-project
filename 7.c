#include <stdio.h>

int main(){
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
		
}