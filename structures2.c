/*!*********************************************************************
 *
 * Further work on the structure functionality, adding in some bits associated
 * with enumerations
 *
 * I am trying to see if I can have a list of 'name' and value and still use both
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct family_definition {
    char    member[10];
    int	    age;
};

struct family_definition family[] = {
	{"dad",		138},
	{"mom",		25},
	{"eldest",	18},
	{"middle",	15},
	{"youngest",	12},
};

#define FAMILY_SIZE		5

/*!*********************************************************************
 *
 * Print out the family structure
 */
 void display_family(void) {

	int i=0;

	do {
		printf("Member:%s\n", family[i].member);
		printf("   Age:%d\n", family[i].age);
		i++;
	} while (i < FAMILY_SIZE);
	return ;
};


int main(int argc, char **argv)
{
	// create union

	display_family();
	return 0;
};


