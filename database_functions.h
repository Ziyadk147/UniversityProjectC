#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H
#include<stdio.h>
#include "functions.h"
#include "cJSON.h"

FILE *openOrCreateFileForWriting(char *filename);//filename is a pointer to string or character array,it will be used in the fopen function;
FILE *openFileForReading(char *filename);
void addJSONToFile(FILE *fileptr , int lineNumber,char *jsonString);
void addStudentToFile(FILE *fileptr , Student student);
void closeFile(FILE *fileptr);


char *readSpecificLineFromFile(FILE *fileptr, int lineNumber,size_t charbuffer);

int getTotalLines(FILE *fileptr);


#endif