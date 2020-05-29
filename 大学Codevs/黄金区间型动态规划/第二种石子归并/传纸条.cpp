#include <iostream>
#include <cstring>
using namespace std;
int main (){
	int n,m;
	cin>>n>>m;
	int map[n+1][m+1];
	for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
			cin>>map[i][j];
	bool isUsed[n+1][m+1];
	memset(isUsed,0,sizeof(isUsed));
	int dp[n+1][m+1],ans=0;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(!isUsed[i][j]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+map[i][j];
			}
		}
	}
	ans+=dp[n][m];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(!isUsed[i][j]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+map[i][j];
			}
		}
	}
	ans+=dp[n][m];
	cout<<ans<<endl;
	return 0;
} 
