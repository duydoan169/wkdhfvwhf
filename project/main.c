#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	int chRole, chA1, chA2, length=0;
	int find, found;
	char yesNo; 
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
									system("cls");
									printf("     ***DELETE STUDENT***\n\n");
									printf("Enter Student ID: ");
									scanf("%d", &find);
									found=-1;
									for(int i=0;i<length; i++){
										if(student[i].studentId==find){
											found=i;
										}
									}
									if(found==-1){
										printf("\n*Can't Find Student With This ID*\n");
									} else{
										printf("      STUDENT INFORMATION\n");
										printf("================================\n");
										printf("ID: %d\n", student[found].studentId);
										printf("Classroom ID: %s\n", student[found].classroomId);
										printf("Full Name: %s\n", student[found].name);
										printf("Email: %s\n", student[found].email);
										printf("Phone Number: %s\n", student[found].phoneNumber);
										do{
											getchar();
											printf("\n\nAre You Sure You Want To Delete This Student? (Y/N): ");
											scanf("%c", &yesNo);
											if(yesNo!='Y' && yesNo!='N'){
												printf("\n\n*Error, Please Try Again*\n");
											}	
										}while(yesNo!='Y' && yesNo!='N');
										if(yesNo=='N'){
											printf("\n*Delete Cancelled*\n");
										} else{
											for(int i=found; i<length; i++){
												student[i]=student[i+1];
												student[i].studentId--;
											}
											length--;
											printf("\n*Delete Successful*\n");
										}
									}
									backAndExit();
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
