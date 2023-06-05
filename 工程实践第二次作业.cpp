#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����γ���Ϣ�ṹ��
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

// ��ʼ������ͷָ��
//Course *head = NULL;

//��ʼ���γ���Ϣ
Course *initial_course(Course *head){
	FILE* fp = fopen("class.txt", "r");
	if (NULL == fp)
	{
		printf("���ļ�ʧ�ܣ���\n");
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
// ���һ���µĿγ�
void add_course(Course *head) {
	FILE* fp = fopen("class.txt", "a");
	
    Course *new_course = (Course*)malloc(sizeof(Course));
    
    printf("������γ����ƣ�");
    scanf("%s", new_course->name);
    printf("������γ̱�ţ�");
    scanf("%d", &new_course->id);
    printf("������γ����ʣ�");
    scanf("%s", new_course->type);
    printf("��������ѧʱ��");
    scanf("%d", &new_course->totalPeriod);
    printf("�������Ͽ�ѧʱ��");
    scanf("%d", &new_course->classPeriod);
    printf("������ʵ��ѧʱ��");
    scanf("%d", &new_course->experiPeriod);
    printf("������ѧ������");
    scanf("%d", &new_course->credit);
	printf("������ѧ�ڣ�");
	scanf("%d", &new_course->term);
	printf("�������Ͽ�ʱ�䣺");
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
   printf("\n��ӿγ̳ɹ���\n\n");
}

// �޸�һ��ָ����ŵĿγ���Ϣ
void modify_course(Course *head) {
	FILE* fp = fopen("class.txt", "w");
	
    int id;
    int fla=0;
    printf("\n������Ҫ�޸ĵĿγ̱��: ");
	scanf("%d", &id);

   Course *current = head;

   while(current != NULL) {
       if(current->id == id) {
            printf("������γ����ƣ�");
    		scanf("%s", current->name);
    		printf("������γ̱�ţ�");
    		scanf("%d", &current->id);
    		printf("������γ����ʣ�");
    		scanf("%s", current->type);
    		printf("��������ѧʱ��");
    		scanf("%d", &current->totalPeriod);
    		printf("�������Ͽ�ѧʱ��");
    		scanf("%d", &current->classPeriod);
    		printf("������ʵ��ѧʱ��");
    		scanf("%d", &current->experiPeriod);
    		printf("������ѧ������");
    		scanf("%d", &current->credit);
			printf("������ѧ�ڣ�");
			scanf("%d", &current->term);
			printf("�������Ͽ�ʱ�䣺");
			scanf("%s", &current->time);

           	printf("\n�ÿγ��ѳɹ��޸�!\n\n");
           	
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

   if(fla==0) printf("\n�Ҳ�����Ӧ�Ŀγ̣������ź��������룡\n\n");
   
   fclose(fp);
}

// ɾ��һ��ָ����ŵĿγ�
void delete_course(Course *head) {
	FILE* fp = fopen("class.txt", "w");
	
    int fla=0;
	int id;
    printf("\n������Ҫɾ���Ŀγ̱��: ");
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
					printf("\n�ÿγ��ѳɹ�ɾ��!\n\n");
					fla = 1;
					break;
				}
            }

			free(current);
            printf("\n�ÿγ��ѳɹ�ɾ��!\n\n");
            
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

    if(fla==0) printf("\n�Ҳ�����Ӧ�Ŀγ̣������ź��������룡\n\n");
    
    fclose(fp);
}

// ������пγ���Ϣ
void display_courses(Course *head) {
   Course *current = head;

   if(head == NULL) {
       printf("\n�����κογ���Ϣ������¼���µĿγ̡�\n\n");
       return;
   }

   printf("---------------------�γ���Ϣ-----------------------\n");
   while(current != NULL) {
        printf("�γ����ƣ�%s\n",current->name);
    	printf("�γ̱�ţ�%d\n",current->id);
    	printf("�γ����ʣ�%s\n",current->type);
    	printf("��ѧʱ��%d\n",current->totalPeriod);
    	printf("�Ͽ�ѧʱ��%d\n",current->classPeriod);
    	printf("ʵ��ѧʱ��%d\n",current->experiPeriod);
    	printf("ѧ������%d\n",current->credit);
		printf("ѧ�ڣ�%d\n",current->term);
		printf("�Ͽ�ʱ�䣺%s\n",current->time);
       printf("\n");
       current = current -> next;
   }
}

//��ѧ�ֲ�ѯ��
void find_in_score(Course *head){
	int credit;
	int num=0 ;
    printf("\n������ѧ��: ");
    scanf("%d", &credit);
    
	Course *current = head;
	
	if(head == NULL) {
       printf("\nû�ж�Ӧѧ�ֵĿγ̡�\n\n");
       return;
    }
    
    printf("\n\t\t\t��Ӧѧ�ֵĿγ�\n");
    printf("--------------------------------------------------------\n");
    while(current != NULL){
    	if(current->credit==credit){
    		printf("�γ����ƣ�%s\n",current->name);
    		printf("�γ̱�ţ�%d\n",current->id);
    		printf("�γ����ʣ�%s\n",current->type);
    		printf("��ѧʱ��%d\n",current->totalPeriod);
    		printf("�Ͽ�ѧʱ��%d\n",current->classPeriod);
    		printf("ʵ��ѧʱ��%d\n",current->experiPeriod);
    		printf("ѧ������%d\n",current->credit);
			printf("ѧ�ڣ�%d\n",current->term);
			printf("�Ͽ�ʱ�䣺%s\n",current->time);
       		printf("\n");
       		current=current->next;
       		num++;
		}else{
			current=current->next;
		} 
	} 
	if(num==0) printf("\n�Բ���û�ж�Ӧѧ�ֵĿγ̡�\n\n");
} 

//��ѧ�ں��Ͽ�ʱ���ѯ 
int find_in_term(int term, char time[],Course *head){

	int num=0 ;
    
	Course *current = head;
	
	if(head == NULL) {
       printf("\nû�ж�Ӧѧ�ڵĿγ̡�\n\n");
       return NULL;
    }
    
    printf("\n\t\t\t��Ӧѧ�ڵĿγ�\n");
    printf("--------------------------------------------------------\n");
    while(current != NULL){
    	if(current->term==term&&strcmp(current->time,time)==0){
    		printf("�γ����ƣ�%s\n",current->name);
    		printf("�γ̱�ţ�%d\n",current->id);
    		printf("�γ����ʣ�%s\n",current->type);
    		printf("��ѧʱ��%d\n",current->totalPeriod);
    		printf("�Ͽ�ѧʱ��%d\n",current->classPeriod);
    		printf("ʵ��ѧʱ��%d\n",current->experiPeriod);
    		printf("ѧ������%d\n",current->credit);
			printf("ѧ�ڣ�%d\n",current->term);
			printf("�Ͽ�ʱ�䣺%s\n",current->time);
       		printf("\n");
       		current=current->next;
       		num++;
		}else{
			current=current->next;
		} 
	} 
	if(num==0) printf("\n�Բ���û�ж�Ӧѧ�ڻ��Ͽ�ʱ��Ŀγ̡�\n\n");
	return num;
} 

//���ѧ���γ̵��ļ� 
void add_classes(int term , char time[],Course *head){
	FILE* fp = fopen("student.txt", "a");
	
	int id; 
	int fla=0;
	printf("��������Ҫѡ��γ̵Ŀγ̱���:");
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
       		
       		printf("\n��ӿγ̳ɹ���\n\n");
       		fla=1;
       		break;
		}else{
			current=current->next;
		} 
	} 
	fclose(fp);
	
	if(fla==0) printf("\nû���ҵ���Ӧ�Ŀγ̣�\n\n"); 
} 

