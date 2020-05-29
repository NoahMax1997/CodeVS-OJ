#include <iostream>
#include <string.h>
using namespace std;
int Set[5005];
int n,m,p;
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
void init(){
	cin>>n>>m>>p;
	for(int i=0;i<=n;i++)
		Set[i]=i;
	int a,b,ra,rb;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		ra=findRoot(a),rb=findRoot(b);
		if(ra==rb)  continue;
		else{
			joinSet(a,b);
		}		
	}
}

void solve(){
	int a,b,ra,rb;
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		ra=findRoot(a),rb=findRoot(b);
		if(ra==rb) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
int main (){
	init();
	solve();
	return 0;
}
