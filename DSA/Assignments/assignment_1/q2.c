/*
Q2. Create an employee structure with the following members
	empid, employee name, salary, year of joining etc.
	Accept the data for certain no. of employees and find their total,
	average, max, min salary.
	Also find out the employees with maximum, minimum service,use a
	function to find service for each employee element in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct empl{
	int empID;
	char name[30];
	long int salary;
	int YoJ;
	int serviceYear;
};

int size,count,presentYr;

void addempl(struct empl *);
long int totalSal(struct empl *);
void averfSal(struct empl *);
void maxSal(struct empl *);
void minSal(struct empl *);
void maxServ(struct empl *);
void minServ(struct empl *);
void servYr(struct empl *);
void display(struct empl *,int);

int main(){
	struct empl Employee;
	int choice;
	long int totalSalary;

	printf("Enter No. of Employees : ");
	scanf("%d",&size);
	struct empl *sp = (struct empl *)malloc(sizeof(struct empl)*size);
	while(1){
		printf("\nWhat you want to do :\n");
		printf("1.ADD Employee\n");
		printf("2.Calculate total salary\n");
		printf("3.Average Salary\n");
		printf("4.Max Salary\n");
		printf("5.Minimum Salary\n");
		printf("6.Max service year\n");
		printf("7.Minimum Service Year\n");
		printf("8.Calculate Service year\n");
		printf("9.Print all Employee data\n");
		printf("0.Exit\n");
		printf("Select Option:\n");

		scanf("%d",&choice);

		switch(choice){
			case 1:
				count++;
				addempl(sp);
				printf("Enter Present year: ");
				scanf("%d",&presentYr);
				servYr(sp);
				display(sp,count-1);
				break;
			case 2:
				totalSalary=totalSal(sp);
				printf("Total Salary Paid is : %ld\n",totalSalary);
				break;
			case 3:
				averfSal(sp);
				break;
			case 4:
				maxSal(sp);
				break;
			case 5:
				minSal(sp);
				break;
			case 6:
				maxServ(sp);
				break;
			case 7:
				minServ(sp);
				break;
			case 8:
				servYr(sp);
				break;
			case 9:
				printf("Data of All Employees\n");
				for(int i=0;i<count;i++){
					display(sp,i);
				}
				break;
			case 0:
				exit(1);
			default:
				printf("Enter Right Option\n");
				break;
		}
	}
	return 0;	
}
void addempl(struct empl *f1){
	
	printf("======Enter Data of employee %d =====\n",count);
	int j=count-1;
	printf("Employee ID: ");
	scanf("%d",&f1[j].empID);
	__fpurge(stdin);

	printf("Name: ");
	scanf("%[^\n]",f1[j].name);
	__fpurge(stdin);

	printf("Salary: ");
	scanf("%ld",&f1[j].salary);
	__fpurge(stdin);
	

	printf("Year of Joining: ");
	scanf("%d",&f1[j].YoJ);
	__fpurge(stdin);
	
	printf("Data Added Successfully\n");
}

long int totalSal(struct empl *sp){
	long int totalSalary=0;

	for(int i=0;i<size;i++){
		totalSalary=totalSalary+sp[i].salary ;
	}
	return totalSalary;
}

void averfSal(struct empl *sp){
	float average;
	long int total;
	total=totalSal(sp);

	average=total/count;

	printf("Average Salary is %f\n",average);
}

void maxSal(struct empl *sp){
	long int max;
	int ind=0;

	max= sp[0].salary;

	for(int i=1;i<count;i++){
		if(sp[i].salary>max){
			max=sp[i].salary;
			ind=i;
		}
	}
	printf("Maximum Salary is %ld of %s\n",max,sp[ind].name);
}

void minSal(struct empl *sp){
	long int min;
	int ind=0;

	min= sp[0].salary;

	for(int i=0;i<count;i++){
		if(sp[i].salary>min){
			min=sp[i].salary;
			ind=i;
		}
	}
	printf("Minimum Salary is %ld of %s\n",min,sp[ind].name);	
}

void maxServ(struct empl *sp){
	int maxServ=sp[0].YoJ;
	int ind=0;
	if(presentYr==0){
		printf("Enter Present Year :");
		scanf("%d",&presentYr);
	}

	for(int i=1;i<count;i++){
		if((presentYr - sp[i].YoJ)>maxServ){
			maxServ=presentYr - sp[i].YoJ;
			ind=i;
		}
	}
	printf("Maximum Service is %d year of %s till %d\n",sp[ind].serviceYear,sp[ind].name,presentYr);

}
void minServ(struct empl *sp){
	int minServ=sp[0].YoJ;
	int ind=0;
	if(presentYr==0){
		printf("Enter Present Year :");
		scanf("%d",&presentYr);
	}

	for(int i=1;i<count;i++){
		if((presentYr - sp[i].YoJ)<minServ){
			minServ=presentYr - sp[i].YoJ;
			ind=i;
		}
	}
	printf("Minimum Service is %d year of %s till %d\n",minServ,sp[ind].name,presentYr);

}
void servYr(struct empl *sp){
	for(int i=0;i<count;i++){
		sp[i].serviceYear=presentYr - sp[i].YoJ;
	}
}

void display(struct empl *f1,int j){
	printf("Employee ID: ");
	printf("%d\n",f1[j].empID);
	
	printf("Name: ");
	printf("%s\n",f1[j].name);
	
	printf("Salary: ");
	printf("%ld\n",f1[j].salary);

	printf("Year of Joining: ");
	printf("%d\n",f1[j].YoJ);

	printf("Service Year: ");
	printf("%d\n",f1[j].serviceYear);
}

