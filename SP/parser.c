#include<stdio.h>
#include<string.h>
/*
for productions:
	E-> TE’
	E’-> +TE’ | -TE’ | null
	T-> FT’
	T’-> *FT’| /FT’ | null
	F-> id/ (E)/ num
*/

char input[20],prod[20][20],id,num;
int pos=-1,l,st=-1;
void advance();
void E();
void Ed();
void T();
void Td();
void F();

void advance()
{
	pos++;
	if(pos < l)
	{
		if(input[pos]>='0' && input[pos]<='9')
		{
			num=input[pos];
			id='\0';
		}
		
		if( (input[pos]>='a' || input[pos]>='A') && (input[pos]<='z' || input[pos]<='Z') )
		{
			id=input[pos];
			num='\0';
		}
	}
}

void E()
{
	strcpy(prod[++st],"E->TE'");
	T();
	Ed();
}

void Ed()
{
	int p=1;
	if(input[pos]=='+')
	{
		p=0;
		strcpy(prod[++st],"E'->+TE'");
		advance();
		T();
		Ed();
	}
	
	if(input[pos]=='-')
	{
		p=0;
		strcpy(prod[++st],"E'->-TE'");
		advance();
		T();
		Ed();
	}

	if(p==1)
		strcpy(prod[++st],"E'->NULL");
	
}

void T()
{
	strcpy(prod[++st],"T->FT'");
	F();
	Td();
}

void Td()
{
	int p=1;
	if(input[pos]=='*')
	{
		p=0;
		strcpy(prod[++st],"T'->*FT'");
		advance();
		F();
		Td();
	}

	if(input[pos]=='/')
	{
		p=0;
		strcpy(prod[++st],"T'->/FT'");
		advance();
		F();
		Td();
	}
	
	if(p==1)
		strcpy(prod[++st],"T'->NULL");
}

void F()
{
	if(input[pos]==id)
	{
		char str[10]={"F->"};
		str[3]=id;
		strcpy(prod[++st],str);
		advance();
		
	}
	
	if(input[pos]==num)
	{
		char str[10]={"F->"};
		str[3]=num;
		strcpy(prod[++st],str);
		advance();
	}
	
	if(input[pos]=='(')
	{
		strcpy(prod[++st],"F->(E)");
		advance();
		E();
		if(input[pos]==')')
			advance();
	}
}

int main()
{
	int i;
	printf("Enter Input String\n");
	scanf("%s",input);
	l=strlen(input);
	input[l]='$';
	advance();
	E();
	if(pos==l)
	{
		printf("String Accepted\n");
		for(i=0;i<=st;i++)
			printf("%s\n",prod[i]);
	}
	else
		printf("String not accepted\n");
	return 0;

}
/*output
student@localhost 331041]$ gcc parser.c
[student@localhost 331041]$ ./a.out
Enter Input String
((a+b)
String Accepted
E->TE'
T->FT'
F->(E)
E->TE'
T->FT'
F->(E)
E->TE'
T->FT'
F->a
T'->NULL
E'->+TE'
T->FT'
F->b
T'->NULL
E'->NULL
T'->NULL
E'->NULL
T'->NULL
E'->NULL


*/

