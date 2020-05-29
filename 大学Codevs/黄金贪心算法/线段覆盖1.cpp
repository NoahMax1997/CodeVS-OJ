#include <iostream>
#include <algorithm>
using namespace std;
typedef struct point{
	int x;
	int y;
}point;
bool cmp(point a,point b){
	if(a.y!=b.y) return a.y<b.y;
	//右端相同影响结果？？？？ 
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
		//确保每个线段 的描述 左端点小于右端点 
	}
	sort(sum,sum+n,cmp); 
	//按照右端点大小升序 排序 
//	for(int i=0;i<n;i++){
//		cout<<sum[i].x<<" "<<sum[i].y<<endl;
//	}
	for(int i=1;i<n;++i){
		if(sum[i].x<sum[flag].y) continue;//从第一个线段开始比较遇到相交的 就删除； 
		flag=i;
		ret++;							// 遇到不想交的 更新起始线段为 这个不相交线段 ，计数器++ 
	}
	cout<<ret<<endl;
	return 0;
}
