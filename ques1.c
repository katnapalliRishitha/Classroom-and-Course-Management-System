#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum {FAILURE,SUCCESS} Status_code;

typedef struct Student_tag{
char *name;
char *enrollno;
char courses[5][10];
struct Student_tag *next;	
}Student;


typedef struct Course_student_tag{
char *stu_name;
char *stu_enroll_no;
char *class_name;
int row_no;
int bench_no;
int seat_no;
struct Course_student_tag *next;
}course_stu;


typedef struct Course_tag{
char *course_name;
char slot;
int count;
course_stu *head1;
course_stu *tail1;
struct Course_tag *next;
}Course;


typedef struct Hash_table{
int arr[26];
}Hash;

typedef struct Course_info_for_class{
char *coursename;
char slot;
int opted_stu;
struct Course_info_for_class *next;
}Course_info;

typedef struct Classroom_tag{
char *class_name;
int no_seats;
int no_benches_row;
Course_info *head;
struct Classroom_tag *next;
}Class;

Course *InsertCourse(Course *head,char *str1,char str2){
Course *newcourse=(Course *)malloc(sizeof(Course));
newcourse->course_name=(char *)malloc(strlen(str1)+1);
strcpy(newcourse->course_name,str1);
newcourse->slot=str2;
newcourse->head1=NULL;
newcourse->count=0;
newcourse->tail1=NULL;
newcourse->next=head;
head=newcourse;
return head;
}

void Printcoursedetails(Course *head)
  {
    Course *lptr=head;
    course_stu *nptr;
    
  while(lptr!=NULL)
     {
      nptr=lptr->head1;
       printf("\n%s %c %d\n",lptr->course_name,lptr->slot,lptr->count);
        while(nptr!=NULL)
		{
	     printf("%s %s \n",nptr->stu_name,nptr->stu_enroll_no);
         nptr=nptr->next;
        }
       lptr=lptr->next;
     }
  }
 
void Initialize_table(Hash *stu)
{
int j=0;
for(j=0;j<26;j++)
 {
	  stu->arr[j]=0;
  }
}

void put_courses_in_student(char *str,Student *head,int k){
int i;
for(i=0;i<10;i++)
  {
      head->courses[k][i]=str[i];
  }	
}

course_stu *Initialize(char *str1,char*str2){
course_stu *newstu=(course_stu *)malloc(sizeof(course_stu));
newstu->stu_name=(char *)malloc(strlen(str1)+1);
strcpy(newstu->stu_name,str1);
newstu->stu_enroll_no=(char *)malloc(strlen(str2)+1);
strcpy(newstu->stu_enroll_no,str2);
newstu->row_no=0;
newstu->bench_no=0;
newstu->seat_no=0;
newstu->next=NULL;
return newstu;
}


