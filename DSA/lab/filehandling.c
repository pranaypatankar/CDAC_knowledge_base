#include<stdio.h>
#include<stdlib.h>

void remNS(char *);
void remSpac(char *);

int main(){
	char name[50];
	int choice;

	printf("Enter file name\n");
	scanf("%s",name);
	while(1)
		{
			printf("Enter your choice: \n");
			printf("1: Remove numbers and Special characers: \n");
			printf("2: Remove Spaces: \n");
			printf("3: EXIT \n");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
					remNS(name);
					break;

				case 2:
					remSpac(name);
					break;

				case 3:
					exit(1);

				default:
					printf("Enter a valid choice");
					break;		
					
			}
		}
	return 0;
}

void remNS(char *name){
	FILE *fp ;
	
	fp=fopen(name,"r");
	if(fp==NULL) printf("file doesnt exist\n");
	char buff[55];
	char new[55];
	int j=0;
	fgets(buff,55,fp);
	for(int i=0;buff[i]!='\0';i++){
		if((buff[i]>='a'&&buff[i]<='z')||(buff[i]>='A'&&buff[i]<='Z')||(buff[i]==' ')||(buff[i]=='\n')){
			new[j]=buff[i];
			j++;
		}
	}
	fclose(fp);
	new[j+1]=EOF;
	fp=fopen(name,"w");

	fputs(new,fp);

	fclose(fp);

}
void remSpac(char *name){
	FILE *fp ;
	
	fp=fopen(name,"r");
	if(fp==NULL) printf("file doesnt exist\n");
	char buff[55];
	fgets(buff,55,fp);
	char new[55];
	int j=0;
	
	for(int i=0;buff[i]!='\0';i++){
		if(buff[i]!=' '|| buff[i]!='\n'){
			new[j]=buff[i];
			j++;
		}
	}
	new[j+1]=EOF;
	fclose(fp);
	printf("%s\n",new);
	fp=fopen(name,"w");

	fputs(new,fp);

	fclose(fp);

}
