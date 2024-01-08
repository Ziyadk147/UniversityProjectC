#include "database_functions.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "functions.h"

FILE *openOrCreateFileForWriting(char *filename){
	
	FILE *fileptr = fopen(filename , "a+");

    if(fileptr == NULL){
		printf("\nFile Could not be opened\n");
		exit(1);
	}

    return fileptr;

}

FILE *openFileForReading(char *filename){
    FILE *fileptr = fopen(filename , "r");

    if(fileptr == NULL){
        printf("\nFile Could not be opened\n");
        exit(1);
    }
    return fileptr;
}
void closeFile(FILE *fileptr){

    fclose(fileptr);

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


	fprintf(fileptr , "{\"roll_no\":%d,\"name\":\"%s\",\"no_of_subjects\":%d",student.roll_no,student.name,student.noOfSubjects);

	for(int i = 0;i < student.noOfSubjects ;i++){

		fprintf(fileptr , ",\"subject_%d""\":%.2f",i + 1,student.marks[i]);

	}
    fprintf(fileptr , ",\"obtained_marks\":%.2f,\"total_marks\":%d,\"percentage\":%.2f%",student.obtainedMarks,student.combinedTotalMarks,student.percentage);

	fprintf(fileptr , "}\n");


}
char readSpecificLineFromFile(FILE *fileptr , int lineNumber ){
    char *tempLine = NULL;
    tempLine = calloc(150 , sizeof (char));
    int count = 1;

    while(count <= lineNumber){

        int i = 0;
        while((tempLine[i] = fgetc(fileptr)) != EOF){
            if(tempLine[i] == '\n'){
                break;
            }
            i++;
        }

        if(count == lineNumber){
            printf("%s" , tempLine);

        }
        count++;

    }
    free(tempLine);


}