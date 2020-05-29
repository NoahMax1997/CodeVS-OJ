#include <iostream>
#include <string.h>
using namespace std;
int dp[2505][2505];
int num[2505],sumA[2505],sumB[2505];
int cha(int i,int j){
	int sum1=0,sum2=0;
	sum1=sumA[j+1]-sumA[i];
	sum2=sumB[j+1]-sumB[i];
	if(sum1==0||sum2==0) return 0;
	return sum1>sum2?sum1-sum2:sum2-sum1; 
}
int main (){
	int m,n,sum1=0,sum2=0;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n-1;i++){
		dp[i][i+1]=1;
		dp[i][i]=1;
	}  
	dp[n-1][n-1]=1;
	sumA[0]=0;
	sumB[0]=0;
	for(int i=1;i<=n;i++){
		cin>>num[i-1];
		if(num[i-1]==1){
			sumA[i]=sumA[i-1]+1;
			sumB[i]=sumB[i-1];
		} 
		if(num[i-1]==2){
			sumB[i]=sumB[i-1]+1;
			sumA[i]=sumA[i-1];
		} 
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			int minSum=1000000;
			if(cha(i,j)<=m)
			 dp[i][j]=1;
			else{
				for(int k=i;k+1<j;k++){
					if(dp[i][k]+dp[k+1][j]<minSum){
						minSum=dp[i][k]+dp[k+1][j];
					}
				}
				dp[i][j]=minSum;
			}
		}
	}
	cout<<dp[0][n-1]; 
	return 0;
} 
