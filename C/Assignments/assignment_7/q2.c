#include<stdio.h>

register int glbal = 10;

int main(){
	register int local=100;

	//printf("global = %d",glbal);//printing value of global register variable // Register can only be used within a block (local), it can not be used in the global scope (outside main).
	printf("local = %d",local); // prointing value of local register variable
	//printf("&global = %p",&global);
	//printf("&local = %p",&local);
/*
	Adresses of register can not be printed weather its local or global

	*/


	return 0;

}