//��ȡ�ļ��е�ѧ���α� 
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

//���ѧ��ѡ���ļ�
void clear(){
	FILE* fp = fopen("student.txt", "w");
	fclose(fp); 
} 

//�鿴ѧ���α�
void watch_list(Course *head_student){
	
	
	head_student=list(head_student); 
	Course *current = head_student;

   if(head_student == NULL) {
       printf("\n�����κογ���Ϣ�����Ƚ���ѡ�Ρ�\n\n");
       return;
   }

   printf("\n\t\t\t��Ŀα�\n");
   printf("--------------------------------------------------------\n");
   while(current != NULL) {
        printf("�γ����ƣ�%s\n",current->name);
    	printf("�γ̱�ţ�%d\n",current->id);
    	printf("�γ����ʣ�%s\n",current->type);
    	printf("��ѧʱ��%d\n",current->totalPeriod);
    	printf("�Ͽ�ѧʱ��%d\n",current->classPeriod);
    	printf("ʵ��ѧʱ��%d\n",current->experiPeriod);
    	printf("ѧ������%d\n",current->credit);
		printf("ѧ�ڣ�%d\n",current->term);
		printf("�Ͽ�ʱ�䣺%s\n",current->time);
       printf("\n");
       current = current -> next;
   }
} 

//�鿴��ѧ��
void watch_credit(Course *head_student){
	
	
	head_student=list(head_student); 
	
	Course *current = head_student;
	
	int all_credit=0; 
	
	if(head_student == NULL) {
       printf("\n�����κογ���Ϣ�����Ƚ���ѡ�Ρ�\n\n");
       return;
   }
   
   while(current != NULL) {
    	all_credit += current->credit;
        current = current -> next;
   }
   
   printf("\n�����ѧ��Ϊ��%d\n",all_credit);
   printf("\nע�⣺��ѡ������60ѧ�ֵĿγ̣������Ҫ����80ѧ�֡�\n");
} 

