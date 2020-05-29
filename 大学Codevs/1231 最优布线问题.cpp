#include <iostream>
#include <algorithm>
using namespace std;
typedef struct edge{
	int v1;
	int v2;
	int length;
}edge;
int n,m,tree[100005],C=0;
long long ans=0;
edge E[100005];
bool cmp(edge a,edge b){
	return a.length<b.length;
}
int findRoot(int x){
	int rx;
	while(tree[x]!=x){
		int temp=tree[x];
		tree[x]=tree[tree[x]];
		x=temp;
	}
	rx=x;
	return rx;
}
void join(int x,int y){
	int rx=findRoot(x),ry=findRoot(y);
	tree[ry]=rx;
} 
void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>E[i].v1>>E[i].v2>>E[i].length;
	}
	sort(E,E+m,cmp);
	for(int i=0;i<=n;i++){
		tree[i]=i;
	}
}
void krustral(){
	while(C<n-1)
	for(int i=0;i<m;i++){
		if(findRoot(E[i].v1)!=findRoot(E[i].v2)){
			join(E[i].v1,E[i].v2);
			ans+=E[i].length;
			C++;
		}	
	}
}
int main (){
	init();
	krustral();
	cout<<ans<<endl;
	return 0;
} 
