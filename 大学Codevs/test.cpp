#include <iostream>
using namespace std;
string str,strSet;
int opt,n;
void lowStr(string& str){
	for(int i=0;i<str.length();i++){
		if(str.at(i)>='A'&&str.at(i)<='Z'){
			str[i]=str[i]+'a'-'A';
		}
	}
//	cout<<str<<endl;
}
int main (){
	cin>>str>>opt>>n;
	while(n--){
		cin>>strSet;
		string temp=strSet;
		if(!opt){
			lowStr(str);
			lowStr(temp);	
		}
		if(temp.find(str)!=temp.npos){
			cout<<strSet<<endl;
		}
	}
	return 0;
} 
