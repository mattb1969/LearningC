/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char** argv) {

	printf("starting the string Functions program\n");
	
	char		s1[6] = "xyz\0";
	char		s2[6] = "abcde\0";
	char		s3[6] = "\0";

	
	printf("The Results\n");
	printf("- Lengths\n");
	printf("Length of null string(s1):%d\n", strlen(s1));
	printf("Length of 5 character string(s2):%d\n", strlen(s2));
	printf("Length of RESULT string(s3):%d\n", strlen(s3));
	

	printf("- Copying\n");
	printf("s1:%s\n", s1);
	printf("s2:%s\n", s2);
	printf("s3:%s\n", s3);
	strcpy(s3,s2);
	printf("Straight copy s2:%s into s3:%s\n", s2, s3);
	strcpy(s3,"\0");
	strcpy(s3, s2+2);
	printf("Copy of the last 3 characters from s2:%s to s3:%s\n", s2, s3);
	strcpy(s3,"\0");
	strncpy(s3, s2, 3);
	printf("Copy of the first 3 characters from s2:%s to s3:%s\n", s2, s3);
	strcpy(s3,"\0");
	strncpy(s3, s2+1, 3);
	printf("Copy the middle 3 characters from s2:%s to s3:%s\n", s2, s3);

	
//	strcat(s1,s2);
	
//	strlen(s1);
	
//	strcmp(s1,s2);
	
	
	
	return (EXIT_SUCCESS);
}

