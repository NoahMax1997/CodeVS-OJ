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
//	double dis[4][4];//��¼�ó��л���֮��ľ���
	int Ti;//�ó��и�����·��̼۸� 
}city;
city City[105]; 
typedef struct DP{
	double distance;//�������еĻ���start ��end  ֮��ľ��� 
	int start; 
	int end;	
}DP;
DP dp[105][105]; //dp[i][j] �����i�����е���j�����е���̾��룻 
double theDis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
//void initDP(){
//	cout<<"in initDP"<<"\n";
//	//��ʼ����������֮�����̾��룬����¼����λ�� start end�� 
//	for(int i=1;i<=s;i++){
//		for(int j=1;j<=i;j++){
//			dp[i][j].distance=10000000000; 
//			if(i==j){
//				dp[i][j].distance=0;
//				dp[i][j].end=0;
//				dp[i][j].start=0;
//			}
//			else{
//				for(int start=1;start<=4;start++){
//					for(int end=1;end<=4;end++){
//						double temp=theDis(City[i].P[start],City[j].P[end])*t;  //�����������㺽�ߵļ۸� 
//						if(dp[i][j].distance>temp){
//							dp[i][j].distance=temp;
//							dp[i][j].start=start;
//							dp[i][j].end=end;	
//							dp[j][i].distance=temp;
//							dp[j][i].start=end;
//							dp[j][i].end=start;
//						}
//					}
//				}
//			}
//		}
//	}
//	//test initDP()
////	for(int i=1;i<=s;i++){
////		for(int j=1;j<=s;j++){
////			if(i==j) continue;
////			cout<<i<<"��"<<j<<" ���: "<<dp[i][j].distance<<" start="<<dp[i][j].start<<" end="<<dp[i][j].end<<" ";
////		}
////		cout<<"\n";
////	} 
//}
void input(){
	cout<<"in input"<<"\n";
	cin>>s>>t>>A>>B;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=3;j++){
			cin>>City[i].P[j].x>>City[i].P[j].y;
		}
		cin>>City[i].Ti;
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
//		for(int k=1;k<=4;k++){
//			for(int l=1;l<=4;l++){
//				if(k==l) continue;
//				City[i].dis[k][l]=theDis(City[i].P[k],City[i].P[l]);
//			}
//		}
	}
//	initDP();
	//test input()
//	for(int i=1;i<=s;i++){
//		for(int j=1;j<=4;j++){
//			cout<<City[i].P[j].x<<" "<<City[i].P[j].y<<" ";
//		}
//		cout<<"\n";
//	}
}
void solve(){
	cout<<"in solve"<<"\n";
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			if(i==j) continue;
			for(int k=1;k<=s;k++){
				if(k==i||k==j) continue;
				double temp=dp[i][k].distance+dp[k][j].distance+theDis(City[k].P[dp[i][k].end],City[k].P[dp[k][j].start])*City[k].Ti;
				if(dp[i][j].distance>temp){
					dp[i][j].distance=temp;
					dp[i][j].start=dp[i][k].start;
					dp[i][j].end=dp[k][j].end;
					dp[j][i].distance=temp;
					dp[j][i].start=dp[k][j].end;
					dp[j][i].end=dp[i][k].start;
				}
			} 
		}
	}
}
void output(){
	cout<<"in output"<<"\n";
	cout<<A<<"  "<<B<<"\n";
	cout<<dp[A][B].distance<<endl;  
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
