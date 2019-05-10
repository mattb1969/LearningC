/*
 * Example_1_2.c
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

/* print Fahrenheit-Celsius table
 *  for fahr = 0 , 20 ..., 300 */
 
int main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of the temperture table */
    upper = 300;    /* upper limit */
    step = 20;      /* step */
    
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
    
	return 0;
}

