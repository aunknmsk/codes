#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*
struct Mnemonic_table
{
	char mnemonic[10];
	int class;
	char opcode[10];
};


struct Symbol_table
{
	char symbol[10];
	int address;
	int size;
}ST[20];

struct Literal_table
{
	 char literal[5];
	 int address;
	 	
}LT[20];


struct Pool_table
{
	int literal_no;
}PT[20];


struct intermediate_code
{
	int lc;
	int code1,type1;
	int code2,type2;
	int code3,type3;
}IC[30];

int nMOT = 28;
int iST=0;
int iLT=0;
int iIC=0;
int litt_ptr=0;
int pll_ptr=0;
int LC=0;

static struct Mnemonic_table MOT[28]=
{
	{"STOP",1,"00"},{"ADD",1,"01"},{"SUB",1,"02"},
	{"MULT",1,"03"},{"MOVER",1,"04"},{"MOVEM",1,"05"},
	{"COMP",1,"06"},{"BC",1,"07"},{"DIV",1,"08"},
	{"READ",1,"09"},{"PRINT",1,"10"},
	{"START",3,"01"},{"END",3,"02"},{"ORIGIN",3,"03"},
	{"EQU",3,"04"},{"LTORG",3,"05"},
	{"DS",2,"01"},{"DC",2,"02"},
	{"AREG",4,"01"},{"BREG",4,"02"},{"CREG",4,"03"},
	{"EQ",5,"01"},{"LT",5,"02"},{"GT",5,"03"},{"LE",5,"04"},
	{"GE",5,"05"},{"NE",5,"06"},{"ANY",5,"07"}
	
};*/


struct MOTtable
{
	char mnemonic[6];
	int  class;
	char opcode[3];
};

struct symboltable
{
	char symbol[8];
	int  address;
	int  size;
}ST[20];

struct intermediatecode
{
	int lc;
	int code1,type1;
	int code2,type2;
	int code3,type3;
}IC[30];

struct Littable
{
	char literal[7];
	int address;
}LT[10];

struct pooltable
{
	int literal_no;
}PT[10];

static struct MOTtable MOT[28]=
{
	{"STOP",1,"00"},{"ADD",1,"01"},{"SUB",1,"02"},
	{"MULT",1,"03"},{"MOVER",1,"04"},{"MOVEM",1,"05"},
	{"COMP",1,"06"},{"BC",1,"07"},{"DIV",1,"08"},
	{"READ",1,"09"},{"PRINT",1,"10"},
	{"START",3,"01"},{"END",3,"02"},{"ORIGIN",3,"03"},
	{"EQU",3,"04"},{"LTORG",3,"05"},
	{"DS",2,"01"},{"DC",2,"02"},
	{"AREG",4,"01"},{"BREG",4,"02"},{"CREG",4,"03"},
	{"EQ",5,"01"},{"LT",5,"02"},{"GT",5,"03"},{"LE",5,"04"},
	{"GE",5,"05"},{"NE",5,"06"},{"ANY",5,"07"}
};

int nMOT=28; //Number of entries in MOT
int LC=0;    //Location counter
int iST=0;   //Index of next entry in Symbol Table
int iIC=0;   //Index of next entry in intermediate code table
int litt_ptr=0;
int pll_ptr=0;

/*

int search_MOT(char symbol[])
{
	int i=0;
	for(i=0;i<nMOT;i++)
	{
		if(strcmp(MOT[i].mnemonic,symbol)==0)
		return i;
	}
	
	return -1;
}


int search_ST(char symbol[])
{
	int i=0;
	for(i=0;i<iST;i++)
	{
		if(strcmp(ST[i].symbol,symbol)==0)
		return i;
	}
	
	return -1;
}

int isliteral(char symbol[])
{
	if(strchr(symbol,'=')==NULL)
	return 0;
	
	return 1;
}


int insert_ST(char symbol[],int address,int size)
{
	strcpy(ST[iST].symbol,symbol);
	ST[iST].address = address;
	ST[iST].size = size;
	
	iST++;
	return (iST-1);
	
}
*/



int search_ST(char symbol[])
{
	int i;
	for(i=0;i<iST;i++)
		if(strcmp(ST[i].symbol,symbol)==0)
			return(i);
	return(-1);
}

int search_MOT(char symbol[])
{
	int i;
	for(i=0;i<nMOT;i++)
		if(strcmp(MOT[i].mnemonic,symbol)==0)
			return(i);
	return(-1);
}

int insert_ST( char symbol[],int address,int size)
{
       strcpy(ST[iST].symbol,symbol);
       ST[iST].address=address;
       ST[iST].size=size;
       iST++;
       return(iST-1);
}

