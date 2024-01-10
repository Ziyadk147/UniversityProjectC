#include "sub-functions.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include "cJSON.h" // https://github.com/DaveGamble/cJSON

char *inputName(size_t nameBuffer) {
    char *name = (char *)malloc(nameBuffer);

    if (name == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }

    printf("Enter the name of the student: ");
    if (scanf("\n%[^\n]", name) != 1) {
        printf("Invalid input for name\n");
        free(name);
        exit(1);
    }

    return name;
}

void setName(Student *student, char *name, size_t nameBuffer) {
    student->name = malloc(nameBuffer); // will be handled in the free mem function
    if (student->name == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }
    student->name = name;
}

int inputNoOfSubjects() {
    int noOfSubjects;
    printf("\nEnter the no of Subjects: ");
    if (scanf("%d", &noOfSubjects) != 1 || noOfSubjects <= 0) {
        printf("Invalid input for number of subjects\n");
        exit(1);
    }

    return noOfSubjects;
}

void setNoOfSubjects(Student *student, int noOfSubjects) {
    student->noOfSubjects = noOfSubjects;
}

float inputTotalMarksOfEachSubject() {
    float totalMarksOfEachSubject;

    printf("\nEnter the total marks of the subjects: ");
    if (scanf("%f", &totalMarksOfEachSubject) != 1 || totalMarksOfEachSubject <= 0) {
        printf("Invalid input for total marks\n");
        exit(1);
    }

    return totalMarksOfEachSubject;
}

void setTotalMarksOfEachSubject(Student *student, float totalMarksOfEachSubject) {
    student->totalMarksOfEachSubject = totalMarksOfEachSubject;
}

float *inputMarks(int noOfSubjects, size_t marksBuffer, float totalMarksOfEachSubject) {
    float *marks = malloc(marksBuffer);

    if (marks == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }

    for (int i = 0; i < noOfSubjects; i++) {
        printf("\nEnter marks of subject %d: ", i + 1);
        float temp;
        if (scanf("%f", &temp) != 1 || temp < 0 || temp > totalMarksOfEachSubject) {
            printf("Invalid input for marks\n");
            free(marks);
            exit(1);
        } else {
            marks[i] = temp;
        }
    }

    return marks;
}

void setMarks(Student *student, float *marks, int noOfSubjects, size_t numberBuffer) {
    student->marks = (float *)malloc(numberBuffer);

    if (student->marks == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        exit(1);
    }

    for (int i = 0; i < noOfSubjects; i++) {
        student->marks[i] = marks[i];
    }
}

float calculateObtainedMarks(int noOfSubjects, float *marks) {
    float sum = 0;

    for (int i = 0; i < noOfSubjects; i++) {
        sum += marks[i];
    }
    return sum;
}

void setObtainedMarks(Student *student, float obtainedMarks) {
    student->obtainedMarks = obtainedMarks;
}

int calculateCombinedTotalMarks(int noOfSubjects, float totalMarksOfEachSubject) {
    return noOfSubjects * totalMarksOfEachSubject;
}

void setCombinedTotalMarks(Student *student, int combinedTotalMarks) {
    student->combinedTotalMarks = combinedTotalMarks;
}

float calculatePercentage(float obtainedMarks, int combinedTotalMarks) {
    return (obtainedMarks / combinedTotalMarks) * 100;
}

void setPercentage(Student *student, float percentage) {
    student->percentage = percentage;
}

int getStudentId() {
    int userId;

    printf("\nEnter the ID of the student\n");

    if (scanf("%d", &userId) != 1 || userId <= 0) {
        printf("Invalid input for student ID\n");
        exit(1);
    }

    return userId;
}

cJSON *parseJSONObject(char *jsonString) {
    cJSON *json_obj = cJSON_Parse(jsonString);

    if (json_obj == NULL || !cJSON_IsObject(json_obj)) {
        printf("Error Parsing JSON Object");
        exit(1);
    }
    return json_obj;
}