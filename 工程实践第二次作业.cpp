#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义课程信息结构体
typedef struct course {
    char name[50];
    int id;
    char type[10];
    int totalPeriod;
	int classPeriod;
	int experiPeriod;	
    int credit;
    int term;
    char time[50];
    struct course *next;
} Course;

// 初始化链表头指针
//Course *head = NULL;

//初始化课程信息
Course *initial_course(Course *head){
	FILE* fp = fopen("class.txt", "r");
	if (NULL == fp)
	{
		printf("打开文件失败！！\n");
		exit(0);
	}
	while(!feof(fp))
	{
		Course *new_course = (Course*)malloc(sizeof(Course));
		fscanf(fp, "%s %d %s %d %d %d %d %d %s\n",
			new_course->name,
			&new_course->id,
			new_course->type,
			&new_course->totalPeriod,
			&new_course->classPeriod,
			&new_course->experiPeriod,
			&new_course->credit,
			&new_course->term,
			new_course->time);
		new_course->next= NULL;
		if(head == NULL) {
       		head = new_course;
   		} else {
       		Course *current = head;
       		while(current->next != NULL) {
           		current = current -> next;
       		}
       		current -> next = new_course;
   		}
	}
	fclose(fp); 
	return head;
}
// 添加一门新的课程
void add_course(Course *head) {
	FILE* fp = fopen("class.txt", "a");
	
    Course *new_course = (Course*)malloc(sizeof(Course));
    
    printf("请输入课程名称：");
    scanf("%s", new_course->name);
    printf("请输入课程编号：");
    scanf("%d", &new_course->id);
    printf("请输入课程性质：");
    scanf("%s", new_course->type);
    printf("请输入总学时：");
    scanf("%d", &new_course->totalPeriod);
    printf("请输入上课学时：");
    scanf("%d", &new_course->classPeriod);
    printf("请输入实验学时：");
    scanf("%d", &new_course->experiPeriod);
    printf("请输入学分数：");
    scanf("%d", &new_course->credit);
	printf("请输入学期：");
	scanf("%d", &new_course->term);
	printf("请输入上课时间：");
	scanf("%s", new_course->time);
	
    new_course->next= NULL;
    
	fputs(" ",fp);
	fputs(new_course->name,fp);
	fputs(" ",fp);
    fprintf(fp,"%d",new_course->id);
    fputs(" ",fp);
    fputs(new_course->type,fp);
    fputs(" ",fp);
    fprintf(fp,"%d",new_course->totalPeriod);
    fputs(" ",fp);
    fprintf(fp,"%d",new_course->classPeriod);
    fputs(" ",fp);
    fprintf(fp,"%d",new_course->experiPeriod);
    fputs(" ",fp);
    fprintf(fp,"%d",new_course->credit);
    fputs(" ",fp);
    fprintf(fp,"%d",new_course->term);
    fputs(" ",fp);
    fputs(new_course->time,fp);
    fputs(" ",fp);

   if(head == NULL) {
       head = new_course;
   } else {
       Course *current = head;
       while(current->next != NULL) {
           current = current -> next;
       }
       current -> next = new_course;
   }
   
   fclose(fp);
   printf("\n添加课程成功！\n\n");
}

