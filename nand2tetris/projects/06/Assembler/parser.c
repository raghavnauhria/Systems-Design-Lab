#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeSpaces(char* raw)		//removes spaces and comments
{
	int i, j=0;
	char *formatted = (char*)malloc(100*sizeof(char));
	for(i=0; raw[i]!='\0'; i++)
	{
		if(raw[i] == '/')
			break;
		if(raw[i] != ' ' && raw[i] != '\t' && raw[i] != '\r' && raw[i] != '\n')
			formatted[j++] = raw[i];
	}
	formatted[j] = '\0';
	return formatted;
}

//remember to check for null strings

char commandType(char* str)
{
	if(str[0] == '@')
		return 'A';
	else if (str[0] == '(')
		return 'L';
	else
		return 'C';
}

char* symbol(char* str)
{
	int i,j=0;
	char *value = (char*)malloc(100*sizeof(char));

	for(i=1; str[i] != '\0'; i++)
		if(str[i] != ')')
			value[j++] = str[i];

	value[j] = '\0';
	return value;
}

char* dest(char* str)
{
	int i,j=0;
	char *destination = (char*)malloc(5*sizeof(char));

	for(i=0; str[i]!='\0'; i++)
		if(str[i] == '=')
		{
			j=1;
			break;
		}	

	if(j==0)
		strcpy(destination, "null");
	else
	{
		j=0;
		for(i=0; str[i]!='='; i++)
			destination[j++] = str[i];
		destination[j] = '\0';
	}
	return destination;
}

char* comp(char* str)
{
	int start=0, end=strlen(str)-1,i,j=0;
	char *computation = (char*)malloc(5*sizeof(char));
	
	for(i=0; str[i]!='\0'; i++)
		if(str[i] == '=')
		{
			start=i+1;
			break;
		}

	for(i=0; str[i]!='\0'; i++)
		if(str[i] == ';')
		{
			end=i-1;
			break;
		}

	for(i=start; i<=end; i++)
		computation[j++] = str[i];
	computation[j] = '\0';
	return computation;
}

char* jump(char* str)
{
	int i,j=0,k=0;
	char *jumping = (char*)malloc(5*sizeof(char));

	for(i=0; str[i]!='\0'; i++)
		if(str[i] == ';')
		{
			j=i+1;
			break;
		}	

	if(j==0)
		strcpy(jumping, "null");
	else
	{
		for(i=j; str[i]!='\0'; i++)
			jumping[k++] = str[i];
		jumping[k] = '\0';
	}
	return jumping;
}