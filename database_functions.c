#include "database_functions.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "functions.h"

FILE *openOrCreateFile(char *filename){
	
	FILE *fileptr = fopen(filename , "a+");

    if(fileptr == NULL){
		printf("\nFile Could not be opened\n");
		exit(1);
	}

    return fileptr;
	
	
}
int getTotalLines(FILE *fileptr){
    char tempLine[1000];
    int count = 0;
    while(fgets(tempLine , sizeof (tempLine) , fileptr )!= NULL){ //keeps reading the lines until the file reaches the end
        count++;
    }
    return count;
}


void addStudentToFile(FILE *fileptr, Student student){


	fprintf(fileptr , "{roll_no:%d,name:%s",student.roll_no,student.name);

	for(int i = 0;i < student.noOfSubjects ;i++){
		fprintf(fileptr , ",subject_%d:%.2f",i + 1,student.marks[i]);
	}
    fprintf(fileptr , ",obtained_marks:%.2f,total_marks:%d,percentage:%.2f%%",student.obtainedMarks,student.combinedTotalMarks,student.percentage);

	fprintf(fileptr , "}\n");
	fclose(fileptr);


}
char *readSpecificLineFromFile(FILE *fileptr , int lineNumber , size_t charBuffer){
    char *tempLine , *jsonLine;


    tempLine = malloc(charBuffer);


    int count = 1;
    while(fgets(tempLine ,charBuffer ,fileptr) != NULL){
        if(count == lineNumber){

          return tempLine;
        }
    };
}