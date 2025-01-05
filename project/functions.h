#include "dataTypes.h"

void roleMenu();
void login();
void manageMenu();
void studentMenu();
void inputStudent(Student student[], int *length);
void printStudent(Student student[], int length);
void editStudent(Student student[], int length);
void backAndExit();
void deleteStudent(Student student[], int *length);
void sortStudent(Student student[], int length);
void saveStudentToFile(Student student[], int length, int a);
void loadStudentFromFile(Student student[], int *length, int a);
void searchStudent(Student student[], int length);

//teacher
void teacherMenu();
void inputTeacher(Teacher teacher[], int *lengthTeacher);
void printTeacher(Teacher teacher[], int lengthTeacher);
void editTeacher(Teacher teacher[], int lengthTeacher);
void deleteTeacher(Teacher teacher[], int *lengthTeacher);
void saveTeacherToFile(Teacher teacher[], int lengthTeacher, int a);
void loadTeacherFromFile(Teacher teacher[], int *lengthTeacher, int a);
void searchTeacher(Teacher teacher[], int lengthTeacher);
