/************************************************************************
* 给定一个如下格式的字符串(1,(2,3),(4,(5,6),7))括号内的元素可以是数字，
* 也可以是另一个括号，请实现一个算法消除嵌套的括号，
* 比如把上面的表达式变成：(1,2,3,4,5,6,7)，如果表达式有误请报错。 
************************************************************************/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool deleteBrackets(string &str);

int main(){
	string str;
	cout<<"Input a string:"<<endl;
	getline(cin,str);
	if(!deleteBrackets(str)){
		cout<<"The format is wrong!"<<endl;
	}
	else
		cout<<str;
	cout<<endl<<"---------------"<<endl;
	main();
}

bool deleteBrackets(string &str){
	stack<char> sk;
	for(int i=0;i<str.length();i++){
		if(str[i]=='('){
			sk.push(str[i]);			
		}
		if(str[i]==')'){
			if(sk.empty()){
				return 0;
			}
			sk.pop();
		}
	}
	if(!sk.empty()){
		return 0;
	}
	string newStr="";
	for(int i=0;i<str.length();i++){
		if((str[i]=='(' || str[i]==')' ) && (i>=1 && i<str.length()-1)){
			continue;
		}
		newStr+=str[i];
	}
	str=newStr;
	return 1;

}