#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	int chRole, chA1, chA2, length=0;

	Student student[100];
	do{
		system("cls");
		roleMenu();
		printf("Enter Your Choice: ");
		scanf("%d", &chRole);
		if(chRole==1){
//			login();
			do{
				system("cls");
				manageMenu();
				printf("Enter Your Choice: ");
				scanf("%d", &chA1);
				switch(chA1){
					case 1:
						
						do{
							system("cls");
							studentMenu();
							printf("Enter Your Choice: ");
							scanf("%d", &chA2);
							
							switch(chA2){
								case 1:
									system("cls");
									inputStudent(student, &length);
									backAndExit();
									break;
								case 2:
									system("cls");
									if(length==0){
										printf("\n*0 Students At The Moment*\n");
									} else{
										printStudent(student, length);
									}
									backAndExit();
									
									break;
								case 3:
									break;
								case 4:
									system("cls");
									editStudent(student, length);
									backAndExit();
									break;
								case 5:
									break;
							}
						}while(chA2!=0);
						break;
				}
			}while(chA1!=0);
		}
	}while(chRole!=0);
	printf("\n*Exited The Program*");
	return 0;
}