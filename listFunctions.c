#include "waitingList.h"

//-------------------------------------------------------------------------------------------
//It checks the status of the node and prints out the corresponding status. It returs char* 
//This is a helper function which helps to print out status in debug mode.
char* doPrintStatus(pGroup head)
{
	char* status;
	if(head->status == inRestaurant) {
		status = "In Restaurant";
		return status;
	}
	else{
		status ="Not In Restaurant";
		return status;
	}
}


//--------------------------------------------------------------------------------------------------------------
//This is a helper function which traverses the list to find the last node. It returns the last node.
pGroup doFindLastNode(pGroup pLastNode)
{	
	//Loop until the second last node is reached.
	while((pLastNode != NULL) && (pLastNode->pNext != NULL)) {
		pLastNode = pLastNode->pNext;	  //Use pNext to reach last node from second last node.
	}
	return pLastNode;					
}


//--------------------------------------------------------------------------------------------------------------------
//If command 'a <size> <name>' is entered, this function gets the name and size of the group and calls the addToList()
//It does not return anything.
void doAdd (pGroup* head)
{
 	/* get group size from input */
 	int size = getPosInt();
 	if (size < 1) {
    	printf ("Error: Add command requires an integer value of at least 1\n");
    	printf ("Add command is of form: a <size> <name>\n");
    	printf ("  where: <size> is the size of the group making the reservation\n");
    	printf ("         <name> is the name of the group making the reservation\n");
    	return;
  	}

 	/* get group name from input */
 	char *name = getName();
	if (NULL == name) {
    	printf ("Error: Add command requires a name to be given\n");
    	printf ("Add command is of form: a <size> <name>\n");
    	printf ("  where: <size> is the size of the group making the reservation\n");
    	printf ("         <name> is the name of the group making the reservation\n");
    	return;
  }
   
	if(doesNameExist(*head, name) == TRUE) {
		printf("Name already exists in the list.\n");
		return;
 	}
 	else {
 		printf("Adding In-restaurant group \"%s\" of size %d\n", name, size);
		addToList(head, name, size, inRestaurant);
		return;
 	}
}


//--------------------------------------------------------------------------------------------------------------------
//If command 'c <size> <name>' is entered, this function gets the name and size of the group and calls the addToList()
//It does not return anything.
void doCallAhead (pGroup* head)
{
 	/* get group size from input */
 	int size = getPosInt();
 	if (size < 1) {
    	printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    	printf ("Call-ahead command is of form: c <size> <name>\n");
    	printf ("  where: <size> is the size of the group making the reservation\n");
    	printf ("         <name> is the name of the group making the reservation\n");
    	return;
   }

 	/* get group name from input */
 	char *name = getName();
 	if (NULL == name) {
    	printf ("Error: Call-ahead command requires a name to be given\n");
    	printf ("Call-ahead command is of form: c <size> <name>\n");
    	printf ("  where: <size> is the size of the group making the reservation\n");
    	printf ("         <name> is the name of the group making the reservation\n");
    	return;
   	}

	if(doesNameExist(*head, name) == TRUE) {
		printf("Name already exists in the list.\n");
 		return;
	}
	else{
		printf ("Adding Call-ahead group \"%s\" of size %d\n", name, size);
		addToList(head, name, size, notInRestaurant);
		return;
	}
}


//--------------------------------------------------------------------------------------------------------------------------
//If command 'w <name>' is entered, this function gets the name and updates the status of call ahead group.
void doWaiting (pGroup head, int debugMode)
{
	/* get group name from input */
 	char *name = getName();
 	if (NULL == name) {
    	printf ("Error: Waiting command requires a name to be given\n");
    	printf ("Waiting command is of form: w <name>\n");
    	printf ("  where: <name> is the name of the group that is now waiting\n");
    	return;
  }
	if(doesNameExist(head, name) == FALSE){
		printf("Name does not exist in the list");
		return;
	}
	if(updateStatus(head, name, debugMode) == TRUE){
		return;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------
//If command 'r <size>' is entered, this function gets the size and calls the retrieveAndRemove().
void doRetrieve (pGroup *head, int debugMode)
{
	 /* get table size from input */
 	int size = getPosInt();
 	if (size < 1) {
    	printf ("Error: Retrieve command requires an integer value of at least 1\n");
    	printf ("Retrieve command is of form: r <size>\n");
    	printf ("  where: <size> is the size of the group making the reservation\n");
    	return;
  }
 	clearToEoln();
 	char* groupRemoved;							
 	groupRemoved = retrieveAndRemove(head, size, debugMode);		//Store the value returned by retrieveAndRemove() in a char* variable.
 	if(strcmp(groupRemoved, "No group") != 0) {
 		printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);
 		printf("The group named  \"%s\" was removed.", groupRemoved);
 	}
 	return;
}


//-----------------------------------------------------------------------------------------------------------------------------
//If command 'l <name>' is entered, this function gets the name and calls the displayGroupSizeAhead().
void doList (pGroup head, int debugMode)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name) {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
 }

 if(doesNameExist(head, name) == YES) {
		printf("Number of groups ahead of \"%s\": %d\n", name, countGroupsAhead(head, name, debugMode));
		displayGroupSizeAhead(head, countGroupsAhead(head, name, debugMode));
		return;
 }
else{
		printf("Name does not exist in list\n");
		return;
	}
}


//---------------------------------------------------------------------------------------------------------------------------
//It displays information of all groups by calling displayListInformation().
void doDisplay (pGroup head)
{
 	clearToEoln();
 	printf ("Display information about all groups\n");
	displayListInformation(head);
}


