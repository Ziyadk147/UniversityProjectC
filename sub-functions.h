#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#include "cJSON.h"
#define C_SUB_FUNCTIONS_H

void inputName(Student *student, size_t nameBuffer);
void inputMarks(Student *student, size_t marksBuffer );
void freeObjectMemory(cJSON ***items);

int inputNoOfSubjects(Student *student);
int inputTotalMarksofSubject(Student *student);
int inputTotalMarksOfAllSubjects(Student *student);
int getStudentId();

float  inputObtainedMarks(Student *student);
float inputPercentage(Student *student);

cJSON *parseJSONObject(char *jsonString);

cJSON printObject(cJSON ***items);

char modifyJSONStringObject(cJSON *json_obj , char *keyName , char *string );
char modifyJSONNumberObject(cJSON *json_obj , char *keyName ,int number );
char modifyJSONFloatObject(cJSON *json_obj , char *keyName ,double number );

#endif //C_SUB_FUNCTIONS_H
