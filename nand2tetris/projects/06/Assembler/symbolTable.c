#include <stdio.h>										
#include <stdlib.h>	
#include <string.h>									
#include "symbolTable.h"

int contains(node* head, char* sym)
{
	int found = 0;
	while(head != NULL)
	{
		if(strcmp(head -> symbol, sym) == 0)
		{
			found = 1;
			break;
		}
		head = head -> next;
	}
	return found;
}

node* addEntry(node* head, char* sym, int add)
{
	if(contains(head, sym) == 0)
	{
		node* newNode = (node*)malloc(sizeof(node));
		strcpy(newNode -> symbol, sym);
		newNode -> address = add;
		newNode -> next = head;
		return newNode;
	}
	else
		return head;
}

int getAddress(node* head, char* sym)
{
	if(contains(head, sym) == 0)
		return -1;
	else
	{
		while(head != NULL)
		{
			if(strcmp(head -> symbol, sym) == 0)
				return head -> address;

			head = head -> next;
		}	
	}
}

void constructor(node** head)
{
	*head = addEntry(*head, "SP", 0);
	*head = addEntry(*head, "LCL", 1);
	*head = addEntry(*head, "ARG", 2);
	*head = addEntry(*head, "THIS", 3);
	*head = addEntry(*head, "THAT", 4);
	*head = addEntry(*head, "R0", 0);
	*head = addEntry(*head, "R1", 1);
	*head = addEntry(*head, "R2", 2);
	*head = addEntry(*head, "R3", 3);
	*head = addEntry(*head, "R4", 4);
	*head = addEntry(*head, "R5", 5);
	*head = addEntry(*head, "R6", 6);
	*head = addEntry(*head, "R7", 7);
	*head = addEntry(*head, "R8", 8);
	*head = addEntry(*head, "R9", 9);
	*head = addEntry(*head, "R10", 10);
	*head = addEntry(*head, "R11", 11);
	*head = addEntry(*head, "R12", 12);
	*head = addEntry(*head, "R13", 13);
	*head = addEntry(*head, "R14", 14);
	*head = addEntry(*head, "R15", 15);
	*head = addEntry(*head, "SCREEN", 16384);
	*head = addEntry(*head, "KBD", 24576);
}