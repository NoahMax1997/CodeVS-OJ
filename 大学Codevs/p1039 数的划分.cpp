/*
作者:Athena_int
题目:p1039 数的划分
*/

//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n+1;i++){
		dp[i][1]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k&&j<=i;j++){
				dp[i][j]=dp[i-j][j]+dp[i-1][j-1]; 
		}
	}
	cout<<dp[n][k]; 
	return 0;
}