Status_code InsertStudent(Student **nptr,Course *list_ptr,char *str1,char *str2,char *str3,char *str4,char *str5,char *str6,char *str7){
int i=0;
char *name;
Course *ptr=list_ptr;
Hash stu;
Status_code sc=SUCCESS;
Initialize_table(&stu);

Student *newstudent=(Student *)malloc(sizeof(Student));
newstudent->name=(char *)malloc(strlen(str1)+1);
strcpy(newstudent->name,str1);
newstudent->enrollno=(char *)malloc(strlen(str2)+1);
strcpy(newstudent->enrollno,str2);

while(ptr!=NULL && sc==SUCCESS)
{
	
int index=ptr->slot-'A';

     if(strcmp(str3,ptr->course_name)==0)
	 {
          stu.arr[index]++;
          ptr->count++;
          if(ptr->head1==NULL)
		   {
              ptr->head1=ptr->tail1=Initialize(str1,str2);
           }
         else
	       {
	          ptr->tail1->next=Initialize(str1,str2);
	          ptr->tail1=ptr->tail1->next;
           }

        put_courses_in_student(str3,newstudent,i);	
        i++;
      }
     else if(strcmp(str4,ptr->course_name)==0)
     {
           stu.arr[index]++;
           ptr->count++;
           if(ptr->head1==NULL)
		   {
              ptr->head1=ptr->tail1=Initialize(str1,str2);
           }
           else
		   {
	          ptr->tail1->next=Initialize(str1,str2);
	          ptr->tail1=ptr->tail1->next;
           }

        put_courses_in_student(str4,newstudent,i);	
        i++;
     } 
     else if(strcmp(str5,ptr->course_name)==0)
      {
           stu.arr[index]++;
           ptr->count++;
           if(ptr->head1==NULL)
		   {
               ptr->head1=ptr->tail1=Initialize(str1,str2);
           }
          else
		   {
	           ptr->tail1->next=Initialize(str1,str2);
	           ptr->tail1=ptr->tail1->next;
           }

        put_courses_in_student(str5,newstudent,i);	
        i++;
      }
      else if(strcmp(str6,ptr->course_name)==0)
	  {
            stu.arr[index]++;
            ptr->count++;
            if(ptr->head1==NULL)
			{
               ptr->head1=ptr->tail1=Initialize(str1,str2);
            }
            else
			{
	            ptr->tail1->next=Initialize(str1,str2);
	            ptr->tail1=ptr->tail1->next;
            }

         put_courses_in_student(str6,newstudent,i);
         i++;	
       }
       else if(strcmp(str7,ptr->course_name)==0)
	   {
            stu.arr[index]++;
            ptr->count++;
            if(ptr->head1==NULL)
			{
                ptr->head1=ptr->tail1=Initialize(str1,str2);
            }
            else
			{
	             ptr->tail1->next=Initialize(str1,str2);
	             ptr->tail1=ptr->tail1->next;
            }
          put_courses_in_student(str7,newstudent,i);	
          i++;
       } 
        if(stu.arr[index]>1)
         {
	        printf("Please choose other course.As the slot %c is same for more than one course",'A'+i);
            sc=FAILURE;
            free(newstudent);
            newstudent=NULL;
	        //Printcoursedetails(list_ptr);
	        printf("Enter the input again.....exiting from program\n");
         }
        ptr=ptr->next;
}
      if(newstudent!=NULL){
         if (*nptr != NULL) 
		 {
             newstudent->next = (*nptr);
            (*nptr)= newstudent;
         } 
	     else 
		 {
             *nptr = newstudent;
         }
    }
return sc;
}

void PrintStudentdetails(Student *head)
  {
   Student *lptr=head;
   while(lptr!=NULL)
   {
    printf("--------------------------------------------------------------------\n");
    printf("%s %s %s %s %s %s %s\n",lptr->name,lptr->enrollno,lptr->courses[0],lptr->courses[1],lptr->courses[2],lptr->courses[3],lptr->courses[4]);
    lptr=lptr->next;
   }
    printf("--------------------------------------------------------------------\n");
}
   

Course* delete_student_from_courses(Course *list_ptr, char *enrolnum) 
  {
  	int flag=0;
    Course *nptr = list_ptr;
    while (nptr != NULL) 
	 {
        course_stu *ptr = nptr->head1;
        course_stu *prev = NULL;
        while (ptr != NULL && flag==0) 
		  {
            if (strcmp(ptr->stu_enroll_no, enrolnum) == 0) 
			   {
            	    nptr->count--;
            	    flag=1;
                   if (prev == NULL) 
				    {
                      nptr->head1 = ptr->next;
				    } 
			     	else 
				    {
                    prev->next = ptr->next;
                    }
                     free(ptr);
              } 
		else 
			  {
                prev = ptr;
            
              }
          ptr = ptr->next;  
        }
        nptr = nptr->next;
        flag=0;
    }
    return list_ptr;
}

Student *delete_student(Student *lptr,char *enrolnum)
  {	
     Student *tail=lptr,*newhead=lptr;
     if(tail!=NULL)
	 {
          if(strcmp(tail->enrollno,enrolnum)==0 && tail==lptr)
	       {
             newhead=tail->next;
             free(tail);
           }
          else
	       {	
             while(strcmp((tail->next)->enrollno,enrolnum)!=0)
	         {
  	             tail=tail->next;
             }
  
            Student *nptr=tail->next;
	        tail->next=(tail->next)->next;
            free(nptr);
          }	
    }	
return newhead;
 } 

Course *delete_course(Course *list_ptr,char *coursename){
Course *tail=list_ptr,*newhead=list_ptr;
if(tail!=NULL){
	if(strcmp(tail->course_name,coursename)==0 && tail==list_ptr){
		newhead=tail->next;
		free(tail);
	}
	else{
       while(strcmp((tail->next)->course_name,coursename)!=0){
  	        tail=tail->next;
          }
 Course *nptr=tail->next;
 tail->next=(tail->next)->next;
 free(nptr);
}
}	
return newhead;
}