// 修改一门指定编号的课程信息
void modify_course(Course *head) {
	FILE* fp = fopen("class.txt", "w");
	
    int id;
    int fla=0;
    printf("\n请输入要修改的课程编号: ");
	scanf("%d", &id);

   Course *current = head;

   while(current != NULL) {
       if(current->id == id) {
            printf("请输入课程名称：");
    		scanf("%s", current->name);
    		printf("请输入课程编号：");
    		scanf("%d", &current->id);
    		printf("请输入课程性质：");
    		scanf("%s", current->type);
    		printf("请输入总学时：");
    		scanf("%d", &current->totalPeriod);
    		printf("请输入上课学时：");
    		scanf("%d", &current->classPeriod);
    		printf("请输入实验学时：");
    		scanf("%d", &current->experiPeriod);
    		printf("请输入学分数：");
    		scanf("%d", &current->credit);
			printf("请输入学期：");
			scanf("%d", &current->term);
			printf("请输入上课时间：");
			scanf("%s", &current->time);

           	printf("\n该课程已成功修改!\n\n");
           	
           	fputs(current->name,fp);
			fputs(" ",fp);
    		fprintf(fp,"%d",current->id);
    		fputs(" ",fp);
    		fputs(current->type,fp);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->totalPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->classPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->experiPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->credit);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->term);
    		fputs(" ",fp);
    		fputs(current->time,fp);
    		fputs(" ",fp);
    		
           	fla=1; 
           	
           	current = current->next;
       } else {
           fputs(current->name,fp);
			fputs(" ",fp);
    		fprintf(fp,"%d",current->id);
    		fputs(" ",fp);
    		fputs(current->type,fp);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->totalPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->classPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->experiPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->credit);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->term);
    		fputs(" ",fp);
    		fputs(current->time,fp);
    		fputs(" ",fp);
    		
		   current = current->next;
       }
   }

   if(fla==0) printf("\n找不到对应的课程，请检查编号后重新输入！\n\n");
   
   fclose(fp);
}

// 删除一门指定编号的课程
void delete_course(Course *head) {
	FILE* fp = fopen("class.txt", "w");
	
    int fla=0;
	int id;
    printf("\n请输入要删除的课程编号: ");
    scanf("%d", &id);

    Course *current = head, *prev;

    while(current != NULL) {
        if(current->id == id) {
            if(current == head) {
                head = current->next;
                fla = 2;
            } else {
                if(current->next != NULL){
                	prev -> next = current -> next;
                	fla = 3;
				}else{
					prev->next = NULL;
					printf("\n该课程已成功删除!\n\n");
					fla = 1;
					break;
				}
            }

			free(current);
            printf("\n该课程已成功删除!\n\n");
            
            if(fla == 2) current = head;
            if(fla == 3) current = prev -> next;
            
        } else {
        	fputs(current->name,fp);
			fputs(" ",fp);
    		fprintf(fp,"%d",current->id);
    		fputs(" ",fp);
    		fputs(current->type,fp);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->totalPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->classPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->experiPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->credit);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->term);
    		fputs(" ",fp);
    		fputs(current->time,fp);
    		fputs(" ",fp);
    		
            prev = current;
            current = current -> next;
        }
    }

    if(fla==0) printf("\n找不到对应的课程，请检查编号后重新输入！\n\n");
    
    fclose(fp);
}

// 浏览所有课程信息
void display_courses(Course *head) {
   Course *current = head;

   if(head == NULL) {
       printf("\n暂无任何课程信息，请先录入新的课程。\n\n");
       return;
   }

   printf("---------------------课程信息-----------------------\n");
   while(current != NULL) {
        printf("课程名称：%s\n",current->name);
    	printf("课程编号：%d\n",current->id);
    	printf("课程性质：%s\n",current->type);
    	printf("总学时：%d\n",current->totalPeriod);
    	printf("上课学时：%d\n",current->classPeriod);
    	printf("实验学时：%d\n",current->experiPeriod);
    	printf("学分数：%d\n",current->credit);
		printf("学期：%d\n",current->term);
		printf("上课时间：%s\n",current->time);
       printf("\n");
       current = current -> next;
   }
}

