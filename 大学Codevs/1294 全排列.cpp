#include <iostream>
#include <set>
using namespace std;
int n;
void dfs(set<int> isOver,int save[12],int index){
	if(index==n+1){
		for(int i=1;i<=n;i++){
		cout<<save[i]<<" ";
		}
	cout<<"\n";
	return;
	}
	for(int i=1;i<=n;i++){
		if(isOver.find(i)!=isOver.end()) continue;
		isOver.insert(i);
		save[index]=i;
		dfs(isOver,save,index+1);
		isOver.erase(i);
	}
}
int main (){
	cin>>n;
	set<int> isOver;
	int save[12];
	int index=1;
	dfs(isOver,save,index);
	return 0;
}
