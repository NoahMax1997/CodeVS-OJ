#include <iostream>
#include <string>
#include <set>
#include <queue>
//字符串最长20  ！！！！！！！！！！！！！！！！！！！！！！！！ 
using namespace std;
string strA,strB;
string strSet1[21],strSet2[21];
set<string>  isOver;
int n=0;
int step=0,flag=0;
typedef struct node{
	string str;
	int step;
}strNode;
queue<strNode> Queue;
void init(){
	cin>>strA>>strB;
	while(cin>>strSet1[n]>>strSet2[n]){
		n++;
	}
//cin>>n;
//for(int i=0;i<n;i++){
//	cin>>strSet1[i]>>strSet2[i];
//}
}
void findSame(strNode& str,int num){
	//在字符串str中找到所有strSet1[num] 部分并替代
	strNode reStr=str,preStr=str; 
	int index=-1,strLen=str.str.length(),tempLen=strSet1[num].length(); 
//	cout<<str.str.find(strSet1[num],index+1)<<endl;
	index=str.str.find(strSet1[num],index+1);
	while(index!=string::npos){
		//不断在str中寻找可替换的字串
		preStr.str.replace(index,tempLen,strSet2[num]);//替换该子串
		if(isOver.find(preStr.str)!=isOver.end()||preStr.str.length()>20){  //控制字符串长度并且防止队列中字符串重复 ！！！！！！！！！！！！！！！！！！！！ 
			index=str.str.find(strSet1[num],index+1);
			continue;
		}//该字符串已经存在
		preStr.step++;
		Queue.push(preStr);
		isOver.insert(preStr.str);
		preStr=str; 
		index=str.str.find(strSet1[num],index+1);
	}
} 
void bfsStr(){
	strNode first;
	first.step=0;
	first.str=strA;
	Queue.push(first);
	while(!Queue.empty()){
		strNode str;
		str=Queue.front();
		Queue.pop();
		if(str.str==strB){
			step=str.step;
			return;
		}
		for(int i=0;i<n;i++){
		//寻找字符串中所有可被替代的部分（可能含有多个相同串） 
		 	findSame(str,i);
		}
	}
}
void output(){
	if(step<=10&&step>0) cout<<step<<endl;
	else if(strA==strB) cout<<0<<endl;
	else cout<<"NO ANSWER!"<<endl;
}
int main (){
	init();
	bfsStr();
	output();
	return 0;
}
