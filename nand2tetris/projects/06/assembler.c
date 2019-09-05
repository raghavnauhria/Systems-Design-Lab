#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
typedef struct table
{	
	char ch[100];
	int address;
	struct table *next;
}symbol;

int main()
{
	FILE *f=fopen("t.asm","r");
	FILE *fp=fopen("out.asm","w");
	FILE *fpp=fopen("loop.asm","w+");
	//FILE *fppp=fopen("loop.asm","r");
	assert(f != NULL);
	assert(fp != NULL);
	assert(fpp != NULL);
	char s[500];
	char * ptr = fgets(s,500,f);
	int n=0;
	symbol * symbol_table = malloc(sizeof(symbol)*1) ;
	symbol *head = symbol_table;
	int addrs = 16;
	while (ptr != NULL)
	{
		int flag=0;
		if(s[0] != '/')
		{
			
			if (s[0] == ' ')
			{
				int i=0;
				while (s[i] == ' ')
				{
					i++;
				}
				char str[500];
				int j=0;
				while (s[i] != ' ')
				{
					str[j] = s[i];
					j++;i++;
				}
				
				str[j] = '\0';
				if(str[0]!='@')
				{
					//printf("%s\n",str);
					fprintf(fp,"%s\n",str);
					n++;
				}
				else
				{
					symbol *temp = symbol_table;
					while (temp != NULL)
					{assert(temp != NULL);
						if (strcmp(temp->ch,str+1) == 0)
						{
							//temp->address=n;
							break;
						}
						//printf("symbol  = %s   %d \n ",head->ch,head->address);
						temp = temp->next;
					}
					
					if (temp == NULL || strcmp(temp->ch,str+1) != 0)
					{
						//assert(temp != NULL);
						char st[100];
						while (fgets(st,100,fpp))
						{	printf("kj\n");
							//fgets(st,100,fpp);
							if(strcmp(st,temp->ch)==0){
								char x[10];
								fgets(x,10,fpp);
								int y=atoi(x);
								temp->address=y;
								flag=1;
								break;
							}
						}
						if(flag==0){
						//printf("k\n");
						strcpy(head->ch,str+1);
						head->address = addrs;
						addrs++;
						}
					
					head->next  = malloc(sizeof(symbol)*1);
					head = head->next;
					
					}
					
					//printf("jjjjjjjjjjjjjjjjjjjj\n");
					//printf("%s",str);
					fprintf(fp,"%s",str);
					n++;
				}
			}
			else if(s[0] == '(')
			{
				int l=strlen(s);
				s[l-3]='\0';
				//printf("%s\n",s+1);
				fprintf(fpp,"%s\n%d\n",s + 1,n);
			}
		}
		ptr = fgets(s,500,f);
	}
	head->next = NULL;
	fclose(f);
	fclose(fp);
	fclose(fpp);
	head = symbol_table;
	
	while (head->next != NULL)
	{
		printf("%s %d\n",head->ch,head->address);
		head = head->next;
	}
	
	/*printf("\n");
	fp=fopen("out.asm","r");
	fpp=fopen("loop.asm","r");
	printf("address %d\n",addrs);
	head = symbol_table;
	
	
	assert(fp != NULL);
	assert(fpp != NULL);
	
	ptr = fgets(s,500,fp);
	int t=10;   //size of symbol table
	int no=0;    //no of symbols
	char *sym=(char*)malloc(sizeof(char)*50*t);
	char *add=(char*)malloc(sizeof(char)*30*t);
	
	 
	
	while (ptr != NULL)
	{
		if(ptr[0]=='@')
		{
			int l=strlen(ptr+1);
			*(ptr + 1 + l-1)='\0';
			int r=0;		//to compare in symbol table
			while(strcmp(ptr+1,sym+50*r)!=0 && r<no)
			{puts(sym+50*r);puts(ptr+1);
				r++;
			}puts("hii\n\n");
			if(strcmp(ptr+1,sym+50*r)==0 && r<no)
			{
				printf("ddddd\n");
			}
			else
			{
				
				
				if(t==no)
				{
					t=t*2;
					sym=realloc(sym,50*t);
					add=realloc(add,30*t);
				}
				int len=strlen(s+1);
				char *ch=s+1;
				ch[len-1]='\0';
				strcpy(sym+50*no,s + 1);
				ch=add+30*no;
				int temp=16 + no;
				int i;
				for(i=15;i>=0;i--)
				{
					ch[i]=temp%2+'0';
					temp=temp/2;
				}
				ch[i]='\0';
				no++;
			}
		}
		ptr = fgets(s,500,fp);
	}
	
	
	for(int i=0;i<no;i++)
	{
	puts("sssss");
		//puts(sym+50*i);
		puts(add+30*i);
	}
	
	free(sym);
	free(add);
	
	fclose(fp);
	fclose(fpp);*/
	return 0;
}
