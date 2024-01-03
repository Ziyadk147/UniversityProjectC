#include "sub-functions.h"
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

void inputName(Student *student, size_t nameBuffer){
    printf("\nEnter Student's Name: ");
    student->name = malloc(nameBuffer);

    if(student->name == NULL){
        printf("\nMEMORY ALLOCATION FAILED..EXITING\n");
        exit(1);
    }
    else{
        scanf("\n%[^\n]" , student->name);
        /*
            we don't use & for student name because in C the arrays passed in the functions argument acts as
            a pointer to the first elemtent by its own so no need to pass the address of the array;
               and the format specifier means it will take everything as input in a single line
            %[ is the begining of the input and ^\n tells it to negate the input if \n is encountered and ] closes the input
        */
    }
}
int inputNoOfSubjects(Student *student){

    printf("\nEnter the no of Subjects of student %s:",student->name);
    scanf("%d" ,&student->noOfSubjects);

    return student->noOfSubjects;
};


void inputMarks(Student *student, size_t marksBuffer , int noOfSubjects){
    student->marks = malloc(marksBuffer);
    if(student->marks == NULL){
        printf("\nMEMORY ALLOCATION FAILED..EXITING\n");
        exit(1);
    }
    else{
        for (int i = 0; i < student->noOfSubjects; i++) {
            printf("Enter marks of Subject %d\n" , i + 1);
            scanf("%f" , &student->marks[i]);
        }
    }
}