int isliteral(char symbol[])
{
	if(strchr(symbol,'=')==NULL)
		return 0;
	return 1;
}

void imperative();
void declarative();
void directive();
void display_ST();
void display_LT();
void display_PT();
void display_IC();
void display_MOT();
void DC();
void DS();
void start();
void equ();
void ltorg();
void origin();

char s1[20],s2[20],s3[20],label[20];
void intermediate();
int tokencount=0;


/*
void main()
{
	int i,token_count=0;
	char file_name[20];
	char newline[30];
	FILE *ptr;
	printf("\nEnter file name:");
	scanf("%s",file_name);
	
	ptr = fopen(file_name,"r");
	PT[0].literal_no=0;
	
	while(!feof(ptr))
	{
		i=0;
		newline[i] = fgetc(ptr);
		
		while(newline[i]!='\n' && newline[i]!=EOF)
		{
			if(!isalnum(newline[i]) && newline[i]!='=')
				newline[i] = ' ';
				
			else
				newline[i] = toupper(newline[i]);
				
				i++;
			newline[i] = fgetc(ptr);	
				
		}
		
		newline[i] = '\0';
		sscanf(newline,"%s",s1);
		
		if(strcmp(s1,"END")==0)
		{
			ltorg();
			break;
		}
		
		if(search_MOT(s1)==-1)
		{
			if(search_ST(s1)==-1)
				insert_ST(s1,LC,0);
			
			token_count = sscanf(newline,"%s%s%s%s",label,s1,s2,s3);
			token_count--;
		}
		
		else
			token_count = sscanf(newline,"%s%s%s",s1,s2,s3);
			
			if(token_count == 0)
			continue;
			
		i=search_MOT(s1);
		
		if(i==-1)
		{
			printf("\nWrong opcode!!!");
			continue;
		}
		
		switch(MOT[i].class)
		{
			case 1 :imperative();
				break;
				
			case 2 :declarative();
				break;
				
			case 3 :directive();
				break;
				
			default:printf("\nWrong opcode!!!");
				break; 
		}
		
		
		
	}
	
	display_ST();
		display_MOT();
		display_PT();
		intermediate();
				

}*/

void main()
{

char file1[40],nextline[80];
	int len,i,j,temp,errortype;
	FILE *ptr1;
	printf("\nenter Source file name:");
	scanf("%s",file1);
	ptr1=fopen(file1,"r");
	
	PT[0].literal_no=0;
	while(!feof(ptr1))
	{
	//Read a line of assembly program and remove special characters
		i=0;
		nextline[i]=fgetc(ptr1);
		while(nextline[i]!='\n'&& nextline[i]!=EOF )
		{
			if(!isalnum(nextline[i]) && nextline[i]!='=')
				nextline[i]=' ';
			else
				nextline[i]=toupper(nextline[i]);
			i++;
			nextline[i]=fgetc(ptr1);
		}
		nextline[i]='\0';
		//printf("nextline[]=%s\n",nextline);

		sscanf(nextline,"%s",s1); //read from the nextline in s1
		if(strcmp(s1,"END")==0) //if the nextline is an END statement
		{
			ltorg();
			break;
		}
		//if the nextline contains a label
		if(search_MOT(s1)==-1)
		{
			if(search_ST(s1)==-1)
				insert_ST(s1,LC,0);
		//separate opcode and operands
			tokencount=sscanf(nextline,"%s%s%s%s",label,s1,s2,s3);
			tokencount--;
		}
		else
		//separate opcode and operands
			tokencount=sscanf(nextline,"%s%s%s",s1,s2,s3);
		if(tokencount==0)//blank line
			continue;//goto the beginning of the loop
		i=search_MOT(s1);
		if(i==-1)
		{
			printf("\nWrong Opcode .... %s",s1);
			continue;
		}
		switch (MOT[i].class)
		{
			case 1: imperative();break;
			case 2: declarative();break;
			case 3: directive();break;
			default: printf("\nWrong opcode ...%s",s1);
			break;
		}
	}
/*	print_opcode();
	print_symbol();
	print_lit_pool();
	intermediate();
	//mcode(); */
	display_MOT();
	display_ST();
	display_PT();
	intermediate(); 
	printf("\n");

}

/*
void equ()
{
	int index=search_ST(label),index1;
	if(index==-1)
		index=insert_ST(label,0,0);
	if(isdigit(s2[0])==0)
	{
		index1=search_ST(s2);
		ST[index].address=ST[index1].address;
	}
	else
		ST[index].address=atoi(s2);
	ST[index].size=1;
}*/




