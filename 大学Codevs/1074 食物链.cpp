#include <iostream>
#include <string.h>
#include <stdio.h>
int n,k,d,x,y,sum=0;
int Set[50008];
int dis[4][4];//记录A，B，C之间的关系 
using namespace std;
int findRoot(int x){
	while(Set[x]!=x){
		Set[x]=Set[Set[x]];
		x=Set[x];
	}
}
void joinSet(int x,int y){
	int rx=findRoot(x),ry=findRoot(y);
	if(rx!=ry){
		Set[rx]=ry;
	}
}
void init(){
	for(int i=1;i<=n+4;i++){
		Set[i]=i;
	}
	dis[1][1]=1,dis[2][2]=1,dis[3][3]=1;
	dis[1][2]=2,dis[2][3]=2,dis[3][1]=2;
	dis[1][3]=0,dis[2][1]=0,dis[3][2]=0;
}
int main (){
	sum=0;
	scanf("%d%d",&n,&k);
//	getchar();
	n+=3;
	init();
	while(k--){
		scanf("%d%d%d",&d,&x,&y);
//		getchar();
		x+=3;
		y+=3;
		if(x>n||y>n){
			sum++;
			continue;
		}
		if(x==y&&d==2){
			sum++;
			continue;
		}
		int rx=findRoot(x),ry=findRoot(y);
		if(x==rx&&y!=ry){
			//x未定义  y定义了 
			for(int i=1;i<=3;i++){
				if(dis[i][ry]==d){
					joinSet(x,i);
					break;
				}
			}
		}
		else if(y==ry&&x!=rx){
			//y未定义  x已经定义 
			for(int i=1;i<=3;i++){
				if(dis[rx][i]==d){
					joinSet(y,i);
					break;
				}
			}	
		}
		else if(y==ry&&x==rx){
			//x，y都没定义 
			int flag=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(dis[i][j]==d&&!flag){
						joinSet(x,i);
						joinSet(y,j);
						flag=1;
					}
				}
			}
		}
		else if(y!=ry&&x!=rx){
			//x,y都定义了
			 if(dis[rx][ry]!=d){
			 	sum++;
			 	continue;
			 }
		}	
	}
	printf("%d\n",sum);
	return 0;
}
