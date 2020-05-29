#include <iostream>
#include <string>
using namespace std;
string And(string& A,string& B,int lenA,int lenB) {
	int sum;
	for(int i=1; i<=lenB; i++) {
		sum=A.at(lenA-i)+B.at(lenB-i)-'0'-'0';
		if(sum<10)  A.at(lenA-i)=sum+'0';
		else {
			sum-=10;
			A.at(lenA-i)=sum+'0';
			A.at(lenA-i-1)++;
			for(int j=lenA-i-1; j>=1; j--) {
				if(A.at(j)>='9'+1) {
					A.at(j-1)++;
					A.at(j)-=10;
				}
			}
		}
	}
	return A;
}
string muti(string A,char ch,int lenA) {
	int sum,save,up=0;
	for(int i=lenA-1; i>=1; i--) {
		sum=(ch-'0')*(A.at(i)-'0')+up;
		save=sum%10;
		up=sum/10;
		if(sum>=10) {
			//相乘产生进位
			A.at(i)=save+'0';
			for(int j=i-1; j>=1; j--) {
				if(A.at(j)>='9'+1) {
					A.at(j-1)++;
					A.at(j)-=10;
				}
			}
		} else {
			//未产生进位
			A.at(i)=sum+'0';
			up=0;
		}
	}
	if(up!=0){
		A.at(0)=up+'0';
	}
	return A;
}
int main () {
	string A,B,ans;
	cin>>A>>B;
	int lenA,lenB;
	for(int i=0; i<A.length()+B.length(); i++) {
		ans+="0";
	}
	int save,up,sum;
	if(lenA<lenB) {
		string c;
		c=A;
		A=B;
		B=c; 
	}
		A="0"+A;
		lenA=A.length(),lenB=B.length();
		string preSum="0";
	 for(int i=lenB-1; i>=0; i--) {
			preSum=muti(A,B.at(i),lenA);
			for(int j=1;j<lenB-i;j++) preSum+="0";
			ans=And(ans,preSum,ans.length(),preSum.length());
			ans="0"+ans;
		}
		int index=ans.find_first_not_of('0');
		if(index==-1) cout<<"0"<<endl; 
		else {
			cout<<ans.substr(index,ans.length()-index)<<endl;
		}
	return 0;
}
