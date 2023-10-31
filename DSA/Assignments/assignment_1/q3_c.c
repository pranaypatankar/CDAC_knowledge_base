#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct demo{
	int num;
	char c;
};

int main(){
	struct demo *h;
	int size;

	printf("Enter no. of elements: ");
	scanf("%d",&size);
	h = (struct demo*)malloc(sizeof(struct demo)*size);

	if(h==NULL){
		printf("Failed to allocate memory\n");
		exit(1);
	}

	for(int i=0;i<size;i++){
		printf("Enter a number : ");
		scanf("%d",&h[i].num);
		__fpurge(stdin);
		printf("Enter a Alphabet : ");
		scanf("%c",&h[i].c);
	}
	printf("\n");

	for(int i=0;i<size;i++){
		printf("Printing elements of structure %d\n",i+1);
		printf("Enter a number : ");
		printf("%d\n",h[i].num);
		printf("Enter a Alphabet : ");
		printf("%c\n",h[i].c);
		printf("\n");
	}

	free(h);
	return 0;
}