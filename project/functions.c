#include <stdio.h>
#include "functions.h"
#include <string.h>
void roleMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\tCHOOSE YOUR ROLE\n");
	printf("================================\n");
	printf("[1] Admin\n");
	printf("[2] Student\n");
	printf("[3] Teacher\n");
	printf("[0] Exit The Program\n");
	printf("================================\n");
}

void login(){
	char email[16];
	char password[9];
	system("cls");
	do{
		
		printf("***Student Management System Using C***\n\n");
		printf("\t    LOGIN\n");
		printf("\n================================\n");
		fflush(stdin);
		printf("Email: ");
		fgets(email, sizeof(email), stdin);
		email[strcspn(email, "\n")] = '\0';
		fflush(stdin);
		printf("Password: ");
		fgets(password, sizeof(password), stdin);
		password[strcspn(password, "\n")] = '\0';
		system("cls");
		if(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0){
			printf("\n*wrong Email Or Password! Please Try Again*\n");
		}
	}while(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0);
}

void manageMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\t     MENU\n");
	printf("================================\n");
	printf("[1] Students Mangement\n");
	printf("[2] Classrooms Management\n");
	printf("[3] Teachers Management\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void studentMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\t STUDENT MENU\n");
	printf("================================\n");
	printf("[1] Add A New Student\n");
	printf("[2] Show All Students\n");
	printf("[3] Search A Student\n");
	printf("[4] Edit A Student\n");
	printf("[5] Delete A Student\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void inputStudent(Student student[], int *length){
	printf("\t***Add A New Student***\n\n");
	getchar();
	student[*length].studentId=*length + 1;
	printf("Enter Student's Classroom ID: ");
	fgets(student[*length].classroomId,5,stdin);
	student[*length].classroomId[strcspn(student[*length].classroomId,"\n")]='\0';
	printf("Enter Student's Full Name: ");
	fgets(student[*length].name,30,stdin);
	student[*length].name[strcspn(student[*length].name,"\n")]='\0';
	printf("Enter Student's Email: ");
	fgets(student[*length].email,35,stdin);
	student[*length].email[strcspn(student[*length].email,"\n")]='\0';
	printf("Enter Student's Phone Number: ");
	fgets(student[*length].phoneNumber,15,stdin);
	student[*length].phoneNumber[strcspn(student[*length].phoneNumber,"\n")]='\0';
	printf("\n*Student Added Successfully*\n"); 
	(*length)++;
}

void printStudent(Student student[], int length){
	printf("\t**ALL STUDENTS**\n\n");
	printf("|=======|========================|==============|============================|==================|\n");
	printf("|  ID   |         Name           | classroomId  |           Email            |     PhoneNumber  |\n");
	printf("|=======|========================|==============|============================|==================|\n");
	for(int i=0; i<length; i++){
		printf("| %-5d | %-22s | %-12s | %-26s | %-16s |\n", 
		student[i].studentId,
		student[i].name,
		student[i].classroomId,
		student[i].email,
		student[i].phoneNumber);
		printf("|=======|========================|==============|============================|==================|\n");
	}
}

void editStudent(Student student[], int length){
	int find, found;
	printf("***EDIT STUDENT INFORMATION***\n\n");
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
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		printf("Enter Student's Classroom ID: ");
		fgets(student[found].classroomId,5,stdin);
		student[found].classroomId[strcspn(student[found].classroomId,"\n")]='\0';
		printf("Enter Student's Full Name: ");
		fgets(student[found].name,30,stdin);
		student[found].name[strcspn(student[found].name,"\n")]='\0';
		printf("Enter Student's Email: ");
		fgets(student[found].email,35,stdin);
		student[found].email[strcspn(student[found].email,"\n")]='\0';
		printf("Enter Student's Phone Number: ");
		fgets(student[found].phoneNumber,15,stdin);
		student[found].phoneNumber[strcspn(student[found].phoneNumber,"\n")]='\0';
		printf("\n*Student's Information Changed Successfully*\n"); 
	}
}

void backAndExit(){
	int backExit;
	do{
		printf("\nGo Back(0) or Exit The Program(10)?: ");
		scanf("%d", &backExit);
		system("cls");
		if(backExit!=0 && backExit!=10){
			printf("\n*Error, Please Try Again*\n");
		}
	}while(backExit!=0 && backExit!=10);
	if(backExit==10){
		printf("\n*Exited The Program*");
		exit(0);
	}
}
