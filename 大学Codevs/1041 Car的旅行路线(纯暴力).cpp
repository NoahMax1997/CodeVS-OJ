#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,s,t,A,B;
typedef struct point{
	int x;
	int y;
}point;
typedef struct city{
	point P[5];
//	double dis[4][4];//记录该城市机场之间的距离
	int Ti;//该城市高速铁路里程价格 
}city;
city City[105]; 
typedef struct DP{
	double disCost[5][5];//两个城市的机场i 和j  之间的距离 	   
}DP;
DP dpCost[105][105]; //dp[i][j] 代表第i个城市到第j个城市的最短距离； 
double theDis(point a,point b){//返回两个点的距离 
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void input(){
	cout<<"in input"<<"\n";
	cin>>s>>t>>A>>B;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			cin>>City[i].P[j].x>>City[i].P[j].y;
		}
		cin>>City[i].Ti;
		//寻找矩形的第四个点
		double temp=0;
		for(int k=1;k<=3;k++){
			for(int l=1;l<=3;l++){
				if(k==l) continue;
				if(temp<theDis(City[i].P[k],City[i].P[l])){
					City[i].P[4].x=City[i].P[l].x+City[i].P[k].x-City[i].P[6-l-k].x;
					City[i].P[4].y=City[i].P[l].y+City[i].P[k].y-City[i].P[6-l-k].y;
					temp=theDis(City[i].P[k],City[i].P[l]);
				}
			}
		} 
	}
	
}
void solve(){
	cout<<"in solve"<<"\n";
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			if(i==j) continue;
			for(int k=1;k<=s;k++){
		
				
			} 
		}
	}
}
void output(){
	cout<<"in output"<<"\n";
	cout<<A<<"  "<<B<<"\n";
	 
}
int main (){
	cin>>n;
	while(n--){
		input();
		solve();
		output();
	}
	return 0;
}
