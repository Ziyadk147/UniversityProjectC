#include "sub-functions.h"
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "cJSON.h" //https://github.com/DaveGamble/cJSON

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


int getStudentId(){
    int userId;

    printf("\t\t\tView Student\nEnter the ID of the student you want to view\n");

    scanf("%d" , &userId);

    return userId;
}



cJSON *parseJSONObject(char *jsonString){

    cJSON *json_obj = cJSON_Parse(jsonString);

    if(json_obj == NULL || !cJSON_IsObject(json_obj)){
        printf("Error Parsing JSON Object");
        exit(1);
    }
    return json_obj;
}

cJSON ***getObjectItemsFromJSON(cJSON *json){
/*
 * the first star means a pointer to an array of pointers this is the whole array itself
 * second stars means a pointer to a pointer these are the elements of the outer array
 * third star is the pointer to a JSON object which are the elements of the inner array
 */
    cJSON ***items;

    items = malloc(sizeof (cJSON**) * 3);

    for (int i = 0; i < 3; i++) {

        items[i] = malloc(sizeof (cJSON*) * 3);

    }

    items[0][0] = cJSON_GetObjectItem(json , "roll_no");
    items[0][1] = cJSON_GetObjectItem(json , "name");
    items[0][2] = cJSON_GetObjectItem(json , "no_of_subjects");


    items[2][0] = cJSON_GetObjectItem(json,"obtained_marks");
    items[2][1] = cJSON_GetObjectItem(json,"total_marks");
    items[2][2] = cJSON_GetObjectItem(json,"percentage");

    int no_of_subjects = items[0][2]->valueint;

    char tempString[no_of_subjects];

    items[1] = malloc(sizeof (cJSON*) * no_of_subjects);

    for (int i = 0; i < no_of_subjects; i++) {

        sprintf(tempString , "subject_%d" , i + 1);

        items[1][i] = cJSON_GetObjectItem(json , tempString);

    }

    return items;
}
cJSON printObject(cJSON ***items){


    char *name = items[0][1]->valuestring;
    int rollNo = items[0][0]->valueint;
    int noOfSubjects = items[0][2]->valueint;
    int totalMarks = items[2][1]->valueint;
    float obtainedMarks = items[2][0]->valuedouble;
    float percentage = items[2][2]->valuedouble;
    float marks[noOfSubjects];

    for (int i = 0; i < noOfSubjects; i++) {
        marks[i] = items[1][i]->valuedouble;
    }

    printStudent(rollNo,name,noOfSubjects,marks,obtainedMarks,totalMarks,percentage);
    free(items);
};


//TODO:://free the allocated memory in the sub functions