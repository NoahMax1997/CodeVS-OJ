#include <iostream>
#include <string.h>
using namespace std;
int main (){
	int N;
	cin>>N;
	int matrix[N+1][N+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			cin>>matrix[i][j];
		}
	}
	int maxNum[N+1];
	memset(maxNum,0,sizeof(maxNum));
	for(int i=0;i<=N;i++) maxNum[i]=matrix[N][i];
	for(int i=N-1;i>0;i--){
		for(int j=1;j<=i;j++){
			maxNum[j]=max(maxNum[j],maxNum[j+1])+matrix[i][j];	
		}
	}
	cout<<maxNum[1]<<endl;
	return 0;
}
