#include<stdio.h>

int main(){
	int n,d,sum,average;
	printf("Enter No. of Subjects: \t");
	scanf("%d",&n);

	int num[n];
	printf("Enter marks of %d subjects :\t",n);


	for(d=0; d<n;d++){
		scanf("%d",&num[d]);
		sum = sum + num[d];
	}

	average = sum/n;

	printf("Average of student : %d \n",average);
	if(average>=90){
		printf("Student got A grade\n");
	}

	else if(average>80 && average<90){
		printf("Student got B grade\n");
	}

	else if(average>70 && average<80){
		printf("Student got C grade\n");
	}

	else if(average>60 && average<70){
		printf("Student got D grade\n");
	}

	else if(average>50 && average<60){
		printf("Student got E grade\n");
	}

	else if(average>40&& average<50){
		printf("Student got F grade\n");
	}
	else printf("Student Failed\n");

	return 0;
}
