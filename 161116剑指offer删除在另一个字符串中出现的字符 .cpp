/************************************************************************
* 题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
* 例如，输入”They are students.”和”aeiou”，
* 则删除之后的第一个字符串变成”Thy r stdnts.”。
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

char* deleteStr(string str1,string str2);
int isInAnotherStr(string str,char ch);

int main(){
	string str1,str2;
	cout<<"Input str1:"<<endl;
	getline(cin,str1);
	cout<<"Input str2:"<<endl;
	getline(cin,str2);
	cout<<"Output:"<<endl;
	cout<<deleteStr(str1,str2)<<endl;
}

char* deleteStr(string str1,string str2){
	int i;
	int length=str1.length();
	char* str=new char[length];
	strcpy(str,str1.c_str());
	for(i=0;i<length;i++){
		if(isInAnotherStr(str2,str[i])){
			length--;
			for(int j=i;j<length;j++){
				str[j]=str[j+1];
			}
			i--;
		}
	}
	str[length]='\0';
	return str;
}
int isInAnotherStr(string str,char ch){
	for(int i=0;i<str.length();i++){
		if(ch==str[i]){
			return 1;
		}
	}
	return 0;
}