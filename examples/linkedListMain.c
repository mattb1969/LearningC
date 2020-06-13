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

/* To Compile
 *  gcc -o linkedList linkedListMain.c linkedList.c -Wall
*/

#include <stdlib.h>
#include <stdio.h>


#include "linkedList.h"

/* Some sample code to check why my linked list is not working correctly
 */
void printLinkedlist(struct app_widgets *widget) {
    Node *current;          // Used by the linked lists.
    int count = 0;
    
    printf("Testing Linked List Output\n");
    printf("==========================\n");
   
    printf("qty readings:%d\n", widget->list.qty_readings);
    printf("max reading:%f\n", widget->list.max_reading);
    printf("min reading:%f\n\n", widget->list.min_reading);

    current = widget->list.listHead;

    do {

        printf("Reading:%d  Data:%f\n", count, current->reading);
        current = current->nextnode;
        count ++;
    } while ((count < widget->list.qty_readings));// && (current->nextnode != NULL));
}

void testLinkedlist(struct app_widgets *widget) {
    
    //// Add a new value to the start of the list every time it runs
    listAddHead(&widget->list, 0.1);
    
    printLinkedlist(widget);
    
    listAddHead(&widget->list, 0.2);
    listAddHead(&widget->list, 1.3);
    listAddHead(&widget->list, 2.4);
    listAddHead(&widget->list, 3.5);
    
    printLinkedlist(widget);
    
    
}

/* List Order
 * New New Start of the main list
 * New Start of the main list
 * Start of the main list pt2
 * >>This has been inserted
 * Start of the main list
 * Middle of the main list
 * End of the main list
 * 
 * >>This is the tail
 */
int main() 
{
	
	Linkedlist	myList;
	Node 		*current;
	
	printf("Initialising lists.....\n");
	
	listInitialise(&myList);
	
	listAddHead(&myList, "Start of the main list");
	listAddHead(&myList, "Start of the main list pt2");
	listAddTail(&myList, "Middle of the main list");
	listAddTail(&myList, "End of the main list");
	
	listAddHead(&myList, "New Start of the main list");
	
	listAddHead(&myList, "New New Start of the main list");


	printf("Listing data from the head....\n");
	
	current = myList.listHead;
	while (current != NULL)
	{
		printf("Head List: data stored is %s\n", (char *) current->data);
		current = current->nextnode;
	}

	listAddTail(&myList, "This is the tail");
	

	printf("\n\nListing data from the tail....\n");

	current = myList.listTail;
	while (current != NULL)
	{
		printf("Tail List: data stored is %s\n", (char *) current->data);
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
		printf("Data stored is %s\n", (char *) current->data);
		current = current->nextnode;
	}

	return EXIT_SUCCESS;
}
