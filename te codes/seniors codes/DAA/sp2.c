#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct symbol
{
	char symbol[50];
	int address;
	int size;
}ST[50];

struct literal
{
	char literal[20];
	int address;
}LT[20];

struct pool
{
	int literal_no;
}PT[20];

struct IC
{
	int LC;
	char opcode1[20],mcode1[20],opcode2[20],mcode2[20],opcode3[20],mcode3[20];
}IC[20];

char s1[10],s2[10],s3[10],s4[10],s5[10],s6[10],s7[10];
int iIC=0;
void init()
{
	strcpy(s1," ");
	strcpy(s2," ");
	strcpy(s3," ");
	strcpy(s4," ");
	strcpy(s5," ");
	strcpy(s6," ");
	strcpy(s7," ");
}

void mcode()
{
	int i;
	printf("\nMcode:");
	for(i=0;i<iIC;i++)
	{
		switch(IC[i].opcode1[0])
		{
			case 'D':
			if(strcmp(IC[i].mcode1,"01")==0)
			printf("\n%d) +00 0 00%s",IC[i].LC,IC[i].mcode2);
			break;
			
			case 'A':
				break;
				
			case 'I':
			if(strcmp(IC[i].mcode1,"00")==0)
			printf("\n%d) +00 0 000",IC[i].LC);
			else
			{
				printf("\n%d) +%s",IC[i].LC,IC[i].mcode1);
				if(strcmp(IC[i].opcode2,"S")!=0)
				printf("%d ",atoi(IC[i].mcode2));
				else
				printf("0%d ",ST[atoi(IC[i].mcode2)].address);
				if(strcmp(IC[i].opcode3,"L")==0)
				printf(" %d",LT[atoi(IC[i].mcode3)].address);
				else if(strcmp(IC[i].opcode3,"S")==0)
				printf(" %d",ST[atoi(IC[i].mcode3)].address);
			}
			break;
		}
	}
}

void main()
{
	FILE *ptr;
	int j,i,count;
	char nextline[50];
	ptr=fopen("literal.txt","r");
	j=0;
	printf("\nLiteral table\n");
	while(fscanf(ptr,"%s%s",s1,s2)!=-1)
	{
		strcpy(LT[j].literal,s1);
		LT[j].address=atoi(s2);
		printf("\n%s\t%d",LT[j].literal,LT[j].address);
		j++;
	}
	fclose(ptr);
	
	ptr=fopen("pooltable.txt","r");
	j=0;
	printf("\nPool table\n");
	while(fscanf(ptr,"%s",s1)!=-1)
	{
		PT[j].literal_no=atoi(s1);
		printf("\n%d",PT[j].literal_no);
		j++;
	}
	fclose(ptr);
	
	ptr=fopen("symbol.txt","r");
	j=0;
	printf("\nSymbol table\n");
	while(fscanf(ptr,"%s%s%s",s1,s2,s3)!=-1)
	{
		strcpy(ST[j].symbol,s1);
		ST[j].address=atoi(s2);
		ST[j].size=atoi(s3);
		printf("%s %d %d\n",ST[j].symbol,ST[j].address,ST[j].size);
		j++;
	}
	fclose(ptr);
	
	ptr=fopen("ic.txt","r");
	j=0;
	printf("\nIntermediate code:\n");
	while(!feof(ptr))
	{
		i=0;
		nextline[i]=fgetc(ptr);
		while(nextline[i]!='\n' && nextline[i]!=EOF)
		{
			if(!isalnum(nextline[i]))
				nextline[i]=' ';
				i++;
				nextline[i]=fgetc(ptr);
		}
		nextline[i]='\0';	
		init();
		count=sscanf(nextline,"%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7);
		if(count==-1)
		continue;
		IC[j].LC=atoi(s1);
		strcpy(IC[j].opcode1,s2);
		strcpy(IC[j].mcode1,s3);
		strcpy(IC[j].opcode2,s4);
		strcpy(IC[j].mcode2,s5);
		strcpy(IC[j].opcode3,s6);
		strcpy(IC[j].mcode3,s7);
		printf("\n %d %s %s %s %s %s %s",IC[j].LC,IC[j].opcode1,IC[j].mcode1,IC[j].opcode2,IC[j].mcode2,IC[j].opcode3,IC[j].mcode3);
		j++;
	}
	iIC=j;
	fclose(ptr);
	mcode();
	printf("\n");
}
