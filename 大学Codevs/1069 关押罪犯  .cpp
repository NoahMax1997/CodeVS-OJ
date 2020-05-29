#include <iostream>
#include <set>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
typedef struct arc{
	int V1;
	int V2;
	int val;
}arc;
int Set[40010];
arc E[100005];
int n,m;
bool cmp(arc a,arc b){
	return a.val>b.val;
}
void init(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>E[i].V1>>E[i].V2>>E[i].val;
	}
	for(int i=0;i<=2*n;i++){
		Set[i]=i;
	}
}
int findRoot(int x){
	while(Set[x]!=x){
		Set[x]=Set[Set[x]];
		x=Set[x];
	}
	return x;
}
void joinSet(int x,int y){
	int rx=findRoot(x),ry=findRoot(y);
	if(rx!=ry){
		Set[rx]=ry; 
	}
}
void solve(){
		sort(E+1,E+m+1,cmp);
		int i;
		for(i=1;i<=m;i++){
			int ra=findRoot(E[i].V1),rb=findRoot(E[i].V2);
			if(ra==rb){
				cout<<E[i].val<<endl;
				break;
			}
			else{
				Set[ra]=Set[E[i].V2+n];
				Set[rb]=Set[E[i].V1+n)];
			}
		}
		if(i==m+1) cout<<0<<endl;
}
int main (){
	init();
	solve();
	return 0;
} 
