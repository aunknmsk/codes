%token WHILE NUM ID
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS
%%

S : WHILE{funct1();} '(' E ')'{funct2();} E ';'{funct3();}
  ;
E : V '=' {push();} E{codegen_assign();}
  | E '+' {push();} E{codegen();}
  | E '-' {push();} E{codegen();}
  | E '*' {push();} E{codegen();}
  | E '/' {push();} E{codegen();}
  | V
  | '(' E ')'
  | NUM{push();}
  | '-' {push();} E{codegen_uminus();} %prec UMINUS
  ;
V : ID{push();}
  ;
%%

#include "lex.yy.c"
#include <ctype.h>

int lnum=1;
int start=1
char subscript[3] = "0";
char temp[3] = "t";
int top=0;
char stack[100][10];
main()
{
	printf("\nEnter the expression:");
	yyparse();
}

push()
{
	strcpy(stack[top++],yytext);
}

codegen_uminus()
{
	strcpy(temp,"t");
	strcat(temp,subscript);
	printf("%s = -%s ",temp,stack[top]);
	top = top-1;
	strcpy(stack[top],temp);
	subscript[0]++;
}

codegen()
{
	strcpy(temp,"t");
	strcat(temp,subscript);
	printf("%s = %s %s %s",temp,stack[top-2],stack[top-1],stack[top]);
	top = top-2;
	strcpy(stack[top],temp);
	subscript[0]++;
}


codegen_assign()
{
	printf("\n%s = %s",stack[top-2],stack[top]);
	top=top-2;
}

funct1()
{
	printf("\nL%d",lnum++);
}

funct2()
{
	strcpy(temp,"t");
	strcat(temp,subscript);
	printf("\n%s =not %s",temp,stack[top]);
	printf("\nif %s goto L%d",temp,lnum);
	subscript[0]++;
}


funct3()
{
	printf("\ngoto L%d",start);
	printf("\nL%d",lnum);
}











