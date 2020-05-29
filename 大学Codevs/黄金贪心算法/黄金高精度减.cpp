#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string A,B;
bool isBig(int lenA,int lenB){
	if(lenA>lenB) return 1;
	else if(lenA==lenB)
	for(int i=0;i<lenA;i++){
		if(A.at(i)-B.at(i)>0) return 1;
	}
	return 0;
}
void oper(string& A,string& B,int lenA,int lenB){
	int sum;
	for(int i=1;i<=lenB;i++){
				sum=A.at(lenA-i)-B.at(lenB-i);
				if(sum>=0)  A.at(lenA-i)=sum+'0';
				else{
					A.at(lenA-i)=sum+'0'+10;
					A.at(lenA-i-1)--;
					if(A.at(lenA-i-1)<'0'){
						A.at(lenA-i-1)+=10;
						A.at(lenA-i-2)--;
					}
			}
		}		
}
void outputAns(int flag){
	int index;
	if(flag){
		index=A.find_first_not_of('0');
		cout<<A.substr(index,A.length()-index);
	}
	else{
		index=B.find_first_not_of('0');
		if(index!=-1){
			cout<<"-"<<B.substr(index,B.length()-index);
		}
		else{
			cout<<"0";
		}
	}
	cout<<endl;
}
void cut(string &A,string &B){
	int lenA=A.length(),lenB=B.length(),flag=0;
	if(isBig(lenA,lenB)){
		//A>B
		flag=1;
		oper(A,B,lenA,lenB);
	}
	else{
		//A<B  A=B
		flag=0;
		oper(B,A,lenB,lenA);
	}
	outputAns(flag);	
}
int main (){
	cin>>A>>B;
	cut(A,B);
	return 0;
} 
