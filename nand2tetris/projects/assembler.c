#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct table
{	
	char *ch;
	int address;
	struct table *next;
}symbol;
symbol *head, *tail;

char *print1(char *ch)
{
	//printf("%s\n",ch);
	int k;
	for(k=1;ch[k]!='\0';k++){}
	//printf("%d",k);
	int size=k;
	//printf("%d\n",size);
	int n=0,i;
	for(int i=size-1;i>=0;i--){
		n+=(ch[i]-48)*pow(10,size-1-i);
	}
	printf("%d\n",n);
	char *bc;
	bc=(char *)malloc(16*sizeof(char));
	//bc[0] = ch[0];
	int j=15;
    while(n>0){
    	//printf("h\n");
        bc[j]=n%2+48;
        printf("%c\n",bc[j]);
        n=n/2;
        j--;
    }
    //printf("%s\n",bc );
    //printf("%d\n",size);
    if(j>0){
    	//printf("r\n");
    	for(int i=j;i>=0;i--)
    		bc[i]=48;
    }
    printf("%s\n",bc );
	return bc;
}
int check_string(char *s1, char *s2)
{
	int count1=strlen(s1);
	int count2=strlen(s2),flag=0;
	for(int i=0;i<=count1-count2;i++)
	{
		for(int j=i;j<i+count2;j++)
		{
			flag=1;
			if (s1[j]!=s2[j-i])
			{
				flag=0;
				break;
			}
		}
		if (flag==1)
			break;
	}
	if (flag==1)
		return 1;
	else
		return 0;
}
void comp(char *ch, char *bc, int *flag)
{
	if(ch[0]=='M' || ch[1]=='M' || ch[2]=='M')
		bc[3]='1';
	else
		bc[3]='0';
	for(int i=0;i<4;i++)
		bc++;
	if(check_string(ch,";")==1){
		
		*flag=1;
		if(ch[0]=='0')
			strcpy(bc,"101010");
		else if(ch[0]=='D')
			strcpy(bc,"001100");
		else if(ch[0]=='A' || ch[0]=='M')
			strcpy(bc,"110000");
	}
	else{
		for(int i=0;i<2;i++)
			ch++;
		if(strcmp(ch,"0")==0)
			strcpy(bc,"101010");
		else if(strcmp(ch,"1")==0)
			strcpy(bc,"111111");
		else if(strcmp(ch,"-1")==0)
			strcpy(bc,"111010");
		else if(strcmp(ch,"D")==0)
			strcpy(bc,"001100");
		else if(strcmp(ch,"A")==0 || strcmp(ch,"M")==0)
			strcpy(bc,"110000");
		else if(strcmp(ch,"!D")==0)
			strcpy(bc,"001101");
		else if(strcmp(ch,"!A")==0 || strcmp(ch,"!M")==0)
			strcpy(bc,"110001");
		else if(strcmp(ch,"-D")==0)
			strcpy(bc,"001111");
		else if(strcmp(ch,"-A")==0 || strcmp(ch,"-M")==0)
			strcpy(bc,"110011");
		else if(strcmp(ch,"D+1")==0)
			strcpy(bc,"011111");
		else if(strcmp(ch,"A+1")==0 || strcmp(ch,"M+1")==0)
			strcpy(bc,"110111");
		else if(strcmp(ch,"D-1")==0)
			strcpy(bc,"001110");
		else if(strcmp(ch,"A-1")==0 || strcmp(ch,"M-1")==0)
			strcpy(bc,"110010");
		else if(strcmp(ch,"D+A")==0 || strcmp(ch,"D+M")==0)
			strcpy(bc,"000010");
		else if(strcmp(ch,"D-A")==0 || strcmp(ch,"D-M")==0)
			strcpy(bc,"010011");
		else if(strcmp(ch,"A-D")==0 || strcmp(ch,"M-D")==0)
			strcpy(bc,"000111");
		else if(strcmp(ch,"D&A")==0 || strcmp(ch,"D&M")==0)
			strcpy(bc,"000000");
		else if(strcmp(ch,"D|A")==0 || strcmp(ch,"D|M")==0)
			strcpy(bc,"010101");
	}	
}

