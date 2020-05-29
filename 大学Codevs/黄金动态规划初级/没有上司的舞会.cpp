#include<iostream>  
#include<cmath>  
#include<algorithm>  
#include<vector>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<string>  
  
using namespace std;  
  
#define maxn 6005  
  
int n;  
int dp[maxn][2],father[maxn];//dp[i][0]0��ʾ��ȥ��dp[i][1]1��ʾȥ��  
bool visited[maxn];  
  
void tree_dp(int node)  
{  
    int i;  
    visited[node] = 1;  
    for(i=1; i<=n; i++)  
    {  
        if(!visited[i]&&father[i] == node)//iΪ����  
        {  
            tree_dp(i);//�ݹ���ú��ӽ�㣬��Ҷ�ӽ�㿪ʼdp  
            //�ؼ�  
            dp[node][1] += dp[i][0];//��˾��,��������  
            dp[node][0] +=max(dp[i][1],dp[i][0]);//��˾������������������  
        }  
    }  
}  
  
int main()  
{  
    int i;  
    int f,c,root;  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(dp,0,sizeof(dp));  
        memset(father,0,sizeof(father));  
        memset(visited,0,sizeof(visited));  
        for(i=1; i<=n; i++)  
        {  
            scanf("%d",&dp[i][1]);  
        }  
        root = 0;//��¼�����  
        bool beg = 1;  
        while (scanf("%d %d",&c,&f),c||f)  
        {  
            father[c] = f;  
            if( root == c || beg )  
            {  
                root = f;  
            }  
        }  
        while(father[root])//���Ҹ����  
            root=father[root];  
        tree_dp(root);  
        int imax=max(dp[root][0],dp[root][1]);  
        printf("%d\n",imax);  
    }  
    return 0;  
}  