void equ()
{
	int index = search_ST(label),index1;
	
	if (index1 == -1)
		index = insert_ST(label,0,0);
	
	if(isdigit(s2[0]) == 0)
	{
		index1 = search_ST(s2);
		ST[index].address = ST[index1].address;
	}
	
	else
		ST[index].address = atoi(s2);
		
	ST[index].size = 1;
		
}

/*
void imperative()
{
	
	int index;
	index=search_MOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0; //intialize
	IC[iIC].lc=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	LC=LC+1;
	if(tokencount>1)
	{
		index=search_MOT(s2);
		//printf("%s\n",s2);
		if(index != -1)
		{
			IC[iIC].code2=index;
			IC[iIC].type2=MOT[index].class;
		}
		else
		{   	//It is a variable
			index=search_ST(s2);
			if(index==-1)
				index=insert_ST(s2,0,0);
			IC[iIC].code2=index;
			IC[iIC].type2=7; //VALUE 7 IS FOR VARIABLES
		}
	}
	
	if(tokencount>2)
	{
		index=search_ST(s3);	// -1 for symbol not defined and literal
		if(isliteral(s3)==0)	//so first check literal	
		{
			if(index==-1)		//symbol undefined
				index=insert_ST(s3,0,0);
			IC[iIC].code3=index;
			IC[iIC].type3=7	; //VALUE 7 IS FOR VARIABLES
		}
		else
		{
			IC[iIC].code3=litt_ptr;
			IC[iIC].type3=8;
			strcpy(LT[litt_ptr].literal,s3);
			litt_ptr++;
			//if literal
		}
	}
	iIC++;
}*/


void imperative()
{
	int index;
	index = search_MOT(s1);
	IC[iIC].type1 = IC[iIC].type2 = IC[iIC].type3 = 0;
	IC[iIC].lc = LC;
	IC[iIC].type1 = MOT[index].class;
	IC[iIC].code1 = index;
	LC = LC+1;
	
	if(tokencount > 1)
	{
		index = search_MOT(s2);
		if (index!=-1)
		{
			IC[iIC].type2 = MOT[index].class;
			IC[iIC].code2 = index;
		}
		
		else
		{
			index = search_ST(s2);
			if (index == -1)
				index = insert_ST(s2,0,0);
			IC[iIC].type2 = 7;
			IC[iIC].code2 = index;
		}
	}
	
	
	if (tokencount > 2)
	{
		index = search_ST(s3);
		if(isliteral(s3)==0)
		{
			if(index==-1)
				index = insert_ST(s3,0,0);
			IC[iIC].type3 = 7;
			IC[iIC].code3 = index;
			
		}
		
		
		else
		{
			IC[iIC].type3 = 8;
			IC[iIC].code3 = litt_ptr;
			strcpy(LT[litt_ptr].literal,s3);
			litt_ptr++;
		}
	}
	
	iIC++;
}


void declarative()
{
	if(strcmp(s1,"DC")==0)
	{
		DC();
		return;
	}
	if(strcmp(s1,"DS")==0)
		DS();
}

void directive()
{
	if(strcmp(s1,"START")==0)
	{
		start();
		return;
	}
	else if(strcmp(s1,"LTORG")==0)
	{
		ltorg();
		return ;
	}
	else if(strcmp(s1,"EQU")==0)
	{
		equ();
		return ;
	}
	else
	{
		origin();
	}
 }

/*
void DC()
{
	int index;
	index=search_MOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0; //intialize
	IC[iIC].lc=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;        //6 IS TYPE FOR CONSTANTS
	IC[iIC].code2=atoi(s2);
	index=search_ST(label);
	if(index==-1)
		index=insert_ST(label,0,0);
	ST[index].address=LC;
	ST[index].size=1;
	LC=LC+1;
	iIC++;
}

void DS()
{
	int index;
	index=search_MOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0; //intialize
	IC[iIC].lc=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;        //6 IS TYPE FOR CONSTANTS
	IC[iIC].code2=atoi(s2);
	index=search_ST(label);
	if(index==-1)
		index=insert_ST(label,0,0);
	ST[index].address=LC;
	ST[index].size=atoi(s2);
	LC=LC+atoi(s2);
	iIC++;
}

*/



void DC()
{
	int index;
	index = search_MOT(s1);
	IC[iIC].type1 = IC[iIC].type2 = IC[iIC].type3 = 0;
	IC[iIC].lc = LC;
	IC[iIC].type1 = MOT[index].class;
	IC[iIC].code1 = index;
	IC[iIC].type2 = 6;
	IC[iIC].code2 = atoi(s2);
	
	index=search_ST(label);
	if(index==-1)
		insert_ST(label,0,0);
	ST[index].address = LC;
	ST[index].size = 1;
	
	LC = LC+1;
	iIC++;
}

