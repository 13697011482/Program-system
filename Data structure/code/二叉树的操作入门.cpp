#include<iostream>
using namespace std;

typedef char DataType;

class BiTreeNode    //�������ڵ���
{
public:
     DataType data;
	 BiTreeNode *leftChild;
	 BiTreeNode *rightChild;
};

class Stack        //ջ�ڵ���
{
public:
	BiTreeNode *curr;
	Stack *next;
};

class LQNode      //��ʽ���нڵ���
{
public:
	BiTreeNode *curr;
	LQNode *next;
};

class LQueue
{
public:
	LQNode *front;    //��ͷָ��
	LQNode *rear;     //��βָ��
};



//�������Ļ��������������յĸ��ڵ㣩
void Initiate(BiTreeNode **root)   //��ʼ���������ĸ��ڵ�
{
     *root=new BiTreeNode();
	 (*root)->leftChild=NULL;
	 (*root)->rightChild=NULL;
}

BiTreeNode *InsertLeftChild(BiTreeNode *curr,DataType x)   //�������ӽڵ�
{
     BiTreeNode *s,*t;
	 if(curr==NULL){
	       return NULL;
	 }
	 t=curr->leftChild;
	 s=new BiTreeNode();
	 s->rightChild=NULL;
	 s->data=x;
	 curr->leftChild=s;
	 s->leftChild=t;
	 return curr->leftChild;
}

BiTreeNode *InsertRightChild(BiTreeNode *curr,DataType x)  //�����Һ��ӽڵ�
{
     BiTreeNode *s,*t;
	 if(curr==NULL)return NULL;
	 t=curr->rightChild;
	 s=new BiTreeNode();
	 s->leftChild=NULL;
	 s->data=x;
	 curr->rightChild=s;
	 s->rightChild=t;
	 return curr->rightChild;
}


void Destroy(BiTreeNode **root)    //���ٶ�����
{
     if((*root)!=NULL&&(*root)->leftChild!=NULL)
		 Destroy(&(*root)->leftChild);
	 if((*root)!=NULL&&(*root)->rightChild!=NULL)
		 Destroy(&(*root)->rightChild);
	 free(*root);
}

//ջ�Ļ�����������ʽ�ṹ����ͷ�ڵ㣩

void InitiateStack(Stack **head)   //��ʼ��ջ
{
	(*head)=new Stack();
	(*head)->curr=NULL;
	(*head)->next=NULL;
}

void StackPush(Stack *head,BiTreeNode *p)  //��ջ
{
	if(p==NULL)
		return;
    Stack *s=new Stack();
	s->curr=new BiTreeNode();
	s->curr->data=p->data;
	s->curr->leftChild=p->leftChild;
	s->curr->rightChild=p->rightChild;
	s->next=head->next;
	head->next=s;
}

bool StackPop(Stack *head,BiTreeNode *p)   //��ջ
{
    if(head->next!=NULL)
	{
	     Stack *temp=head->next;
		 p->data=temp->curr->data;
		 p->leftChild=temp->curr->leftChild;
		 p->rightChild=temp->curr->rightChild;
		 head->next=temp->next;
		 free(temp->curr);
		 free(temp);
		 return true;
	}
	else
		 return false;
}

void Destroy(Stack **head)   //����ջ��ͷ�ڵ�
{
    free(*head);
}

//���еĻ�������
void QueueInitiate(LQueue **head)
{
	*head=new LQueue();
	(*head)->front=NULL;
	(*head)->rear=NULL;
}

void QueueAppend(LQueue *head,BiTreeNode *p)    //�����
{
    LQNode *q=new LQNode();
	q->curr=new BiTreeNode();
	q->curr->data=p->data;
	q->curr->leftChild=p->leftChild;
	q->curr->rightChild=p->rightChild;
	q->next=NULL;
	if(head->rear!=NULL)
		head->rear->next=q;
	head->rear=q;
	if(head->front==NULL)
		head->front=q;
}

void QueueGetNode(LQueue *head,BiTreeNode *p)   //������
{
	if(head->front==NULL)
		return;
	LQNode *temp=head->front;
	p->data=head->front->curr->data;
	p->leftChild=head->front->curr->leftChild;
	p->rightChild=head->front->curr->rightChild;
	head->front=head->front->next;
	free(temp->curr);
	free(temp);
}

void Destroy(LQueue **head)   //����
{
     free(*head);
}

//�����������

void PreOrder(BiTreeNode *root,Stack *head)    //�ǵݹ�ǰ������������ڵ�
{
	BiTreeNode *p=new BiTreeNode();
	StackPush(head,root);
    while(head->next!=NULL)
	{
	     StackPop(head,p);
		 cout<<p->data<<" ";
		 if(p->rightChild!=NULL)
		   StackPush(head,p->rightChild); 
		 if(p->rightChild!=NULL)
		   StackPush(head,p->leftChild);
	}
}


