#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef char DataType;
const int MAXSIZE=10;
const int MAXWEIGHT=99;

class RowColWeight
{
public:
     int row;
	 int col;
	 int weight;
	 RowColWeight(int r,int c,int w)
	 {
	      row=r;
		  col=c;
		  weight=w;
	 }
};

class node    
{
public:
	int des;
	int weight;
	node()
	{
	}
	node(int des,int weight)
	{
	    this->des=des;
		this->weight=weight;
	}
};

class GraphOne      //��Ӿ���
{
public:
	vector<DataType>vertices;
	int edge[MAXSIZE][MAXSIZE];
	int numOfVer;   //��¼����������Ϊ����Ƶ��ʹ�����������Żض����������������������ʱ���ڴ�����
	GraphOne();
	void InsertEdge(int v1,int v2,int Weight);   //�����
	void InsertVertices(DataType data);    //���붥��
	void show();     //����ڽӾ���
	int GetFirstVertices(int v);   //ȡ��һ���ڽӽڵ�
	int GetNextVertices(int v1,int v2);     //ȡ�ڶ����ڽӽڵ�
	void DepthFSearch(int visited[],int v);  //�����������
	void BroadFSearch(int visited[],int v);  //�����������
	void SearchMinTree(queue<node>&lowVer);   //����С������
};


class vertices
{
public:
	DataType data;
	vector<node>adj;
	vertices(DataType data)
	{
	      this->data=data;
	}
};

class GraphTwo   //�ڽӱ�
{
public:
	vector<vertices>ver;
	int numOfVer;
	int numOfEdge;
	GraphTwo()
	{
	     numOfVer=0;
		 numOfEdge=0;
	}
	void InsertVertices(DataType ver);
	void InsertEdge(int v1,int v2,int weight);
	int GetFirstNode(int v,node& n);    //����ʱ����1�����򷵻�2
	int GetNextNode(int v1,int v2,node& n);
	void show();
};


//��Ӿ����Ա����ʵ��

GraphOne::GraphOne()
{
     for(int i=0;i<MAXSIZE;i++)
	 {
	      for(int j=0;j<MAXSIZE;j++)
		  {
		      if(i==j)
				  this->edge[i][j]=0;
			  else
				  this->edge[i][j]=MAXWEIGHT;
		  }
	 }
	 numOfVer=0;
}

void GraphOne::InsertEdge(int v1,int v2,int Weight)   //�����
{
	if(v1<0||v1>this->numOfVer-1||v2<0||v2>this->numOfVer-1||v1==v2)
	{
	       cout<<"����Ĳ�������"<<endl;
		   return;
	}
	this->edge[v1][v2]=Weight;
	this->edge[v2][v1]=Weight;
}

void GraphOne::InsertVertices(DataType data)    //���붥��
{
	if(this->numOfVer>MAXSIZE)
	{
	     cout<<"��ǰ�Ķ��������ѳ������Χ"<<endl;
		 return;
	}
	(this->vertices).push_back(data);
	this->numOfVer++;
}

void GraphOne::show()
{
	cout<<"�ڽӾ���"<<endl;
	cout<<"���㼯�ϣ�";
    for(int i=0;i<numOfVer;i++)
	{
		cout<<this->vertices[i]<<" ";
	}
	cout<<endl;
	cout<<"Ȩֵ���ϣ�"<<endl;
	for(int i=0;i<numOfVer;i++)
	{
	     for(int j=0;j<numOfVer;j++)
			 cout<<this->edge[i][j]<<" ";
		 cout<<endl;
	}
}

int GraphOne::GetFirstVertices(int v)    
{
	if(vertices.size()-1<v)
	{
	       return -1;
	}
	for(int i=0;i<numOfVer;i++)
	{
	     if(edge[v][i]!=0&&edge[v][i]<MAXWEIGHT)
			 return i;
	}
	return -1;
}

int GraphOne::GetNextVertices(int v1,int v2)
{
   if(v1<0||v1>numOfVer-1||v2<0||v2>numOfVer-1)
	   return -1;
   for(int i=v2+1;i<numOfVer;i++)
   {
	     if(edge[v1][i]!=0&&edge[v1][i]<MAXWEIGHT)
			 return i;         
   }
   return -1;
}

void GraphOne::DepthFSearch(int visited[],int v)   //�����������
{
    visited[v]=1;
	cout<<vertices[v]<<" ";
	int w=GetFirstVertices(v);
	while(w!=-1)
	{
		 if(visited[w]!=1)
			 DepthFSearch(visited,w);
		 w=GetNextVertices(v,w);
	}
}

void GraphOne::BroadFSearch(int visited[],int v)  //�����������
{
   queue<int>ver;
   ver.push(v);
   cout<<vertices[v]<<" ";
   visited[v]=1;
   while(!ver.empty())
   {
	   int v=ver.front();
	   ver.pop();
	   int w=GetFirstVertices(v);
	   while(w!=-1)
	   {
	       if(visited[w]!=1){
			   cout<<vertices[w]<<" ";
		   	   ver.push(w);
		   }
		   visited[w]=1;
		   w=GetNextVertices(v,w);

	   }
   }
}

