#include<iostream>
using namespace std;
const int MAXSIZE=10;
const int MAXSIZEWEIGHT=10;
int V[MAXSIZE],W[MAXSIZE];
int value[MAXSIZE][MAXSIZEWEIGHT];

int findMaxValue(int N,int M)
{
    for(int i=1;i<=N;i++)
	{
	      for(int j=1;j<=M;j++)
		  {
		       if(W[i]>j)
				   value[i][j]=value[i-1][j];
			   else
			   {
			       value[i][j]=value[i-1][j]>(value[i-1][j-W[i]]+V[i])?value[i-1][j]:value[i-1][j-W[i]]+V[i];
			   }
		  }
	}
	return value[N][M];
}





int main()
{
     int N,M;
	 cout<<"��������Ʒ�������Լ�������������";
	 cin>>N>>M;
	 for(int i=1;i<=N;i++)
	 {
	       cout<<"��"<<i+1<<"����Ʒ�ļ�ֵ�Լ����:";
		   cin>>V[i]>>W[i];
	 }
	 memset(value,0,sizeof(int));
	 cout<<"���������ܴ���������ֵΪ��"<<findMaxValue(N,M)<<endl;
	 system("pause");
	 return 0;
}