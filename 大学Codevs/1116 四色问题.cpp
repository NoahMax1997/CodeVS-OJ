#include <iostream>
#include <string.h>
#include <set> 
using namespace std;
int n;
int map[10][10];
set <int> isOver;
typedef struct point{
	int num;
	int colorSet[10];//记录点的颜色  
	long long hash;
}point;
point P[10];
int ans=0;
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
		P[i].num=i;
		P[i].hash=0;
		memset(P[i].colorSet,0,sizeof(P[i].colorSet));
	}
}
void getHash(point& test){
	for(int i=1;i<=n;i++){
		test.hash*=5;
		test.hash+=test.colorSet[i];
	}
}
bool isCompleted(point test){
	for(int i=1;i<=n;i++){
		if(test.colorSet[i]==0) return 0;
	}
	return 1;
}
bool overColor(point test,int color,int num){
	for(int i=1;i<=n;i++){
		if(map[num][i]&&test.colorSet[i]==color)
			return 1;	
	}
	return 0;
}
void dfsPoint(point dfsP){
	for(int i=dfsP.num+1;i<=n;i++){
		if(dfsP.colorSet[i]!=0) continue;
		//给下一个空白点涂色
		for(int color=1;color<=4;color++){
			if(overColor(dfsP,color,i)) continue;   //改颜色与相邻点颜色冲突 
			point test=dfsP;
			test.num=i;
			test.colorSet[i]=color;
			getHash(test);	
			dfsPoint(test);
		}
	}
	if(isCompleted(dfsP)){
		ans++;
//		cout<<ans<<"\n";
//		isOver.insert(dfsP.hash);
	}
}
void output(){
	cout<<ans<<endl;
}
int main (){
	input();
	for(int i=1;i<=4;i++){
		P[1].colorSet[1]=i;
		dfsPoint(P[1]);
	}
	output();
	return 0;
}
