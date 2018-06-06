#include<iostream>
#include<queue> 
#include<map> 


using namespace std;


queue<int>q1;


map<int, int>step;


int istate;
int dr[4]={0,1,0,-1};//0,1,2,3分别表示左，下，右，上 
int dc[4]={-1,0,1,0};//0,1,2,3分别表示左，下，右，上 
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
		for(i=0;i<4;i++)//0，1，2，3分别表示左下右上 
		{
			if(canmoveto(u,i))//状态u能否向第i个方向移动，状态u得到的第i个新状态是否合法
			{
				v=moveto(u,i);
				if(v==876543210)//如果v是目标状态 
				{
					return (step[u]+1);//返回到达目标的最小步数 
				}
				if(step.count(v)==0)//如果v是一个新状态 
				{
					q1.push(v);//v加入队列
					           //标注v是已经到达过的结点
					step[v]=step[u]+1;//记录到达v的最小步数 
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


void init()//1.起点加入队列 2.标注起点是已到达过的节点3.记录到达起点的最小步数为零 
{
	q1.push(istate);
	step[istate]=0;
}


int canmoveto(int u,int dire)
{
	int sa[3][3];
	int brow,bcol;//空格所在的行列 
	int r,c,i,j;//空格向dire方向走一步到达的行列 
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
	int brow,bcol;//空格所在的行列 
	int r,c,i,j;//空格向dire方向走一步到达的行列 
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
