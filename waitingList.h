// Author: Sakina Master  
// Restaurant Waiting List System
// Date: August 2018
   
/* header files to connect the 3 source files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
typedef enum {notInRestaurant = 0, inRestaurant} groupStatus;

//Struct defining group info
typedef struct groupInfo
{
	char *name;
	int groupSize;
	groupStatus status;
	struct groupInfo *pNext;
}group;

typedef group* pGroup;

//Function prototypes
//userInterface.c
void clearToEoln();
int getNextNWSChar();
int getPosInt();
char* getName();
void printCommands();

//listFunctions.c
char* doPrintStatus(pGroup head);       //utility function
pGroup doFindLastNode(pGroup pLastNode);//utility function
void doAdd (pGroup* head);
void doCallAhead (pGroup* head);
void doWaiting (pGroup head, int debugMode);
void doRetrieve (pGroup *head, int debugMode);
void doList (pGroup head, int debugMode);
void doDisplay (pGroup head);

//listImplementation.c
void addToList(pGroup* head, char* name, int size, groupStatus status);
boolean doesNameExist(pGroup head, char *name);
boolean updateStatus(pGroup head, char *name, int debugMode);
char* retrieveAndRemove(pGroup *head, int tableSize, int debugMode);
int countGroupsAhead(pGroup head, char* name, int debugMode);
void displayGroupSizeAhead(pGroup head, int groupsAhead);
void displayListInformation(pGroup head);

