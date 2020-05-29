#include <iostream>
using namespace std;
int array[200005],n,m;
void buildSegTree(int root,int array[],int start,int end){
	if(start==end){
		cin>>array[root];
//		cout<<root<<" "<<array[root]<<endl;
	} 
	else{
		int mid=(start+end)/2;
		buildSegTree(root*2,array,start,mid);
		buildSegTree(root*2+1,array,mid+1,end);
	}
}
int sectionAnd(int root,int CStart,int CEnd,int QStart,int QEnd){
	if(CStart>QEnd||CEnd<QStart) return 0;
	else if(CStart==CEnd&&CStart>=QStart&&CEnd<=QEnd){
		return array[root];
	}
	else{
		int mid=(CStart+CEnd)/2;
		return sectionAnd(root*2,CStart,mid,QStart,QEnd)+sectionAnd(root*2+1,mid+1,CEnd,QStart,QEnd);
	}
}
int query(int root,int start,int end,int num){
	if(start==end&&start==num){
//		cout<<array[root]<<"\n";
		return array[root];
	}
	else if(start>num||num>end)  return -1;
	else{
		int mid=(start+end)/2;
		if(query(root*2,start,mid,num)!=-1){
			return query(root*2,start,mid,num);
		}
		query(root*2+1,mid+1,end,num);
	}
}
void increase(int root,int start,int end,int IStart,int IEnd,int addVal){
	if(start>IEnd||end<IStart) return;
	else if(start==end&&start>=IStart&&end<=IEnd){
//		cout<<array[root]<<"\n";
		array[root]+=addVal;
	}
	else{
		int mid=(start+end)/2;
		increase(root*2,start,mid,IStart,IEnd,addVal);
		increase(root*2+1,mid+1,end,IStart,IEnd,addVal);
	}
}
void input(){
	cin>>n;
	buildSegTree(1,array,1,n);
	cin>>m;
	while(m--){
		int flag;
		cin>>flag;
		if(flag==1){
			int a,b,num;
			cin>>a>>b>>num;
			increase(1,1,n,a,b,num);
		}
		else{
			int num;
			cin>>num;
			cout<<query(1,1,n,num)<<endl; 
		}
	}
}
int main (){
	input();
//	for(int i=1;i<=n;i++){
//		cout<<query(1,1,n,i)<<endl;
//	}
//	increase(1,1,n,1,n,2);
//	for(int i=1;i<=n;i++){
//		cout<<query(1,1,n,i)<<endl;
//	}
	return 0;
} 
