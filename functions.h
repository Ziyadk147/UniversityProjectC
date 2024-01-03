#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stddef.h>
#include<stdlib.h>

//making student structure
typedef struct{
	char *name;
    float totalMarksOfEachSubject;
    float *marks;
    float obtainedMarks;
    int roll_no;
    int noOfSubjects;
    int combinedTotalMarks;

} Student;


void addStudent(Student *student);
void setRollNo(FILE *fileptr , Student *student);
void printStudent(Student student);
void freeMemory(Student *student);
#endif