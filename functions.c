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


cJSON *getStudentFromDatabase(FILE *fileptr){
    int studentId;
    char *temp;

    size_t charBuffer = 256;
    studentId = getStudentId();

    temp = readSpecificLineFromFile(fileptr , studentId , charBuffer);

    cJSON *json_obj = parseJSONObject( temp);

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

int editMenu(cJSON ***items , cJSON *json_obj){

    int editMenuChoice = 0 , loopChoice = 0 , roll_no;
    char *json_string;
    do{

        system("cls");
        printObject(items);
        printf("\n What do you want to edit\n2\tname\n3\tnoOfSubjects\n4\tmarks\n5\tobtainedMarks\n6\ttotalMarks\n7\tpercentage\n");
        scanf("%d" , &editMenuChoice);


        switch (editMenuChoice) {
            case 1:

                *json_string = modifyJSONNumberObject(json_obj , "roll_no" , roll_no);
                printf("%s\n" , json_string);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                break;

        }
        printf("\nPress 1 for continue editing:");
        scanf("%d" , &loopChoice);
    }while(loopChoice == 1);
}
