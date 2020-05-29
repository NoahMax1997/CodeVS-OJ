#include <iostream>
#include <queue>
#include <string>
#include <string.h>
//递归超时、内存也超
//深搜 
using namespace std;
typedef struct node{
	int x;
	int y;
}node;
char Map[52][52];
node start;
int R,C,N;
string order[1005];
queue<node> ansQueue;
bool isOver[55][55][1005];
void initMap(){
	cin>>R>>C;
	for(int i=1;i<=R;i++){
		cin>>Map[i]+1;
		for(int j=1;j<=C;j++){
			if(Map[i][j]=='*'){
				start.x=i;
				start.y=j;
			}
		}
	}
//	cout<<start.x<<" "<<start.y<<endl;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>order[i];
	}
	memset(isOver,0,sizeof(isOver));
}
void dfsMap(node reStart,int num){
	//reStart表示现在车子位置、num表示下当前指令的编号
	if(num==N)  ansQueue.push(reStart); //指令已经操作完成 
	else{
		if(order[num]=="EAST"){
			//向东走 
			for(int i=reStart.y+1;i<=C;i++){
				if(Map[reStart.x][i]=='X') break;
				else{
					node next;
					next.x=reStart.x;
					next.y=i;
					if(!isOver[next.x][next.y][num+1]){
						dfsMap(next,num+1);
						isOver[next.x][next.y][num+1]=1;
					}
				}
			} 
		} 
		else if(order[num]=="WEST"){
			//向西走 
			for(int i=reStart.y-1;i>=1;i--){
				if(Map[reStart.x][i]=='X') break;
				else{
					node next;
					next.x=reStart.x;
					next.y=i;
					if(!isOver[next.x][next.y][num+1]){
						dfsMap(next,num+1);
						isOver[next.x][next.y][num+1]=1;
					}
				}
			} 
		}
		else if(order[num]=="SOUTH"){
			//向南走 
			for(int i=reStart.x+1;i<=R;i++){
				if(Map[i][reStart.y]=='X') break;
				else{
					node next;
					next.x=i;
					next.y=reStart.y;
					if(!isOver[next.x][next.y][num+1]){
						dfsMap(next,num+1);
						isOver[next.x][next.y][num+1]=1;
					}
				}
			}
		} 
		else if(order[num]=="NORTH"){
			//向北走
			for(int i=reStart.x-1;i>=1;i--){
				if(Map[i][reStart.y]=='X') break;
				else{
					node next;
					next.x=i;
					next.y=reStart.y;
					if(!isOver[next.x][next.y][num+1]){
						dfsMap(next,num+1);
						isOver[next.x][next.y][num+1]=1;
					}
				}
			} 
		}
	}
}
int main (){
	initMap();
	dfsMap(start,0);
	if(!ansQueue.empty())  	Map[start.x][start.y]='.';
	while(!ansQueue.empty()){
		node out=ansQueue.front();
		ansQueue.pop();
		Map[out.x][out.y]='*';
	}
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cout<<Map[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