//用学分查询；
void find_in_score(Course *head){
	int credit;
	int num=0 ;
    printf("\n请输入学分: ");
    scanf("%d", &credit);
    
	Course *current = head;
	
	if(head == NULL) {
       printf("\n没有对应学分的课程。\n\n");
       return;
    }
    
    printf("\n\t\t\t对应学分的课程\n");
    printf("--------------------------------------------------------\n");
    while(current != NULL){
    	if(current->credit==credit){
    		printf("课程名称：%s\n",current->name);
    		printf("课程编号：%d\n",current->id);
    		printf("课程性质：%s\n",current->type);
    		printf("总学时：%d\n",current->totalPeriod);
    		printf("上课学时：%d\n",current->classPeriod);
    		printf("实验学时：%d\n",current->experiPeriod);
    		printf("学分数：%d\n",current->credit);
			printf("学期：%d\n",current->term);
			printf("上课时间：%s\n",current->time);
       		printf("\n");
       		current=current->next;
       		num++;
		}else{
			current=current->next;
		} 
	} 
	if(num==0) printf("\n对不起，没有对应学分的课程。\n\n");
} 

//用学期和上课时间查询 
int find_in_term(int term, char time[],Course *head){

	int num=0 ;
    
	Course *current = head;
	
	if(head == NULL) {
       printf("\n没有对应学期的课程。\n\n");
       return NULL;
    }
    
    printf("\n\t\t\t对应学期的课程\n");
    printf("--------------------------------------------------------\n");
    while(current != NULL){
    	if(current->term==term&&strcmp(current->time,time)==0){
    		printf("课程名称：%s\n",current->name);
    		printf("课程编号：%d\n",current->id);
    		printf("课程性质：%s\n",current->type);
    		printf("总学时：%d\n",current->totalPeriod);
    		printf("上课学时：%d\n",current->classPeriod);
    		printf("实验学时：%d\n",current->experiPeriod);
    		printf("学分数：%d\n",current->credit);
			printf("学期：%d\n",current->term);
			printf("上课时间：%s\n",current->time);
       		printf("\n");
       		current=current->next;
       		num++;
		}else{
			current=current->next;
		} 
	} 
	if(num==0) printf("\n对不起，没有对应学期或上课时间的课程。\n\n");
	return num;
} 

//添加学生课程到文件 
void add_classes(int term , char time[],Course *head){
	FILE* fp = fopen("student.txt", "a");
	
	int id; 
	int fla=0;
	printf("请输入你要选择课程的课程编码:");
	scanf("%d",&id);
	
	Course *current = head;
	
	while(current != NULL){
    	if(current->term == term&&current->id == id&&strcmp(current->time,time)==0){
			
			fputs(current->name,fp);
			fputs(" ",fp);
    		fprintf(fp,"%d",current->id);
    		fputs(" ",fp);
    		fputs(current->type,fp);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->totalPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->classPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->experiPeriod);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->credit);
    		fputs(" ",fp);
    		fprintf(fp,"%d",current->term);
    		fputs(" ",fp);
    		fputs(current->time,fp);
    		fputs(" ",fp);
    		
       		current=current->next;
       		
       		printf("\n添加课程成功！\n\n");
       		fla=1;
       		break;
		}else{
			current=current->next;
		} 
	} 
	fclose(fp);
	
	if(fla==0) printf("\n没有找到相应的课程！\n\n"); 
} 

//读取文件中的学生课表 
Course *list(Course *head_student){
	FILE* fp = fopen("student.txt", "r");
	
	while(!feof(fp))
	{
		Course *student_list = (Course*)malloc(sizeof(Course));
		fscanf(fp, "%s %d %s %d %d %d %d %d %s\n",
			student_list->name,
			&student_list->id,
			student_list->type,
			&student_list->totalPeriod,
			&student_list->classPeriod,
			&student_list->experiPeriod,
			&student_list->credit,
			&student_list->term,
			student_list->time);
		student_list->next= NULL;
		if(head_student == NULL) {
       		head_student = student_list;
   		} else {
       		Course *stu_current = head_student;
       		while(stu_current->next != NULL) {
           		stu_current = stu_current -> next;
       		}
       		stu_current -> next = student_list;
   		}
	}
	fclose(fp); 
	return(head_student);
}

//清除学生选课文件
void clear(){
	FILE* fp = fopen("student.txt", "w");
	fclose(fp); 
} 

