#include<stdio.h>

int main(){
	int n,d,s,avr;

	printf("enter no. of inputs:\n");
	scanf("%d",&n);
	int a[n];
	printf("enter inputs :");

	for(d=0;d<n;d++){
		scanf("%d",&a[d]);
	}
	for(d=0;d<n;d++){
		s=s+a[d];
	}
	printf("sum of inputs : %d\n",s);
	avr=s/n;
	printf("average of inputs : %d\n",avr);
	return 0;
}
