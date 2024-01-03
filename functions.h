#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stddef.h>
#include<stdlib.h>

//making student structure
typedef struct{
	char *name;
    float totalMarksOfSubject;
    float *marks;
    int roll_no;
    int noOfSubjects;
} Student;

int  calculateTotalMarks(int array[]);
float calculatePercentage(float obtainedMarks , float totalMarksEach ,float noOfSubjects);

void addStudent(Student *student);
void printStudent(Student student);
void freeMemory(Student *student);
#endif