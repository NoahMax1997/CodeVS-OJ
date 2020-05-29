#include <iostream>
using namespace std;
int n,m;
int array[100005];
int main (){
	cin>>n;
	for(int i=1;i<=n;i++)   cin>>array[i];
	cin>>m;
	int num,a,b;
	while(m--){
		cin>>num>>a>>b;
		int ans=0;
		if(num==1){
			array[a]+=b;
		}
		else{
			for(int i=a;i<=b;i++){
				ans+=array[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
