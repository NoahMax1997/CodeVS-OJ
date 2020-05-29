#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m,s,t,minV=1,maxV=10000000,preMin,preMax;
typedef struct arc{
	int V1;
	int V2;
	int val;
}arc;
arc E[5005];
int Set[505];
bool findit=0; 
void initSet(){
	for(int i=0;i<505;i++){
		Set[i]=i;
	}
}
int get(int ,int);
void input(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>E[i].V1>>E[i].V2>>E[i].val;
	}
	cin>>s>>t;
}
int get(int a,int b){
	if(a>b){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	if(b%a==0) return a;
	return get(b%a,a);
}
int findRoot(int x){
	while(Set[x]!=x){
		x=Set[x];
	}
	return x;
}
int joinSet(int x,int y){
	int rx=findRoot(x),ry=findRoot(y);
	Set[rx]=ry;
	int temp=x;
	while(Set[x]!=x){
		temp=Set[x];
		Set[x]=ry;
		x=temp;
	}
}
bool cmp(arc a,arc b){
	return a.val<b.val;
}
void kruskal(){
	sort(E+1,E+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<E[i].V1<<" "<<E[i].V2<<" "<<E[i].val<<"\n";
//	}
	for(int i=1;i<=m;i++){
		initSet();
		preMin=E[i].val,preMax=E[i].val;
		joinSet(E[i].V1,E[i].V2);
		for(int j=i;j<=m;j++){
			if(findRoot(E[j].V1)!=findRoot(E[j].V2)){
				preMin=min(preMin,E[j].val);
				preMax=max(preMax,E[j].val);
				joinSet(E[j].V1,E[j].V2);
			}
			if(findRoot(s)==findRoot(t)){
				findit=1;
				if(((double)preMax/(double)preMin)<((double)maxV/(double)minV)){
					maxV=preMax;
					minV=preMin;
					break;
				}
			}
		}
	}
}
int main (){
	input();
	kruskal();
	if(findit){
		int temp=get(minV,maxV);
		if(maxV%minV==0) cout<<maxV/minV<<endl;
		else cout<<maxV/temp<<"/"<<minV/temp<<endl; 
	}
	else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
