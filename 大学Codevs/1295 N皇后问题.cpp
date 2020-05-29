#include <iostream>
#include <string.h>
using namespace std;
int map[15][15];
int n;
int ans=0;
bool sum[40];
bool des[40];
bool line[20];
bool isDanger(int i,int j){
	//判断往 i，j处下棋 是否合法 
	if(line[j]) return 1;
	if(sum[i+j]) return 1;
	if(des[i-j+13]) return 1;
	return 0;
}
void dfs(int row){
	//向第row行放棋 
	if(row>n) {
		ans++;	
		return;
	}

	for(int l=1;l<=n;l++){
		if(isDanger(row,l)) continue;
//		map[row][l]=1;
		line[l]=1;
		sum[row+l]=1;
		des[row-l+13]=1;
		dfs(row+1);
//		map[row][l]=0;
		line[l]=0;
		sum[row+l]=0;
		des[row-l+13]=0;
	} 
}
int main (){
	cin>>n;
	memset(sum,0,sizeof(sum));
	memset(des,0,sizeof(des));
	memset(line,0,sizeof(line));
	int row=1;
	dfs(row);
	cout<<ans<<endl;
	return 0;
}
