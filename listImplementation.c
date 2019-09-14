#include "waitingList.h"

//--------------------------------------------------------------------------------------------------------------
//This function adds a new node at the end of the list. It does not return anything. It uses pass by reference to reflect the changes.
void addToList(pGroup* head, char* name, int size, groupStatus status)
{
	pGroup newNode = (pGroup) malloc (sizeof(group));	//Allocate memeory for newNode
	//Set the values for the newly created node.
	newNode->name = name;								
	newNode->groupSize = size;
	if(status == inRestaurant) {
		newNode->status = inRestaurant;
	}
	else {
		newNode->status = notInRestaurant;
	}
	newNode -> pNext = NULL;
	pGroup pLastNode = doFindLastNode(*head);
	if(pLastNode == NULL) {					//Check if last node in the list is null.
		*head = newNode;				//If yes then make the head point to the new node.
		return;
	}
	else {
		pLastNode->pNext = newNode;			//If no then link the last node with the newNode.
		return;
	}
}


//--------------------------------------------------------------------------------------------------------------
//Checks if the name given by the user is already present in the list. 
//This function returns a boolean value of TRUE is name is present. It returns FALSE otherwise.
boolean doesNameExist(pGroup head, char *name)
{
	if(head == NULL) {					//Check if list is empty
		return FALSE;
	}
	while(head != NULL) {					//Loop until end of the list is reached.
		if(strcmp(head->name, name) == 0) {		//Return true if the given name is already present in the list
			return TRUE;
		}
		head = head->pNext;
	}
	return FALSE;
}


//-------------------------------------------------------------------------------------------------------------------------
//It changes the status to inRestaurant when a call-ahead group arrives at the restaurant.
//It returns a boolean value of TRUE when the status is updated, else it returns FALSE.
boolean updateStatus(pGroup head, char *name, int debugMode)
{
	char* status;
	if(head == NULL) {							//Check if list is empty.
		printf("List is empty. Status cannot be updated.\n");
		return FALSE;
	}
	if(debugMode == TRUE) {
		printf("DEBUG MODE:\n\tName\tSize\tStatus\n");
	}
	while(head != NULL) {					//Loop until the pointer does not point to NULL
		if(strcmp(head->name, name) == 0){		//Compare the names stored in the list with the name entered by user.
			if(head->status == inRestaurant){
				printf("The customer is already waiting in the restaurant.");
				if(debugMode == TRUE) {
					status = doPrintStatus(head);
					printf("%s\t%d\t%s\n",head->name, head->groupSize, status);
				}
				return FALSE;
			}
			else{
				head->status = inRestaurant;	//Update the status if the custoner was notInRestaurant to inRestaurant. 
				if(debugMode == TRUE) {
					status = doPrintStatus(head);
					printf("%s\t%d\t%s\n",head->name, head->groupSize, status);
				}
				printf ("Call-ahead group \"%s\" is now waiting in the restaurant\n", head->name);
				return TRUE;
			}
		}
		head = head->pNext;
	}
	return FALSE;
}


//---------------------------------------------------------------------------------------------------------------------------
//It finds the first in-restaurant group that can fit at a given table. It returns the name of the group that was removed. 
char* retrieveAndRemove(pGroup *head, int tableSize, int debugMode)
{
	//char* status;
	char* groupRetrieved = "No group";					//Stores the name of the group removed.
	pGroup curr = *head;
	if(curr == NULL){
		printf("List is empty.\n");
		return groupRetrieved;
	}
	if(curr->groupSize <= tableSize && curr->status == inRestaurant){ 	//Check if the first node can fit at a given table.
		*head = (*head)->pNext;
		groupRetrieved = curr->name;
		free(curr);														//deallocating memory for the node removed.
		return groupRetrieved;
	}
	
	while(curr->pNext != NULL)			//Loop until the second last element.
	{	
	//	if(debugMode == TRUE) {
	//		printf("DEBUG MODE in retrieveAndRemobe\n\tName\tSize\tStatus\n");
	//		status = doPrintStatus(curr);
	//		printf("%s\t%d\t%s\n", curr->name, curr->groupSize, status);
	//	}
		if((curr->pNext->groupSize <= tableSize) && (curr->pNext->status == inRestaurant)) {
			curr->pNext = curr-> pNext -> pNext;
			groupRetrieved = curr->pNext->name;
			free(curr->pNext);		//deallocating memory for the node removed.
			return groupRetrieved;
		}
		curr = curr->pNext;
	}
	printf("No group can be allocated a table\n");
	return groupRetrieved;
}


//----------------------------------------------------------------------------------------------------------------------------
//It counts the number of groups which are waiting ahead of a group with a specific name. It returns an integer value.
int countGroupsAhead(pGroup head, char* name, int debugMode)
{	
	char* status;
	if(debugMode == TRUE){
		printf("DEBUG MODE IN CountGroupsAhead\n#\tName\tSize\tStatus\n");
	}
	if(head == NULL)
		{ return 0; }
	int numberOfGroups = 0;
	while(head != NULL){
		if(debugMode == TRUE) {
			status = doPrintStatus(head);
			printf("%s\t%d\t%s\n\n",head->name, head->groupSize, status);
		}
		if(strcmp(head -> name, name) == 0){
			return numberOfGroups;
		}
		numberOfGroups++;
		head = head->pNext;
	}
	return 0;
}


//----------------------------------------------------------------------------------------------------------------------------
//It traverses until a specific group name and prints out the group's name and size until that specific group name. 
//It does not return anything.
void displayGroupSizeAhead(pGroup head, int groupsAhead)
{	
	int numOfGroups = 0;
	if(head == NULL){
		printf("List is empty.\n");
		return;
	}
	if(numOfGroups == groupsAhead){
		printf("It is first group on the list.\n");
		return;
	}
	printf("\tName\tSize\n");
	int i;
	for(i=1; i<=groupsAhead; i++){
		printf("%d\t%s\t%d\n", i, head->name, head->groupSize);
		head = head->pNext;
		numOfGroups++;
	}
	return;
}


//------------------------------------------------------------------------------------------------------------------------------
//It traverses through the entire list and prints out the group name, size and the group's status. It does not return anything.
void displayListInformation(pGroup head)
{
	int index = 1;
	char *status;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	printf("\tName\tSize\tStatus\n");
	while(head != NULL){
		status = doPrintStatus(head);
		printf("%d\t%s\t%d\t%s\n", index, head->name, head->groupSize, status);
		index++;
		head = head -> pNext;
	}
	return;
}




