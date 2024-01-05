#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include "sub-functions.h"
#include "database_functions.h"

void addStudent(Student *student){


    char *name;
    float totalMarksOfEachSubject = 0,obtainedMarks = 0 ,percentage,*marks;
    int noOfSubjects = 0,combinedTotalMarks;

    name = inputName();

    setName(student , name);

    noOfSubjects = inputNoOfSubjects();

    setNoOfSubjects(student,  noOfSubjects);

    totalMarksOfEachSubject = inputTotalMarksOfEachSubject();

    setTotalMarksOfEachSubject(student , totalMarksOfEachSubject);

    marks = inputMarks(noOfSubjects ,totalMarksOfEachSubject);

    setMarks(student , marks , noOfSubjects);
    obtainedMarks = calculateObtainedMarks(noOfSubjects , marks);

    setObtainedMarks(student , obtainedMarks);

    combinedTotalMarks = calculateCombinedTotalMarks(noOfSubjects , totalMarksOfEachSubject);

    setCombinedTotalMarks(student , combinedTotalMarks);

    percentage = calculatePercentage(obtainedMarks , combinedTotalMarks);

    setPercentage(student , percentage);

    free(name);
    free(marks);

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
    free(temp);
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

//    for (int i = 0; i < 3; i++) {
//        free(items[i]);
//    }
//    free(items);

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
};

int editMenu(FILE *fileptr,cJSON ***items , cJSON *json_obj){

    int editMenuChoice = 0 , loopChoice = 0 ,rollNo = items[0][0]->valueint;
    char *json_string ,*name;
//    json_string = (char *) malloc(sizeof (char) * 50);

    do{
        system("cls");
        printObject(items);
        printf("\n What do you want to edit\n1\tname\n2\tnoOfSubjects\n3\tmarks\n");
        scanf("%d" , &editMenuChoice);


        switch (editMenuChoice) {
            case 1:
                name = inputName();
                json_string = modifyJSONStringObject(json_obj , "name" , name);
                printf("%s" , json_string);
                addJSONToFile(fileptr , rollNo ,json_string);
                free(json_string );
                free(name);
                break;

            case 2:


                break;
            case 3:

                break;
        }
        printf("\nPress 1 for continue editing:");
        scanf("%d" , &loopChoice);

    }while(loopChoice == 1);
}