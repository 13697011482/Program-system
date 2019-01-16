#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"searchMenu.h"
#include"studentshow.h"

extern Student *head;

void showAllByCategory(enum studentcategory category)
{
    int page=1,allpage,count=0,choose;
	Student *p1=head;
	while(p1!=NULL){
	    if(p1->category==category)
			count++;
		p1=p1->next;
	}
	if(count<=10)
		allpage=1;
	else if(count%10==0){
	    allpage=count/10;
	}
	else allpage=count/10+1;
	do{
		if(page==1&&allpage==1){
		     printf("======================================================================\n");
			 getPage(page,category);
			 printf("----------------------------------------------------------------------\n");
			 printf("             ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��0������\n",page,allpage);
			 printf("======================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==1&&allpage>1){
			 printf("=============================================================================\n");
			 getPage(page,category);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��2����һҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("==============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page>1&&page!=allpage){
		     printf("================================================================================================\n");
			 getPage(page,category);
			 printf("------------------------------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��2����һҳ ��3����ҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("================================================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==allpage){
			 printf("=============================================================================\n");
			 getPage(page,category);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��3����ҳ��0���˳�\n",page,allpage);
			 printf("=============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		if(choose==1)
			page--;
		if(choose==2)
			page++;
		if(choose==3)
			page=1;
		if(choose==4)
			page=allpage;
		if(choose==0)break;
		system("cls");
	}while(1);
	printf("��ѯ�������밴���������...\n");
	getchar();
	system("cls");
}

void showByClass(enum studentcategory category,char *specialty,char *classes)
{
	int page=1,allpage,count=0,choose;
	Student *p1=head;
	while(p1!=NULL){
	    if(p1->category==category&&strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0)
			count++;
		p1=p1->next;
	}
	if(count<=10)
		allpage=1;
	else if(count%10==0){
	    allpage=count/10;
	}
	else allpage=count/10+1;
	do{
		if(page==1&&allpage==1){
		     printf("======================================================================\n");
			 getPageByClasses(category,specialty,classes,page);
			 printf("----------------------------------------------------------------------\n");
			 printf("             ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��0������\n",page,allpage);
			 printf("======================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==1&&allpage>1){
			 printf("=============================================================================\n");
			 getPageByClasses(category,specialty,classes,page);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��2����һҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("==============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page>1&&page!=allpage){
		     printf("================================================================================================\n");
			 getPageByClasses(category,specialty,classes,page);
			 printf("------------------------------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��2����һҳ ��3����ҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("================================================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==allpage){
			 printf("=============================================================================\n");
			 getPageByClasses(category,specialty,classes,page);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��3����ҳ��0���˳�\n",page,allpage);
			 printf("=============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		if(choose==1)
			page--;
		if(choose==2)
			page++;
		if(choose==3)
			page=1;
		if(choose==4)
			page=allpage;
		if(choose==0)break;
		system("cls");
	}while(1);
	printf("��ѯ�������밴���������...\n");
	getchar();
	system("cls");
}

void showById(int id)    /*����ѧ����ʾ������Ϣ*/
{
    Student *p=head;
	while(p!=NULL){
	    if(p->id==id)break;
		p=p->next;
	}
	if(p==NULL){
	      printf("û���ҵ�������Ϣ...\n");
		  getchar();
		  getchar();
		  system("cls");
		  return;
	}
	else {
		printf("���ҵ�������Ϣ��\n");
		show_one_student(p);
		printf("�밴���������...\n");
		getchar();
		getchar();
		system("cls");
	}
}

void showByName(char *name)
{
	 Student *p=head;
	while(p!=NULL){
	    if(strcmp(p->name,name)==0)break;
		p=p->next;
	}
	if(p==NULL){
	      printf("û���ҵ�������Ϣ...\n");
		  getchar();
		  getchar();
		  system("cls");
		  return;
	}
	else {
		printf("���ҵ�������Ϣ��n");
		show_one_student(p);
		printf("�밴���������...\n");
		getchar();
		getchar();
		system("cls");
	}
}

void showFailByClassCourse(char *specialty,char *classes,int course)
{
    int page=1,allpage,count=0,choose;
	Student *p1=head;
	while(p1!=NULL){
	    if(strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0&&course==1&&p1->math>=0&&p1->math<60)
			count++;
		else if(strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0&&course==2&&p1->english>=0&&p1->english<60)
			count++;
		else if(strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0&&course==3&&p1->clanguage>=0&&p1->clanguage<60)
			count++;
		else if(strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0&&course==4&&p1->comprehensive>=0&&p1->comprehensive<60)
			count++;
		else if(strcmp(p1->specialty,specialty)==0&&strcmp(p1->classes,classes)==0&&course==5&&p1->thesis>=0&&p1->thesis<60)
			count++;
		p1=p1->next;
	}
	if(count==0){
	   printf("û���ҵ�����ѧ������Ϣ...\n");
	   getchar();
	   getchar();
	   system("cls");
	}
	if(count<=10)
		allpage=1;
	else if(count%10==0){
	    allpage=count/10;
	}
	else allpage=count/10+1;
	do{
		if(page==1&&allpage==1){
			 printf("                     ���ſ�Ŀ�����������Ϊ%dλ                 \n",count);
		     printf("======================================================================\n");
			 getPageFailByClassCourse(specialty,classes,course,page);
			 printf("----------------------------------------------------------------------\n");
			 printf("             ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��0������\n",page,allpage);
			 printf("======================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==1&&allpage>1){
			 printf("                       ���ſ�Ŀ�����������Ϊ%dλ                      \n",count);
			 printf("=============================================================================\n");
			 getPageFailByClassCourse(specialty,classes,course,page);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��2����һҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("=============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page>1&&page!=allpage){
			 printf("                                ���ſ�Ŀ�����������Ϊ%dλ                                \n",count);
		     printf("================================================================================================\n");
			 getPageFailByClassCourse(specialty,classes,course,page);
			 printf("------------------------------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��2����һҳ ��3����ҳ ��4��βҳ ��0���˳�\n",page,allpage);
			 printf("================================================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=2&&choose!=4&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		else if(page==allpage){
			 printf("                        ���ſ�Ŀ�����������Ϊ%dλ                     \n",count);
			 printf("=============================================================================\n");
			 getPageFailByClassCourse(specialty,classes,course,page);
			 printf("-----------------------------------------------------------------------------\n");
			 printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��3����ҳ��0���˳�\n",page,allpage);
			 printf("=============================================================================\n");
			 do{
			   printf("��ѡ��>>");
			   scanf("%d",&choose);
			   if(choose!=0&&choose!=1&&choose!=3)
				   printf("��������������ѡ��...\n");
			   else break;
			 }while(1);
		}
		if(choose==1)
			page--;
		if(choose==2)
			page++;
		if(choose==3)
			page=1;
		if(choose==4)
			page=allpage;
		if(choose==0)break;
		system("cls");
	}while(1);
	printf("��ѯ�������밴���������...\n");
	getchar();
	system("cls");
}