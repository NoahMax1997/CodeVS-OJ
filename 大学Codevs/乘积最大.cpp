/*
作者:Athena_int
题目:p1017 乘积最大
*/
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
int toInt(int i,int j,string str){
	int ret=0;
	 stringstream sin;
	 sin<<str.substr(i,j-i);
	 sin>>ret;
	 return ret;
}
int main()
{
    int n,k;
   
    string str;
    cin>>n>>k;
	cin>>str;
	int dp[n+1][k+1];//dp[i][j] 代表在前i个数中划分出j个数字 使得其乘积最大； 
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][1]=toInt(0,i,str);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k+1&&j<=i;j++){
			for(int l=1;l<=i;l++){
				dp[i][j]=max(dp[l][j-1]*toInt(l,i,str),dp[i][j]);
			}
		}
	}
	cout<<dp[n][k+1]; 
	return 0;
}
