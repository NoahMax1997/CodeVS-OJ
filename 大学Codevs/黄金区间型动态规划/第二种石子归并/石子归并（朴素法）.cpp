#include <iostream>
using namespace std;
//朴素算法：
//dp[i][j] 表示合并i到j堆石子最小花费 
int main (){
	int n,flag=0,temp;
	cin>>n;
	int w[n+1],dp[n+1][n+1],sum[n+1];
	dp[0][0]=0;
	sum[0]=0; 
	for(int i=1;i<n+1;i++){
		sum[i]=0;
		cin>>w[i];
		sum[i]+=sum[i-1]+w[i];
		dp[i][i]=0;
	}
	for(int time=1;time<n;time++){
		for(int i=1,j=i+time;i<n-time+1;i++,j++){
			dp[i][j]=100000000;
			flag=100000000;
			for(int k=i;k<=j;k++){ 
				if(flag>dp[i][k]+dp[k+1][j]){
					flag=dp[i][k]+dp[k+1][j];  
				}
			}
			dp[i][j]=flag+sum[j]-sum[i-1];
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
} 