void DS()
{
	int index;
	index = search_MOT(s1);
	IC[iIC].type1 = IC[iIC].type2 = IC[iIC].type3 =0;
	IC[iIC].lc = LC;
	IC[iIC].type1 = MOT[index].class;
	IC[iIC].code1 = index;
	IC[iIC].type2 = 6;
	IC[iIC].code2 = atoi(s2);
	
	index = search_ST(label);
	if(index==-1)
		index= insert_ST(label,0,0);
	ST[index].address = LC;
	ST[index].size = atoi(s2);
	LC = LC + atoi(s2);
	iIC++;        
}



void start()
{
	int index;
	index = search_MOT(s1);
	IC[iIC].type1 = IC[iIC].type2 = IC[iIC].type3 = 0;
	IC[iIC].lc = LC;
	IC[iIC].type1 = MOT[index].class;
	IC[iIC].code1 = index;
	IC[iIC].type2 = 6;
	IC[iIC].code2 = atoi(s2);
	
	LC = atoi(s2);
	iIC++;
}

/*
void start()
{
	int index;
	index=search_MOT(s1);
	IC[iIC].type1=IC[iIC].type2=IC[iIC].type3=0; //intialize
	IC[iIC].lc=LC;
	IC[iIC].code1=index;
	IC[iIC].type1=MOT[index].class;
	IC[iIC].type2=6;        //6 IS TYPE FOR CONSTANTS
	IC[iIC].code2=atoi(s2);
	LC=atoi(s2);
	iIC++;
}
*//*
void intermediate()
{
	int i;
	char decode[9][3]={" ","IS","DL","AD","RG","CC","C","S","L"};
	printf("\nIntermediate Code :");
	for(i=0;i<iIC;i++)
	{
		printf("\n%3d)   (%s,%2s)",IC[i].lc,decode[IC[i].type1],MOT[IC[i].code1].opcode);
		if(IC[i].type2!=0)
		{
			if(IC[i].type2<6)
				printf(" (%s,%2s)",decode[IC[i].type2],MOT[IC[i].code2].opcode);
			else
				printf("  (%s,%2d)",decode[IC[i].type2],IC[i].code2);
		}
		if(IC[i].type3!=0)
			printf("  (%s,%2d)",decode[IC[i].type3],IC[i].code3);
	}
}*/




void intermediate()
{
	int i;
	char decode[9][3] = {" ","IS","DL","AD","RG","CC","C","S","L"};
	
	
	for (i=0;i<iIC;i++)
	{
		printf("\n%3d   (%s %2s)",IC[i].lc,decode[IC[i].type1],MOT[IC[i].code1].opcode );
		
		if(IC[i].type2!=0)
		{
			if(IC[i].type2<6)
				printf(" (%s %2s)",decode[IC[i].type2],MOT[IC[i].code2].opcode);
			else
				printf(" (%s %2d)",decode[IC[i].type2],IC[i].code2);
		}
		
		if(IC[i].type3!=0)
		{
			printf(" (%s %2d)",decode[IC[i].type3],IC[i].code3);
		}
	}	
}




void display_ST()
{
	int i;
	printf("\n*******symbol table ***********\n");
	for(i=0;i<iST;i++)
		printf("%10s  %3d   %3d\n",ST[i].symbol,ST[i].address,ST[i].size);
}

void display_MOT()
{
	int i;
	printf("\n***********opcode table *************\n");
	for(i=0;i<nMOT;i++)
		if(MOT[i].class==1)
			printf("%6s   %2s\n",MOT[i].mnemonic,MOT[i].opcode);
}

void display_PT()
{
	int i;
	printf("\n********** LITTAB **************\n");
	for(i=0;i<litt_ptr;i++)
		printf("%s   %d\n",LT[i].literal,LT[i].address);
	printf("\n********** POOLTAB **************\n");
	for(i=0;i<pll_ptr;i++)
		printf("%d\n",PT[i].literal_no);
}
  

/*
void origin()
{
	LC=atoi(s2);
}
  
void ltorg()
{
	int i;
	for(i=PT[pll_ptr].literal_no;i<litt_ptr;i++)
	{
		LT[i].address=LC++;
	}
	pll_ptr++;
	PT[pll_ptr].literal_no=litt_ptr; 
}*/



void origin()
{
	LC = atoi(s2);
}



void ltorg()
{
	int i;
	for(i=PT[pll_ptr].literal_no; i<litt_ptr;i++)
	{
		LT[i].address = LC++;
	}
	
	pll_ptr++;
	PT[pll_ptr].literal_no = litt_ptr;
}
