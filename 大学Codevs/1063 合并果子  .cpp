#include <iostream>
#include <string.h>
//动态规划写法（数组开的太大） 
using namespace std;
int n;
int dp[10005][10005];
int weight[10005];
int sum[10005];
int getsum(int i,int j)  
{  
    if(i+j >= n) return getsum(i,n-i-1) + getsum(0,(i+j)%n);  
    else return sum[i+j] - (i>0 ? sum[i-1]:0);  
}  
void init(){
	cin>>n;
	weight[0]=0;
	memset(dp,0x77,sizeof(dp));
	memset(sum,0,sizeof(sum));
	cin>>weight[0];
	sum[0]=weight[0];
	for(int i=1;i<n;i++){
		cin>>weight[i];
		sum[i]=sum[i-1]+weight[i];
	}
}
int main (){
	init();
	for(int i=1;i<=n-1;i++){
//		dp[i][i+1]=sum[i+1]-sum[i-1];
		dp[i][i]=0;
	}
	dp[n][n]=0;
//	for(int i=n;i>=1;i--){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=j;k++){
//				dp[i][j]=min(dp[i][j],dp[i][k]+dp[i+(k+1)%n][j-k-1]+sum[j]-sum[i-1]);
//			}
////			dp[i][j]+=sum[j]-sum[i-1];
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
//		}
//	}
for(int i=0;i<n;i++)  
        dp[i][0]= 0;  
for(int j=1;j<n;j++)  
    {  
        for(int i=0;i<n;i++)  
        {  
            dp[i][j] = 1<<30;  
            for(int k=0;k<j;k++)  
            {  
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[(i+k+1)%n][j-k-1] + getsum(i,j)); 
//				printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);  
            }  
        }  
    }
//	cout<<dp[1][n]<<endl;
	int minval = dp[0][n-1];  
    for(int i=0;i<n;i++)  
    {  
        minval = min(minval,dp[i][n-1]);  
    } 
    cout<<minval<<endl;
	return 0;
} 