//查看学生课表
void watch_list(Course *head_student){
	
	
	head_student=list(head_student); 
	Course *current = head_student;

   if(head_student == NULL) {
       printf("\n暂无任何课程信息，请先进行选课。\n\n");
       return;
   }

   printf("\n\t\t\t你的课表\n");
   printf("--------------------------------------------------------\n");
   while(current != NULL) {
        printf("课程名称：%s\n",current->name);
    	printf("课程编号：%d\n",current->id);
    	printf("课程性质：%s\n",current->type);
    	printf("总学时：%d\n",current->totalPeriod);
    	printf("上课学时：%d\n",current->classPeriod);
    	printf("实验学时：%d\n",current->experiPeriod);
    	printf("学分数：%d\n",current->credit);
		printf("学期：%d\n",current->term);
		printf("上课时间：%s\n",current->time);
       printf("\n");
       current = current -> next;
   }
} 

//查看总学分
void watch_credit(Course *head_student){
	
	
	head_student=list(head_student); 
	
	Course *current = head_student;
	
	int all_credit=0; 
	
	if(head_student == NULL) {
       printf("\n暂无任何课程信息，请先进行选课。\n\n");
       return;
   }
   
   while(current != NULL) {
    	all_credit += current->credit;
        current = current -> next;
   }
   
   printf("\n你的总学分为：%d\n",all_credit);
   printf("\n注意：请选够至少60学分的课程，但最后不要超过80学分。\n");
} 

//选课
void choose_classes(Course *head){
	
	Course *head_student=NULL;
	int choice;
	int term;
	char time[50];
	int fla;
	printf("\n请输入学期: ");
    scanf("%d", &term);
    printf("\n请输入上课时间:");
    scanf("%s", &time);
    
	fla = find_in_term(term,time,head);
	if(fla!=0) add_classes(term,time,head);
	
	while(1) {
        printf("----------------------学生选课系统----------------------\n");
        printf("1. 继续选课                                          \n");
        printf("2. 查看课表                                          \n");
        printf("3. 查看总学分                                        \n");
        printf("4. 退出系统                                          \n");
        printf("--------------------------------------------------------\n");

        printf("请输入您的选择(1-4): ");
        scanf("%d", &choice);

         switch(choice) {
            case 1:
                printf("\n请输入上课时间:");
    			scanf("%s", &time);
				fla = find_in_term(term,time,head);
				if(fla!=0) add_classes(term,time,head);
                break;

            case 2:
                watch_list(head_student);
                break;

            case 3:
                watch_credit(head_student);
                break;
					
            case 4:
            	clear();
                exit(0);

            default:
               printf("\n无效的选择，请重新输入！\n\n");
         }
    }
}

// 主菜单
void main_menu(Course *head) {
    int choice;

    while(1) {
        printf("\n\t\t\t学生选课管理系统\n");
        printf("-----------------------主菜单---------------------------\n");
        printf("1. 添加一门新的课程                                \n");
        printf("2. 修改一门指定编号的课程                          \n");
        printf("3. 删除一门指定编号的课程                          \n");
        printf("4. 浏览所有课程信息                                \n");
        printf("5. 按照学分经行课程查询                            \n");
        printf("6. 进入进行选课                                    \n");
        printf("7. 退出系统                                        \n");
        printf("--------------------------------------------------------\n");

        printf("请输入您的选择(1-7): ");
        scanf("%d", &choice);

         switch(choice) {
            case 1:
                add_course(head);
                break;

            case 2:
                modify_course(head);
                break;

            case 3:
                delete_course(head);
                break;

            case 4:
                display_courses(head);
                break;
			
			case 5:
				find_in_score(head);
				break;
			
			case 6:
				choose_classes(head);
				break;
					
            case 7:
                exit(0);

            default:
               printf("\n无效的选择，请重新输入！\n\n");
         }
    }
}

int main() {
    // 运行主菜单
    Course *head = NULL;
    head =initial_course(head);
    main_menu(head);

    return 0;
}
