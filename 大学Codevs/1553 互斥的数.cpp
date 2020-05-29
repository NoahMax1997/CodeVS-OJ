#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<long long,bool> myMap;
long long in[100005];
int main (){
	long long n,p;
	cin>>n>>p;
	for(long long i=1;i<=n;i++){
		cin>>in[i];
		myMap[in[i]]=1;
	} 
	long long count=0;
	sort(in+1,in+1+n);
	for(long long i=1;i<=n;i++){
		if(myMap[in[i]]){
			count++;
			myMap[in[i]*p]=0;
		}
	}
	cout<<count<<endl;
	return 0;
}