void shift_courses(int i,Student *nptr){
int j;
for(j=i;j<5;j++){
strcpy(nptr->courses[j],nptr->courses[j+1]);
}
}


Student *delete_course_from_student(Student *lptr,char *course_name){
Student *nptr=lptr;
int i=0;
while(nptr!=NULL){
for(i=0;i<5;i++){
if(strcmp(nptr->courses[i],course_name)==0){
shift_courses(i,nptr);	
}
}
nptr=nptr->next;
}
return lptr;	
}		

Class *InsertClass(Class *head,char *str1,int seats,int no_ben_row){
Class *newclass=(Class *)malloc(sizeof(Class));
newclass->class_name=(char *)malloc(strlen(str1)+1);
strcpy(newclass->class_name,str1);
newclass->no_seats=seats;
newclass->no_benches_row=no_ben_row;
newclass->next=head;
newclass->head=NULL;
head=newclass;
return head;	
}

void Printclass(Class *head){
Class *ptr=head;
while(ptr!=NULL){
printf("----------------------------------------------------------------------------------------------------------\n");
printf("%s %d\n",ptr->class_name,ptr->no_seats);
Course_info *cptr=ptr->head;
while(cptr!=NULL){
printf("----------------\n");
printf("%s-%c-%d\n",cptr->coursename,cptr->slot,cptr->opted_stu);
cptr=cptr->next;
}
printf("\n");
ptr=ptr->next;
}
}

Course_info *Initialize_course_info(Course *ptr){
Course_info *newcourse=(Course_info *)malloc(sizeof(Course_info));
newcourse->coursename=(char *)malloc(strlen(ptr->course_name)+1);
strcpy(newcourse->coursename,ptr->course_name);
newcourse->opted_stu=ptr->count;
newcourse->slot=ptr->slot;
newcourse->next=NULL;
return newcourse;	
}

int lenclass(Class* head)
{
int n;
   if(head == NULL)
   {
   n=0;
   }
   else
   {
   n=lenclass(head->next)+1;
   }
 return n;
}

int lencourses(Course* head)
{
int n;
   if(head == NULL)
   {
   n=0;
   }
   else
   {
   n=lencourses(head->next)+1;
   }
 return n;
}

Class* BubbleSortclass(Class *head)
{
  Class *ptr1=head,*ptr2;
  int n=lenclass(head);
  int i=0;
  while(i<=(n))
  {
       Class *prev=NULL,*temp;
       ptr2 = head;
       while(ptr2 != NULL && ptr2->next!=NULL)
       {
        if(ptr2->no_seats < ptr2->next->no_seats)
         {
            if(prev==NULL)
            {
             head=head->next;
             ptr2->next=head->next;
             head->next=ptr2;
             ptr2=head;
            }
            else
            {
             prev->next = ptr2->next;
             temp=ptr2->next->next;
             ptr2->next->next=ptr2;
             ptr2->next=temp;
             ptr2=prev->next;
            }
         }
        i++;
        prev=ptr2;
        ptr2=ptr2->next;
       }

  }
return head;
}

Course* Bubblesortcourses_stuno(Course *head)
{
  Course *ptr1=head,*ptr2;
  int n=lencourses(head);
  int i=0;
  while(i<=(n))
  {
     Course *prev=NULL,*temp;
       ptr2 = head;
       while(ptr2 != NULL && ptr2->next!=NULL)
       {
        if(ptr2->count< ptr2->next->count)
         {
            if(prev==NULL)
            {
             head=head->next;
             ptr2->next=head->next;
             head->next=ptr2;
             ptr2=head;
            }
            else
            {
             prev->next = ptr2->next;
             temp=ptr2->next->next;
             ptr2->next->next=ptr2;
             ptr2->next=temp;
             ptr2=prev->next;
            }
         }
        i++;
        prev=ptr2;
        ptr2=ptr2->next;
       }

  }
return head;
}


