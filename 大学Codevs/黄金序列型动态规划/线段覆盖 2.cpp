//#include <iostream>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//typedef struct node{
//	int x;
//	int y;
//	int value;
//}node;
//bool cmp(node a,node b){
//	return a.y<b.y;
//}
//int main (){
//	int n,j;
//	cin>>n;
//	int dp[n+1];
//	node input[n+1];
//	for(int i=1;i<n+1;i++){
//		cin>>input[i].x>>input[i].y>>input[i].value;
//	}
//	dp[0]=0;
//	sort(input+1,input+n+1,cmp);
//	for(int i=1;i<n+1;i++){
//		dp[i]=input[i].value;
//	}
//	int flag=1;
//	bool isDelete[n+1];
//	memset(isDelete,0,sizeof(isDelete));
//	for(int i=2;i<n+1;i++){
//		if(input[i].x<input[flag].y&&dp[flag]<dp[flag]-input[flag].value+input[i].value){ 
//			//需要去掉前一条线段 保留当前线段 
//			for(j=1;j<flag;j++){
//				//在i-1之前 与i线段相交的线段 
//				if(isDelete[j]||input[j].y>input[i].x){
//					continue;
//				}
//				dp[i]+=input[j].value;
//			}
//			if(dp[i]>dp[i-1]){
//				//删除 第i-1 线段 
//				dp[i-1]=0;
//				isDelete[i-1]=1;
//				flag=i;
//			}
//			else{
//				//删除 第i 线段 
//				flag=i-1;
//				dp[i]=0;
//				isDelete[i]=1;
//			} 
//		}
//		else if(input[i].x>=input[flag].y){
//			dp[i]=dp[flag]+input[i].value;
//			flag=i;
//		}
//		else isDelete[i]=1;
//	}
//	int max=0;
//	for(int i=1;i<n+1;i++){
//		if(max<dp[i]) max=dp[i];
//	}
//	cout<<max<<endl;
//	return 0;
//} 

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef struct node{
	int x;
	int y;
	int value;
}node;
bool cmp(node a,node b){
	return a.y<b.y;
}
int main (){
	int n,j;
	cin>>n;
	int dp[n+1];
	node input[n+1];
	for(int i=1;i<n+1;i++){
		cin>>input[i].x>>input[i].y>>input[i].value;
	}
	dp[0]=0;
	sort(input+1,input+n+1,cmp);
	dp[1]=input[1].value;
	int flag=0;
	bool isDelete[n+1];
	memset(isDelete,0,sizeof(isDelete));
	for(int i=2;i<n+1;i++){
		flag=0;
		for(int j=1;j<i;j++){
			if(input[i].x>=input[j].y&&flag<dp[j]){
				flag=dp[j];
			}
		}
		dp[i]=flag+input[i].value;
	}
	int max=0;
	for(int i=1;i<n+1;i++){
		if(max<dp[i]) max=dp[i];
	}
	cout<<max<<endl;
	return 0;
} 




