#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
typedef struct node{
	int x;
	int y;
	int num;
}node;
char Map[52][52];
node start;
int R,C,N;
string order[1005];
queue<node> Queue;
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
				start.num=0;
			}
		}
	}
//	cout<<start.x<<" "<<start.y<<endl;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>order[i];
	}
	memset(isOver,0,sizeof(isOver));//��ʼ���������� 
}
void bfsSolve(){
	node reStart=start;
	Queue.push(start);
	while(!Queue.empty()){
		//��¼ÿ����ִ��ָ����ܵ����λ��   �������
		reStart=Queue.front();
		Queue.pop();
		if(reStart.num==N) {
			//�Ѿ��������ָ����� 
			ansQueue.push(reStart);
			continue;
		}
		if(order[reStart.num]=="EAST"){
			for(int i=reStart.y+1;i<=C;i++){
				if(Map[reStart.x][i]=='X') break;//����X ֹͣ��÷����ƶ� 
				node temp=reStart;
				temp.num++;
				temp.y=i;
				if(!isOver[temp.x][temp.y][temp.num]){
					Queue.push(temp);
					isOver[temp.x][temp.y][temp.num]=1;
				}
			}	
		}
		else if(order[reStart.num]=="WEST"){
			for(int i=reStart.y-1;i>=1;i--){
				if(Map[reStart.x][i]=='X') break;//����X ֹͣ��÷����ƶ� 
				node temp=reStart;
				temp.num++;
				temp.y=i;
				if(!isOver[temp.x][temp.y][temp.num]){
					Queue.push(temp);
					isOver[temp.x][temp.y][temp.num]=1;
				}
			}	
		}
		else if(order[reStart.num]=="SOUTH"){
			for(int i=reStart.x+1;i<=R;i++){
				if(Map[i][reStart.y]=='X') break;
				node temp=reStart;
				temp.num++;
				temp.x=i;
				if(!isOver[temp.x][temp.y][temp.num]){
					Queue.push(temp);
					isOver[temp.x][temp.y][temp.num]=1;
				}		
			}	
		}
		else if(order[reStart.num]=="NORTH"){
			for(int i=reStart.x-1;i>=1;i--){
				if(Map[i][reStart.y]=='X') break;
				node temp=reStart;
				temp.num++;
				temp.x=i;
				if(!isOver[temp.x][temp.y][temp.num]){
					Queue.push(temp);
					isOver[temp.x][temp.y][temp.num]=1;
				}		
			}	
		}	 
	}
}
void output(){
	if(!ansQueue.empty()) Map[start.x][start.y]='.';
 	while(!ansQueue.empty()){
		node test=ansQueue.front();
		ansQueue.pop();
		Map[test.x][test.y]='*';
	}
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cout<<Map[i][j];
		}
		cout<<endl;
	}
}
int main (){
	initMap();//��ͼ��ʼ���������ʼ�� 
	bfsSolve();//����������� 
	output();//����� 
	return 0;
} 
