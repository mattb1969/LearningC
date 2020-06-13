/*
 * Getting Out of a loop.c
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
#include <conio.h>


static void LoopingTest(void)
{
    int completed = 0;
    // start the loop
    do
    {
        printf("Looping...\n");
        
        
    } while (completed == 0);
    return;
}


int main(int argc, char **argv)
{
	LoopingTest();
	return 0;
}
