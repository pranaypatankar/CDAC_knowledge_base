#include<stdio.h>

int main(){
	char a;

	printf("enter character (a-z) :");

	scanf("%c",&a);

	if(a=='a' || a=='e' || a=='i'|| a=='o' || a=='u'){
		printf("It is a vowel\n");
	}
	else {printf("its not a vowel\n"); }

	return 0;
}
