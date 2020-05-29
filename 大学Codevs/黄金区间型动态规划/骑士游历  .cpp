#include <iostream>
using namespace std;
typedef struct node {
	int x;
	int y;
}Node;
int n,m;
long long ans=0;
Node A,B;
void dfs(int x,int y){
	if(x<=n&&y<=m&&x<=B.x){
		if(x==B.x&&y==B.y){
			ans++;
		}
		else{
			dfs(x+1,y+2);
			dfs(x+1,y-2);
			dfs(x+2,y+1);
			dfs(x+2,y-1);
		}
	}	
}
int main (){
	cin>>n>>m>>A.x>>A.y>>B.x>>B.y;
	dfs(A.x,B.y);
	cout<<ans<<endl;
	return 0;
} 
//�ݹ鳬ʱ 
