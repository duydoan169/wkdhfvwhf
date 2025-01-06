#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void roleMenu(){
	printf("     ***Management System Using C***\n\n");
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
		printf("\t    LOGIN\n");
		printf("\n================================\n");
		printf("Email(admin@gmail.com): ");
		fgets(email, sizeof(email), stdin);
		if(strcspn(email, "\n")==strlen(email)){
			while ((getchar()) != '\n');
		} else{
			email[strcspn(email, "\n")] = '\0';
		}
		printf("Password(password): ");
		fgets(password, sizeof(password), stdin);
		if(strcspn(password, "\n")==strlen(password)){
			while ((getchar()) != '\n');
		} else{
			password[strcspn(password, "\n")] = '\0';
		}
		system("cls");
		if(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0){
			printf("\n*wrong Email Or Password! Please Try Again*\n\n");
		}
	}while(strcmp(password,"password")!=0 || strcmp(email,"admin@gmail.com")!=0);
}

void manageMenu(){
	printf("    ***Management System Using C***\n\n");
	printf("\t     MENU\n");
	printf("================================\n");
	printf("[1] Students Mangement\n");
	printf("[2] Teachers Management\n");
	printf("[3] Classrooms Management\n");
	printf("[0] Back\n");
	printf("================================\n");
}

//student

