#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str;
	
	/* initial memory allocation */
	str = (char *)malloc(15);
	strcpy(str, "tutorials point");
	printf("String = %s, Address = %p\n", str, &str);
	
	/* reallocationg memory */
	free(str);
	printf(".\n");
	str = (char *) realloc(str, 25);			// Changes the location the pointer is pointing to!
	//str = (char *) malloc(25);
	strcat(str, " lesson");
	printf("String = %s, Address = %p\n", str, &str);
	
	
	
	/* deallocation of memory */
	free(str);
	
	return(0);
}
