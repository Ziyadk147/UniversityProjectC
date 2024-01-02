#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H
#include<stdio.h>
#include "functions.h"
FILE *openOrCreateFile(char *filename);//filename is a pointer to string or character array,it will be used in the fopen function;

void addStudentToFile(FILE *fileptr , Student student);

#endif