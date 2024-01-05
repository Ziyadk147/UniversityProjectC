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
    float percentage;
    int roll_no;
    int noOfSubjects;
    int combinedTotalMarks;


} Student;

//addstudent
void addStudent(Student *student);
void setRollNo(FILE *fileptr , Student *student);
void printStudent(int rollNo , char *name , int noOfSubjects , float *marks ,float obtainedMarks ,int combinedTotalMarks,float percentage);
void freeMemory(Student *student);

//viewstudent
void viewStudent();
#endif