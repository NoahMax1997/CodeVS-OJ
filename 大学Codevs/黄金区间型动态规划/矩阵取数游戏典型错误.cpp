#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main  (){
	int n,m;
	cin>>n>>m;
	int matrix[n][m],i,j;
	int head[n],tail[n];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>matrix[i][j];
		}
		head[i]=0;
		tail[i]=m-1;
	}
	int min=1<<30,flag1,flag2;
	long ans=0;
	for(i=1;i<=m;i++){
		int sign[n];
		for(int k=0;k<n;k++){
			sign[k]=0;
		}
		for(int k=0;k<n;k++){
			min=1<<30;
			for(j=0;j<n;j++){
			if(!sign[j]&&head[j]!=m&&min>matrix[j][head[j]]){
				min=matrix[j][head[j]];
				flag1=j;
				flag2=1;
			}
			if(!sign[j]&&tail[j]!=-1&&min>matrix[j][tail[j]]){
				min=matrix[j][tail[j]];
				flag1=j;
				flag2=0;
			}	
		}
		sign[flag1]=1;
		if(flag2){
			head[flag1]++;
		}
		else{
			tail[flag1]--;
		}
			ans+=pow(2,i)*min;
		}
	}
	cout<<ans<<endl;
	return 0;
}
