#include <stdio.h>
#include <stdlib.h>

#define size 5

void display(int *);
void enqueue(int *,int *,int *,int);
int dequeue(int *,int *,int *);

int main(){
	int arr[size];
	int choice,ele,ret;

	int front = -1;
	int rear=-1;

	for(int i=0;i<size;i++)
		arr[i]=-99;

	while(1){

		printf("Select: \n1. Enqueue\n2. Dequeue\n3. Display\n4. exit \n");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter ele :");
			scanf("%d",&ele);
			enqueue(arr,&front,&rear,ele);
			break;

		case 2:
			ret=dequeue(arr,&front,&rear);
			if(ret!=-1){
				printf("Popped Element =%d\n",ret);
				break;
			}
			break;

		case 3:
			display(arr);
			printf("\n\n");
			break;

		case 4:
			exit(1);

		default:
			printf("Invalid Choice\n");
			break;
		}
	}
	return 0;
}

void display(int *a){
	for(int i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
}

void enqueue(int *a,int *f,int *r,int e){
	
	if((*r==size-1&&*f==0)||(*r+1==*f)){
		printf("Queue is Full\n");
		return ;
	}

	if(*r==size-1)
		*r=0;
	else
		(*r)++;
	a[*r]=e;

	if(*f==-1)
		*f=0;
}

int dequeue(int *a,int *f,int *r){

	if(*f==-1){
		printf("End of Stack\n");
		return -1;
	}

	int ret=a[*f];
	a[*f]=-99;

	if(*f==size-1&&*r!=size-1)
		*f=0;
	else if(*f!=*r)
			(*f)++;
	else {
		*f=-1;
		*r=-1;
	}

	return ret;
}

