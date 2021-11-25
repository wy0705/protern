#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mmax 100
#define maxt 100000000
int v[mmax][mmax];

void Prim(int n){
	int low[mmax];//
	int clo[mmax];
	bool s[mmax];//判断该节点是否在S中
	s[1]=true;
	for(int i=2;i<=n;i++){
		low[i]=v[1][i];//初始化
		clo[i]=1;
		s[i]=false;
	}
	for(int i=1;i<n;i++){//对剩余的n-1个顶点进行操作 ,此处的i并无实际意思，只是起到一个记录变量的作用
		int min=maxt;
		int j=1;
		for(int k=2;k<=n;k++)//从V-S中找到S中边权最小的节点
			if((low[k]<min)&&(!s[k])){
				min=low[k];
				j=k;
			}
			cout<<j<<" "<<clo[j]<<":"<<low[j]<<endl;
			s[j]=true;
			for(int k=2;k<=n;k++){//调整low中的值，加入j节点之后，使得两个集合中的距离最小
				if((v[j][k]<low[k])&&(!s[k])){
					low[k]=v[j][k];
					clo[k]=j;
				}
			}

	}
}

int main()
{
	int n,m;//n vertexs and m edges
	cin>>n>>m;
	int ii,jj,tt;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		v[i][j]=maxt;
	}
	for(int i=0;i<m;i++){
		cin>>ii>>jj>>tt;
		v[ii][jj]=tt;
		v[jj][ii]=tt;
	}
	Prim(n);
	return 0;
}

//6 10
//1 2 6
//1 4 5
//1 3 1
//2 3 5
//2 5 3
//3 4 5
//3 5 6
//3 6 4
//4 6 2
//5 6 6