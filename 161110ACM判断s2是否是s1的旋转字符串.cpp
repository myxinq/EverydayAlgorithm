/************************************************************************
* ��������һ��isSubstring����,
* ���Լ��һ���ַ����Ƿ�����һ���ַ������Ӵ���
* �����ַ���s1��s2��ֻʹ��һ��isSubstring�����ж�s2�Ƿ���s1����ת�ַ�����
* ���磺��waterbottle���ǡ�erbottlewat������ת�ַ�����
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
			cout<<"��"<<endl;
		}
		else{
			cout<<"����"<<endl;
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