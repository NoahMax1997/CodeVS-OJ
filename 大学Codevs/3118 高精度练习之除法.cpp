#include <iostream>
#include <string.h>
using namespace std;
char op1[505],op2[505];
int len1,len2;
void init(){
	scanf("%s%s",op1,op2);
	len1=strlen(op1),len2=strlen(op2);
}
int cmp(char a[505],char b[505]){
	//a>b 返回1 
	int len1=strlen(a),len2=strlen(b);
	if(len1>len2) return 1;
	else if(len1==len2){
		int i=0;
		for(i=0;i<len1;i++){
			if(a[i]-b[i]>0) return 1;
		}
		if(i==len1) return 0;
	} 
	return -1;
}
char* subtraction(char a[505],char b[505]){
	char* ans=new char[505];
	int flag=1; //记录结果符号   1 正  0 负 
	memset(ans,'0',sizeof(ans));
	int len1=strlen(a),len2=strlen(b);
	if(cmp(a,b)==-1){
		//保证a>=b 
		char* temp=a;
		a=b;
		b=temp;
		flag=0; 
	}
	else if(cmp(a,b)==0){
		ans[0]='0';
		ans[1]='\0';
		return ans;
	}
	len1=strlen(a),len2=strlen(b);
	//////  a-b
	int inc=0;
	strcpy(ans+1,a);
	for(int i=0;i<len2;i++){
		int temp=ans[len1-i]-b[len2-i-1]-inc;
		if(temp<0){
			inc=1;
			temp+=10;
		}
		else inc=0;
		ans[len1-i]=temp+'0';
	}
	for(int i=len1-len2;i>=1;i--){
		int temp=ans[i]-inc-'0';
		if(temp<0){
			inc=1;
			temp+=10;
		}
		else inc=0;
		ans[i]=temp+'0';
	}
	int index=0;
	while(ans[index++]=='0');
	if(!flag){
		ans[index-2]='-';
		return ans+index-2;
	} 
	return ans+index-1;
}
char* addition(char a[505],char b[505]){
	char* ans=new char[505];
	memset(ans,'\0',sizeof(ans));
	int len1=strlen(a),len2=strlen(b);
	if(len1<len2){
		//保证a>=b 
		char* temp=a;
		a=b;
		b=temp;
	}
	len1=strlen(a),len2=strlen(b);
	strcpy(ans+1,a);
	int inc=0;
	for(int i=0;i<len2;i++){
		int temp=(ans[len1-i]-'0'+b[len2-1-i]-'0'+inc);
		if(temp>=10){
			inc=1;
			temp-=10;
		}
		else inc=0;
		ans[len1-i]=temp+'0';
	}
	for(int i=len1-len2;i>=0;i--){
		int temp=ans[i]-'0'+inc;
		if(temp>=10){
			inc=1;
			temp-=10;
		}
		else inc=0;
		ans[i]=temp+'0';
	}
	if(ans[0]=='\0')  return ans+1;
	return ans;
}
char* multiplication(char a[505],char b[505]){
	char* ans=new char[10010];
	memset(ans,'\0',sizeof(ans));
	int len1=strlen(a),len2=strlen(b);
	if(len1<len2){
		//保证a>=b 
		char* temp=a;
		a=b;
		b=temp;
	}
	len1=strlen(a),len2=strlen(b);
	int inc=0,start=505;
	for(int i=0;i<len2;i++){
		for(int j=len1-1;j>=0;j--){
			int temp=(a[j]-'0')*(b[len2-1-i]-'0')+inc;
			inc=temp/10;
			temp=temp%10;
			if(ans[start+j-i]=='\0') 
				ans[start+j-i]=temp+'0';
			else ans[start+j-i]+=temp;
		}
		if(inc>0){
			start--;
			ans[start]=inc+'0';
		}
	}
	return ans+start;
}
char* division(char a[505],char b[505]){
	char* ans=new char[505];
	memset(ans,0,sizeof(ans));
	if(cmp(a,b)==1){
		
	}
	else if(cmp(a,b)==0){
		ans[0]=1;
	}
	else if(cmp(a,b)==-1){
		
	}
	return ans;
}
int main (){
	init();
//	printf("multiply %s\n",addition(op1,op2));
//	printf("multiply %s\n",subtraction(op1,op2));
	printf("multiply %s\n",multiplication(op1,op2));
	return 0;
}
