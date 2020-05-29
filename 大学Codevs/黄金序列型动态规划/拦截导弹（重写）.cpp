#include <iostream>
#include <stdio.h>
using namespace std;
int daodan[25];
int dp[25];
int main (){
	int n=1;
//	cin>>n;
	while(cin>>daodan[n]){
		n++;
	}
	n--;
	for(int i=0;i<25;i++) dp[i]=1;
	int ans=0;
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(daodan[i]>=daodan[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		dp[i]>ans?ans=dp[i]:ans;
	}
	printf("%d\n",ans);
	ans=0;
	for(int i=0;i<25;i++) dp[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(daodan[j]<daodan[i]) dp[i]=max(dp[i],dp[j]+1);
		}
		if(ans<dp[i]) ans=dp[i];
	}
	cout<<ans;
	return 0;
}
