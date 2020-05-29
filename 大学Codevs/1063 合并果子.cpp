#include <iostream>
#include <string.h>
#include <queue> 
#include <algorithm>
//动态规划写法（数组开的太大） 
using namespace std;
int n,ans=0;
int weight[10005];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>weight[i];
	}
}
struct cmp{
	bool operator()(int x,int y){
		return x>y;
	}
};
priority_queue<int,vector<int>,cmp> myQueue;
int main (){ 
	init();
	sort(weight+1,weight+1+n);
	for(int i=1;i<=n;i++) myQueue.push(weight[i]);
	for(int i=1;i<=n-1;i++){
		int temp1=0,temp2=0;
		temp1=myQueue.top();
		myQueue.pop();
		temp2=myQueue.top();
		myQueue.pop();
		myQueue.push(temp1+temp2);
		ans+=temp1+temp2;
	}
	cout<<ans;
	return 0;
} 
