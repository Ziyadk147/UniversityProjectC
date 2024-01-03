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

    inputMarks(student ,marksBuffer ,noOfSubjects);


}

void setRollNo(FILE *fileptr , Student *student){

    int currentLine = getTotalLines(fileptr);

    student->roll_no = currentLine + 1;

}

void printStudent(Student student){
	printf("Roll number of student is %d" , student.roll_no);

    printf("\nName of Student is %s\n" , student.name);

    for(int i = 0 ; i < student.noOfSubjects; i++){

        printf("Marks of Subject %d are %.2f\n" , i + 1, student.marks[i]);

    }
}

void freeMemory(Student *student){

	free(student->name);
    free(student->marks);
}

