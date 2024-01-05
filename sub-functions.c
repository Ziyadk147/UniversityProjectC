#include "sub-functions.h"
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "cJSON.h" //https://github.com/DaveGamble/cJSON
#include <string.h>


char *inputName(){
    char *name;
    size_t nameBuffer = 50 * sizeof (char);
    name = (char*)malloc(nameBuffer);

    if(name == NULL){
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }
    printf("Enter the name of the student: ");
    scanf("\n%[^\n]" ,name);

    return name;
}
void setName(Student *student , char *name){
    size_t nameBuffer = 50 * sizeof (char);
    student->name = malloc(nameBuffer);
    if(student->name == NULL){
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }
    strcpy(student->name , name);

}

int inputNoOfSubjects(){
    int noOfSubjects;
    printf("\nEnter the no of Subjects: ");
    scanf("%d" ,&noOfSubjects);

    return noOfSubjects;
}
void setNoOfSubjects(Student *student,int noOfSubjects){
    student->noOfSubjects = noOfSubjects;
}

float inputTotalMarksOfEachSubject(){
    float totalMarksOfEachSubject;

    printf("\nEnter the total marks of the subjects: ");
    scanf("%f" ,&totalMarksOfEachSubject);

    return totalMarksOfEachSubject;
}
void setTotalMarksOfEachSubject(Student *student ,float totalMarksOfEachSubject ){

    student->totalMarksOfEachSubject = totalMarksOfEachSubject;

}
float *inputMarks(int noOfSubjects  ,float totalMarksOfEachSubject){
    size_t  marksBuffer = sizeof(float) *  noOfSubjects;
//BUFFER is set to the size of float times the total subjects,so that enough memory will be allocated
    float *marks , temp = 0;
    marks =  malloc(marksBuffer);

    for (int i = 0; i < noOfSubjects ; i++) {

        printf("\nEnter marks of subject %d: " ,i + 1);
        scanf("%f" ,&temp);

        if(temp > totalMarksOfEachSubject){
            printf("Entered marks greater than %f ",totalMarksOfEachSubject);
            exit(1);
        }
        else{
            marks[i] = temp;
        }
    }

    return  marks;

}
void setMarks(Student *student , float *marks , int noOfSubjects ){

    size_t  marksBuffer = sizeof(float) *  noOfSubjects;

    student->marks = (float * ) malloc(marksBuffer);

    for (int i = 0; i < noOfSubjects;i++) {

    student->marks[i] = marks[i];

    }
}
float calculateObtainedMarks(int noOfSubjects , float *marks ){

    float sum = 0;

    for (int i = 0; i < noOfSubjects;i++) {

        sum += marks[i];

    }
    return sum;
}
void setObtainedMarks(Student *student , float obtainedMarks){

    student->obtainedMarks = obtainedMarks;

}
int calculateCombinedTotalMarks(int noOfSubjects , float  totalMarksOfEachSubject){

    return noOfSubjects * totalMarksOfEachSubject;

}
void setCombinedTotalMarks(Student *student , int combinedTotalMarks){

    student->combinedTotalMarks = combinedTotalMarks;

}

float calculatePercentage(float obtainedMarks ,int  combinedTotalMarks){

    return (obtainedMarks / combinedTotalMarks) * 100;

}

void setPercentage(Student *student , float percentage){

    student->percentage = percentage;

}

int getStudentId(){
    int userId;

    printf("\nEnter the ID of the student\n");

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

char *modifyJSONStringObject(cJSON *json_obj , char *keyName , char *name ){
    cJSON_ReplaceItemInObjectCaseSensitive(json_obj , keyName , cJSON_CreateString(name));
    char *json_str = cJSON_PrintUnformatted(json_obj);
    return json_str;
}

char *modifyJSONNumberObject(cJSON *json_obj , char *keyName ,int number ){
    cJSON_ReplaceItemInObjectCaseSensitive(json_obj , keyName , cJSON_CreateNumber(number));
    char *json_str = cJSON_Print(json_obj);
    return json_str;
}
//char modifyJSONFloatObject(cJSON *json_obj , char *keyName ,double number ){
//    cJSON_ReplaceItemInObjectCaseSensitive(json_obj , keyName , cJSON_create(number));
//    char *json_str = cJSON_Print(json_obj);
//    return *json_str;
//}/



//TODO:://free the allocated memory in the sub functions