Class *Allot_courses_to_classes(Course *list_ptr,Class *head){
Course *coptr=list_ptr;
Class *clptr=head;
int flag=0;
if(coptr==NULL){	
	printf("no courses to allot seats to\n");
}
else{
while(coptr!=NULL)
     {
        if(clptr==NULL)
	      {
	     printf("no classrooms available to allot\n");

           }
        else
          {
            while(clptr!=NULL && flag==0)
	         {
	    	      flag=0;
              if(clptr->no_seats>coptr->count && coptr->count!=0)
                 {
                  flag=1;
                  if(clptr->head==NULL)
			        {
                       clptr->head=Initialize_course_info(coptr);
                    }
                  else
		            {
                       Course_info *prevnode=NULL;
                       Course_info *ciptr = clptr->head;
                       int flag1 = 1;
                       while (ciptr != NULL && flag1 == 1) 
			             {
                           flag1 = 0;
                           if (ciptr->slot != coptr->slot) 
				             {
                                flag1 = 1;
                             }

                           if (ciptr->next == NULL) 
						      {
                                     prevnode = ciptr;
                              }
                              
                            ciptr = ciptr->next;
                        }
                        if (flag1 == 1) 
						    {
                           prevnode->next = Initialize_course_info(coptr);
                           }
                        if(flag1==0){
                        	flag=0;
                        	clptr=clptr->next;
						}
                   }
                }
           else 
		       {
                 clptr = clptr->next;
               }
             }
if(flag==0)
      {
	      printf("No of students in %s course are more than largest free classroom hence cant allot\n",coptr->course_name);
      }
clptr=head;
flag=0;
coptr=coptr->next;
         }
   }
}
return head;	
}


 Course* Bubblesortcoursesslot(Course *head)
{
  Course *ptr1=head,*ptr2;
  int n=lencourses(head);
  int i=0;
  while(i<=(n))
  {
     Course *prev=NULL,*temp;
       ptr2 = head;
       while(ptr2 != NULL && ptr2->next!=NULL)
       {
        if(ptr2->slot> ptr2->next->slot)
         {
            if(prev==NULL)
            {
             head=head->next;
             ptr2->next=head->next;
             head->next=ptr2;
             ptr2=head;
            }
            else
            {
             prev->next = ptr2->next;
             temp=ptr2->next->next;
             ptr2->next->next=ptr2;
             ptr2->next=temp;
             ptr2=prev->next;
            }
         }
        i++;
        prev=ptr2;
        ptr2=ptr2->next;
       }

  }
return head;
}

