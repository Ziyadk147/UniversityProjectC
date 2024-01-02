#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stddef.h>
#include<stdlib.h>

//making student structure
typedef struct{
	char *name;
	int roll_no;
	int marks[5];
} Student;

//int calculateObtainedMarks(int marks[]);
//float calculatePercentage(float obtainedMarks, float totalMarks, float totalSubjects);
void addStudent(Student *student);
void printStudent(Student student);
void freeMemory(Student *student);
#endif