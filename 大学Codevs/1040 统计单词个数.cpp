#include<iostream>
#include <stdio.h>
#include <string.h>
//����1��ÿ�β��Ե���һ���ַ�����ֻ�Ƿֶ�����롣
//����2�� �ַ����ж�Ҳ�ö�̬�滮˼��  sum[i][j]��ʾi��j֮���ж��ٸ�����Ҫ��ĵ��ʣ��������ʲ��ܹ��ÿ�ʼ��һ����ĸ��.�����ַ�i��
using namespace std;
int k,p,s,strLen;
int sum[205][205],dp[205][205];
string str,dic[10];
void input(){
	string inputStr;
	str.clear();
	inputStr.clear();
	cin>>p>>k;
	for(int i=0;i<p;i++){
		cin>>inputStr;
		str+=inputStr;
	}
	cin>>s;
	for(int i=0;i<s;i++){
		cin>>dic[i];
	}	
}
int isCh(int i,int j){
//	str="thisisabook";
	string subStr;
//	s=4;
//	dic[0]="is",dic[1]="a",dic[2]="ok",dic[3]="sab";
//	cout<<str<<"\n";
	for(int k=0;k<s;k++){
		int len=dic[k].length();
		if(i+len-1>j) continue;
		subStr=str.substr(i,len);
		if(dic[k]==subStr) return 1;
	}
	return 0;
}
void dpDic(){
	//����sum[i][j] ʹ���ʾi~j֮�䵥�ʸ��� 
//	str="thisisabook";
	strLen=str.length();
	memset(sum,0,sizeof(sum));
	for(int i=strLen;i>0;i--){
		for(int j=strLen;j>=i;j--){
			sum[i][j]=sum[i+1][j]+isCh(i-1,j-1);
//			cout<<i+1<<"~"<<j+1<<": "<<sum[i+1][j+1]<<"\n";
		}
	}
}
void dpStr(){
	strLen=str.length();
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=strLen;i++){
		for(int j=1;j<=k;j++){
			for(int k=j-1;k<i;k++){
				dp[i][j]=max(dp[i][j],dp[k][j-1]+sum[k+1][i]);
//				if(i==4){
//					cout<<"i="<<i<<"j= "<<j<<" dp[i][j]= "<<dp[i][j]<<" k="<<k<<"sum[i-k+1][i]="<<sum[i-k+1][i]<<endl; 
//				}
			}
		}
	}
}
void output(){
	printf("%d\n",dp[strLen][k]);
}
int main (){
	int test;
	cin>>test;
	while(test--){
		input();
		dpDic();
		dpStr();
		output();
	}
	return 0;
} 
