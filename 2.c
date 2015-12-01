#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	hcheckerx1=higher x value of the rightmost line segment
	hcheckery1=corresponding y value of the higher x value of the rightmost line segment
	lcheckerx1=lower x value of the rightmost line segment
	lcheckery1=corresponding y value of the lower x value of the rightmost line segment
	hcheckerx2=higher x value of the leftmost line segment
	hcheckery2=corresponding y value of the higher x value of the leftmost line segment
	lcheckerx2=lower x value of the leftmost line segment
	lcheckery2=corresponding y value of the lower x value of the leftmost line segment
	high=higher y value between hcheckery1 and lcheckery1
	low=lower y value between hcheckery1 and lcheckery1
	high1=higher value between hcheckery2 and lcheckery2
	low1=lower value between hcheckery2 and lcheckery2
*/

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

int main(){
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
			float high, low;
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