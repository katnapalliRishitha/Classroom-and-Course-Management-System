#include<stdio.h>
#include "ques1.c"
#include<stdlib.h>
#include<string.h>

int main(){
FILE *fptr1,*fptr2,*fptr4,*copy;
char *str1,str,*str2,*str3,*str4,*str5,*str6,*str7,line[100],*enrollnum,*coursename,line1[100];
Class *head=NULL;
Course *list_ptr=NULL;
Student *lptr=NULL;

int ch;
fptr1=fopen("courseinfo.txt","r");
printf("--------------------------------------------------------------------\n");
printf("COURSENAME  -  SLOT\n");
while((fgets(line,100,fptr1))!=NULL){
 str1 = (char*) malloc(50 * sizeof(char));
sscanf(line,"%s %c",str1,&str);
printf("%s\t%c\n",str1,str);
list_ptr=InsertCourse(list_ptr,str1,str);
free(str1);
}
fclose(fptr1);

fptr2=fopen("stu.txt","r");
Status_code sc=SUCCESS;
    
      while((fgets(line,100,fptr2))!=NULL && sc==SUCCESS)
	  {
        str1 = (char*) malloc(50 * sizeof(char));
          str2 = (char*) malloc(50 * sizeof(char));
            str3 = (char*) malloc(50 * sizeof(char));
              str4 = (char*) malloc(50 * sizeof(char));
                str5= (char*) malloc(50 * sizeof(char));
                   str6 = (char*) malloc(50 * sizeof(char));
                      str7 = (char*) malloc(50 * sizeof(char));
                         sscanf(line,"%s %s %s %s %s %s %s",str1,str2,str3,str4,str5,str6,str7);
                         //printf("%s %s %s %s %s %s %s\n",str1,str2,str3,str4,str5,str6,str7);
                         sc=InsertStudent(&lptr,list_ptr,str1,str2,str3,str4,str5,str6,str7);
                      free(str1);
                  free(str2);
                free(str3);
             free(str4);
        free(str5);
       free(str6);
     free(str7);
      }
      fclose(fptr2);
      
	  if(sc!=FAILURE)
	  {
         PrintStudentdetails(lptr);
      } 
	  
	  
	    
printf("--------------------------------------------------------------------\n");
do{
	printf("\t\tMENU");
    printf("\n-------------------------------------\n");
    printf("PRESS 1.Adding a student to the student-list. ");
    printf("\nPRESS 2.Deletion of a student from the student-list.");
    printf("\nPRESS 3.Adding a course to the course list.");
    printf("\nPRESS 4.Allotment of classrooms for lectures. ");
    printf("\nPRESS 5.Allotment of classrooms for exams.");
    printf("\nPRESS 6.Print the list of students and the exam seat allotted to each student for a given slot.");
    printf("\nPRESS 7.TO EXIT.");
    printf("\n-------------------------------------\n");
    printf("Enter Your Choice: ");
    scanf("%d",&ch);
switch(ch){
case 1:
     {
      printf("Enter Student name : ");
      str1 = (char*) malloc(50 * sizeof(char));
      scanf("%s",str1);
      printf("Enter Students Enrollment no: ");
      str2 = (char*) malloc(50 * sizeof(char));
      scanf("%s",str2);
      printf("Enter 5 courses to register: ");
      str3 = (char*) malloc(50 * sizeof(char));
      str4 = (char*) malloc(50 * sizeof(char));
      str5= (char*) malloc(50 * sizeof(char));
      str6 = (char*) malloc(50 * sizeof(char));
      str7 = (char*) malloc(50 * sizeof(char));
      scanf("%s %s %s %s %s",str3,str4,str5,str6,str7);
      sc=InsertStudent(&lptr,list_ptr,str1,str2,str3,str4,str5,str6,str7);
      free(str1);
      free(str2);
      free(str3);
      free(str4);
      free(str5);
      free(str6);
      free(str7);
      if(sc!=FAILURE)
	  {
         PrintStudentdetails(lptr);
      } 	  
      break;
    }
case 2:
      { 
	  	
       printf("Enter Student Enrollment Number to delete the student info:");
       enrollnum=(char*) malloc(50 * sizeof(char));
       scanf("%s",enrollnum);
       list_ptr=delete_student_from_courses(list_ptr,enrollnum);
       lptr=delete_student(lptr,enrollnum);
       PrintStudentdetails(lptr);
       Printcoursedetails(list_ptr);
       break;
     }
case 3:
     {
     	char slot;
     	printf("Enter course name to add in Course_list : ");
        str1 = (char*) malloc(50 * sizeof(char));
        scanf("%s",str1);
        fflush(stdin);
     	printf("Enter the slot for given course: ");
     	scanf("%c",&slot);
        list_ptr=InsertCourse(list_ptr,str1,slot);
        free(str1);
	    Printcoursedetails(list_ptr);
	   
       printf("Enter Coursename to delete the course:");
       coursename=(char*) malloc(50 * sizeof(char));
       scanf("%s",coursename);
       lptr=delete_course_from_student(lptr,coursename);
       list_ptr=delete_course(list_ptr,coursename);
       PrintStudentdetails(lptr);
       Printcoursedetails(list_ptr);
       break;
    }
case 4:
	{
      int seats,no_ben_row;
       fptr4=fopen("classroominfo.txt","r");
       printf("CLASSNAME -  SEATS\n");
      while(fgets(line1,100,fptr4)!=NULL){
        str1 = (char*) malloc(50 * sizeof(char));
        sscanf(line1,"%s %d",str1,&seats);
        no_ben_row =(seats/12); // classroom capacity(no_of_seats)  must be a multiple of 12
        head=InsertClass(head,str1,seats,no_ben_row);
        free(str1);
     }
       head=BubbleSortclass(head);
       list_ptr=Bubblesortcourses_stuno(list_ptr);
       head= Allot_courses_to_classes(list_ptr,head);
       Printclass(head);
      fclose(fptr4);
      break;
   }
case 5:
	{
	  list_ptr=Bubblesortcoursesslot(list_ptr);
	  Allot_exam_seats_students(list_ptr,head);
	  break;
	}
case 6:
	{ 
	 char slot;
	 printf("Enter a slot to Print the list of students and the exam seat allotted to each student :");
	 fflush(stdin);
	 scanf("%c",&slot);
     Print_exam_alloted(list_ptr,slot);
     break;
	}
}
}while(ch!=7);
}


