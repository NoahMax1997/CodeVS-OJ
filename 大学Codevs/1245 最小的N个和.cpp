#include <iostream>
#include <algorithm>
#include <queue> 
#include <stdio.h>
using namespace std;
struct cmp{
	bool operator()(int x,int y){
		return x>y;
	}
};
int a[100001],b[100001];
priority_queue<int,vector<int>,cmp> myQueue;
int main (){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	sort(a,a+n);
	sort(b,b+n);
	int count=1;
	for(int i=0;i<n;i++){
		int end=n/(i+1);
		for(int j=0;j<end;j++){
			myQueue.push(a[i]+b[j]);
		}
	}
	while(!myQueue.empty()){
		if(count==n+1) break;
		int temp=myQueue.top();
		printf("%d ",myQueue.top());
		myQueue.pop(); 
		count++;
	}
	return 0;
}
