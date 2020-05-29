
#include <iostream>
#include <stdio.h>
#include <map>
#include  <queue>
using namespace std;
typedef struct sta{
	int last;
	long long hash;
	int map[5][5];
	int step;
}node;
node first;
queue<node> Queue; 
map<long long,bool> isQueue[3];//记录已经经历过的棋盘哈希值和上次移动的棋子颜色； 
int b=0,w=1;//分黑棋先移动；白棋先移动两种情况。
int xx[]={1,-1,0,0},yy[]={0,0,1,-1}; 
void initMap(){
	first.step=0;
	char ch[6];
	for(int i=1;i<5;i++){
		cin>>ch+1;
		for(int j=1;j<5;j++){
			if(ch[j]=='W') first.map[i][j]=1;
			else if(ch[j]=='B') first.map[i][j]=2;
			else first.map[i][j]=0;
		}
	}
	
//	for(int i=1;i<5;i++){
//		for(int j=1;j<5;j++){
//			cout<<first.map[i][j]<<" "; 
//		}
//		cout<<endl;
//	}
}
void getHashValue(node& test){
	//得到当前棋盘的哈希值 
	long long sum=0;
	for(int i=1;i<5;i++){
		for(int j=1;j<5;j++){
			sum*=3;
			sum+=test.map[i][j];
		}
	}
	test.hash=sum;
}
bool cheak(node& test){
	for(int i=1;i<5;i++){
		//判断同一行是否满足 
		int j;
		for(j=1;j<4;j++){
			if(test.map[i][j]!=test.map[i][j+1]) break;
		}
		if(j==4) return 1;
	}
	for(int i=1;i<5;i++){
		int j;
		//判断同一列是否满足 
		for(j=1;j<4;j++){
			if(test.map[j][i]!=test.map[j+1][i]) break;
		}
		if(j==4) return 1;
	}
	if(test.map[1][1]==test.map[2][2]&&test.map[3][3]==test.map[4][4]&&test.map[2][2]==test.map[3][3])  return 1;
	if(test.map[1][4]==test.map[2][3]&&test.map[3][2]==test.map[4][1]&&test.map[2][3]==test.map[3][2])  return 1;
	return 0;
}
int bfsAns(node& first){
	while(!Queue.empty()){
//		cout<<ans<<endl;
		node now=Queue.front();
		Queue.pop();
		if(cheak(now)){
			 return now.step; 
		}
		for(int x=1;x<5;x++){
			for(int y=1;y<5;y++){
				if(now.map[x][y]!=0) continue;
				int nowx,nowy;
				for(int index=0;index<4;index++){
					nowx=x+xx[index],nowy=y+yy[index];
					if(now.map[nowx][nowy]==now.last) continue;
					if(nowx<1||nowx>4||nowy<1||nowy>4) continue;
					node next=now;
					next.last=3-next.last;
					next.step++;
					swap(next.map[x][y],next.map[nowx][nowy]);
					getHashValue(next);
					if(isQueue[next.last].find(next.hash)!=isQueue[next.last].end()) continue;
					Queue.push(next);
					isQueue[next.last][next.hash]=1;
				}
			}
		}
	}
} 
void output(){
	int ans;
	first.last=1;
	getHashValue(first);
	isQueue[first.last][first.hash]=1;
	Queue.push(first);
	ans=bfsAns(first);
	for(int i=0;i<3;i++){
		isQueue[i].clear();
	}
	while(!Queue.empty()){
//		cout<<Queue.front().hash<<endl;
		Queue.pop();
	} 
	first.last=2;
	getHashValue(first);
	Queue.push(first);
	isQueue[first.last][first.hash]=1;
	ans=min(bfsAns(first),ans);
	cout<<ans<<endl;
}
int main (){
	initMap();
	output();
	return 0;
} 
