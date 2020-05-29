#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int n,s,t,A,B;
typedef struct point{
	int x;
	int y;
}point;
typedef struct city{
	point P[5];
	double dis[5][5];//��¼�ó��л���֮��ľ���
	int Ti;//�ó��и�����·��̼۸� 
}city;
city City[105];
double ans=1000000000;
bool S[105][5]; 
double disCost[105][5][105][5];
double theDis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void initDis(){
//	cout<<"in initDis"<<"\n";
	//��ʼ�����������ľ��� 
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			for(int k=1;k<=4;k++){
				for(int l=1;l<=4;l++){
					if(i==j){
						//ͬһ���л���
						disCost[i][k][j][l]=City[i].dis[k][l]*City[i].Ti;
					}
					else{
						disCost[i][k][j][l]=theDis(City[i].P[k],City[j].P[l])*t;
					}
//					cout<<i<<"��"<<k<<"����"<<j<<"��"<<l<<"��������Ϊ�� "<< disCost[i][k][j][l]<<endl;
				}
			}
		}
	}
//	cout<<"end initDis"<<endl; 
}
//int getHash(int cityNum,int planeNum){
//	return cityNum*6+planeNum;	
//}
void initS(){
	for(int i=1;i<=s;i++){
		for(int j=1;j<=4;j++){
			S[i][j]=0;
		}
	}
}
void input(){
//	cout<<"in input"<<"\n";
	cin>>s>>t>>A>>B;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			cin>>City[i].P[j].x>>City[i].P[j].y;
			S[i][j]=0;
		}
		cin>>City[i].Ti;
//		cout<<City[i].Ti<<"\n";
		//Ѱ�Ҿ��εĵ��ĸ���
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
		S[i][4]=0;
		for(int k=1;k<=4;k++){
			for(int l=1;l<=4;l++){
				City[i].dis[k][l]=theDis(City[i].P[k],City[i].P[l]);
			}
		}
	}
	initDis();
}
void solve(){
//	cout<<"in solve"<<"\n";
	for(int num=1;num<=4;num++){
		int cityNum=A,planeNum=num;
		for(int i=1;i<=4;i++) S[A][i]=1;
		int flag=0;
		while(!flag){
//			cout<<"in flag"<<endl;
			for(int i=1;i<=s;i++){//������㵽������ľ��� 
				if(i==A) continue;
				for(int j=1;j<=4;j++){
					if(S[i][j]) continue;
					if(	disCost[A][num][i][j]>disCost[A][num][cityNum][planeNum]+disCost[cityNum][planeNum][i][j]){
						disCost[A][num][i][j]=disCost[A][num][cityNum][planeNum]+disCost[cityNum][planeNum][i][j];
					}
				}
			}
			double min=100000000; 
			for(int i=1;i<=s;i++){
				if(i==A) continue;
				for(int j=1;j<=4;j++){
					if(S[i][j]) continue;
					if(	disCost[A][num][i][j]<min){
						min=disCost[A][num][i][j];
						cityNum=i,planeNum=j;
					}
				}
			}
			S[cityNum][planeNum]=1;
			if(cityNum==B&&ans>min){
				ans=min;
//				cout<<ans<<"\n";
				initS();
				flag=1;
			}
			if(cityNum==B) break;
		}
	}
//	cout<<"end solve"<<endl;
}
void output(){
	 printf("%.1lf\n",ans);
}
int main (){
	cin>>n;
	while(n--){
		input();
		if(A==B) cout<<"0.0"<<endl;
		else {
			solve();
			output();
		}
	}
	return 0;
}
