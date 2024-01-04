#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#include "cJSON.h"
#define C_SUB_FUNCTIONS_H

void inputName(Student *student, size_t nameBuffer);
void inputMarks(Student *student, size_t marksBuffer );

int inputNoOfSubjects(Student *student);
int inputTotalMarksofSubject(Student *student);
int inputTotalMarksOfAllSubjects(Student *student);
int getStudentId();

float  inputObtainedMarks(Student *student);
float inputPercentage(Student *student);

cJSON *parseJSONObject(char *jsonString);
cJSON ***getObjectItemsFromJSON(cJSON *json_obj);

cJSON printObject(cJSON ***items);

#endif //C_SUB_FUNCTIONS_H
