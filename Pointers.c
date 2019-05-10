/*
 * Pointers.c
 * 
 * Copyright 2018 Matthew Bennett <>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

static void calculation(int a, int b)
{
    printf("Performing Calculation\n");

    printf("Result:%d\n", (a * b));
    return;
}

static void pointer_calculation(int *x, int *y, int *z)
{
    printf("Performing Pointer Calculation\n");

    printf("a:%d\n", *x);
    printf("b:%d\n", *y);
    printf("\nPointer of a:%p\n", &x);
    printf("Pointer of b:%p\n", &y);
    *z = (*x * *y);
    printf("Pointer Calculation:%d\n", *z );
    return;
}


static void array_calculation(int *array)
{
    printf("Performing Array Calculation\n");

    printf("Value of a:%d\n", *array[0]);
    printf("Value of b:%d\n", *array[1]);
    printf("\nPointer of a:%p\n", &array[0]);
    printf("Pointer of b:%p\n", &array[1]);
    *array[2] = (*array[0] * *array[1]);
    printf("Array Calculation:%d\n", *array[2]);
    return;
}

int main(int argc, char **argv)
{
    printf("Starting the program\n");
	int a = 3;
    int b = 5;
    int c = 0;

    printf("Setting values array\n");

    int values[3];
    values[0] = 3;
    values[1] = 5;
    values[2] = 0;

    printf("Setting p_values pointers\n");

    int p_values[3];
    p_values[0] = 3;
    p_values[1] = 5;

    printf("First Calculation\n");


    calculation(a,b);

    pointer_calculation(&a, &b, &c);

    printf("Doing pointer calculation with a array\n");

    pointer_calculation(&values[0], &values[1], &values[2]);

    printf("Doing calculation with a pointed to array\n");

    array_calculation(&p_values);
    
	return 0;
}

