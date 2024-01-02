#include "database_functions.h"
#include<stdio.h>
#include "functions.h"

FILE *openOrCreateFile(char *filename){
	
	FILE *fileptr = fopen(filename , "a+");
	if(fileptr == NULL){
		printf("\nFile Could not be opened\n");
		exit(1);
	}
	return fileptr;
	
	
}
void addStudentToFile(FILE *fileptr, Student student){
	
	fprintf(fileptr , "%s,",student.name);

	for(int i = 0;i < 5;i++){
		fprintf(fileptr , "%d,",student.marks[i]);
	}

	fprintf(fileptr , "\n");
	fclose(fileptr);
	
}