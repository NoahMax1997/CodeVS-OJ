#include <iostream>
#include <string.h> 
#include <string>
#include <stdio.h>
using namespace std;
int main (){
	int high=300000,daoDan[21],n=1,ans=0,m;
	while(cin>>daoDan[n]){
		n++;
	}
	int dp[n],num=0,max=0;
	for(int i=1;i<n;i++) dp[i]=1;
	//初始化 每个导弹都可能是最长非递增序列的起始 
	for(int i=2;i<n;++i){
		for(int j=1;j<i;j++){
			if(daoDan[j]>=daoDan[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	for(int i=1;i<n;++i){
		if(dp[i]>max) max=dp[i]; 
	}
	cout<<max<<endl;
	for(int i=1;i<n;i++) dp[i]=1;
	for(int i=2;i<n;++i){
		for(int j=1;j<i;j++){
			if(daoDan[j]<daoDan[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	for(int i=1;i<n;++i){
		if(dp[i]>num) num=dp[i]; 
	}
	cout<<num<<endl;
	return 0;
} 
