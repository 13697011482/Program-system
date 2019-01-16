#include<iostream>
#include<malloc.h>
#include<math.h>
using namespace std;
typedef struct node
{
      int x;  //ϵ��
	  int n;  //ָ��
	  int symbol;   //��ÿ������ʽ��Ϊһ�����壬��������Ϊ����ʱ��symbioΪ1������Ϊ������ʱΪ-1;
	  node *next;
}LNode;

void ListInitiate(LNode **head)             //�����ʼ��
{
      (*head)=(LNode *)malloc(sizeof(LNode));
	  (*head)->next=NULL;
	  (*head)->symbol=1;
}

void ListInset(LNode *head,int x,int n)     //����������,����ʱ����xΪ�½ڵ��ϵ����nΪ�½ڵ��ָ��
{
      LNode *temp=(LNode *)malloc(sizeof(LNode)),*p=head,*q=NULL;
	  temp->x=x;
	  temp->n=n;
	  temp->symbol=1;
	  while(p->next!=NULL&&p->n<n)     //ѡ�����λ�ã������½ڵ�
	  {
		     q=p;
	         p=p->next;
	  }
	  if(p->next==NULL&&p->n<n)      //�ҵ�����λ�ú󣬽��в������
	  {
	         p->next=temp;
			 temp->next=NULL;
	  }
	  else
	  {
	         q->next=temp;
			 temp->next=p;
	  }
}

LNode *ListApp(LNode *head1,LNode *head2)    //�����������
{
      LNode *head,*p=head1->next,*q=head2->next,*temp,*s;
	  ListInitiate(&head);
	  s=head;
	  while(p!=NULL&&q!=NULL)     //�˴��Ƚ�������кϲ����������Ϊ�˷���������������ܹ�ͬʱ���У����Դ˴��Ὠ��һ��������������ϲ���Ķ���ʽ
	  {
	          if(p->n<=q->n)      //�˴��������ʱ�临�Ӷ�ΪO��n��;
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=p->x;
				   temp->n=p->n;
				   temp->symbol=1;
				   p=p->next;
			  }
			  else
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=q->x;
				   temp->n=q->n;
				   temp->symbol=1;
				   q=q->next;
			  }
			  s->next=temp;
			  temp->next=NULL;
			  s=temp;
	  }
	  while(p!=NULL)       //�˴��������ʣ�µĻ�û�������һ��������ֱ����������������
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=p->x;
		  temp->n=p->n;
		  temp->symbol=p->symbol;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  p=p->next;
	  }
	  while(q!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=q->x;
		  temp->n=q->n;
		  temp->symbol=q->symbol;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  q=q->next;
	  }
	  s=head->next;
	  if(s==NULL)
		  return head;
	  while(s->next!=NULL)   //���������ָ����ͬ�����
	  {
	        if(s->n==s->next->n)     //ָ����ͬ�Ľ�����Ӳ��������Ѷ���֮�͸�ֵ��ǰһ���ڵ㴦����һ���ڵ���ɾ��
			{
			       s->x*=s->symbol;
				   s->next->x*=s->next->symbol;
				   s->x+=s->next->x;
				   LNode *temp=s->next;
				   s->next=s->next->next;
				   free(temp);
			}
			else 
			{
				   s->x*=s->symbol;
				   s=s->next;
			}
			if(s==NULL)
				break;
	  }
	  return head;     //�Ż��������ͷָ��
}

LNode *ListSubstract(LNode *head1,LNode *head2)    //�����������
{
      LNode *head,*p=head1->next,*q=head2->next,*temp,*s;
	  ListInitiate(&head);
	  s=head;
	  q->symbol=-1;
	  while(p!=NULL&&q!=NULL)
	  {
	          if(p->n<=q->n)
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=p->x;
				   temp->n=p->n;
				   temp->symbol=1;
				   p=p->next;
			  }
			  else
			  {
			       temp=(LNode *)malloc(sizeof(LNode));
				   temp->x=q->x*-1;
				   temp->n=q->n;
				   temp->symbol=-1;
				   q=q->next;
			  }
			  s->next=temp;
			  temp->next=NULL;
			  s=temp;
	  }
	  while(p!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=p->x;
		  temp->n=p->n;
		  temp->symbol=1;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  p=p->next;
	  }
	  while(q!=NULL)
	  {
		  temp=(LNode *)malloc(sizeof(LNode));
		  temp->x=q->x*-1;
		  temp->n=q->n;
		  temp->symbol=-1;
		  temp->next=NULL;
		  s->next=temp;
		  s=temp;
		  q=q->next;
	  }
	  //�������
	  s=head->next;
	  if(s==NULL)
		  return head;
	  while(s->next!=NULL)   //ָ����ͬ�����
	  {
	        if(s->n==s->next->n)
			{
				   s->x+=s->next->x;
				   LNode *temp=s->next;
				   s->next=s->next->next;
				   free(temp);
			}
			else
			{
			       s=s->next;
			}
			if(s==NULL)
				break;
	  }
	  return head;       
}

void ListOutput(LNode *head)    //���
{
     LNode *p=head->next;
	 while(p->x==0)    //����һ��ϵ����Ϊ0�Ľڵ�λ��
		 p=p->next;
	 if(p->n!=0)       //�������ʽ�ĵ�һ��
		 cout<<p->x<<"X^"<<p->n;
	 else 
		 cout<<p->x;
	 p=p->next;
	 while(p!=NULL)
	 {
		 if(p->x==0)    //�������ʽϵ��Ϊ0�������
		 {
		       p=p->next;
			   continue;
		 }
		 if(p->x>0)    //�ж϶���ʽ�ķ���
			 cout<<"+";
		 else if(p->x<0) 
			 cout<<"-";
		 if(p->n!=0)  
			 cout<<abs(p->x)<<"X"<<"^"<<p->n;
		 else
			 cout<<abs(p->x);
		 p=p->next;
	 }
}

void ListDestroy(LNode *head)
{
     LNode *p=head;
	 while(head!=NULL)
	 {
	      head=head->next;
		  free(p);
		  p=head;
	 }
}

int main()
{
	int x=1,n;
    LNode *head1,*head2,*head3=NULL,*head4=NULL;
	ListInitiate(&head1);
	ListInitiate(&head2);
	cout<<"��ֱ���������һԪ����ʽÿһ���ϵ����ָ����ϵ������0ʱ�˳�"<<endl;
	cout<<"�������һ��һԪ����ʽ��"<<endl;
    while(x!=0)
   {
	    cin>>x;
		if(x==0)
			break;
		cin>>n;
		ListInset(head1,x,n);
   }
	cout<<"������ڶ���һԪ����ʽ:"<<endl;
	x=1;
	while(x!=0)
   {
	    cin>>x;
		if(x==0)
			break;
		cin>>n;
		ListInset(head2,x,n);
   }
   head3=ListApp(head1,head2);
   cout<<"��ʽ�ӷֱ�Ϊ��"<<endl;
   ListOutput(head1);
   cout<<endl;
   ListOutput(head2);
   cout<<endl;
   cout<<"��ʽ��ӣ�";
   ListOutput(head3);
   cout<<endl;
   head4=ListSubstract(head1,head2);
   cout<<"��ʽ�����";
   ListOutput(head4);
   cout<<endl;
   ListDestroy(head1);
   ListDestroy(head2);
   ListDestroy(head3);
   ListDestroy(head4);
   system("pause");
   return 0;
}