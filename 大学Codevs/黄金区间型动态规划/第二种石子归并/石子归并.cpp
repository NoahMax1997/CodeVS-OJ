#include <iostream>
using namespace std;
//GarsiaWachs算法 
//设序列是stone[]，从左往右，找一个满足stone[k-1] <= stone[k+1]的k，
//找到后合并stone[k]和stone[k-1]，再从当前位置开始向左找最大的j，
//使其满足stone[j] > stone[k]+stone[k-1]，插到j的后面就行。一直重复，
//直到只剩下一堆石子就可以了。
//在这个过程中，可以假设stone[-1]和stone[n]是正无穷的
typedef struct node{
	int w;
	node* next;
}node;
node* first=new node;
int len;
int  find(){
	node* index=new node;
	index=first->next;
	node* pre=first;
	node* flag;
	node* prepre=first;
	int sum=0;
	while(index->next!=NULL){
		if(pre->w<=index->next->w){
			//合并 index 和pre节点 
			pre->w+=index->w;
			pre->next=index->next;
			sum=pre->w;
			delete index;
			index=first;
			while(index!=pre){
				if(index->w>sum){
					flag=index;
				}
				index=index->next;
			}
			//将pre插到flag后面
			prepre->next=pre->next;
			pre->next=flag->next;
			flag->next=pre;
			 break; 
		}
		prepre=pre;
		pre=index;
		index=index->next;	
	}
	return sum;
}
int main (){
	int n;
	cin>>n;
	node* last=new node;
	len=n;
	first->w=1000000; 
	first->next=new node;
	last=first->next;
	while(n--){
		cin>>last->w;
		last->next=new node;
		last=last->next;	
	}
	last->w=1000000;
	last->next=NULL;
	last=first;
	int sum=0;
	while(len!=1){
		sum+=find();
		len--;
	}
	cout<<sum<<endl;
	return 0;
} 
