#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main (){
	int cardNum,blockNum,start,cardId[4]={0};
	cin>>blockNum>>cardNum>>start;
	blockNum--;
	int block[blockNum+1],card[cardNum+1];
	memset(block,0,sizeof(block));
	memset(card,0,sizeof(card));
	for(int i=1;i<blockNum+1;i++){
		cin>>block[i];
	}
	for(int i=1;i<cardNum+1;i++){
		cin>>card[i];
		cardId[card[i]-1]++;
	}
	int dp[cardId[0]+1][cardId[1]+1][cardId[2]+1][cardId[3]+1];
	memset(dp,0,sizeof(dp));
	int nowStep=0;
	//i，j,k,l分别代表卡片片类型1，2，3，4 的数量 
	//dp[i][j][k][l] 代表用i，j,k,l张卡片所得到的最高分 
	for(int i=0;i<=cardId[0];++i){
		for(int j=0;j<=cardId[1];++j){
			for(int k=0;k<=cardId[2];++k){
				for(int l=0;l<=cardId[3];++l){
					nowStep=i*1+j*2+k*3+l*4;
					if(i>0){
						dp[i][j][k][l]=max(dp[i-1][j][k][l]+block[nowStep],dp[i][j][k][l]);
					}
					if(j>0){
						dp[i][j][k][l]=max(dp[i][j-1][k][l]+block[nowStep],dp[i][j][k][l]);
					}
					if(k>0){
						dp[i][j][k][l]=max(dp[i][j][k-1][l]+block[nowStep],dp[i][j][k][l]);
					}
					if(l>0){
						dp[i][j][k][l]=max(dp[i][j][k][l-1]+block[nowStep],dp[i][j][k][l]);
					}
				}
			}
		}
	}
	cout<<dp[cardId[0]][cardId[1]][cardId[2]][cardId[3]]+start<<endl;
	return 0;
} 
