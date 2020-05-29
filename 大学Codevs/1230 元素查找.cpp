#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
map<int,bool> myMap;
int main (){
	int n,m;
	cin>>n>>m;
	while(n--){
		int a;
		cin>>a;
		myMap[a]=1;
	}
	while(m--){
		int a;
		cin>>a;
		if(myMap.find(a)!=myMap.end()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
