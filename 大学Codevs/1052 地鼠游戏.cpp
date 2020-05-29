#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct mouce{
	int stay;
	int score;
}mouce;
mouce num[105];
int dp[105][10000];
bool cmp(mouce a,mouce b){
	return a.stay<b.stay;
}
int main(){
	memset(dp,0,sizeof(dp));
	int n,MAX=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i].stay;
		MAX=max(MAX,num[i].stay);
	}
	for(int i=1;i<=n;i++){
		cin>>num[i].score;
	}
	sort(num+1,num+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i].stay;j++){
			for(int k=1;k<i;k++){
				if(dp[i-1][j-1]+num[i].score>dp[])
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
} 
