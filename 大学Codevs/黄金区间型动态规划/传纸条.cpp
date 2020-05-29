#include <iostream>
#include <string.h>
using namespace std;
int main (){
	int n,m;
	cin>>n>>m;
	int matrix[n+1][m+1];
	memset(matrix,0,sizeof(matrix));
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			cin>>matrix[i][j];
		}
	}	
	int x1,x2,k;
	int dp[n+m+1][n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int k=2;k<m+n+1;k++)
	for(x1=1;x1<n+1&&x1<k;x1++){
			for(x2=1;x2<n+1&&x2<k;x2++){
				if(x1!=x2){
					dp[k][x1][x2]=max(max(dp[k-1][x1-1][x2],dp[k-1][x1][x2-1]),max(dp[k-1][x1-1][x2-1],dp[k-1][x1][x2]))+matrix[x1][k-x1]+matrix[x2][k-x2];	
				}
			}
	}
	cout<<max(dp[m+n][n][n-1],dp[m+n][n-1][n])<<endl;
	return 0;
}
