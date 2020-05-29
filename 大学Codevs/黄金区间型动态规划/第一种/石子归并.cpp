#include <iostream>
using namespace std;
typedef struct node{
	int w;
	node* next;
}node;
node* first=new node;
int searchLeast(node* first){
	node* index=first;
	node* pre=first;
	node* next=first->next;
	int min=100000;
	while(index->next->next!=NULL){
		if(min>index->w+index->next->w){
			min=index->w+index->next->w;
			pre=index;
			next=index->next;
		}
		index=index->next;
	}
	//合并最小石堆 pre next
	 pre->w=pre->w+next->w;
	 pre->next=next->next;
	 delete next;
	 return pre->w;
}
int main (){
	int n;
	cin>>n;
	node* last=new node;
	last=first;
	while(n--){
		cin>>last->w;
		if(n==0)
			continue;
		last->next=new node;
		last=last->next;	
	}
//	cout<<last->w;
	last->next=NULL;
	last=first;
//	while(last!=NULL){
//		cout<<last->w<<"  ";
//		last=last->next; 
//	}
	int sum=0;
	while(first->next!=NULL){
		sum+=searchLeast(first);
	}
	cout<<sum<<endl;
	return 0;
} 
