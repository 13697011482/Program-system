#include<iostream>
using namespace std;
const int MAXSIZE=12;
static int num;
int a[MAXSIZE][MAXSIZE] =

{{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},     

{ 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1},     

{-1, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0,-1},    

{-1, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1,-1},    

{-1,-1,-1, 0,-1,-1,-1, 0,-1,-1, 0,-1},    

{-1, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1},

{-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1},

{-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1},

{-1, 0,-1,-1,-1,-1, 0,-1,-1,-1, 0,-1},

{-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},

{-1, 0, 0, 0, 0,-1,-1, 0,-1, 0, 0, 0},

{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

void print()     //����Թ�·��
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
	       if(a[i][j]==-1)
			   cout<<"= ";
		   else if(a[i][j]==0)
			   cout<<"  ";
		   else
			   cout<<"* ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}

void find(int i,int j)
{
	a[i][j]=1;            //��ǵ�ǰ���
	if(i==10&&j==11){
	       num++;
		   print();
		   a[i][j]=0;
		   return;
	}
	if(i-1>-1&&a[i-1][j]==0){
	       find(i-1,j);   //����Ѱ��
	}
	if(i+1<MAXSIZE&&a[i+1][j]==0){
	       find(i+1,j);  //����Ѱ��
	}
	if(j-1>-1&&a[i][j-1]==0){
	       find(i,j-1);  //����Ѱ��
	}
	if(j+1<MAXSIZE&&a[i][j+1]==0){
	       find(i,j+1); //����Ѱ��      
	}
	{
        a[i][j]=0;   
        return;
	}

}

int main()
{
	  cout<<"����Թ���״"<<endl;
	  print();
	  cout<<"�������·��"<<endl;
      find(1,0);     //�����λ�ò���4
	  cout<<"һ��"<<num<<"�ִ�"<<endl;
	  system("pause");    
	  return 0;
}
