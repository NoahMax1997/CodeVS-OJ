#include <iostream>
#include <algorithm>
using namespace std;
typedef struct point{
	int x;
	int y;
}point;
bool cmp(point a,point b){
	if(a.y!=b.y) return a.y<b.y;
	//�Ҷ���ͬӰ������������ 
}
int main (){
	int n,a,b,flag=0,ret=1;
	cin>>n;
	point sum[101];
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>b){
			a=a+b;
			b=a-b;
			a=a-b;
		}
		sum[i].x=a;
		sum[i].y=b;
		//ȷ��ÿ���߶� ������ ��˵�С���Ҷ˵� 
	}
	sort(sum,sum+n,cmp); 
	//�����Ҷ˵��С���� ���� 
//	for(int i=0;i<n;i++){
//		cout<<sum[i].x<<" "<<sum[i].y<<endl;
//	}
	for(int i=1;i<n;++i){
		if(sum[i].x<sum[flag].y) continue;//�ӵ�һ���߶ο�ʼ�Ƚ������ཻ�� ��ɾ���� 
		flag=i;
		ret++;							// �������뽻�� ������ʼ�߶�Ϊ ������ཻ�߶� ��������++ 
	}
	cout<<ret<<endl;
	return 0;
}
