#include <iostream>
using namespace std;
typedef struct node{
	int head;
	int tail;
}node;
int n;

int main (){
	cin>>n;
	int dp[n][n];
	node input[200];
	for(int i=0;i<n;i++){
		cin>>input[i].head;
		if(i==0)  continue;
		input[i-1].tail=input[i].head;
	}
	input[n-1].tail=input[0].head;
	for(int i=0;i<n;i++) dp[i][0]=0;
	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
			dp[i][j]=0;
			for(int k=0;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[(i+k+1)%n][j-k-1]+input[i].head*input[(k+i+1)%n].head*input[(i+j)%n].tail);
			}
		}
	}
	int max=0;
	for(int i=0;i<n;i++){
		if(dp[i][n-1]>max){
			max=dp[i][n-1];
		}
	}
	cout<<max<<endl;
	return 0;
}
