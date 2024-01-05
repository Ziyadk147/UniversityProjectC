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
		printf("\t\t\tStudent Management System\nEnter Your Selection\n1\tAdd New student\n2\tView A Student\n3\tEdit A Student\n4\tDelete A Student\n5\tExit\n");
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
                cJSON ***itemsArray = getObjectItemsFromJSON(json_obj);
                printObject(itemsArray);
//                freeItems(itemsArray,itemsArray[0][1]->valueint);
                closeFile(fileptr);
                cJSON_Delete(json_obj); // Free cJSON object after using it

                break;
			case 3:
				fileptr = openOrCreateFileForWriting(database);
                cJSON *json = getStudentFromDatabase(fileptr);
                cJSON ***items = getObjectItemsFromJSON(json);
                editMenu(fileptr , items , json);
                closeFile(fileptr);
                cJSON_Delete(json_obj); // Free cJSON object after using it

                break;
			case 4:
				//
				break;
			case 5:
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
	
                         