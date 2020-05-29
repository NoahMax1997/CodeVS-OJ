#include <iostream>
using namespace std;
typedef struct node{
	int x;
	int y;
}Node;
Node horse,B;
Node danger[9];
int sum=0;
bool isdanger(int x,int y){
	for(int i=0;i<9;i++){
		if(x==danger[i].x&&y==danger[i].y) return 1;
	}
	return 0;
}
void dfs(int x,int y){
	if(x<=B.x&&y<=B.y){
		if(!isdanger(x,y)){
			if(x==B.x&&y==B.y){
				sum++;	
			}
			else{
				dfs(x+1,y);
				dfs(x,y+1);
			}
		}	
	}
}
int main (){
	cin>>B.x>>B.y>>horse.x>>horse.y;
	danger[0].x=horse.x+2,danger[0].y=horse.y+1;
	danger[1].x=horse.x+1,danger[1].y=horse.y+2;
	danger[2].x=horse.x-1,danger[2].y=horse.y+2;
	danger[3].x=horse.x-2,danger[3].y=horse.y+1;
	danger[4].x=horse.x-2,danger[4].y=horse.y-1;
	danger[5].x=horse.x-1,danger[5].y=horse.y-2;
	danger[6].x=horse.x+1,danger[6].y=horse.y-2;
	danger[7].x=horse.x+2,danger[7].y=horse.y-1;
	danger[8].x=horse.x,danger[8].y=horse.y;
	dfs(0,0);
	cout<<sum<<endl;
	return 0;
}
