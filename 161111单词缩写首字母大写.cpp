/************************************************************************
* һ��������ÿ�����ʵ�����ĸ�Ĵ�д��ϳ�Ϊ�ô������д��
* ���磬C�����ﳣ�õ�EOF����end of file����д��
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string shortWords(string str);
bool isWord(char ch);
int main(){
	string str;
	getline(cin,str);
	cout<<shortWords(str)<<endl;

}

string shortWords(string str){
	string res="";
	//cout<<str<<endl;
	for(int i=0;i<str.length();i++){
		if(i==0 && isWord(str[i])){
			if((str[0]>='A' && str[0]<='Z')){
				res+=str[0];
			}
			if((str[0]>='a' && str[0]<='z')){
				res+=(str[0]-32);
			}
		}
		if(i!=0 && isWord(str[i]) && !isWord(str[i-1])){
			if((str[i]>='A' && str[i]<='Z')){
				res+=str[i];
			}
			if((str[i]>='a' && str[i]<='z')){
				res+=(str[i]-32);
			}
		}
	}
	return res;
}
bool isWord(char ch){
	if(ch>='A' && ch<='Z'){
		return true;
	}
	if(ch>='a' && ch<='z'){
		return true;
	}
	return false;
}