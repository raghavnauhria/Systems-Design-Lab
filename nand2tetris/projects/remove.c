#include<stdio.h>
#include<string.h>
#include<ctype.h>
int Empty(char* s)
{
	while(*s != '\0')
	{
		if(!isspace((unsigned char)*s))
			return 0;

		s++;
	}
	return 1;
}
void rags()
{
FILE *f=fopen("Max.asm","r");
FILE *fp=fopen("new.asm","w");
FILE *fpp=fopen("loop.asm","w");
char s[100];

int n=0;

if(f == NULL)
{
	printf("Error! Empty\n");
}

while (fgets(s, sizeof(s), f))
{
	if(s[0] == '/' || Empty(s))
		continue;
	else
	{
		int i=0;
		while (s[i] == ' ')
		{
			i++;
		}

		char str[100];
		int j=0;

		while(s[i] != ' ' && s[i] !='\n')
		{
			str[j] = s[i];
			j++;i++;
		}

		str[j] = '\0';

		if(str[0] == '(')
		{
			fprintf(fpp,"%s%d\n",str,n);
		}
		else if(str[0] != '@')
			{
				fprintf(fp,"%s\n",str);
				n++;
			}
			else
			{
				fprintf(fp,"%s",str);
				n++;
			}
	}
}

fclose(f);
fclose(fp);
fclose(fpp);
}
