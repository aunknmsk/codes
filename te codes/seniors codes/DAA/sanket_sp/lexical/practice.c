#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct terminal_table
{
	char terminal[7];
}TT[20];

struct literal_table
{
	char literal[7];
}LT[20];


struct identifier_table
{
	char identifier[7];
}IT[20];

struct uni_st
{
	char token[7];
	char class[10];
}UST[20];

struct Mnemonic_Table
{
	char mnemonic[10];
};

struct Mnemonic_Table MOT[20] = 
{
	{"int"},{"void"},{"main"},{"{"},{"}"},{";"},{"="},{"+"},{"++"},{","},{"("},{")"},{"~"},{"*"}

};

char s1[20];
int ust_ptr=0;
int nMOT=12;
int tt_ptr=0;
int lt_ptr=0;
int it_ptr=0;
/*
int search_MOT(char s1[])
{
	int i=0;
	for(i=0;i<nMOT;i++)
	{
		if(strcmp(s1,MOT[i].mnemonic)==0)
		return 1;
	}
	
	return -1;
}
*/


int search_MOT(char symbol[])
{
	int i;
	for(i=0;i<nMOT;i++)
		if(strcmp(MOT[i].mnemonic,symbol)==0)
			return 1;
	return(-1);
}

void print_terminal()
{
	int i;
	printf("\nvalue of tt_ptr:%d",tt_ptr);
	for(i=0;i<tt_ptr;i++)
	{
		printf("\n%7s",TT[i].terminal);
	}
}

void print_id()
{
	int i;
	printf("\nvalue of it_ptr:%d",it_ptr);
	for(i=0;i<it_ptr;i++)
	{
		printf("\n%3s",IT[i].identifier);
	}
}



void print_literal()
{
	int i;
	printf("\nvalue of lt_ptr:%d",lt_ptr);
	for(i=0;i<lt_ptr;i++)
	{
		printf("\n%3s",LT[i].literal);
	}
}




void print_ust()
{
	int i;
	printf("\nvalue of ust_ptr:%d",ust_ptr);
	for(i=0;i<ust_ptr;i++)
	{
		printf("\n%7s   %7s",UST[i].token,UST[i].class);
	}
}






/*

void addtoterminal(int pos)
{
	int flag=0;
	int i;
	char temp[20];
	strcpy(temp,MOT[pos].mnemonic);
	for(i=0;i<tt_ptr;i++)
	{
		if(strcmp(temp,TT[i].terminal)==0)
		flag=1;
	}
	
	if(!flag)
	strcpy(TT[tt_ptr++].terminal,temp);
}
*/


void addtoterminal(int pos)
{
	int flag=0,i;
	char temp[20];
	strcpy(temp,MOT[pos].mnemonic);
	for(i=0;i<tt_ptr;i++)
	{
		if(strcmp(TT[i].terminal,temp)==0)
			flag=1;
	}
	if(!flag)
	strcpy(TT[tt_ptr++].terminal,temp);
}
void addtoliteral(char s1[])
{
	int i;
	int flag=0;
	for(i=0;i<lt_ptr;i++)
	{
		if(strcmp(s1,LT[i].literal)==0)
		flag=1;
	}
	
	if(!flag)
	strcpy(LT[lt_ptr++].literal,s1);
}



void addtoidentifier(char s1[])
{
	int i;
	int flag=0;
	for(i=0;i<it_ptr;i++)
	{
		if(strcmp(s1,IT[i].identifier)==0)
		flag=1;
	}
	
	if(!flag)
	strcpy(IT[it_ptr++].identifier,s1);
}







/*

void main()
{
	char filename[20];
	char *data;
	int offset;
	char newline[30];
	FILE *fp;
	int pos;
	
	
	printf("\nEnter file name:");
	scanf("%s",filename);
	
	fp = fopen(filename,"r");
	
	int i;
	
	while(!feof(fp))
	{
		i=0;
		newline[i] = fgetc(fp);
		while(newline[i]!='\n' && newline[i]!=EOF)
		{
			i++;
			newline[i] = fgetc(fp);
		}
		newline[i] = '\0';
		
		data = newline;
		while(sscanf(data,"%s%n",s1,&offset)==1)
		{
			data += offset;
		pos = search_MOT(s1);
		
		if(pos!=-1)
		{
			addtoterminal(pos);
			strcpy(UST[ust_ptr].token,s1);
			strcpy(UST[ust_ptr].class,"terminal");
			ust_ptr++;
		}    
		
		
		
		
		else
		{
			if(isalpha(s1[0]))
			{
				addtoidentifier(s1);
				strcpy(UST[ust_ptr].token,s1);
				strcpy(UST[ust_ptr].class,"identifier");
				ust_ptr++;
			}
			
			
			else
			{
				addtoliteral(s1);
				strcpy(UST[ust_ptr].token,s1);
				strcpy(UST[ust_ptr].class,"literal");
				ust_ptr++;	
			}
			
		}
		
		
		
	}

	}
	
		printf("\nTerminal table:");
		print_terminal();
		printf("\nidentifier table");
		
		print_id();
		printf("\nliteral table");
		
		print_literal();
		printf("\nuniform symbol table");
		print_ust();
}

*/












int main()
{
	//UST ust[100];
	int u=0;
	char file1[40],nextline[80],s1[20];
	char *data;
	int x,len,i,j,temp,errortype,offset;
	FILE *ptr1;
	ptr1=fopen("sample.c","r");
	while(!feof(ptr1))
	{
	//Read a line of assembly program and remove special characters
		i=0;
		nextline[i]=fgetc(ptr1);
		while(nextline[i]!='\n'&& nextline[i]!=EOF )
		{
			i++;
			nextline[i]=fgetc(ptr1);
		}
		nextline[i]='\0';
		data=nextline;
		while(sscanf(data,"%s%n",s1,&offset)==1)
		{
			data +=offset;
			int pos=search_MOT(s1);
			
			if(pos!=-1)
			{
				addtoterminal(pos);
				strcpy(UST[u].token,s1);
				strcpy(UST[u].class,"terminal");
				u++;
				
			}
			else
			{
				if(isalpha(s1[0]))
				{
					addtoidentifier(s1);
					strcpy(UST[u].token,s1);
					strcpy(UST[u].class,"identifier");
					u++;
				}
				else
				{
				 	addtoliteral(s1);
				 	strcpy(UST[u].token,s1);
				 	strcpy(UST[u].class,"literal");
					u++;
				}
			}
		}
	}
	printf("Terminal table");
	print_terminal();
	printf("\nIdentifier Table\n");
	print_id();
	printf("\nLiteral Table\n");
	print_literal();
	
	printf("\nuniform symbol table\n:");
	print_ust();
	printf("\n\n");
	/*
	printf("\n\n\nUST\n\n\n");
	for(x=0;x<u;x++)
	{
		printf("%s\t%s\n",ust[x].token,ust[x].class);
	}*/
}