void studentMenu(){
	printf("***Student Management System Using C***\n\n");
	printf("\t STUDENT MENU\n");
	printf("================================\n");
	printf("[1] Add A New Student\n");
	printf("[2] Show All Students\n");
	printf("[3] Search A Student\n");
	printf("[4] Edit A Student\n");
	printf("[5] Delete A Student\n");
	printf("[6] Sort Students By Name\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void inputStudent(Student student[], int *length){
	int count, check, ch;
	printf("\t***Add A New Student***\n\n");
	getchar();
	do{
		count=0;
		printf("Enter Student's ID: ");
		if(scanf("%d", &student[*length].studentId)==1){
			for(int i=0; i<*length; i++){
				if(student[i].studentId==student[*length].studentId){
					count++;
				}
			}
			if(count!=0 || student[*length].studentId<1 || student[*length].studentId>99999){
				printf("\n*Student ID Must Be Positive And Not Already Exist*\n\n");
			}
		} else{
			printf("\n*Student ID Must Be A Number*\n\n");
			while ((getchar()) != '\n');
		}
	}while(count!=0 || student[*length].studentId<1 || student[*length].studentId>99999);
	getchar();
	
	do{
		check=0;
		printf("Enter Student's Full Name: ");
		fgets(student[*length].name,25,stdin);
		if(strcspn(student[*length].name,"\n")==strlen(student[*length].name)){
			while ((getchar()) != '\n');
		} else{
			student[*length].name[strcspn(student[*length].name,"\n")]='\0';
		}
		for(int i=0; i<strlen(student[*length].name); i++){
			if(isalpha(student[*length].name[i])==0 && student[*length].name[i] != ' '){
				check++;
			}
		}
		if(student[*length].name[0]=='\0' || check!=0 || student[*length].name[0]==' '){
			printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
		}
	}while(student[*length].name[0]=='\0' || check!=0 || student[*length].name[0]==' ');
	
	do{
		check=0;
		printf("Enter Student's Classroom ID: ");
		fgets(student[*length].classroomId,5,stdin);
		if(strcspn(student[*length].classroomId, "\n")==strlen(student[*length].classroomId)){
			while((getchar())!='\n');
		} else{
			student[*length].classroomId[strcspn(student[*length].classroomId,"\n")]='\0';
		}
		for(int i=0; i<strlen(student[*length].classroomId); i++){
			if(isdigit(student[*length].classroomId[i])==0){
				check++;
			}
		}
		if(student[*length].classroomId[0]=='\0' || check!=0 || student[*length].classroomId[0]==' '){
			printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
		}
	}while(student[*length].classroomId[0]=='\0' || check!=0 || student[*length].classroomId[0]==' ');
	
	do{
		count=0;
		check=0;
		printf("Enter Student's Email: ");
		fgets(student[*length].email,30,stdin);
		if(strcspn(student[*length].email, "\n")==strlen(student[*length].email)){
			while((getchar())!='\n');
		} else{
			student[*length].email[strcspn(student[*length].email,"\n")]='\0';
		}
		for(int i=0; i<*length; i++){
			if(strcmp(student[i].email,student[*length].email)==0){
				count++;
			}
		}
		for(int i=0; i<strlen(student[*length].email); i++){
			if(isalpha(student[*length].email[i])==0 && student[*length].email[i]!='@' && student[*length].email[i]!='.' && student[*length].email[i]!='-' && student[*length].email[i]!='_' && isdigit(student[*length].email[i])==0){
				check++;
			}
		}
		if(count!=0 || student[*length].email[0]=='\0' || check!=0 || student[*length].email[0]==' ' || student[*length].email[0]=='.' || student[*length].email[0]=='@'){
			printf("\n*Email Must Not Be Empty, Contain Special Characters(Except \".\",\"-\",\"_\"), Or Already Exist*\n\n");
		}
	}while(count!=0 || student[*length].email[0]=='\0' || check!=0 || student[*length].email[0]==' ' || student[*length].email[0]=='.' || student[*length].email[0]=='@');
	
	do{
		count=0;
		check=0;
		printf("Enter Student's Phone Number: ");
		fgets(student[*length].phoneNumber,15,stdin);
		if(strcspn(student[*length].phoneNumber, "\n")==strlen(student[*length].phoneNumber)){
			while((getchar())!='\n');
		} else{
			student[*length].phoneNumber[strcspn(student[*length].phoneNumber,"\n")]='\0';
		}
		for(int i=0; i<*length; i++){
			if(strcmp(student[i].phoneNumber,student[*length].phoneNumber)==0){
				count++;
			}
		}
		for(int i=0; i<strlen(student[*length].phoneNumber); i++){
			if(isdigit(student[*length].phoneNumber[i])==0){
				check++;
			}
		}
		if(count!=0 || student[*length].phoneNumber[0]=='\0' || check!=0 || student[*length].phoneNumber[0]==' '){
			printf("\n*PhoneNumber Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
		}
		if(strlen(student[*length].phoneNumber)!=10){
			printf("\n*PhoneNumber Must Have 10 Digits*\n\n");
		}
	}while(count!=0 || student[*length].phoneNumber[0]=='\0' || check!=0 || student[*length].phoneNumber[0]==' ' || strlen(student[*length].phoneNumber)!=10);

	printf("\n*Student Added Successfully*\n"); 
	(*length)++;
	saveStudentToFile(student, *length,1);
}

void printStudent(Student student[], int length){
	printf("\t**ALL STUDENTS**\n\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	for(int i=0; i<length; i++){
		printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
		student[i].studentId,
		student[i].name,
		student[i].classroomId,
		student[i].email,
		student[i].phoneNumber);
		printf("|=======|===========================|==============|================================|==================|\n");
	}
}

void editStudent(Student student[], int length){
	int find, found, count=0, check=0;
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
		printf("Full Name: %s\n", student[found].name);
		printf("Classroom ID: %s\n", student[found].classroomId);
		printf("Email: %s\n", student[found].email);
		printf("Phone Number: %s\n", student[found].phoneNumber);
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		do{
			count=0;
			printf("Enter Student's ID: ");
			if(scanf("%d", &student[found].studentId)==1){
				for(int i=0; i<length; i++){
					if(i!=found && student[i].studentId==student[found].studentId){
						count++;
					}
				}
				if(count!=0 || student[found].studentId<1 || student[found].studentId>99999){
					printf("\n*Student ID Must Be Positive And Not Already Exist*\n\n");
				}
			} else{
				printf("\n*Student ID Must Be A Number*\n\n");
				while ((getchar()) != '\n');
			}
		}while(count!=0 || student[found].studentId<1 || student[found].studentId>99999);
		getchar();
		
		do{
			check=0;
			printf("Enter Student's Full Name: ");
			fgets(student[found].name,25,stdin);
			if(strcspn(student[found].name,"\n")==strlen(student[found].name)){
				while ((getchar()) != '\n');
			} else{
				student[found].name[strcspn(student[found].name,"\n")]='\0';
			}
			for(int i=0; i<strlen(student[found].name); i++){
				if(isalpha(student[found].name[i])==0 && student[found].name[i] != ' '){
					check++;
				}
			}
			if(student[found].name[0]=='\0' || check!=0 || student[found].name[0]==' '){
				printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
			}
		}while(student[found].name[0]=='\0' || check!=0 || student[found].name[0]==' ');
		
		do{
			check=0;
			printf("Enter Student's Classroom ID: ");
			fgets(student[found].classroomId,5,stdin);
			if(strcspn(student[found].classroomId, "\n")==strlen(student[found].classroomId)){
				while((getchar())!='\n');
			} else{
				student[found].classroomId[strcspn(student[found].classroomId,"\n")]='\0';
			}
			for(int i=0; i<strlen(student[found].classroomId); i++){
				if(isdigit(student[found].classroomId[i])==0){
					check++;
				}
			}
			if(student[found].classroomId[0]=='\0' || check!=0 || student[found].classroomId[0]==' '){
				printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
			}
		}while(student[found].classroomId[0]=='\0' || check!=0 || student[found].classroomId[0]==' ');
		
		do{
			count=0;
			check=0;
			printf("Enter Student's Email: ");
			fgets(student[found].email,30,stdin);
			if(strcspn(student[found].email, "\n")==strlen(student[found].email)){
				while((getchar())!='\n');
			} else{
				student[found].email[strcspn(student[found].email,"\n")]='\0';
			}
			for(int i=0; i<length; i++){
				if(i!=found && strcmp(student[i].email,student[found].email)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(student[found].email); i++){
				if(isalpha(student[found].email[i])==0 && student[found].email[i]!='@' && student[found].email[i]!='.' && student[found].email[i]!='-' && student[found].email[i]!='_' && isdigit(student[found].email[i])==0){
					check++;
				}
			}
			if(count!=0 || student[found].email[0]=='\0' || check!=0 || student[found].email[0]=='@' || student[found].email[0]=='.' || student[found].email[0]=='_'){
				printf("\n*Email Must Not Be Empty, Contain Special Characters(Except \".\",\"-\",\"_\"), Or Already Exist*\n\n");
			}
		}while(count!=0 || student[found].email[0]=='\0' || check!=0 || student[found].email[0]=='@' || student[found].email[0]=='.' || student[found].email[0]=='_');
		
		do{
			count=0;
			check=0;
			printf("Enter Student's Phone Number: ");
			fgets(student[found].phoneNumber,15,stdin);
			if(strcspn(student[found].phoneNumber, "\n")==strlen(student[found].phoneNumber)){
				while((getchar())!='\n');
			} else{
				student[found].phoneNumber[strcspn(student[found].phoneNumber,"\n")]='\0';
			}
			for(int i=0; i<length; i++){
				if(i!=found && strcmp(student[i].phoneNumber,student[found].phoneNumber)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(student[found].phoneNumber); i++){
				if(isdigit(student[found].phoneNumber[i])==0){
					check++;
				}
			}
			if(count!=0 || student[found].phoneNumber[0]=='\0' || check!=0 || student[found].phoneNumber[0]==' '){
				printf("\n*PhoneNumber Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
			}
			if(strlen(student[found].phoneNumber)!=10){
				printf("\n*PhoneNumber Must Have 10 Digits*\n\n");
			}
		}while(count!=0 || student[found].phoneNumber[0]=='\0' || check!=0 || student[found].phoneNumber[0]==' ' || strlen(student[found].phoneNumber)!=10);
		printf("\n*Student's Information Changed Successfully*\n"); 
		saveStudentToFile(student, length, 1);
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
		printf("\n======Thank You======\n");
		printf("==== See You Soon ====");
		exit(0);
	}
}

void deleteStudent(Student student[], int *length){
	int find, found;
	char yesNo;
	printf("     ***DELETE STUDENT***\n\n");
	printf("Enter Student ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<*length; i++){
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
		printf("Full Name: %s\n", student[found].name);
		printf("Classroom ID: %s\n", student[found].classroomId);
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
			for(int i=found; i<*length; i++){
				student[i]=student[i+1];
			}
			(*length)--;
			printf("\n*Delete Successful*\n");
			saveStudentToFile(student, *length, 1);
		}
	}
}

void sortStudent(Student student[], int length){
	int sortOrder;
	if(length<2){
		system("cls");
		printf("*Not Enough Students To Sort*\n");
	} else{
		saveStudentToFile(student, length,0);
		do{
			printf("\nSort By Ascending(0) or Descending(1) order: ");
			scanf("%d", &sortOrder);
		}while(sortOrder!=1 && sortOrder!=0);
		system("cls");
		if(sortOrder==0){
			for(int i=1; i<length; i++){
				Student key = student[i];
				int j = i-1;
				while(j>=0 && strcmp(key.name, student[j].name)<0){
					student[j+1]=student[j];
					j--;
				}
				student[j+1]=key;
			}
		} else{
			for(int i=1; i<length; i++){
				Student key = student[i];
				int j = i-1;
				while(j>=0 && strcmp(key.name, student[j].name)>0){
					student[j+1]=student[j];
					j--;
				}
				student[j+1]=key;
			}
		}
	}
    if(length>=2){
    	printf("\n\t**SORTED STUDENTS**\n\n");
		printf("|=======|===========================|==============|================================|==================|\n");
		printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
		printf("|=======|===========================|==============|================================|==================|\n");
		for(int i=0; i<length; i++){
			
			printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
			student[i].studentId,
			student[i].name,
			student[i].classroomId,
			student[i].email,
			student[i].phoneNumber);
			printf("|=======|===========================|==============|================================|==================|\n");
		}
	}
	loadStudentFromFile(student, &length,0);
}

void saveStudentToFile(Student student[], int length, int a){
	FILE *ptr=fopen("studentData.dat", "wb");
	if(ptr==NULL){
		printf("\n\n*Can't Open File*\n");
	}
	fwrite(student,sizeof(Student),length,ptr);
	if(a==1){
		printf("\n*Saved Successfully*\n");
	}
	fclose(ptr);
}

void loadStudentFromFile(Student student[], int *length, int a){
	FILE *ptr=fopen("studentData.dat", "rb");
	if(ptr==NULL){
		printf("Can't Open File");
	}
	*length=fread(student, sizeof(Student), 100, ptr);
	if(a==1){
		printf("\n*Loaded Successfully*\n");
	}
	fclose(ptr);
}

void searchStudent(Student student[], int length){
	int count=0;
	int firstTime;
	char name[30];
	getchar();
	do{
		printf("\nEnter Student Name To Search: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name,"\n")]='\0';
		if(strlen(name)<=1){
			printf("\n*Minimum 2 Characters Required, Try Again*\n");
		}
	}while(strlen(name)<=1);
	system("cls");
	printf("\n    SEARCH RESULT FOR \"%s\":\n\n", name);
	firstTime=0;
	for(int i=0; i<length; i++){
		if((strstr(student[i].name, name))!= NULL){
			if(firstTime==0){
				printf("|=======|===========================|==============|================================|==================|\n");
				printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
				printf("|=======|===========================|==============|================================|==================|\n");
				firstTime++;
			}
			printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
			student[i].studentId,
			student[i].name,
			student[i].classroomId,
			student[i].email,
			student[i].phoneNumber);
			printf("|=======|===========================|==============|================================|==================|\n");
			count++;
		}
	}
	if(count==0){
	printf("*No Result*\n");
	}
}

//teacher

void teacherMenu(){
	printf("***Teacher Management System Using C***\n\n");
	printf("\t TEACHER MENU\n");
	printf("================================\n");
	printf("[1] Add A New Teacher\n");
	printf("[2] Show All Teachers\n");
	printf("[3] Search A Teacher\n");
	printf("[4] Edit A Teacher\n");
	printf("[5] Delete A Teacher\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void inputTeacher(Teacher teacher[], int *lengthTeacher){
	int count, check, ch;
	printf("\t***Add A New Teacher***\n\n");
	getchar();
	do{
		count=0;
		printf("Enter Teacher's ID: ");
		if(scanf("%d", &teacher[*lengthTeacher].teacherId)==1){
			for(int i=0; i<*lengthTeacher; i++){
				if(teacher[i].teacherId==teacher[*lengthTeacher].teacherId){
					count++;
				}
			}
			if(count!=0 || teacher[*lengthTeacher].teacherId<1 || teacher[*lengthTeacher].teacherId>99999){
				printf("\n*Teacher ID Must Be Positive And Not Already Exist*\n\n");
			}
		} else{
			printf("\n*Teacher ID Must Be A Number*\n\n");
			while ((getchar()) != '\n');
		}
	}while(count!=0 || teacher[*lengthTeacher].teacherId<1 || teacher[*lengthTeacher].teacherId>99999);
	getchar();
	
	do{
		check=0;
		printf("Enter Teacher's Full Name: ");
		fgets(teacher[*lengthTeacher].name,25,stdin);
		if(strcspn(teacher[*lengthTeacher].name,"\n")==strlen(teacher[*lengthTeacher].name)){
			while ((getchar()) != '\n');
		} else{
			teacher[*lengthTeacher].name[strcspn(teacher[*lengthTeacher].name,"\n")]='\0';
		}
		for(int i=0; i<strlen(teacher[*lengthTeacher].name); i++){
			if(isalpha(teacher[*lengthTeacher].name[i])==0 && teacher[*lengthTeacher].name[i] != ' '){
				check++;
			}
		}
		if(teacher[*lengthTeacher].name[0]=='\0' || check!=0 || teacher[*lengthTeacher].name[0]==' '){
			printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
		}
	}while(teacher[*lengthTeacher].name[0]=='\0' || check!=0 || teacher[*lengthTeacher].name[0]==' ');
	
	do{
		check=0;
		printf("Enter Teacher's Classroom ID: ");
		fgets(teacher[*lengthTeacher].classroomId,5,stdin);
		if(strcspn(teacher[*lengthTeacher].classroomId, "\n")==strlen(teacher[*lengthTeacher].classroomId)){
			while((getchar())!='\n');
		} else{
			teacher[*lengthTeacher].classroomId[strcspn(teacher[*lengthTeacher].classroomId,"\n")]='\0';
		}
		for(int i=0; i<strlen(teacher[*lengthTeacher].classroomId); i++){
			if(isdigit(teacher[*lengthTeacher].classroomId[i])==0){
				check++;
			}
		}
		if(teacher[*lengthTeacher].classroomId[0]=='\0' || check!=0 || teacher[*lengthTeacher].classroomId[0]==' '){
			printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
		}
	}while(teacher[*lengthTeacher].classroomId[0]=='\0' || check!=0 || teacher[*lengthTeacher].classroomId[0]==' ');
	
	do{
		count=0;
		check=0;
		printf("Enter Teacher's Email: ");
		fgets(teacher[*lengthTeacher].email,30,stdin);
		if(strcspn(teacher[*lengthTeacher].email, "\n")==strlen(teacher[*lengthTeacher].email)){
			while((getchar())!='\n');
		} else{
			teacher[*lengthTeacher].email[strcspn(teacher[*lengthTeacher].email,"\n")]='\0';
		}
		for(int i=0; i<*lengthTeacher; i++){
			if(strcmp(teacher[i].email,teacher[*lengthTeacher].email)==0){
				count++;
			}
		}
		for(int i=0; i<strlen(teacher[*lengthTeacher].email); i++){
			if(isalpha(teacher[*lengthTeacher].email[i])==0 && teacher[*lengthTeacher].email[i]!='@' && teacher[*lengthTeacher].email[i]!='.' && teacher[*lengthTeacher].email[i]!='-' && teacher[*lengthTeacher].email[i]!='_' && isdigit(teacher[*lengthTeacher].email[i])==0){
				check++;
			}
		}
		if(count!=0 || teacher[*lengthTeacher].email[0]=='\0' || check!=0 || teacher[*lengthTeacher].email[0]==' ' || teacher[*lengthTeacher].email[0]=='.' || teacher[*lengthTeacher].email[0]=='@'){
			printf("\n*Email Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
		}
	}while(count!=0 || teacher[*lengthTeacher].email[0]=='\0' || check!=0 || teacher[*lengthTeacher].email[0]==' ' || teacher[*lengthTeacher].email[0]=='.' || teacher[*lengthTeacher].email[0]=='@');
	
	do{
		count=0;
		check=0;
		printf("Enter Teacher's Phone Number: ");
		fgets(teacher[*lengthTeacher].phoneNumber,15,stdin);
		if(strcspn(teacher[*lengthTeacher].phoneNumber, "\n")==strlen(teacher[*lengthTeacher].phoneNumber)){
			while((getchar())!='\n');
		} else{
			teacher[*lengthTeacher].phoneNumber[strcspn(teacher[*lengthTeacher].phoneNumber,"\n")]='\0';
		}
		for(int i=0; i<*lengthTeacher; i++){
			if(strcmp(teacher[i].phoneNumber,teacher[*lengthTeacher].phoneNumber)==0){
				count++;
			}
		}
		for(int i=0; i<strlen(teacher[*lengthTeacher].phoneNumber); i++){
			if(isdigit(teacher[*lengthTeacher].phoneNumber[i])==0){
				check++;
			}
		}
		if(count!=0 || teacher[*lengthTeacher].phoneNumber[0]=='\0' || check!=0 || teacher[*lengthTeacher].phoneNumber[0]==' '){
			printf("\n*PhoneNumber Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
		}
		if(strlen(teacher[*lengthTeacher].phoneNumber)!=10){
			printf("\n*PhoneNumber Must Have 10 Digits*\n\n");
		}
	}while(count!=0 || teacher[*lengthTeacher].phoneNumber[0]=='\0' || check!=0 || teacher[*lengthTeacher].phoneNumber[0]==' ' || strlen(teacher[*lengthTeacher].phoneNumber)!=10);

	printf("\n*Teacher Added Successfully*\n"); 
	(*lengthTeacher)++;
	saveTeacherToFile(teacher, *lengthTeacher,1);
}

void printTeacher(Teacher teacher[], int lengthTeacher){
	printf("\t**ALL TEACHERS**\n\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
	printf("|=======|===========================|==============|================================|==================|\n");
	for(int i=0; i<lengthTeacher; i++){
		printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
		teacher[i].teacherId,
		teacher[i].name,
		teacher[i].classroomId,
		teacher[i].email,
		teacher[i].phoneNumber);
		printf("|=======|===========================|==============|================================|==================|\n");
	}
}

void editTeacher(Teacher teacher[], int lengthTeacher){
	int find, found, count=0, check=0;
	printf("***EDIT TEACHER INFORMATION***\n\n");
	printf("Enter Teacher ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<lengthTeacher; i++){
		if(teacher[i].teacherId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Teacher With This ID*\n");
	} else{
		printf("      TEACHER INFORMATION\n");
		printf("================================\n");
		printf("ID: %d\n", teacher[found].teacherId);
		printf("Full Name: %s\n", teacher[found].name);
		printf("Classroom ID: %s\n", teacher[found].classroomId);
		printf("Email: %s\n", teacher[found].email);
		printf("Phone Number: %s\n", teacher[found].phoneNumber);
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		do{
			count=0;
			printf("Enter Teacher's ID: ");
			if(scanf("%d", &teacher[found].teacherId)==1){
				for(int i=0; i<lengthTeacher; i++){
					if(i!=found && teacher[i].teacherId==teacher[found].teacherId){
						count++;
					}
				}
				if(count!=0 || teacher[found].teacherId<1 || teacher[found].teacherId>99999){
					printf("\n*Teacher ID Must Be Positive And Not Already Exist*\n\n");
				}
			} else{
				printf("\n*Teacher ID Must Be A Number*\n\n");
				while ((getchar()) != '\n');
			}
		}while(count!=0 || teacher[found].teacherId<1 || teacher[found].teacherId>99999);
		getchar();
		
		do{
			check=0;
			printf("Enter Teacher's Full Name: ");
			fgets(teacher[found].name,25,stdin);
			if(strcspn(teacher[found].name,"\n")==strlen(teacher[found].name)){
				while ((getchar()) != '\n');
			} else{
				teacher[found].name[strcspn(teacher[found].name,"\n")]='\0';
			}
			for(int i=0; i<strlen(teacher[found].name); i++){
				if(isalpha(teacher[found].name[i])==0 && teacher[found].name[i] != ' '){
					check++;
				}
			}
			if(teacher[found].name[0]=='\0' || check!=0){
				printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
			}
		}while(teacher[found].name[0]=='\0' || check!=0);
		
		do{
			check=0;
			printf("Enter Teacher's Classroom ID: ");
			fgets(teacher[found].classroomId,5,stdin);
			if(strcspn(teacher[found].classroomId, "\n")==strlen(teacher[found].classroomId)){
				while((getchar())!='\n');
			} else{
				teacher[found].classroomId[strcspn(teacher[found].classroomId,"\n")]='\0';
			}
			for(int i=0; i<strlen(teacher[found].classroomId); i++){
				if(isdigit(teacher[found].classroomId[i])==0){
					check++;
				}
			}
			if(teacher[found].classroomId[0]=='\0' || check!=0){
				printf("\n*Classroom ID Must Not Be Empty Or Be A Negative Number*\n\n");
			}
		}while(teacher[found].classroomId[0]=='\0' || check!=0);
		
		do{
			count=0;
			check=0;
			printf("Enter Teacher's Email: ");
			fgets(teacher[found].email,30,stdin);
			if(strcspn(teacher[found].email, "\n")==strlen(teacher[found].email)){
				while((getchar())!='\n');
			} else{
				teacher[found].email[strcspn(teacher[found].email,"\n")]='\0';
			}
			for(int i=0; i<lengthTeacher; i++){
				if(i!=found && strcmp(teacher[i].email,teacher[found].email)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(teacher[found].email); i++){
				if(isalpha(teacher[found].email[i])==0 && teacher[found].email[i]!='@' && teacher[found].email[i]!='.' && teacher[found].email[i]!='-' && teacher[found].email[i]!='_' && isdigit(teacher[found].email[i])==0){
					check++;
				}
			}
			if(count!=0 || teacher[found].email[0]=='\0' || check!=0){
				printf("\n*Email Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
			}
		}while(count!=0 || teacher[found].email[0]=='\0' || check!=0);
		
		do{
			count=0;
			check=0;
			printf("Enter Teacher's Phone Number: ");
			fgets(teacher[found].phoneNumber,15,stdin);
			if(strcspn(teacher[found].phoneNumber, "\n")==strlen(teacher[found].phoneNumber)){
				while((getchar())!='\n');
			} else{
				teacher[found].phoneNumber[strcspn(teacher[found].phoneNumber,"\n")]='\0';
			}
			for(int i=0; i<lengthTeacher; i++){
				if(i!=found && strcmp(teacher[i].phoneNumber,teacher[found].phoneNumber)==0){
					count++;
				}
			}
			for(int i=0; i<strlen(teacher[found].phoneNumber); i++){
				if(isdigit(teacher[found].phoneNumber[i])==0){
					check++;
				}
			}
			if(count!=0 || teacher[found].phoneNumber[0]=='\0' || check!=0){
				printf("\n*Email Must Not Be Empty, Contain Special Characters, Or Already Exist*\n\n");
			}
		}while(count!=0 || teacher[found].phoneNumber[0]=='\0' || check!=0);
		printf("\n*Teacher's Information Changed Successfully*\n"); 
		saveTeacherToFile(teacher, lengthTeacher, 1);
	}
}

void deleteTeacher(Teacher teacher[], int *lengthTeacher){
	int find, found;
	char yesNo;
	printf("     ***DELETE TEACHER***\n\n");
	printf("Enter Teacher ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<*lengthTeacher; i++){
		if(teacher[i].teacherId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Teacher With This ID*\n");
	} else{
		printf("      TEACHER INFORMATION\n");
		printf("================================\n");
		printf("ID: %d\n", teacher[found].teacherId);
		printf("Full Name: %s\n", teacher[found].name);
		printf("Classroom ID: %s\n", teacher[found].classroomId);
		printf("Email: %s\n", teacher[found].email);
		printf("Phone Number: %s\n", teacher[found].phoneNumber);
		do{
			getchar();
			printf("\n\nAre You Sure You Want To Delete This Teacher? (Y/N): ");
			scanf("%c", &yesNo);
			if(yesNo!='Y' && yesNo!='N'){
				printf("\n\n*Error, Please Try Again*\n");
			}	
		}while(yesNo!='Y' && yesNo!='N');
		if(yesNo=='N'){
			printf("\n*Delete Cancelled*\n");
		} else{
			for(int i=found; i<*lengthTeacher; i++){
				teacher[i]=teacher[i+1];
				
			}
			(*lengthTeacher)--;
			printf("\n*Delete Successful*\n");
			saveTeacherToFile(teacher, *lengthTeacher, 1);
		}
	}
}

void saveTeacherToFile(Teacher teacher[], int lengthTeacher, int a){
	FILE *teacherPtr=fopen("teacherData.dat", "wb");
	if(teacherPtr==NULL){
		printf("\n\n*Can't Open File*\n");
	}
	fwrite(teacher,sizeof(Teacher),lengthTeacher,teacherPtr);
	if(a==1){
		printf("\n*Saved Successfully*\n");
	}
	fclose(teacherPtr);
}

void loadTeacherFromFile(Teacher teacher[], int *lengthTeacher, int a){
	FILE *teacherPtr=fopen("teacherData.dat", "rb");
	if(teacherPtr==NULL){
		printf("Can't Open File");
	}
	*lengthTeacher=fread(teacher, sizeof(Teacher), 100, teacherPtr);
	if(a==1){
		printf("\n*Loaded Successfully*\n");
	}
	fclose(teacherPtr);
}

void searchTeacher(Teacher teacher[], int lengthTeacher){
	int count=0;
	int firstTime;
	char name[30];
	getchar();
	do{
		printf("\nEnter Teacher Name To Search: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name,"\n")]='\0';
		if(strlen(name)<=1){
			printf("\n*Minimum 2 Characters Required, Try Again*\n");
		}
	}while(strlen(name)<=1);
	system("cls");
	printf("\n    SEARCH RESULT FOR \"%s\":\n\n", name);
	firstTime=0;
	for(int i=0; i<lengthTeacher; i++){
		if((strstr(teacher[i].name, name))!= NULL){
			if(firstTime==0){
				printf("|=======|===========================|==============|================================|==================|\n");
				printf("|  ID   |           Name            | classroomId  |             Email              |    PhoneNumber   |\n");
				printf("|=======|===========================|==============|================================|==================|\n");
				firstTime++;
			}
			printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
			teacher[i].teacherId,
			teacher[i].name,
			teacher[i].classroomId,
			teacher[i].email,
			teacher[i].phoneNumber);
			printf("|=======|===========================|==============|================================|==================|\n");
			count++;
		}
	}
	if(count==0){
	printf("*No Result*\n");
	}
}

//classroom

void classroomMenu(){
	printf("***Classroom Management System Using C***\n\n");
	printf("\tCLASSROOM MENU\n");
	printf("================================\n");
	printf("[1] Add A New Classroom\n");
	printf("[2] Show All Classrooms\n");
	printf("[3] Search A Classroom\n");
	printf("[4] Edit A Classroom\n");
	printf("[5] Delete A Classroom\n");
	printf("[6] Sort Classrooms By Name\n");
	printf("[0] Back\n");
	printf("================================\n");
}

void inputClassroom(Classroom classroom[], int *lengthClassroom){
	int count, check, ch;
	printf("\t***Add A New Classroom***\n\n");
	getchar();
	do{
		count=0;
		printf("Enter Classroom's ID: ");
		if(scanf("%d", &classroom[*lengthClassroom].classroomId)==1){
			for(int i=0; i<*lengthClassroom; i++){
				if(classroom[i].classroomId==classroom[*lengthClassroom].classroomId){
					count++;
				}
			}
			if(count!=0 || classroom[*lengthClassroom].classroomId<1 || classroom[*lengthClassroom].classroomId>99999){
				printf("\n*Classroom ID Must Be Positive And Not Already Exist*\n\n");
			}
		} else{
			printf("\n*Classroom ID Must Be A Number*\n\n");
			while ((getchar()) != '\n');
		}
	}while(count!=0 || classroom[*lengthClassroom].classroomId<1 || classroom[*lengthClassroom].classroomId>99999);
	getchar();
	
	do{
		check=0;
		printf("Enter Classroom's Name: ");
		fgets(classroom[*lengthClassroom].name,25,stdin);
		if(strcspn(classroom[*lengthClassroom].name,"\n")==strlen(classroom[*lengthClassroom].name)){
			while ((getchar()) != '\n');
		} else{
			classroom[*lengthClassroom].name[strcspn(classroom[*lengthClassroom].name,"\n")]='\0';
		}
		for(int i=0; i<strlen(classroom[*lengthClassroom].name); i++){
			if(isalpha(classroom[*lengthClassroom].name[i])==0 && isdigit(classroom[*lengthClassroom].name[i])==0 && classroom[*lengthClassroom].name[i] != ' ' && classroom[*lengthClassroom].name[i] != '-' && classroom[*lengthClassroom].name[i] != '_'){
				check++;
			}
		}
		if(classroom[*lengthClassroom].name[0]=='\0' || check!=0 || classroom[*lengthClassroom].name[0]==' '){
			printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
		}
	}while(classroom[*lengthClassroom].name[0]=='\0' || check!=0 || classroom[*lengthClassroom].name[0]==' ');
	
	do{
		check=0;
		printf("Enter Classroom's Teacher ID: ");
		fgets(classroom[*lengthClassroom].teacherId,5,stdin);
		if(strcspn(classroom[*lengthClassroom].teacherId,"\n")==strlen(classroom[*lengthClassroom].teacherId)){
			while ((getchar()) != '\n');
		} else{
			classroom[*lengthClassroom].teacherId[strcspn(classroom[*lengthClassroom].teacherId,"\n")]='\0';
		}
		for(int i=0; i<strlen(classroom[*lengthClassroom].teacherId); i++){
			if(isdigit(classroom[*lengthClassroom].teacherId[i])==0){
				check++;
			}
		}
		if(classroom[*lengthClassroom].teacherId[0]=='\0' || check!=0 || classroom[*lengthClassroom].teacherId[0]==' '){
			printf("\n*Teacher ID Must Not Be Empty Or Be A Negative Number*\n\n");
		}
	}while(classroom[*lengthClassroom].teacherId[0]=='\0' || check!=0 || classroom[*lengthClassroom].teacherId[0]==' ');

	printf("\n*Classroom Added Successfully*\n"); 
	(*lengthClassroom)++;
	saveClassroomToFile(classroom, *lengthClassroom,1);
}

void printClassroom(Classroom classroom[], int lengthClassroom){
	printf("\t**ALL CLASSROOMS**\n\n");
	printf("|=======|===========================|==============|\n");
	printf("|  ID   |           Name            |  teacherId   |\n");
	printf("|=======|===========================|==============|\n");
	for(int i=0; i<lengthClassroom; i++){
		printf("| %-5d | %-25s | %-12s |\n", 
		classroom[i].classroomId,
		classroom[i].name,
		classroom[i].teacherId);
		printf("|=======|===========================|==============|\n");
	}
}

void editClassroom(Classroom classroom[], int lengthClassroom){
	int find, found, count=0, check=0;
	printf("***EDIT CLASSROOM INFORMATION***\n\n");
	printf("Enter Classroom ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<lengthClassroom; i++){
		if(classroom[i].classroomId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Classroom With This ID*\n");
	} else{
		printf("    CLASSROOM INFORMATION\n");
		printf("================================\n");
		printf("Classroom ID: %d\n", classroom[found].classroomId);
		printf("Classroom Name: %s\n", classroom[found].name);
		printf("Teacher ID: %s\n", classroom[found].teacherId);
		printf("\n***UPDATE INFORMATION***\n\n");
		getchar();
		do{
			count=0;
			printf("Enter Classroom's ID: ");
			if(scanf("%d", &classroom[found].classroomId)==1){
				for(int i=0; i<lengthClassroom; i++){
					if(i!=found && classroom[i].classroomId==classroom[found].classroomId){
						count++;
					}
				}
				if(count!=0 || classroom[found].classroomId<1 || classroom[found].classroomId>99999){
					printf("\n*Classroom ID Must Be Positive And Not Already Exist*\n\n");
				}
			} else{
				printf("\n*Classroom ID Must Be A Number*\n\n");
				while ((getchar()) != '\n');
			}
		}while(count!=0 || classroom[found].classroomId<1 || classroom[found].classroomId>99999);
		getchar();
		
		do{
			check=0;
			printf("Enter Classroom's Name: ");
			fgets(classroom[found].name,25,stdin);
			if(strcspn(classroom[found].name,"\n")==strlen(classroom[found].name)){
				while ((getchar()) != '\n');
			} else{
				classroom[found].name[strcspn(classroom[found].name,"\n")]='\0';
			}
			for(int i=0; i<strlen(classroom[found].name); i++){
				if(isalpha(classroom[lengthClassroom].name[i])==0 && isdigit(classroom[lengthClassroom].name[i])==0 && classroom[lengthClassroom].name[i] != ' ' && classroom[lengthClassroom].name[i] != '-' && classroom[lengthClassroom].name[i] != '_'){
					check++;
				}
			}
			if(classroom[found].name[0]=='\0' || check!=0 || classroom[found].name[0]==' '){
				printf("\n*Name Must Not Be Empty Or Contains Special Characters*\n\n");
			}
		}while(classroom[found].name[0]=='\0' || check!=0 || classroom[found].name[0]==' ');
		
		do{
			check=0;
			printf("Enter Classroom's Teacher ID: ");
			fgets(classroom[found].teacherId,5,stdin);
			classroom[found].teacherId[strcspn(classroom[found].teacherId,"\n")]='\0';
			for(int i=0; i<strlen(classroom[found].teacherId); i++){
				if(isdigit(classroom[found].teacherId[i])==0){
					check++;
				}
			}
			if(classroom[found].teacherId[0]=='\0' || check!=0 || classroom[found].teacherId[0]==' '){
				printf("\n*Teacher ID Must Not Be Empty Or Be A Negative Number*\n\n");
			}
		}while(classroom[found].teacherId[0]=='\0' || check!=0 || classroom[found].teacherId[0]==' ');
		printf("\n*Classroom's Information Changed Successfully*\n"); 
		saveClassroomToFile(classroom, lengthClassroom, 1);
	}
}

void deleteClassroom(Classroom classroom[], int *lengthClassroom){
	int find, found;
	char yesNo;
	printf("     ***DELETE CLASSROOM***\n\n");
	printf("Enter Classroom ID: ");
	scanf("%d", &find);
	found=-1;
	for(int i=0;i<*lengthClassroom; i++){
		if(classroom[i].classroomId==find){
			found=i;
		}
	}
	if(found==-1){
		printf("\n*Can't Find Classroom With This ID*\n");
	} else{
		printf("    CLASSROOM INFORMATION\n");
		printf("================================\n");
		printf("Classroom ID: %d\n", classroom[found].classroomId);
		printf("Classroom Name: %s\n", classroom[found].name);
		printf("Teacher ID: %s\n", classroom[found].teacherId);
		do{
			getchar();
			printf("\n\nAre You Sure You Want To Delete This Classroom? (Y/N): ");
			scanf("%c", &yesNo);
			if(yesNo!='Y' && yesNo!='N'){
				printf("\n\n*Error, Please Try Again*\n");
			}	
		}while(yesNo!='Y' && yesNo!='N');
		if(yesNo=='N'){
			printf("\n*Delete Cancelled*\n");
		} else{
			for(int i=found; i<*lengthClassroom; i++){
				classroom[i]=classroom[i+1];
				
			}
			(*lengthClassroom)--;
			printf("\n*Delete Successful*\n");
			saveClassroomToFile(classroom, *lengthClassroom, 1);
		}
	}
}

void sortClassroom(Classroom classroom[], int lengthClassroom){
	int sortOrder;
	if(lengthClassroom<2){
		system("cls");
		printf("*Not Enough Classrooms To Sort*\n");
	} else{
		saveClassroomToFile(classroom, lengthClassroom,0);
		do{
			printf("\nSort By Ascending(0) or Descending(1) order: ");
			scanf("%d", &sortOrder);
		}while(sortOrder!=1 && sortOrder!=0);
		system("cls");
		if(sortOrder==0){
			for(int i=1; i<lengthClassroom; i++){
				Classroom key = classroom[i];
				int j = i-1;
				while(j>=0 && strcmp(key.name, classroom[j].name)<0){
					classroom[j+1]=classroom[j];
					j--;
				}
				classroom[j+1]=key;
			}
		} else{
			for(int i=1; i<lengthClassroom; i++){
				Classroom key = classroom[i];
				int j = i-1;
				while(j>=0 && strcmp(key.name, classroom[j].name)>0){
					classroom[j+1]=classroom[j];
					j--;
				}
				classroom[j+1]=key;
			}
		}
	}
    if(lengthClassroom>=2){
    	printf("\n\t**SORTED STUDENTS**\n\n");
		printf("|=======|===========================|==============|\n");
		printf("|  ID   |           Name            |  teacherId   |\n");
		printf("|=======|===========================|==============|\n");
		for(int i=0; i<lengthClassroom; i++){
			
			printf("| %-5d | %-25s | %-12s |\n", 
			classroom[i].classroomId,
			classroom[i].name,
			classroom[i].teacherId);
			printf("|=======|===========================|==============|\n");
		}
	}
	loadClassroomFromFile(classroom, &lengthClassroom,0);
}

void saveClassroomToFile(Classroom classroom[], int lengthClassroom, int a){
	FILE *classroomPtr=fopen("classroomData.dat", "wb");
	if(classroomPtr==NULL){
		printf("\n\n*Can't Open File*\n");
	}
	fwrite(classroom,sizeof(Classroom),lengthClassroom,classroomPtr);
	if(a==1){
		printf("\n*Saved Successfully*\n");
	}
	fclose(classroomPtr);
}

void loadClassroomFromFile(Classroom classroom[], int *lengthClassroom, int a){
	FILE *classroomPtr=fopen("classroomData.dat", "rb");
	if(classroomPtr==NULL){
		printf("Can't Open File");
	}
	*lengthClassroom=fread(classroom, sizeof(Classroom), 100, classroomPtr);
	if(a==1){
		printf("\n*Loaded Successfully*\n");
	}
	fclose(classroomPtr);
}

void searchClassroom(Classroom classroom[], int lengthClassroom){
	int count=0;
	int firstTime;
	char name[30];
	getchar();
	do{
		printf("\nEnter Classroom Name To Search: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name,"\n")]='\0';
		if(strlen(name)<=1){
			printf("\n*Minimum 2 Characters Required, Try Again*\n");
		}
	}while(strlen(name)<=1);
	system("cls");
	printf("\n    SEARCH RESULT FOR \"%s\":\n\n", name);
	firstTime=0;
	for(int i=0; i<lengthClassroom; i++){
		if((strstr(classroom[i].name, name))!= NULL){
			if(firstTime==0){
				printf("|=======|===========================|==============|\n");
				printf("|  ID   |           Name            |  teacherId   |\n");
				printf("|=======|===========================|==============|\n");
				firstTime++;
			}
			printf("| %-5d | %-25s | %-12s | %-30s | %-16s |\n", 
			classroom[i].classroomId,
			classroom[i].name,
			classroom[i].teacherId);
			printf("|=======|===========================|==============|\n");
			count++;
		}
	}
	if(count==0){
	printf("*No Result*\n");
	}
}