void InOrder(BiTreeNode *root,Stack *head)    //�ǵݹ���������������ڵ�
{
	BiTreeNode *q=root->leftChild,*p= new BiTreeNode();
	StackPush(head,root);  //�˴�������Ϊ�˽�������ѭ��
	while(head->next!=NULL)
	{
		while(q!=NULL){          //�Ȱ����нڵ��������ջ
			StackPush(head,q);
			q=q->leftChild;
		}
		if(head->next!=NULL)
		{
		    StackPop(head,p);
			cout<<p->data<<" ";
			if(p->rightChild!=NULL){
				StackPush(head,p->rightChild);      //������ĳһ���ڵ����������Ϊ�գ�����ǰ��ջ��������Ϊ�޷�������ڵ��������
				q=p->rightChild->leftChild;         //��¼���ڵ���������λ��
			}
		}
	}
}

void PostOrder(BiTreeNode *root,void visit(DataType item))     //�ݹ����������������
{
    if(root!=NULL)
	{
		PostOrder(root->leftChild,visit);
		PostOrder(root->rightChild,visit);
		visit(root->data);
	}
}

void visit(DataType item)
{
     cout<<item<<" ";
}

void PrintBiTree(BiTreeNode *root,LQueue *Q)  //�������Ĳ���������
{
	BiTreeNode *q=new BiTreeNode();
	QueueAppend(Q,root);
	while(Q->front!=NULL)
	{
         QueueGetNode(Q,q);
		 cout<<q->data<<" ";
		 if(q->leftChild!=NULL)
			 QueueAppend(Q,q->leftChild);
		 if(q->rightChild!=NULL)
			 QueueAppend(Q,q->rightChild);
	}
}

int BiTreeDepth(BiTreeNode *root)    //������������
{
    if(root==NULL)
		return 0;
	int LeftDepth=BiTreeDepth(root->leftChild);
	int RightDepth=BiTreeDepth(root->rightChild);
	return LeftDepth>RightDepth?LeftDepth+1:RightDepth+1;
}

void PrintLeaves(BiTreeNode *root,void visit(DataType item))    //�ú���������Ҷ�ڵ�
{
	if(root!=NULL)
	{
		PrintLeaves(root->leftChild,visit);
		PrintLeaves(root->rightChild,visit);
		if(root->leftChild==NULL&&root->rightChild==NULL)
			visit(root->data);
	}
}

void PrintNotLeaves(BiTreeNode *root,LQueue *Q)    //ʹ�ò�����������Ҷ�ڵ�
{
	BiTreeNode *p=new BiTreeNode();
	QueueAppend(Q,root);
	while(Q->front!=NULL)
	{
		QueueGetNode(Q,p);
		if(p->leftChild!=NULL&&p->rightChild!=NULL)
			cout<<p->data<<" ";
		if(p->leftChild!=NULL)
			QueueAppend(Q,p->leftChild);
		if(p->rightChild!=NULL)
			QueueAppend(Q,p->rightChild);
	}
}
int main()
{
	BiTreeNode *root,*p,*q;
	Stack *head;
	LQueue *Q;
	Initiate(&root);
	InitiateStack(&head);
	QueueInitiate(&Q);
	//������������ڵ����������������
	//step1:������ڵ��������
	root->data='A';
	p=InsertLeftChild(root,'B');
	q=p;
	p=InsertLeftChild(p,'C');
	q=InsertRightChild(q,'D');
	q=p;
	p=InsertLeftChild(p,'E');
	q=InsertRightChild(q,'F');
	//step2:������ڵ��������
	p=InsertRightChild(root,'G');
	q=p;
	p=InsertLeftChild(p,'H');
	q=InsertRightChild(q,'I');
	q=p;
	p=InsertLeftChild(p,'J');
	q=InsertRightChild(q,'K');
	cout<<"ǰ��";
	PreOrder(root,head);   //ǰ��
	cout<<endl;
	cout<<"����";
	InOrder(root,head);    //����
	cout<<endl;
	cout<<"����";
	PostOrder(root,visit);      //����
	cout<<endl;
	cout<<"����";
	PrintBiTree(root,Q);     //����
	cout<<endl;
	cout<<"�ö����������Ϊ��"<<BiTreeDepth(root)<<endl;
	cout<<"���������Ҷ�ڵ㣺";
	PrintLeaves(root,visit);
	cout<<endl;
	cout<<"��������ķ�Ҷ�ڵ㣺";
	PrintNotLeaves(root,Q);
	cout<<endl;
	Destroy(&root);
	Destroy(&head);
	Destroy(&Q);
	system("pause");
	return 0;
}