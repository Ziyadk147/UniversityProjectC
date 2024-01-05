#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stddef.h>
#include<stdlib.h>
#include"cJSON.h"

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
void freeItems(cJSON ***items , int noOfSubjects);

cJSON * getStudentFromDatabase(FILE *fileptr);
cJSON ***getObjectItemsFromJSON(cJSON *json_obj);
cJSON printObject(cJSON ***items);



int editMenu(FILE *fileptr,cJSON ***items , cJSON *json_obj);
#endif