void dest(char *ch, char *bc)
{
	for(int i=0;i<10;i++)
		bc++;
	if(check_string(ch,"M")==1)
		strcpy(bc,"001");
	else if(check_string(ch,"D")==1)
		strcpy(bc,"010");
	else if(check_string(ch,"MD")==1)
		strcpy(bc,"011");
	else if(check_string(ch,"A")==1)
		strcpy(bc,"100");
	else if(check_string(ch,"AM")==1)
		strcpy(bc,"101");
	else if(check_string(ch,"AD")==1)
		strcpy(bc,"110");
	else if(check_string(ch,"AMD")==1)
		strcpy(bc,"111");
	else
		strcpy(bc,"000");
}
void jump(char *ch, char *bc)
{
	for(int i=0;i<13;i++)
		bc++;
	if(check_string(ch,"JGT")==1)
		strcpy(bc,"001");
	else if(check_string(ch,"JEQ")==1)
		strcpy(bc,"010");
	else if(check_string(ch,"JGE")==1)
		strcpy(bc,"011");
	else if(check_string(ch,"JLT")==1)
		strcpy(bc,"100");
	else if(check_string(ch,"JNE")==1)
		strcpy(bc,"101");
	else if(check_string(ch,"JLE")==1)
		strcpy(bc,"110");
	else if(check_string(ch,"JMP")==1)
		strcpy(bc,"111");
	else
		strcpy(bc,"000");	
}
char *dec_bin(int n)
{
	char *bc;
	bc=(char *)malloc(16*sizeof(char));
	//bc[0] = ch[0];
	int j=15;
    while(n>0){
    	//printf("h\n");
        bc[j]=n%2+48;
        printf("%c\n",bc[j]);
        n=n/2;
        j--;
    }
    //printf("%s\n",bc );
    //printf("%d\n",size);
    if(j>0){
    	//printf("r\n");
    	for(int i=j;i>=0;i--)
    		bc[i]=48;
    }
    printf("%s\n",bc );
	return bc;
}
int count_add=16;
int addToTable(char *c)
{
	symbol *temp=(symbol *)malloc(sizeof(symbol));
	temp->next=NULL;
	temp->ch=c;
	temp->address=count_add++;
	if(head==NULL){		
		head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
	return temp->address;
}
void ashwin(void)
{
	FILE *f=fopen("Add.asm","r");
	FILE *fp=fopen("new.asm","w");
	FILE *fpp=fopen("loop.asm","w");
	char s[100];
	//char * ptr = fgets(s,100,f);
	int n=0;
	
	if(f == NULL)
	{
		printf("Error! Empty\n");
	}
	
	while (fgets(s, sizeof(s), f))
	{
		if(s[0] != '/')
		{
			if (s[0] == ' ')
			{
				int i=0;
				while (s[i] == ' ')
				{
					i++;
				}
				char str[100];
				int j=0;
				while(i<=100)
					if(s[i] != ' ')
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
				fprintf(fpp,"%s %d\n",s + 1,n);
			}
		}
		//ptr = fgets(s,100,f);
	}
	
	fclose(f);
	fclose(fp);
	fclose(fpp);
}
int main(int argc, char const *argv[])
{
	/*char *d=(char *)malloc(5*sizeof(char));
	strcpy(d,"nipam");
	printf("%s\n",++d );*/
	ashwin();
	FILE *fptr=fopen("new.asm","r");
	if(fptr==NULL){
		printf("error\n");
		return 0;
	}
	FILE *fptr1=fopen("new.hack","w");
	char *ch;
	head=NULL;
	tail=NULL;
	//ashwin();
	ch=(char *)malloc(10*sizeof(char));
	while(!feof(fptr)){
		//fscanf(fptr,"%s",ch);
		//printf("%s\n",ch);
		fscanf(fptr,"%s",ch);
		char *bc;
		int flag=0;
		bc=(char *)malloc(16*sizeof(char));
		if(ch[0]=='@'){
			//printf("a\n");
			ch[0]='0';
			if(isalpha(ch[1])){
				printf("asd\n");
				int add=addToTable(++ch);
				printf("add=%d\n",add);
				bc=dec_bin(add);
			}
			else
				strcpy(bc,print1(ch));
			//printf("%s\n",bc);
		}
		
		else{
			//printf("c\n");
			bc[0]='1';bc[1]='1';bc[2]='1';
			comp(ch,bc,&flag);
			if(flag==0){
				dest(ch,bc);
			}
			else{
				bc[10]='0';bc[11]='0';bc[12]='0';
			}
			jump(ch,bc);
			//printf("%s\n",bc);
			//strcpy(bc,print(ch));

		}
		fprintf(fptr1,"%s\n",bc);
	}
	fclose(fptr);
	fclose(fptr1);
	return 0;
}
