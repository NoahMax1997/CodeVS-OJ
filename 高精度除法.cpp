#include <iostream>
#include <string> 
using namespace std;
string a,b;
void input(){
	cin>>a>>b;
}
int whichBigger(string a,string b){
	int lena=a.length();
	int lenb=b.length();
	if(lena>lenb) return 1;
	else if(lena<lenb) return 2;
	else{
		int i;
		for(i=0;i<lena;i++){
			if(a.at(i)>b.at(i)) return 1;
			else if(a.at(i)<b.at(i)) return 2;
		}
	}
	return 0;
}
string stringToInt(string a){
	string ret="";
	int i=0;
	for(i=0;i<a.length();i++){
		if(a.at(i)!='0'){
			break;
		}
	}
	return a.substr(i,a.length());
}
string Minus(string aa,string bb){
//	string ret,aa,bb;
//	if(whichBigger(a,b)==1){
//		aa=a,bb=b;	
//	}else if(whichBigger(a,b)==2){
//		aa=b,bb=a;
//	}else return "0";
	int flag=0;
		int i,j;
		for(i=aa.length()-1,j=bb.length()-1;j>=0;j--,i--){
			int temp=aa.at(i)-bb.at(j)-flag;
			if(temp<0){
				flag=1;
				temp+=10;
			}else flag=0;
			aa.at(i)=temp+'0';
		}
		for(;i>=0;i--){
			if(flag==1){
				int temp=aa.at(i)-'1';
				if(temp<0){
					flag=1;
					temp+=10;
				}else flag=0;
				aa.at(i)=temp+'0';
			}
		}
//		cout<<aa<<endl;
		return stringToInt(aa);		
}
bool isLessZero(string str){
	int i;
	for(i=0;i<str.length();i++){
		int temp=str.at(i)-'0';
		if(temp<0) return true;
	}
	return false;
}
string Muti(string a,int  bb){
//	int bb=b.at(0)-'0';
	int flag=0;
	for(int i=a.length()-1;i>=0;i--){
		int temp=(a.at(i)-'0')*bb+flag;
		flag=temp/10;
		a.at(i)=temp%10+'0'; 
	}
	if(flag!=0){
		char i=flag+'0';
		a.insert(0,1,i);
	}
	return a;
}

int main (){
	string ret="";
	input();
	if(whichBigger(a,b)==0){
		ret="1";
	}else if(whichBigger(a,b)==2){
		ret="0";
	}else{
		string str=a.substr(0,b.length());
		int start=b.length()-1;
		if(whichBigger(str,b)==2){
			start=b.length();
			str=a.substr(0,b.length()+1);
		}
		while(start<a.length()){
			if(whichBigger(str,b)==2){
				ret+="0";
				start++;
				if(start<a.length()){
					str=str+a.at(start);	
				}
			} 
			else if(whichBigger(str,b)==0){
				ret+="1";
				start++;
				if(start<a.length()){
					str=a.at(start);	
				}
			} 
			else{
				int i=1; 
				string temp;
				for(i=1;i<=9;i++){
					temp=Muti(b,i);
					if(whichBigger(temp,str)==1) break;
				}
				ret+='0'+i-1;
				temp=Muti(b,i-1);
				str=Minus(str,temp);
				start++;
				if(start<a.length()){
					str=str+a.at(start);	
				}
			}
		}
		
	}
//	cout<<Muti(a,b)<<endl;
	cout<<ret<<endl;	
	return 0;
} 
