#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#define C_SUB_FUNCTIONS_H

void inputName(Student *student, size_t nameBuffer);
void inputMarks(Student *student, size_t marksBuffer );

int inputNoOfSubjects(Student *student);
int inputTotalMarksofSubject(Student *student);
int inputTotalMarksOfAllSubjects(Student *student);
int getStudentId();

float  inputObtainedMarks(Student *student);
float inputPercentage(Student *student);

void convertJsonToArray(char *jsonString);
#endif //C_SUB_FUNCTIONS_H
