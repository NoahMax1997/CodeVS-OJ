#include <iostream>
#include <stdio.h>
using namespace std;
int map[10][10];
int ans=-1;
bool row[10][10];
bool col[10][10];
bool sudoku[10][10]; 
int step=0;
int score[10][10]={
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6},
};
//每个数字不能再小九宫格内出现 
int numOfSudoku(int i,int j){
	if(i>=1&&i<=3&&j>=1&&j<=3) return 1;
	else if(i>=1&&i<=3&&j>=4&&j<=6) return 2;
	else if(i>=1&&i<=3&&j>=7&&j<=9) return 3;
	else if(i>=4&&i<=6&&j>=1&&j<=3) return 4;
	else if(i>=4&&i<=6&&j>=4&&j<=6) return 5;
	else if(i>=4&&i<=6&&j>=7&&j<=9) return 6;
	else if(i>=7&&i<=9&&j>=1&&j<=3) return 7;
	else if(i>=7&&i<=9&&j>=4&&j<=6) return 8;
	else if(i>=7&&i<=9&&j>=7&&j<=9) return 9;
}
void initMap(){
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]){
				row[i][map[i][j]]=1;
				col[j][map[i][j]]=1;
				sudoku[numOfSudoku(i,j)][map[i][j]]=1;
			}
		}
	}		
}
void coutMap(){
	cout<<endl;
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}
int ansMap(){
	int ret=0;
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			ret+=map[i][j]*score[i][j];
		}
	}
	return ret;
}
bool isDanger(int i,int j,int num){
	if(row[i][num]||col[j][num]||sudoku[numOfSudoku(i,j)][num]) return 1;
	return 0;
}
void dfsMap(int i,int j,int ret){
//	if(ans==2879)
//	cout<<i<<" "<<j<<endl;
//	step++;
	if(i==0&&ret>ans){
//		coutMap();
//		cout<<ansMap()<<endl;
		ans=ret;
		return;
	}
	if(map[i][j]){//该位置已经填上数字 
		ret+=map[i][j]*score[i][j];
		if(j>=2){
			dfsMap(i,j-1,ret);
		}
		else{
			dfsMap(i-1,9,ret);
		}
	}
	else{
		for(int num=9;num>=1;num--){
			if(isDanger(i,j,num))  continue;
			else{
				map[i][j]=num;
				ret+=map[i][j]*score[i][j];
				row[i][num]=1;
				col[j][num]=1;
				sudoku[numOfSudoku(i,j)][num]=1;
				if(j>=2){
					dfsMap(i,j-1,ret);
				}
				else{
					dfsMap(i-1,9,ret);
				}
				ret-=map[i][j]*score[i][j];
				map[i][j]=0;
				row[i][num]=0;
				col[j][num]=0;
				sudoku[numOfSudoku(i,j)][num]=0;
			}
		}
	}
}
int main (){
	initMap();
	int ret=0;
	dfsMap(9,9,ret);
	cout<<ans<<endl;
//	cout<<step;
	return 0;
} 
