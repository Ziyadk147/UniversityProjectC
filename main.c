#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "database_functions.h"
#include <cJSON.h> //https://github.com/DaveGamble/cJSON

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int exitChoice,menuChoice;
	FILE *fileptr;
	fileptr = openOrCreateFileForWriting("newDatabase.txt");

	do{
		system("cls");
		printf("\t\t\tStudent Management System\nEnter Your Selection\n1\tAdd New student\n2\tView A Student\n3\tEdit A Student\n4\tDelete A Student\n5\tExit\n");
		scanf("%d" , &menuChoice);
		switch(menuChoice){
			case 1:{
				Student newStudent;
				addStudent(&newStudent);
                setRollNo(fileptr , &newStudent);
                addStudentToFile(fileptr , newStudent);
                printStudent(newStudent);
                freeMemory(&newStudent);
                closeFile(fileptr);
                break;
			}

			case 2:
                fileptr = openFileForReading("newDatabase.txt");
                viewStudent(fileptr);
                closeFile(fileptr);

				break;
			case 3:
				//
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
	
                         