#include <iostream>
#include <queue>
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
}
int main (){
	
	return 0;
} 
