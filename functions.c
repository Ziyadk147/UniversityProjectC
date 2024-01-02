#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "database_functions.h"
#include "functions.h"


void addStudent(Student *student){
	int totalMarks;
	
	size_t nameBuffer = 50;
	
	printf("\nEnter Student's Name\n");	
	
	student->name = malloc(nameBuffer);
	
	if(student->name == NULL){
		printf("\nStudent Memory Allocation Failed!\n");
		exit(1);
	}
	scanf("\n%[^\n]" , student->name); 
	/*
		we dont use & for student name because in C the arrays passed in the functions argument acts as 
		a pointer to the first elemtent by its own so no need to pass the address of the array;
		and the format specifier means it will take everything as input in a single line
		%[ is the begining of the input and ^\n tells it to negate the input if \n is encountered and ] closes the input
		*/

	for(int i = 0 ; i < 5;i++){	
		printf("\nEnter marks of subject %d: ",i + 1);
		scanf("%d" , &student->marks[i]);
	}
}

void printStudent(Student student){
	printf("\nName of Student is %s\n" , student.name);
	for(int i = 0 ; i < 5; i++){
		printf("Marks of Subject %d are %d\n" , i + 1, student.marks[i]);
	}
	printf("Roll number of student is %d" , student.roll_no);
}

void freeMemory(Student *student){
	
	free(student->name);
	
}

