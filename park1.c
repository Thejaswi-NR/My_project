#include<stdio.h>
#include<string.h>
#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define WHITE "\x1b[37m"
void entry();
void Exit();
void reset();
int main()
{
	printf("-------------------------------------------\n");
	printf("                vacancy Details            \n");
	printf("-------------------------------------------\n");
	int var=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=5;j++){
			printf("B%02d:  A    ",var++);
		}
		printf("\n");
	}
	int choice;
	char ch='y';
	while(ch=='y'||ch=='Y'){
		printf("1:Entry\n2:Exit\n3.Reset\nEnter our choice: \n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:entry();
			       break;

			case 2:Exit();
			       break;

			case 3:reset();
			       break;
		}
		printf(WHITE"Do you want to continue!(y/n)\n");
		scanf(" %c",&ch);
	}
}
void entry()
{
	int var=1;
	char arr[25];
	FILE *fvac=fopen("vancancy.txt","r");
	int i=0;
	while((fscanf(fvac,"%[^\n]\n",arr)) != EOF){
		i++;
	}
	char arr1[20][5]={"B01","B02","B03","B04","B05","B06","B07","B08","B09","B10",
		"B11","B12","B13","B14","B15","B16","B17","B18","B19","B20"};
	int flag=0;
	int k=0;
	for(int i=0;i<20;i++){
		if(arr[i]=='0'){
			k=i;
			arr[k]='1';
			flag=1;
			break;
		}

	}
	if(flag==1)
	{
		printf(WHITE"Welcome to Didital parking system\n");
		printf(WHITE"Allocated position is %s\n",arr1[k]);
	}
	printf("-------------------------------------------\n");
	printf("                vacancy Details            \n");
	printf("-------------------------------------------\n");
	for(int i=0;i<20;i++)
	{
		if(i%5==0)
		{
			printf("\n");
		}
		if(arr[i]=='0')
		{
			printf(WHITE"B%02d:  "GREEN"A    ",var++);
		}
		else
		{
			printf(WHITE"B%02d:  "RED"N    ",var++);
		}
	}

	printf("\n");

	fclose(fvac);
	fvac=fopen("vancancy.txt","w");
	fprintf(fvac,"%s\n",arr);
	fclose(fvac);
}
void Exit(){
	int var=1;
	char arr[25];
	FILE *fvac=fopen("vancancy.txt","r");
	int i=0;
	while((fscanf(fvac,"%[^\n]\n",arr))!= EOF){
		i++;
	}
	char arr1[20][5]={"B01","B02","B03","B04","B05","B06","B07","B08","B09","B10",
		"B11","B12","B13","B14","B15","B16","B17","B18","B19","B20"};
	char str[20];
	int flag=0;
	printf("Enter the allocated position:\n");
	scanf(" %[^\n]",str);


	for(int i=0;i<20;i++){
		if(strcmp(arr1[i],str)==0){
			flag=1;
			arr[i]='0';
			break;
		}
	}
	if(flag==1){

		printf(WHITE"Thank you\nVisit again\n");
	}
	if(flag==0)
	{
		printf("Enter the correct position\n");
		return;
	}

	printf("-------------------------------------------\n");
	printf("                vacancy Details            \n");
	printf("-------------------------------------------\n");
	for( int i=0;i<20;i++)
	{
		if ( i %  5 ==0)
		{
			printf("\n");
		}
		if (arr[i] == '0')
		{
			printf(WHITE"B%02d:  "GREEN"A    ",var++);
		}
		else
		{
			printf(WHITE"B%02d:  "RED"N    ",var++);
		}

	}
	printf("\n");
	fclose(fvac);
	fvac=fopen("vancancy.txt","w");
	fprintf(fvac,"%s\n",arr);
	fclose(fvac);
}
void reset()
{
	int var=1;
	char arr[25];
	FILE *fvac=fopen("vancancy.txt","r");
	int i=0;
	while((fscanf(fvac,"%[^\n]\n",arr))!= EOF){
		i++;
	}
	int k;
	for(int i=0;i<20;i++){
		if(arr[i]=='1'){
			k=i;
			arr[k]='0';
		}
	}
	printf("-------------------------------------------\n");
	printf("                vacancy Details            \n");
	printf("-------------------------------------------\n");
	for( int i=0;i<20;i++)
	{
		if ( i %  5 ==0)
		{
			printf("\n");
		}
		if (arr[i] == '0')
		{
			printf(WHITE"B%02d:    "GREEN"A    ",var++);
		}
	}
	printf("\n");
	fclose(fvac);
	fvac=fopen("vancancy.txt","w");
	fprintf(fvac,"%s\n",arr);
	fclose(fvac);
}
