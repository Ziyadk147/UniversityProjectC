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
char *readSpecificLineFromFile(FILE *fileptr , int lineNumber , size_t charBuffer){

    char *tempLine;
    cJSON *json_obj;

    tempLine = malloc(charBuffer);

    int count = 1;

    while(fgets(tempLine ,charBuffer ,fileptr) != NULL){
        if(count == lineNumber){
            return tempLine;
//            json_obj = cJSON_Parse(tempLine);
//            printf("%s" , cJSON_Print(json_obj));
        }
        count++;
    };
    fclose(fileptr);

}

char *readAllLinesFromFile(FILE *fileptr ){
    char *templine;
    cJSON *json_object ;
    int buffer = 10000;
    templine = (char *)malloc( buffer * sizeof (char*));

    while(fgets(templine , buffer , fileptr ) != NULL){
        json_object = cJSON_Parse(templine);
        printf("%s" , cJSON_Print(json_object));
    }; //reads until it encouters null;
    free(templine);
    free(json_object);



};