#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H
#include<stdio.h>
#include "functions.h"
FILE *openOrCreateFileForWriting(char *filename);//filename is a pointer to string or character array,it will be used in the fopen function;
FILE *openFileForReading(char *filename);
void addStudentToFile(FILE *fileptr , Student student);
void closeFile(FILE *fileptr);

char *readSpecificLineFromFile(FILE *fileptr, int lineNumber,size_t charbuffer);

int getTotalLines(FILE *fileptr);



/*
 * read the previous lines
 * check the previous id number and add one
 * in case of no previous id number then just store 1 as id
 * store the data with the new id number
 */


#endif