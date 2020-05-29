#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct edge{
	int a;
	int b;
	int cost;
}E;
E ed[100005];
int n,m,ans=0;
int set[1005];
void init(){
	for(int i=0;i<1005;i++){
		set[i]=i;
	}
}
int findRoot(int a){
	while(set[a]!=a){
		a=set[a];
	}
	return a;
}
void join(int x,int y){
	int rx=findRoot(x);
	int ry=findRoot(y);
	set[rx]=ry;
}
bool cmp(E a,E b){
	return a.cost<b.cost;
}
int main (){
	cin>>n>>m;
	init();
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&ed[i].a,&ed[i].b,&ed[i].cost);
	}
	sort(ed,ed+m,cmp); 
	for(int i=0;i<m;i++){
//		cout<<findRoot(ed[i].a)<<findRoot(ed[i].b)<<"\n";
		if(findRoot(ed[i].a)!=findRoot(ed[i].b)){
			ans+=ed[i].cost;
			join(ed[i].a,ed[i].b);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
