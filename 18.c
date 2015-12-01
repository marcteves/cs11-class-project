#include <stdio.h>
#include <string.h>

int main(){
	char string[1000];
	int i, ascii;
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
}