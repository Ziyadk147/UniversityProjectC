#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#include "cJSON.h"
#define C_SUB_FUNCTIONS_H

char *inputName(size_t nameBuffer);
void setName(Student *student,char *name , size_t nameBuffer);
int inputNoOfSubjects();
void setNoOfSubjects(Student *student , int noOfSubjects);
float inputTotalMarksOfEachSubject();
void setTotalMarksOfEachSubject(Student *student ,float totalMarksOfEachSubject);
float *inputMarks(int noOfSubjects,size_t marksBuffer,float totalMarksOfEachSubject);
void setMarks(Student *student , float *marks , int noOfSubjects,size_t numberBuffer);
float calculateObtainedMarks(int noOfSubjects , float *marks);
void setObtainedMarks(Student *student , float obtainedMarks);
int calculateCombinedTotalMarks(int noOfSubjects , float  totalMarksOfEachSubject);
void setCombinedTotalMarks(Student *student , int combinedTotalMarks);
float calculatePercentage(float obtainedMarks, int  combinedTotalMarks);
void setPercentage(Student *student , float percentage);


int getStudentId();



cJSON *parseJSONObject(char *jsonString);

cJSON printObject(cJSON ***items);

int findStringCharIndex(char *array);

#endif //C_SUB_FUNCTIONS_H
