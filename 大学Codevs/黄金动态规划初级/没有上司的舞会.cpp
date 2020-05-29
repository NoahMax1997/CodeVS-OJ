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
int dp[maxn][2],father[maxn];//dp[i][0]0表示不去，dp[i][1]1表示去了  
bool visited[maxn];  
  
void tree_dp(int node)  
{  
    int i;  
    visited[node] = 1;  
    for(i=1; i<=n; i++)  
    {  
        if(!visited[i]&&father[i] == node)//i为下属  
        {  
            tree_dp(i);//递归调用孩子结点，从叶子结点开始dp  
            //关键  
            dp[node][1] += dp[i][0];//上司来,下属不来  
            dp[node][0] +=max(dp[i][1],dp[i][0]);//上司不来，下属来、不来  
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
        root = 0;//记录父结点  
        bool beg = 1;  
        while (scanf("%d %d",&c,&f),c||f)  
        {  
            father[c] = f;  
            if( root == c || beg )  
            {  
                root = f;  
            }  
        }  
        while(father[root])//查找父结点  
            root=father[root];  
        tree_dp(root);  
        int imax=max(dp[root][0],dp[root][1]);  
        printf("%d\n",imax);  
    }  
    return 0;  
}  
