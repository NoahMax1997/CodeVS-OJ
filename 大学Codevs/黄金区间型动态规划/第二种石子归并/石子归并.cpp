#include <iostream>
using namespace std;
//GarsiaWachs�㷨 
//��������stone[]���������ң���һ������stone[k-1] <= stone[k+1]��k��
//�ҵ���ϲ�stone[k]��stone[k-1]���ٴӵ�ǰλ�ÿ�ʼ����������j��
//ʹ������stone[j] > stone[k]+stone[k-1]���嵽j�ĺ�����С�һֱ�ظ���
//ֱ��ֻʣ��һ��ʯ�ӾͿ����ˡ�
//����������У����Լ���stone[-1]��stone[n]���������
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
			//�ϲ� index ��pre�ڵ� 
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
			//��pre�嵽flag����
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