void GraphOne::SearchMinTree(queue<node>&lowVer)
{
     int *distance=new int[8];
	 memset(distance,0,sizeof(distance));
	 for(int i=0;i<8;i++)
		 distance[i]=edge[0][i];
	 distance[0]=-1;
	 node ver(0,0);
	 lowVer.push(ver);
	 for(int i=1;i<8;i++)
	 {
		 int min=MAXWEIGHT;
		 int k=i;
		 for(int j=1;j<8;j++)
		 {
		      if(min>distance[j]&&distance[j]>0)
			  {
			        min=distance[j];
					k=j;
			  }
		 }
		 ver.des=k;
		 ver.weight=min;
		 lowVer.push(ver);
		 distance[k]=-1;
		 for(int j=1;j<8;j++)
		 {
		      if(edge[k][j]<distance[j]&&distance[j]>0)
				  distance[j]=edge[k][j];
		 }
	 }
}

//�ڽӱ��Ա����ʵ��

void GraphTwo::InsertVertices(DataType data)
{
	vertices vertice(data);
	(this->ver).push_back(vertice);
	this->numOfVer++;
}

void GraphTwo::InsertEdge(int v1,int v2,int weight)
{
    if(v1<0||v1>numOfVer-1||v2<0||v2>numOfVer-1)
	{
	    cout<<"����Ĳ�������"<<endl;
		return;
	}
	node n1(v2,weight),n2(v1,weight);
	(this->ver)[v1].adj.push_back(n1);
	(this->ver)[v2].adj.push_back(n2);
	this->numOfEdge+=2;
}

int GraphTwo::GetFirstNode(int v,node& n)
{
   if(v<0||v>numOfVer-1)
   {
       cout<<"��������"<<endl;
	   return -1;
   }
   if((this->ver)[v].adj.size()>0)
   {
	   n.des=(this->ver)[v].adj[0].des;
	   n.weight=(this->ver)[v].adj[0].weight;
	   return 1;
   }
   return -1;
}

int GraphTwo::GetNextNode(int v1,int v2,node& n)
{
   if(v1<0||v1>numOfVer-1||v2<0||v2>numOfVer-1)
   {
       cout<<"��������"<<endl;
	   return -1;
   }
   if((this->ver)[v1].adj.size()>1)
   {
	   vector<node>::const_iterator p=(this->ver)[v1].adj.begin();
	   while(p!=(this->ver)[v1].adj.end()&&p->des!=v2){
		    p++;
	   }
	   if(p!=(this->ver)[v1].adj.end()&&p->des==v2)
	   {
		   n.des=p->des;
		   n.weight=p->weight;
		   return 1;
	   }
	   else
	       return -1;
   } 
}

void GraphTwo::show()
{
    cout<<"�ڽӱ�"<<endl;
	vector<vertices>::const_iterator p1=ver.begin();
	vector<node>::const_iterator p2;
	for(int i=0;i<numOfVer;i++)
	{
		cout<<p1->data<<" ";
		p2=(p1->adj).begin();
		while(p2!=(p1->adj).end())
		{
			cout<<p2->des<<"+"<<p2->weight<<" ";
			p2++;
		}
		p1++;
		cout<<endl;
	}
}




int main()
{
      GraphOne one;
	  GraphTwo two;
	  queue<node>lowVer;
	  DataType a[]={'A','B','C','D','E','F','G','H'};
	  RowColWeight rcl[]={RowColWeight(0,1,50),RowColWeight(0,2,60),RowColWeight(1,4,40),RowColWeight(1,3,65),RowColWeight(2,3,52),RowColWeight(2,6,45),RowColWeight(3,4,50),RowColWeight(3,5,30),RowColWeight(3,6,30),RowColWeight(4,5,70),RowColWeight(6,7,30)};
	  int visited[8];
	  for(int i=0;i<8;i++)
	  {
		  one.InsertVertices(a[i]);
		  two.InsertVertices(a[i]);
		  visited[i]=0;
	  }
	  for(int i=0;i<11;i++)
	  {
		  one.InsertEdge(rcl[i].col,rcl[i].row,rcl[i].weight);
		  two.InsertEdge(rcl[i].col,rcl[i].row,rcl[i].weight);
	  }
	  one.show();
	  two.show();
	  cout<<"��������������У�";
	  one.DepthFSearch(visited,0);
	  cout<<endl;
	  memset(visited,0,sizeof(visited));
	  visited[0];
	  cout<<"��������������У�";
	  one.BroadFSearch(visited,0);
	  cout<<endl;
	  cout<<"��С��������"<<endl;
	  one.SearchMinTree(lowVer);
	  int count=0;
	  while(lowVer.size()>0)
	  {
		  node ver=lowVer.front();
		  lowVer.pop();
		  count++;
		  if(count==1)
			  cout<<"��С�������Ķ���Ϊ��"<<one.vertices[ver.des]<<endl;
		  else
			  cout<<"���㣺"<<one.vertices[ver.des]<<"   "<<"Ȩֵ��"<<ver.weight<<endl;
	  }
	  system("pause");
	  return 0;
}