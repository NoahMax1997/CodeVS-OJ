#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//两个牧场可能不止一条路 相连 
int dis[123][123];
int p,t,a,b;
char ch1,ch2;
bool S[123];
void input(){
	cin>>p;
	memset(dis,1,sizeof(dis));
	memset(S,0,sizeof(S));
	while(p--){
		cin>>ch1>>ch2>>t;
		a=ch1,b=ch2;
		if(t<dis[a][b]){
			dis[a][b]=t;
			dis[b][a]=t;
		} 
	}
}
void dijkstra(){
	int first=90,k=first;
	S[first]=1;
	while(k<60||k>=90){
		for(int i=1;i<123;i++){
			if(S[i])  continue;
			dis[first][i]=min(dis[first][k]+dis[k][i],dis[first][i]);
		}
		int min=100000000;
		for(int i=1;i<123;i++){
			if(S[i]) continue;
			if(min>dis[first][i]){
				min=dis[first][i];
				k=i;
			}
		}
		S[k]=1;
	}
	printf("%c ",k);
	cout<<dis[first][k]<<endl;
}
int main (){
	input();
	dijkstra();
	return 0;
} 
