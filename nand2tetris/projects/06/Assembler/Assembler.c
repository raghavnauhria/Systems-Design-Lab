#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "symbolTable.h"

int main(int argc, char* argv[])
{
	char* filename = argv[1];
	FILE* fin = fopen(filename,"r");

	char fileout[strlen(filename)+2];
	strcpy(fileout, filename);

	int i, n=strlen(filename), ctr=0;
	
	fileout[n-3] = 'h';
	fileout[n-2] = 'a';
	fileout[n-1] = 'c';
	fileout[n] = 'k';
	fileout[n+1] = '\0';
	FILE* fout = fopen(fileout,"w");
	
	char* asmline = (char*)malloc(100*(sizeof(char)));
	size_t asmsize = 100;

	node* head = NULL;
	constructor(&head);

	while(getline(&asmline,&asmsize,fin)>=0)
	{
		char* rawline = removeSpaces(asmline);

		if(strlen(rawline)==0)
			continue;

		char typ = commandType(rawline);
		
		if(typ == 'C' || typ == 'A')
		{
			ctr++;
		}
		else if(typ == 'L')
		{
			char* value = symbol(rawline);
			head = addEntry(head,value,ctr);
		}
	}

	fseek(fin, 0, SEEK_SET);
	
	ctr = 16;
	
	while(getline(&asmline,&asmsize,fin)>=0)
	{
		char* rawline = removeSpaces(asmline);
		
		if(strlen(rawline)==0)
			continue;
		
		char typ = commandType(rawline);
		if(typ == 'A')
		{
			int addr = ctr;
			char* value = symbol(rawline);
			if(isalpha(value[0]))
			{
				if(!contains(head, value))
				{
					//addr = 16;
					//if(!strcmp(value,"math.1"))addr = 17;
					head = addEntry(head, value, addr);
					printf("%s %d\n",value,addr);
					ctr++;
				}
				else
				{
					addr = getAddress(head, value);
				}
			}
			else
			{
				addr = atoi(value);
			}
			
			char mcode[17];
			mcode[16]='\0';
			for(i=15; i>=0; i--)
			{
				mcode[i] = '0'+addr%2;
				addr/=2;
			}
			fprintf(fout,"%s\n",mcode);
		}
		else if(typ == 'C')
		{
			char* ccode = compcode(comp(rawline));
			char* dcode = destcode(dest(rawline));
			char* jcode = jumpcode(jump(rawline));
			char mcode[17];
			mcode[0] = '\0';
			strcat(mcode,"111");
			strcat(mcode,ccode);
			strcat(mcode,dcode);
			strcat(mcode,jcode);
			fprintf(fout,"%s\n",mcode);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}