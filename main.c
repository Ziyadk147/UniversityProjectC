#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "database_functions.h"
#include <cJSON.h> //https://github.com/DaveGamble/cJSON

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int exitChoice,menuChoice;


	do{
        FILE *fileptr;
        char *database = "newDatabase.txt";
		system("cls");
		printf("\t\t\tStudent Management System\nEnter Your Selection\n1\tAdd New student\n2\tView A Student\n3\tView All Students\n4\tExit\n");
		scanf("%d" , &menuChoice);
		switch(menuChoice){
			case 1:{
                fileptr = openOrCreateFileForWriting(database );
                Student newStudent;
				addStudent(&newStudent);
                setRollNo(fileptr , &newStudent);
                addStudentToFile(fileptr , newStudent);
                closeFile(fileptr);
                printStudent(newStudent.roll_no,newStudent.name,newStudent.noOfSubjects,newStudent.marks,newStudent.obtainedMarks,newStudent.combinedTotalMarks,newStudent.percentage);
                freeMemory(&newStudent);
                break;
			}

			case 2:
                fileptr = openFileForReading(database );
                cJSON *json_obj = getStudentFromDatabase(fileptr);
//                printf("%s" , cJSON_Print(json_obj));
/*
 *      The printing could have already been done in the JSON formatted by the above commented file
 *      i implemented the printing function for the sake of the requirement of 2d arrays :);
 *
 * */
                cJSON ***itemsArray = getObjectItemsFromJSON(json_obj);
                printObject(itemsArray);
                closeFile(fileptr);
				break;
			case 3:
                fileptr = openFileForReading(database);
                readAllLinesFromFile(fileptr);
                closeFile(fileptr);
                break;
			case 4:
                exit(0);
                break;
			default:
				printf("Enter a valid Choice\n");
				break;	
		}
		printf("\nPress 1 to continue\n");
		scanf("%d",&exitChoice);
		system("cls");
	}while(exitChoice == 1);

}
	
                         