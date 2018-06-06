#include<iostream>
#include<queue> 
#include<map> 


using namespace std;


queue<int>q1;


map<int, int>step;


int istate;
int dr[4]={0,1,0,-1};//0,1,2,3�ֱ��ʾ���£��ң��� 
int dc[4]={-1,0,1,0};//0,1,2,3�ֱ��ʾ���£��ң��� 
int bfs();
void readdate();
void init();
int canmoveto(int u,int dire);
int moveto(int u ,int dire);


int main()
{
	int num;
	readdate();
	init();
	num=bfs();
	cout<<num<<endl;
	return 0;
}


int bfs()
{
	int u,v,i;
	while(!q1.empty())
	{
		u=q1.front();
		q1.pop();
		for(i=0;i<4;i++)//0��1��2��3�ֱ��ʾ�������� 
		{
			if(canmoveto(u,i))//״̬u�ܷ����i�������ƶ���״̬u�õ��ĵ�i����״̬�Ƿ�Ϸ�
			{
				v=moveto(u,i);
				if(v==876543210)//���v��Ŀ��״̬ 
				{
					return (step[u]+1);//���ص���Ŀ�����С���� 
				}
				if(step.count(v)==0)//���v��һ����״̬ 
				{
					q1.push(v);//v�������
					           //��עv���Ѿ�������Ľ��
					step[v]=step[u]+1;//��¼����v����С���� 
				} 
			} 
		}
	}
	return -1;
}


void readdate()
{
	int i,j;
	int bs[3][3],num;
	
	num=0;
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			cin>>bs[i][j];
			num=num*10+bs[i][j];
		}
	istate=num;
}


void init()//1.��������� 2.��ע������ѵ�����Ľڵ�3.��¼����������С����Ϊ�� 
{
	q1.push(istate);
	step[istate]=0;
}


int canmoveto(int u,int dire)
{
	int sa[3][3];
	int brow,bcol;//�ո����ڵ����� 
	int r,c,i,j;//�ո���dire������һ����������� 
	for(i=2;i>=0;i--)
		for(j=2;j>=0;j--)
		{
			sa[i][j]=u%10;
			u=u/10;
			if(sa[i][j]==0)
			{
				brow=i;
				bcol=j;
			}
		}
	r=brow+dr[dire];
	c=bcol+dc[dire]; 
	if(r<=2&&r>=0&&c<=2&&c>=0)
	{
		return 1;
	} 
	return 0;
}


int moveto(int u,int dire)
{
	int sa[3][3],sum=0;
	int brow,bcol;//�ո����ڵ����� 
	int r,c,i,j;//�ո���dire������һ����������� 
	for(i=2;i>=0;i--)
		for(j=2;j>=0;j--)
		{
			sa[i][j]=u%10;
			u=u/10;
			if(sa[i][j]==0)
			{
				brow=i;
				bcol=j;
			}
		}
	r=brow+dr[dire];
	c=bcol+dc[dire]; 
	sa[brow][bcol]=sa[r][c];
	sa[r][c]=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
		sum=sum*10+sa[i][j];
		}
	return sum;
} 
