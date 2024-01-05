#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include "sub-functions.h"
#include "database_functions.h"

void addStudent(Student *student){

    size_t nameBuffer = 50 ,marksBuffer = sizeof(float);

    int noOfSubjects = 0;

    marksBuffer *= noOfSubjects; //BUFFER is set to the size of float times the total subjects,so that enough memory will be allocated

    inputName(student , nameBuffer);

    noOfSubjects = inputNoOfSubjects(student);

    inputTotalMarksofSubject(student);

    inputMarks(student ,marksBuffer );

    inputObtainedMarks(student);

    inputTotalMarksOfAllSubjects(student);

    inputPercentage(student);
}

void setRollNo(FILE *fileptr , Student *student){

    int currentLine = getTotalLines(fileptr);

    student->roll_no = currentLine + 1;

}

void printStudent(int rollNo , char *name , int noOfSubjects , float *marks ,float obtainedMarks ,int combinedTotalMarks,float percentage){
	printf("Roll number of student is %d\nName of Student is %s\n" , rollNo,name);

    for(int i = 0 ; i < noOfSubjects; i++){

        printf("Marks of Subject %d are %.2f\n" , i + 1, marks[i]);

    }
    printf("Student no %d has earned total of %.2f marks out of %d \npercentage is %.2f%%" , rollNo,obtainedMarks , combinedTotalMarks,percentage);

}

void freeMemory(Student *student){

	free(student->name);
    free(student->marks);
}


void viewStudent(FILE *fileptr){
    int studentId;
    char *temp;

    size_t charBuffer = 256;

    studentId = getStudentId();

    temp = readSpecificLineFromFile(fileptr , studentId , charBuffer);

    cJSON *json_obj = parseJSONObject( temp);

    cJSON ***itemsArray = getObjectItemsFromJSON(json_obj);

}