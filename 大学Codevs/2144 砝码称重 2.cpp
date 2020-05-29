#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m,weight[35];
long long sum[35];
int step=0,ans=100000000,flag=0;
bool used[35];
void init(){
	memset(sum,0,sizeof(sum));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	sort(weight,weight+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+weight[i-1];
	}
}
void dfs(int num){
	if(m==0&&ans>step){
		ans=step;
		return;
	}
	if(sum[num]<m) return; 
	for(int i=num-1;i>=0;i--){
		if(weight[i]>m) continue;//舍弃该砝码 
		m-=weight[i];			//选用该砝码 
		step++;
		dfs(i);
		step--;
		m+=weight[i];
	}
}

int main (){
	init();
	dfs(n);
	cout<<ans<<endl;
}
