#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct edge{
	int v1;
	int v2;
	int length;
}edge;
edge num[10005];
int dis[105][105];
int S[105],ans=0,lowCost[105],n,count=1;
void init(){
	int row,col;
	cin>>n;
	for(int i=1;i<=n*n;i++){
		row=(i-1)/n;
		col=(i-1)%n;
		scanf("%d",&dis[row][col]);
	}
	memset(S,0,sizeof(S));
	S[0]=1;						//将0点放入集合 
	for(int i=0;i<n;i++){
		if(i==0) continue;
		lowCost[i]=dis[0][i]; //初始化点集V各点到S的最短距离 
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}
void prim(){
	while(count<n){
		int nextVel,length=1000000000;
		for(int i=0;i<n;i++){
			if(S[i]) continue;
			if(length>lowCost[i]){ //找到下一个进入集合S的点 
				nextVel=i;
				length=lowCost[i];
			}
		}
		S[nextVel]=1;
		ans+=length;
		count++;
		//更新V集各点到S的距离
		for(int i=0;i<n;i++){
			if(S[i]) continue;
			if(dis[i][nextVel]<lowCost[i]){
				lowCost[i]=dis[i][nextVel];
			}
		} 
	}
}
int main(){
	init();
	prim();
	cout<<ans<<endl;
	return 0;
} 
