#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#include "cJSON.h"
#define C_SUB_FUNCTIONS_H

char *inputName();
void setName(Student *student,char *name );
int inputNoOfSubjects();
void setNoOfSubjects(Student *student , int noOfSubjects);
float inputTotalMarksOfEachSubject();
void setTotalMarksOfEachSubject(Student *student ,float totalMarksOfEachSubject);
float *inputMarks(int noOfSubjects,float totalMarksOfEachSubject);
void setMarks(Student *student , float *marks , int noOfSubjects);
float calculateObtainedMarks(int noOfSubjects , float *marks);
void setObtainedMarks(Student *student , float obtainedMarks);
int calculateCombinedTotalMarks(int noOfSubjects , float  totalMarksOfEachSubject);
void setCombinedTotalMarks(Student *student , int combinedTotalMarks);
float calculatePercentage(float obtainedMarks, int  combinedTotalMarks);
void setPercentage(Student *student , float percentage);


int getStudentId();



cJSON *parseJSONObject(char *jsonString);

cJSON printObject(cJSON ***items);

char *modifyJSONStringObject(cJSON *json_obj , char *keyName , char *string );
char *modifyJSONNumberObject(cJSON *json_obj , char *keyName ,int number );
char *modifyJSONFloatObject(cJSON *json_obj , char *keyName ,double number );

#endif //C_SUB_FUNCTIONS_H
