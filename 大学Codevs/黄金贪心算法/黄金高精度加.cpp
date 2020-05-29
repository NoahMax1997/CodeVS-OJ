#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string And(string& A,string& B,int lenA,int lenB){
	int sum;
	for(int i=1;i<lenB;i++){
			sum=A.at(lenA-i)+B.at(lenB-i)-'0'-'0';
			if(sum<10)  A.at(lenA-i)=sum+'0';
			else{
				sum-=10;
				A.at(lenA-i)=sum+'0';
				A.at(lenA-i-1)++;
				for(int j=lenA-i-1;j>=1;j--){
					if(A.at(j)>='9'+1){
						A.at(j-1)++;
						A.at(j)-=10;
					}
				}
			}
		}
	return A;
}
int main (){
	string A,B,ans; 
	int lenA,lenB;
	cin>>A>>B;
	A="0"+A;
	B="0"+B;
	lenA=A.length(),lenB=B.length();
	if(lenA>=lenB){
		//A´ó 
		ans=And(A,B,lenA,lenB);
	}
	else{
		//B´ó
		ans=And(B,A,lenB,lenA); 
	}
	int index=ans.find_first_not_of('0');
	if(index==-1) cout<<"0"<<endl;
	else  cout<<ans.substr(index,ans.length()-index)<<endl;
	return 0;
} 
