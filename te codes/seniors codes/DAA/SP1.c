#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct symbol
{
	char symbol[40];
	int address;
	int size;
}ST[50];

struct literal
{
	char literal[7];
	int address;
}LT[50];

struct pool
{
	int literal_no;
}PT[10];

struct Intermediate
{
	int LC;
	int code1,type1,code2,type2,code3,type3;
}IC[100];

struct Mnemonic
{
	char mnemonic[50];
	int class;
	char opcode[3];
};

static struct Mnemonic MOT[28]={{"STOP",1,"00"},{"ADD",1,"01"},{"SUB",1,"02"},{"MULT",1,"03"},{"MOVER",1,"04"},{"MOVEM",1,"05"},{"COMP",1,"06"},{"BC",1,"07"},{"DIV",1,"08"},{"READ",1,"09"},{"PRINT",1,"10"},{"START",3,"01"},{"END",3,"02"},{"ORIGIN",3,"03"},
	{"EQU",3,"04"},{"LTORG",3,"05"},
	{"DS",2,"01"},{"DC",2,"02"},
	{"AREG",4,"01"},{"BREG",4,"02"},{"CREG",4,"03"},
	{"EQ",5,"01"},{"LT",5,"02"},{"GT",5,"03"},{"LE",5,"04"},
	{"GE",5,"05"},{"NE",5,"06"},{"ANY",5,"07"}
};

int nMOT=28;
int litptr=0,poolptr,LC=0,iIC=0,iST=0;
char label[20],s1[10],s2[10],s3[10];
int i,tokencount;
int searchMOT(char symbol[])
{
	for(i=0;i<nMOT;i++)
		if(strcmp(MOT[i].mnemonic,symbol)==0)
		return (i);
	return (-1);
}

int searchST(char symbol[])
{
	for(i=0;i<iST;i++)
		if(strcmp(ST[i].symbol,symbol)==0)
		return (i);
	return (-1);
}

int insertST(char symbol[],int address,int size)
{
		strcpy(ST[iST].symbol,symbol);
		ST[i].address=address;
		ST[i].size=size;
		iST++;
		return (iST-1);
}

int isliteral(char symbol[])
{
	if(strchr(symbol,'=')==NULL)
		return 0;
	return 1;
}
FILE *ptr;		
void LTORG();
void DC();
void DS();
void EQU();
void START();
void ORIGIN();
void imperative();
void directive();
void declaration();
void print_symbol();
void print_lit_pool();
void intermediate_code();
void main()
{
	char nextline[100],file[100];
	printf("\nEnter the file name:");
	scanf("%s",file);
	ptr=fopen(file,"r");
	//PT[0].literal_no=0;
	while(!feof(ptr))
	{
		i=0;
		nextline[i]=fgetc(ptr);
		while(nextline[i]!='\n' && nextline[i]!=EOF)
		{
			if(!isalnum(nextline[i]) && nextline[i]!='=')
				
				nextline[i]=' ';
			
			else
			
				nextline[i]=toupper(nextline[i]);
				i++;
				nextline[i]=fgetc(ptr);
			
		}
		nextline[i]='\0';
		sscanf(nextline,"%s",s1);
		if(strcmp(s1,"END")==0)
		{
			LTORG();
			break;
		}
		if(searchMOT(s1)==-1)
		{
			if(searchST(s1)==-1)
			insertST(s1,LC,1);
			tokencount=sscanf(nextline,"%s%s%s%s",label,s1,s2,s3);
			tokencount--;
		}
		else
			tokencount=sscanf(nextline,"%s%s%s",s1,s2,s3);
			if(tokencount==0)
			continue;
			i=searchMOT(s1);
			if(i==-1)
			{	
				printf("Wrong %s",s1);
				continue;
			}
			switch(MOT[i].class)
			{
				case 1:imperative();
					break;
				case 2:declaration();
					break;
				case 3:directive();
					break;
				default:printf("Wrong");
				break;
			}
		}
	print_symbol();
	print_lit_pool();
	intermediate_code();
	printf("Created :-D");
}

