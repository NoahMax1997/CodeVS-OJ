/*
����:Athena_int
��Ŀ:p1017 �˻����
*/
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
int toInt(int i,int j,string str){
	int ret=0;
	 stringstream sin;
	 sin<<str.substr(i,j-i);
	 sin>>ret;
	 return ret;
}
int main()
{
    int n,k;
   
    string str;
    cin>>n>>k;
	cin>>str;
	int dp[n+1][k+1];//dp[i][j] ������ǰi�����л��ֳ�j������ ʹ����˻���� 
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][1]=toInt(0,i,str);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k+1&&j<=i;j++){
			for(int l=1;l<=i;l++){
				dp[i][j]=max(dp[l][j-1]*toInt(l,i,str),dp[i][j]);
			}
		}
	}
	cout<<dp[n][k+1]; 
	return 0;
}
