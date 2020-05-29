#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main (){
	int v,n,sum=0;
	cin>>v>>n;
	int *vi=new int[n+1];
	for(int i=1;i<n+1;i++){
		cin>>vi[i];
	}
	int dp[n+1][v+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n+1;i++){
		for(int j=1;j<v+1;j++){
			if(vi[i]>j){
				//当前箱子大于总当前容量 
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j-vi[i]]+vi[i],dp[i-1][j]);
			}
		} 
	}
	cout<<v-dp[n][v]<<endl;
	return 0;
} 
