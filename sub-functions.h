#ifndef C_SUB_FUNCTIONS_H
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "functions.h"
#define C_SUB_FUNCTIONS_H

void inputName(Student *student, size_t nameBuffer);
void inputMarks(Student *student, size_t marksBuffer ,int noOfSubjects);
int inputNoOfSubjects(Student *student);


#endif //C_SUB_FUNCTIONS_H
