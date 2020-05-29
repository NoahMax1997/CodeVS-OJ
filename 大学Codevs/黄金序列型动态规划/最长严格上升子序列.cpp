#include <iostream>
using namespace std;
int main (){
	int n;
	cin>>n;
	int input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	int dp[n];
	for(int i=0;i<n;i++) dp[i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(input[i]>input[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	int max=0;
	for(int i=0;i<n;i++){
		if(max<dp[i]) max=dp[i];
	}
	cout<<max<<endl;
	return 0;
} 