void Allot_exam_seats_students(Course *list_ptr,Class *head)
{
int seatno=1, rowno=1,benchno=1;
int next_rowno=1,next_benchno=1,next_seatno=1;
int stu_count=0;
Course *coptr=list_ptr;
course_stu *ciptr;
Class *clptr=head,*prev_classptr;
int flag=0,empty_seats=0;
char prev_slot='\0';
 if(coptr==NULL)
     {
	   printf("No courses to allot seats to\n");
     }
else
    {
      while(coptr!=NULL)
          {
             seatno=1;rowno=1;benchno=1;flag=0;
             stu_count=coptr->count; 
             ciptr=coptr->head1;
             clptr=head;
             if(coptr->slot==prev_slot)
			 {
               seatno=2;
               rowno=1;
               benchno=1; 
              }
              while(clptr!=NULL && flag==0 && stu_count!=0)
                 {
                 empty_seats=seatcalc(clptr->no_benches_row);
                   while(ciptr!=NULL)
                  {
                  	 if(coptr->slot!=prev_slot)
			           {
                           if(clptr->no_seats-empty_seats>=stu_count)
                                {
                                   ciptr->class_name=(char *)malloc(strlen(clptr->class_name)+1);
                                    strcpy(ciptr->class_name,clptr->class_name);
                                    ciptr->row_no=rowno;
                                    ciptr->bench_no=benchno;
                                      ciptr->seat_no=seatno;
                                   if(benchno%2!=0 && seatno%3==0 && benchno%(clptr->no_benches_row)==0){
                            	        benchno=1;
                           	            rowno=rowno+1;
						            }
						           else if(benchno%2==0 && seatno%3!=0 && benchno%(clptr->no_benches_row)==0){
									    benchno=1;
                           	          rowno=rowno+1;
							       } 
							       if(benchno%2!=0 && seatno%3==0){
                            	       benchno=benchno+1;
							       }
							       else if(benchno%2==0 && seatno%3!=0){
							 	       benchno=benchno+1;
							       }
							       seatno=seatno+2;
                                   flag=1;
                                }
                           else
					         {
                     	         ciptr->class_name=(char *)malloc(strlen(clptr->class_name)+1);
                                  strcpy(ciptr->class_name,clptr->class_name);
                                 ciptr->row_no=rowno;
                                 ciptr->bench_no=benchno;
                                 ciptr->seat_no=seatno;
							        
							        if(benchno%2!=0 && seatno%3==0 && benchno%(clptr->no_benches_row)==0){
                                      	benchno=1;
                           	            rowno=rowno+1;
						              }						              
						            else if(benchno%2==0 && seatno%3!=0 && benchno%(clptr->no_benches_row)==0){
							          benchno=1;
                           	          rowno=rowno+1;
						            }
						             else if(benchno%2==0 && seatno%3!=0){
								       benchno=benchno+1;
							          }
							          else if(benchno%2!=0 && seatno%3==0){
                            	        benchno=benchno+1;
							          }						          
						            
							         seatno=seatno+2;
                                   if(seatno==clptr->no_seats || seatno-1==clptr->no_seats)
                                      {
                                        stu_count=stu_count-(clptr->no_seats-empty_seats);
                                        clptr=clptr->next;
                                      empty_seats=seatcalc(clptr->no_benches_row);
                                     seatno=1;
                                      rowno=1;
                                      benchno=1;   
                                      }
							                            
                             }
				       }
				     else
					  {
				     	        if(empty_seats>=stu_count)
                                {
				     	                ciptr->class_name=(char *)malloc(strlen(clptr->class_name)+1);
                                       strcpy(ciptr->class_name,clptr->class_name);
                                       ciptr->row_no=rowno;
                                      ciptr->bench_no=benchno;
                                     ciptr->seat_no=seatno;
                                     if(seatno%3==0){
                                      benchno=benchno+1;
							          }
							        else if(seatno%benchno!=0){
								     benchno=benchno+1;
							        }
						           if(benchno%2!=0 &&benchno%(clptr->no_benches_row)==0){
                            	     benchno=1;
                           	         rowno=rowno+1;
						             }
						          else if(seatno%3==0&&benchno%(clptr->no_benches_row)==0){
						   	       benchno=1;
                           	      rowno=rowno+1;
						          }
						         seatno=seatno+2;
							       flag=1;
                             }
                           else
					        {
                     	    ciptr->class_name=(char *)malloc(strlen(clptr->class_name)+1);
                            strcpy(ciptr->class_name,clptr->class_name);
                            ciptr->row_no=rowno;
                            ciptr->bench_no=benchno;
                            ciptr->seat_no=seatno;
                            if(seatno%3==0){
                            	benchno=benchno+1;
							}
							else if(seatno%benchno!=0){
								benchno=benchno+1;
							}
                            if(benchno%2!=0 && benchno%(clptr->no_benches_row)==0){
                            	benchno=1;
                           	   rowno=rowno+1;
						    }
						    else if(seatno%3==0 && benchno%(clptr->no_benches_row)==0){
							    benchno=1;
                           	   rowno=rowno+1;
							}
							 seatno=seatno+2;
                            if(seatno==clptr->no_seats || seatno-1==clptr->no_seats)
                                {
                                stu_count=stu_count-(clptr->no_seats-empty_seats);
                                clptr=clptr->next;
                                empty_seats=seatcalc(clptr->no_benches_row);
                                seatno=2;
                                rowno=1;
                                benchno=1;   
                               }
							                            
                        }
                   }
                          if(ciptr->next==NULL)
						  {
                       	   prev_slot=coptr->slot;
					      }
				 ciptr=ciptr->next;     	
			  }
		   }
	 coptr=coptr->next;		
       }
}
}


int seatcalc(int no_benches_row){
int sum_empty_seats;
sum_empty_seats=(no_benches_row*3)/2;
return sum_empty_seats*4;
}

void Print_exam_alloted(Course *list_ptr,char slot){
Course *coptr=list_ptr;	
course_stu *ciptr;
while(coptr!=NULL)
  {
   if(coptr->slot==slot)
   {
      printf("%s\n",coptr->course_name);
      ciptr=coptr->head1;
      printf(" The allottment is done in row-bench-seat format \n");
      while(ciptr!=NULL)
	  {
	  printf("%s %s %s    %d  %d  %d\n",ciptr->stu_name,ciptr->stu_enroll_no,ciptr->class_name,ciptr->row_no,ciptr->bench_no,ciptr->seat_no);
	  ciptr=ciptr->next;
      }
   }
 coptr=coptr->next;
 printf("\n");
}	
}

 
        
           
            

