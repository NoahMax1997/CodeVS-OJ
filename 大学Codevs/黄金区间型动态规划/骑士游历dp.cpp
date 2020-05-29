#include <iostream>
#include <string.h>
using namespace std;
int main (){
	int n,m,x1,y1,x2,y2;
	cin>>n>>m>>x1>>y1>>x2>>y2;
	long long dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[x1][y1]=1;
	for(int i=x1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-1>0&&j-2>0){
				dp[i][j]+=dp[i-1][j-2];
			}
			if(i-1>0&&j+2<=m){
				dp[i][j]+=dp[i-1][j+2];
			}
			if(i-2>0&&j-1>0){
				dp[i][j]+=dp[i-2][j-1];
			}
			if(i-2>0&&j+1<=m){
				dp[i][j]+=dp[i-2][j+1];
			}
		}
	}
	cout<<dp[x2][y2];
	return 0;
} 
