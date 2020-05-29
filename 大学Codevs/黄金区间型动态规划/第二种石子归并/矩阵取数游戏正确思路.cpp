#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main (){
 	int n,m;
 	cin>>n>>m;
 	int matrix[n][m];
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			cin>>matrix[i][j];
		 }
	 }
	 long long dp[m][m],ans=0;
	 for(int row=0;row<n;row++){
	 	memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++){
			dp[i][i]=matrix[row][i]*pow(2,m);
		}
	 	for(int time=1;time<m;time++){
		 	for(int i=0;i<m-time;i++){
		 		int j=i+time;
		 		dp[i][j]=max(dp[i+1][j]+matrix[row][i]*pow(2,m-time),dp[i][j-1]+matrix[row][j]*pow(2,m-time));
			 }
		 }
		ans+=dp[0][m-1];
	 }
	 cout<<ans<<endl;
 	return 0;
} 