void imperative()
{
	int index=searchMOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0;
	IC[iIC].LC=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	LC=LC+1;
	if(tokencount>1)
	{
		index=searchMOT(s2);
		
		if(index!=-1)
		{
			IC[iIC].code2=index;
			IC[iIC].type2=MOT[index].class;
		}
		else
		{
			index=searchST(s2);
			if(index==-1)
			index=insertST(s2,0,1);
			IC[iIC].code2=index;
			IC[iIC].type2=7;
		}
	}
	if(tokencount>2)
	{
		index=searchST(s3);
		if(isliteral(s3)==0)
		{
			if(index==-1)
			index=insertST(s3,0,1);
			IC[iIC].code3=index;
			IC[iIC].type3=7;
		}
		else
		{
			IC[iIC].code3=litptr;
			IC[iIC].type3=8;
			strcpy(LT[litptr].literal,s3);
			litptr++;
		}
	}
	iIC++;
}

void intermediate_code()
{	
	char decode[9][3]={" ","IS","DL","AD","RG","CC","S","L","C"};
	for(i=0;i<iIC;i++)
	{
		printf("\n%d)   (%s,%2s)",IC[i].LC,decode[IC[i].type1],MOT[IC[i].code1].opcode);
		if(IC[i].type2!=0)
		{
			if(IC[i].type2<6)
			printf("(%s,%2s)",decode[IC[i].type2],MOT[IC[i].code2].opcode);
		
		else
			printf("(%s,%2d)",decode[IC[i].type2],IC[i].code2);
		}
		if(IC[i].type3!=0)
		{
			printf("(%s,%2d)",decode[IC[i].type3],IC[i].code3);
		}
	}
}
					
void directive()
{
	if(strcmp(s1,"START")==0)
	{
		START();
		return;
	}
	else if(strcmp(s1,"LTORG")==0)
	{
		LTORG();
		return;
	}
	else if(strcmp(s1,"EQU")==0)
	{
		EQU();
		return;
	}
	else 
	{
		ORIGIN();
		return;
	}
}

void START()
{
	int index=searchMOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0;
	IC[iIC].LC=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;
	IC[iIC].code2=atoi(s2);
	LC=atoi(s2);
	iIC++;
}

void ORIGIN()
{
	LC=atoi(s2);
}

void EQU()
{
	int index=searchST(label),index1;
	if(index==-1)
	index=insertST(label,0,0);
	if(isdigit(s2[0])==0)
	{
		index1=searchST(s2);
		ST[index].address=ST[index1].address;
	}
	else
		ST[index].address=atoi(s2);
		ST[index].size=1;
		
}

void LTORG()
{
	for(i=PT[poolptr].literal_no;i<litptr;i++)
	{
		LT[i].address=LC++;
	}
	poolptr++;
	PT[poolptr].literal_no=litptr;
}

void declaration()
{
	if(strcmp(s1,"DC"))
	{
		DC();
		return;
	}
	if(strcmp(s1,"DS"))
	{
		DS();
		return;
	}
}

void DC()
{
	int index=searchMOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0;
	IC[iIC].LC=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;
	IC[iIC].code2=atoi(s2);
	index=searchST(label);
	if(index==-1)
	index=insertST(label,0,0);
	ST[index].address=LC;
	ST[index].size=1;
	LC=LC+1;
	iIC++;
}

void DS()
{
	int index=searchMOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0;
	IC[iIC].LC=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;
	IC[iIC].code2=atoi(s2);
	index=searchST(label);
	if(index==-1)
	index=insertST(label,0,0);
	ST[index].address=LC;
	ST[index].size=atoi(s2);
	LC=LC+atoi(s2);
	iIC++;
}

void print_symbol()
{
	printf("\nSymbol table");
	for(i=0;i<iST;i++)
	{
		printf("\n%s\t%d\t%d",ST[i].symbol,ST[i].address,ST[i].size);
	}
}

void print_lit_pool()
{
	printf("\nLiteral table");
	for(i=0;i<litptr;i++)
	{
		printf("\n%s\t%d",LT[i].literal,LT[i].address);
	}
	printf("\nPool Table:");
	for(i=0;i<poolptr;i++)
	{
		printf("\n%d",PT[i].literal_no);
	} 
}	