//ѡ��
void choose_classes(Course *head){
	
	Course *head_student=NULL;
	int choice;
	int term;
	char time[50];
	int fla;
	printf("\n������ѧ��: ");
    scanf("%d", &term);
    printf("\n�������Ͽ�ʱ��:");
    scanf("%s", &time);
    
	fla = find_in_term(term,time,head);
	if(fla!=0) add_classes(term,time,head);
	
	while(1) {
        printf("----------------------ѧ��ѡ��ϵͳ----------------------\n");
        printf("1. ����ѡ��                                          \n");
        printf("2. �鿴�α�                                          \n");
        printf("3. �鿴��ѧ��                                        \n");
        printf("4. �˳�ϵͳ                                          \n");
        printf("--------------------------------------------------------\n");

        printf("����������ѡ��(1-4): ");
        scanf("%d", &choice);

         switch(choice) {
            case 1:
                printf("\n�������Ͽ�ʱ��:");
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
               printf("\n��Ч��ѡ�����������룡\n\n");
         }
    }
}

// ���˵�
void main_menu(Course *head) {
    int choice;

    while(1) {
        printf("\n\t\t\tѧ��ѡ�ι���ϵͳ\n");
        printf("-----------------------���˵�---------------------------\n");
        printf("1. ���һ���µĿγ�                                \n");
        printf("2. �޸�һ��ָ����ŵĿγ�                          \n");
        printf("3. ɾ��һ��ָ����ŵĿγ�                          \n");
        printf("4. ������пγ���Ϣ                                \n");
        printf("5. ����ѧ�־��пγ̲�ѯ                            \n");
        printf("6. �������ѡ��                                    \n");
        printf("7. �˳�ϵͳ                                        \n");
        printf("--------------------------------------------------------\n");

        printf("����������ѡ��(1-7): ");
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
               printf("\n��Ч��ѡ�����������룡\n\n");
         }
    }
}

int main() {
    // �������˵�
    Course *head = NULL;
    head =initial_course(head);
    main_menu(head);

    return 0;
}
