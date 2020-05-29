#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;
string endHash="123804765";
typedef struct status{
	char map[4][4];
	string hash;
	int step;
	int i,j;
}status;
status start;
set<string> hashSet;
queue<status> Queue;
int ans=10000000;
void coutMap(status);
void getHash(status& S){
	S.hash.clear();
	for(int i=0;i<9;i++){
		S.hash+=S.map[i/3+1][i%3+1];
	}
//	coutMap(S);
//	cout<<"\n";
//	cout<<S.hash<<"\n";
}
bool hashEqual(string a,string b){
	return a==b;
}
void findZero(status& S){
	for(int k=1;k<4;k++)
		for(int l=1;l<4;l++)
			if(S.map[k][l]=='0'){
				S.i=k,S.j=l;
				return;
			}
}
void initQueue(){
	Queue.push(start);
	hashSet.insert(start.hash);
//	cout<<(hashSet.find("1234666")==hashSet.end());
}
void input(){
	string in;
	cin>>in;
	for(int i=0;i<9;i++){
		start.map[i/3+1][i%3+1]=in[i];
	}
	start.step=0;
	getHash(start);
	findZero(start);
}
void coutMap(status S){
		for(int i=1;i<4;i++){
		for(int j=1;j<4;j++){
			cout<<S.map[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void up(status S){
//	coutMap(S);
	if(S.i-1<1) return;//上面的数字不存在 
	char t=S.map[S.i][S.j];
	S.map[S.i][S.j]=S.map[S.i-1][S.j];
	S.map[S.i-1][S.j]=t;
//	cout<<"\n";
//	coutMap(S);
	S.i--;
	getHash(S);
//	cout<<S.hash<<"\n";
//	cout<<(hashSet.find(S.hash)==hashSet.end());
	if(hashSet.find(S.hash)!=hashSet.end())   return;//此状态已经存在 
	S.step++;
//	coutMap(S);
	Queue.push(S); 
	hashSet.insert(S.hash);
}
void down(status S){
//	coutMap(S);
	if(S.i+1>3) return;//下面的数字不存在
	char t=S.map[S.i][S.j];
	S.map[S.i][S.j]=S.map[S.i+1][S.j];
	S.map[S.i+1][S.j]=t;
	S.i++;
	getHash(S);
	if(hashSet.find(S.hash)!=hashSet.end())  return; //此状态已经存在 
	S.step++;
	Queue.push(S);
	hashSet.insert(S.hash);
}
void left(status S){
//	coutMap(S);
	if(S.j-1<1) return;//左面的数字不存在
	char t=S.map[S.i][S.j];
	S.map[S.i][S.j]=S.map[S.i][S.j-1];
	S.map[S.i][S.j-1]=t;
	S.j--;
	getHash(S);
	if(hashSet.find(S.hash)!=hashSet.end())  return; //此状态已经存在 
	S.step++;
	Queue.push(S);
	hashSet.insert(S.hash);
}
void right(status S){
//	coutMap(S);
	if(S.j+1>3) return;//右面的数字不存在
	char t=S.map[S.i][S.j];
	S.map[S.i][S.j]=S.map[S.i][S.j+1];
	S.map[S.i][S.j+1]=t;
	S.j++;
	getHash(S);
	if(hashSet.find(S.hash)!=hashSet.end())  return; //此状态已经存在 
	S.step++;
	Queue.push(S);
	hashSet.insert(S.hash);
}
void bfsMap(){
	while(!Queue.empty()){
		status test=Queue.front();
//		coutMap(test);
		if(hashEqual(test.hash,endHash)&&ans>test.step){
			ans=test.step;
		}
		up(test);//0和上面的数字交换 
		down(test);//0和下面的数字交换 
		left(test);//0和左面的数字交换 
		right(test);//0和右面的数字交换 
		Queue.pop(); 
	}
}
int main (){
	input();
	initQueue();
	bfsMap();
	cout<<ans<<endl;
	return 0;
}
