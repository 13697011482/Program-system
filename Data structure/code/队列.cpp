#include"��ʽ����.h"
#include<iostream>

int main()
{
	 DataType x;
     LQueue p;
	 QueueInitiate(&p);
	 for(int i=0;i<6;i++)
	 {
	      scanf("%d",&x);
		  QueueAppend(&p,x);
	 }
	 QueueDelete(&p,&x);
	 printf("��ɾ����Ԫ���ǣ�%d\n",x);
	 for(int i=0;i<6;i++)
	 {
	        if(QueueDelete(&p,&x))
			     printf("%d\n",x);
	 }
	 system("pause");
	 return 0;
}