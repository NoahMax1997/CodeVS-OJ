#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int dis[105][105];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i) continue;
			for(int j=1;j<=n;j++){
				if(k==j) continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}	
	}
}
void output(){
	int Q,a,b;
	cin>>Q;
	while(Q--){
		scanf("%d%d",&a,&b); 
		printf("%d\n",dis[a][b]);
	}
} 
int main (){
	input();
	floyd();
	output();
	return 0;
}
