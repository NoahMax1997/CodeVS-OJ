#include <iostream>
#include <string>
#include <string.h>
#include <map> 
using namespace std;
typedef struct wordNode{
	string strWord;
	int strLen;
	int sum[25];
	int sumHash;
}wordNode;
wordNode first;
int n,flag=0,ans=0;
string dic[25];
map<string,map<int,bool> > flagMap; 
void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>dic[i];
		first.sum[i]=0;
		for(int j=0;j<i;j++){
			if(dic[j]==dic[i]){
				i--;
				n--;
				break;
			}
		}
	} 
//	cout<<n<<endl;
	cin>>first.strWord;
	first.strLen=first.strWord.length();
	first.sumHash=0;
}
void  getHash(wordNode& test){
	test.sumHash=0;
	for(int i=0;i<n;i++){
		test.sumHash*=3;
		test.sumHash+=test.sum[i];
	}
}
bool isOver(string str1,string str2){
	//判断str1 str2 
	int len1=str1.length(),len2=str2.length();
	if(len1<len2){
		//保证str1比str2长 
		string t=str1;
		str1=str2;
		str2=t;
		len1=len1+len2;
		len2=len1-len2;
		len1=len1-len2;
	}
	if(str1.find(str2)==str1.length()-str2.length()&&str2.find(str1.at(str1.length()-1))==str2.length()-1) return 1;
	return 0;
}
wordNode combine(wordNode node1,string str2,int num){
	string str1=node1.strWord;
	char ch=str1.at(node1.strLen-1);
	int index=-1;
	index=str2.find(ch,index+1);
	int overStrlen=0;
	while(index!=string::npos){
		int i;
		for(i=index;i>=0;i--){
			if(str1.at(node1.strLen-1-index+i)!=str2.at(i)){
				index=str2.find(ch,index+1);
				break;
			}
		}
		if(i==-1){
			overStrlen=index+1;
			break;
		}
		if(index==string::npos) break;		
	}
	if(overStrlen==0) return node1;
	node1.strWord+=str2.substr(overStrlen,str2.length()-overStrlen);
	node1.strLen=node1.strWord.length();
	node1.sum[num]++;
	getHash(node1);
	return node1;
}
void dfsWord(wordNode word){
	for(int i=0;i<n;i++){
		if(first.strWord==word.strWord&&first.strWord.at(0)!=dic[i].at(0)) continue;
		if(isOver(word.strWord,dic[i])&&first.strWord!=word.strWord)			//两部分有重合  不能成为龙 
			continue;
		if(word.sum[i]>=2) continue;	
		wordNode test=combine(word,dic[i],i);
		if(test.strWord==word.strWord) continue;
		if(flagMap[test.strWord].find(test.sumHash)!=flagMap[test.strWord].end()) //该状态已经存在 
			continue;
//		word=test;
		flagMap[test.strWord][test.sumHash]=1;
//		cout<<test.strWord<<"\n";
		dfsWord(test);
//		cout<<test.strWord<<"\n";
	}
	if(word.strLen>ans)
	{   
		ans=word.strLen;
	 } 
}
void output(){
	cout<<ans<<"\n";
}
int main (){
	init();
	dfsWord(first);
	output();
	return 0;
} 
