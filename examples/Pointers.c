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
    printf("\nPerforming Calculation\n");

    printf("Result:%d\n", (a * b));
    return;
}

static void pointer_calculation(int *x, int *y, int *z)
{
    printf("\nDoing Pointer Calculation with a array\n");


    printf("a:%d\n", *x);
    printf("b:%d\n", *y);
    printf("Pointer of a:%p\n", &x);
    printf("Pointer of b:%p\n", &y);
    *z = (*x * *y);
    printf("Pointer Calculation:%d\n", *z );
    return;
}

static void pointer_floater_calculation(float *fx, float *fy, float *fz)
{
    printf("\nDoing FLOATING pointer calculation with a array\n");

    printf("a:%f\n", *fx);
    printf("b:%f\n", *fy);
    printf("Floating Pointer of a:%p\n", &fx);
    printf("Floating Pointer of b:%p\n", &fy);
    *fz = (*fx * *fy);
    printf("Floating Pointer Calculation:%f\n", *fz );
    return;
}


static void array_calculation(int *array)
{
    printf("\nDoing calculation with a pointed to array\n");
 
    printf("Value of a:%d\n", array[0]);
    printf("Value of b:%d\n", array[1]);
    printf("Pointer of a:%p\n", &array[0]);
    printf("Pointer of b:%p\n", &array[1]);
    array[2] = (array[0] * array[1]);
    printf("Array Calculation:%d\n", array[2]);
    return;
}

int main(int argc, char **argv)
{
    printf("Starting the program\n");
	int a = 3;
    int b = 5;
    int c = 0;
    
    float e = 3.4;
    float f = 6.7;
    float g = 0.0;

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

    pointer_calculation(&values[0], &values[1], &values[2]);

    pointer_floater_calculation(&e, &f, &g);

    array_calculation(p_values);
    
	return 0;
}

