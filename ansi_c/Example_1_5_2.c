/*
 * Example_1_5_2.c
 * 
 * Copyright 2017  <pi@RPi_3B>
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

/* COutn characters as input; version 1*/

int main(int argc, char **argv)
{
    long nc;
    
    nc = 0;
    
    while (getchar() != EOF)
        ++nc;
    
    printf("Character input:%ld", nc);
    
    /* 2nd Version */
    
    double nnc;
    
    for (nnc = 0; getchar() != EOF; ++nnc)
        ;
    
    printf("For Version:%.0f", nnc);
    
	return 0;
}

