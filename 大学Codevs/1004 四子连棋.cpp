#include <iostream>
#include <string.h>
using namespace std;
int main (){
	char set[4][4];
	int x1=1,x2,y1,y2;
	memset(set,0,sizeof(set));
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>set[i][j];
			if(x1&&set[i][j]=='0'){
				x1=0;
				x1=i,y1=j;
			}
			if(!x1&&set[i][j]=='0'){
				x2=i,y2=j;
			}
		}
	}
	
	return 0;
}
