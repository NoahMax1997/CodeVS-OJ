#include <iostream>
using namespace std;
typedef struct tree{
	int val;
	int s;
}tree;
tree segTree[70005];
int n; 
void buildTree(int root,int start,int end){
	if(start==end){
		segTree[root].val=start;
//		cout<<root<<" "<<start<<endl;
		segTree[root].s=1;
		return; 
	}
	else{
		int mid=(start+end)/2;
		buildTree(root*2,start,mid);
		buildTree(root*2+1,mid+1,end);
		segTree[root].s=segTree[root*2].s+segTree[root*2+1].s;
	}	
}
int delNodeOfTree(int root,int start,int end,int num){// num表示要删第几个 
	if(start==end){
		segTree[root].s=0;
//		cout<<root<<" "<<segTree[root].val<<"\n";
		return segTree[root].val;
	}
	else{
		int mid=(start+end)/2;
		int temp=0;
		if(num<=segTree[root*2].s){
			temp= delNodeOfTree(root*2,start,mid,num);
		}
		else{
			temp= delNodeOfTree(root*2+1,mid+1,end,num-segTree[root*2].s);
		}
		segTree[root].s=segTree[root*2].s+segTree[root*2+1].s;
		return temp;
	}
}
int main (){
	int m;
	cin>>n>>m;
	int temp=1;
	buildTree(1,1,n);
	for(int i=n;i>=1;i--){
		temp+=(m-1)%i;
		if(temp>i) temp-=i;
		cout<<delNodeOfTree(1,1,n,temp)<<" ";
	}
	return 0;
} 
