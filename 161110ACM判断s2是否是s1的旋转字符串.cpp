/************************************************************************
* 假设你有一个isSubstring函数,
* 可以检测一个字符串是否是另一个字符串的子串。
* 给出字符串s1和s2，只使用一次isSubstring就能判断s2是否是s1的旋转字符串。
* 例如：“waterbottle”是“erbottlewat”的旋转字符串。
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool isSubString(string str,string subStr);
bool isRotation(string str,string rotaStr);

int main(){
	string str1,str2;
	while(1){
		cout<<"Input str1 and str2:"<<endl;
		cin>>str1>>str2;
		if(isRotation(str1,str2)){
			cout<<"是"<<endl;
		}
		else{
			cout<<"不是"<<endl;
		}
		cout<<"-----------------"<<endl;

	}
}

bool isRotation(string str,string rotaStr){
	return (str.size()==rotaStr.size() && isSubString(str+str,rotaStr));
}

bool isSubString(string str,string subStr){
	if(str.find(subStr)!=string::npos){
		return true;
	}
	else{
		return false;
	}
}