/* ========================================================================== */
/*                                                                            */
/*   linkedListmain.c                                                         */
/*   (c) 2019 Ciaran Morgan                                                   */
/*                                                                            */
/*   Implementation of a double linked list                                   */
/*                                                                            */
/*   Added extra test for mid list insertion                                  */
/*                                                                            */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>


#include "linkedList.h"


int main() 
{
	
	Linkedlist	myList;
	Node 		*current;
	
	printf("Initialising lists.....\n");
	
	listInitialise(&myList);
	
	listAddHead(&myList, "Start of the main list");
	listAddTail(&myList, "Middle of the main list");
	listAddTail(&myList, "End of the main list");
	
	listAddHead(&myList, "New Start of the main list");
	
	listAddHead(&myList, "New New Start of the main list");


	printf("Listing data from the head....\n");
	
	current = myList.listHead;
	while (current != NULL)
	{
		printf("Head List: data stored is %s\n", current->data);
		current = current->nextnode;
	}

	listAddTail(&myList, "This is the tail");
	

	printf("\n\nListing data from the tail....\n");

	current = myList.listTail;
	while (current != NULL)
	{
		printf("Tail List: data stored is %s\n", current->data);
		current = current->prevnode;
	}
    
    printf("\nAdding an item to the middle.\n");
    
    int     c = 0;
    
    current = myList.listHead;
	while (current != NULL)
	{
		// Cycle through data to get the middle node 
        c++;
        if (c > 2) {
            // Stopping in the middle of the list
            break;
        }
		current = current->nextnode;
	}
	
    listInsertNode(&myList, "This has been inserted", current);
    
    current = myList.listHead;
	while (current != NULL)
	{
		printf("Data stored is %s\n", current->data);
		current = current->nextnode;
	}

	return EXIT_SUCCESS;
}
