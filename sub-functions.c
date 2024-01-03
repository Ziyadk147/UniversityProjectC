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

int inputTotalMarksofSubject(Student *student){

    printf("\nEnter the total marks of the subjects:");
    scanf("%f" ,&student->totalMarksOfEachSubject);

    return student->totalMarksOfEachSubject;
}

void inputMarks(Student *student, size_t marksBuffer ){
    float temp = 0;
    student->marks = malloc(marksBuffer);
    if(student->marks == NULL){
        printf("\nMEMORY ALLOCATION FAILED..EXITING\n");
        exit(1);
    }
    else{
        for (int i = 0; i < student->noOfSubjects; i++) {
            printf("Enter marks of Subject %d\n" , i + 1);
            scanf("%f" , &temp);

            if(temp > student->totalMarksOfEachSubject){
                printf("\nMarks input invalid....EXITING..\n");
                exit(1);
            }
            else{
                student->marks[i] = temp;
            }
        }
    }
}
float inputObtainedMarks(Student *student){

    float sum = 0;
    for (int i = 0; i < student->noOfSubjects;i++) {
        sum += student->marks[i];
    }
    student->obtainedMarks = sum;

    return sum;
}
int inputTotalMarksOfAllSubjects(Student *student){

    student->combinedTotalMarks = student->noOfSubjects * student->totalMarksOfEachSubject;

    return student->combinedTotalMarks;

}
float inputPercentage(Student *student){

    student->percentage = (student->obtainedMarks/student->combinedTotalMarks) * 100;

    return student->percentage;
}