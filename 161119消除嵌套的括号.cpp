/************************************************************************
* ����һ�����¸�ʽ���ַ���(1,(2,3),(4,(5,6),7))�����ڵ�Ԫ�ؿ��������֣�
* Ҳ��������һ�����ţ���ʵ��һ���㷨����Ƕ�׵����ţ�
* ���������ı��ʽ��ɣ�(1,2,3,4,5,6,7)��������ʽ�����뱨�� 
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