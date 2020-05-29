#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[2505];
int num[2505],sumA[2505],sumB[2505];
int cha(int i,int j){
	int sum1=0,sum2=0;
	sum1=sumA[j]-sumA[i-1];
	sum2=sumB[j]-sumB[i-1];
	if(sum1==0||sum2==0) return 0;
	return sum1>sum2?sum1-sum2:sum2-sum1; 
}
int main (){
	int m,n,sum1=0,sum2=0;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	sumA[0]=0;
	sumB[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(num[i]==1){
			sumA[i]=sumA[i-1]+1;
			sumB[i]=sumB[i-1];
		} 
		if(num[i]==2){
			sumB[i]=sumB[i-1]+1;
			sumA[i]=sumA[i-1];
		} 
	}
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+1;
		for(int j=i;j>=1;j--){
			if(cha(j,i)<=m){
				dp[i]=min(dp[j-1]+1,dp[i]);
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
} 
