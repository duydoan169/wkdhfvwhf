#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <ctype.h>
int main(int argc, char *argv[]) {
	int chRole, chA1, chA2, chA3, chA4, length=0, lengthTeacher=0, lengthClassroom=0;
	Student student[100];
	Teacher teacher[100];
	Classroom classroom[100];
	do{
		system("cls");
		roleMenu();
		printf("Enter Your Choice: ");
		scanf("%d", &chRole);
		getchar();
		if(chRole==1){
			login();
			do{
				system("cls");
				manageMenu();
				printf("Enter Your Choice: ");
				scanf("%d", &chA1);
				switch(chA1){
					case 1:
						loadStudentFromFile(student, &length,0);
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
									searchStudent(student, length);
									backAndExit();
									break;
								case 4:
									system("cls");
									editStudent(student, length);
									backAndExit();
									break;
								case 5:
									system("cls");
									deleteStudent(student, &length);
									backAndExit();
									break;
								case 6:
									sortStudent(student, length);
									backAndExit();
									break;
							}
						}while(chA2!=0);
						break;
					case 2:
						loadTeacherFromFile(teacher, &lengthTeacher,0);
						do{
							system("cls");
							teacherMenu();
							printf("Enter Your Choice: ");
							scanf("%d", &chA3);
							switch(chA3){
								case 1:
									system("cls");
									inputTeacher(teacher, &lengthTeacher);
									backAndExit();
									break;
								case 2:
									system("cls");
									if(lengthTeacher==0){
										printf("\n*0 Teachers At The Moment*\n");
									} else{
										printTeacher(teacher, lengthTeacher);
									}
									backAndExit();
									break;
								case 3:
									searchTeacher(teacher, lengthTeacher);
									backAndExit();
									break;
								case 4:
									system("cls");
									editTeacher(teacher, lengthTeacher);
									backAndExit();
									break;
								case 5:
									system("cls");
									deleteTeacher(teacher, &lengthTeacher);
									backAndExit();
									break;
							}
						}while(chA3!=0);
						break;
					case 3:
						loadClassroomFromFile(classroom, &lengthClassroom,0);
						do{
							system("cls");
							classroomMenu();
							printf("Enter Your Choice: ");
							scanf("%d", &chA4);
							switch(chA4){
								case 1:
									system("cls");
									inputClassroom(classroom, &lengthClassroom);
									backAndExit();
									break;
								case 2:
									system("cls");
									if(lengthClassroom==0){
										printf("\n*0 Classrooms At The Moment*\n");
									} else{
										printClassroom(classroom, lengthClassroom);
									}
									backAndExit();
									
									break;
								case 3:
									searchClassroom(classroom, lengthClassroom);
									backAndExit();
									break;
								case 4:
									system("cls");
									editClassroom(classroom, lengthClassroom);
									backAndExit();
									break;
								case 5:
									system("cls");
									deleteClassroom(classroom, &lengthClassroom);
									backAndExit();
									break;
								case 6:
									sortClassroom(classroom, lengthClassroom);
									backAndExit();
									break;
							}
						}while(chA4!=0);
						break;
				}
			}while(chA1!=0);
		}
	}while(chRole!=0);
	printf("\n======Thank You======\n");
	printf("==== See You Soon ====");
	return 0;
}
