#include<stdio.h>
#include<stdlib.h>

int slab_1(int);
int slab_2(int);
int slab_3(int);
int slab_4(int);
int slab_5(int);

int main(){
	int income,age,tax,slab;
	char gender;
	printf("Enter age :- ");
	scanf("%d",&age);
	printf("Enter Gender(m/f):- ");
	scanf("%c",&gender);
	printf("Enter Income of Tax payer:-\n");
	scanf("%d",&income);
	
	if(income<=250000) slab =1;
	else if(income<=500000&&income>250000) slab=2;
	else if(income<=1000000&&income>500000) slab=3;
	else if(income<=1250000&&income>1000000) slab= 4;
	else slab=5;

	switch(slab){
		case 1:
			tax=slab_1(income);
			break;
		case 2:
			tax=slab_2(income);
			break;
		case 3:
			tax=slab_3(income);
			break;
		case 4:
			tax=slab_4(income);
			break;
		case 5:
			tax=slab_5(income);
			break;
		default:
			exit(1);
	}
	if(gender=='f')	tax=tax-(tax*0.1);
	else if (age >=60) tax=tax-(tax*0.15);
	else if (gender=='f'&& age>=60)tax=tax-(tax*0.125);

	printf("tax payable is : %d\n",tax);
	return 0;
}

int slab_1(int income){
	int t=0;
	return t;
}

int slab_2(int income){
	int t=(income-250000)*0.5;
	return t;
}

int slab_3(int income){
	int t=12500+((income-500000)*0.1);
	return t;
}

int slab_4(int income){
	int t=112500+((income-1000000)*0.2);
	return t;
}

int slab_5(int income){
	int t=162500+((income-1250000)*0.3);
	return t;
}
