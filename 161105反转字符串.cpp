/************************************************************************/
/* 使用C/C++编写函数，实现字符串反转，
/* 要求不使用任何系统函数，且时间复杂度最小，
/* 函数原型：char* reverse_str(char* str)。
/************************************************************************/

#include <iostream>
using namespace std;
char* reverse_str(char* str);
int main(){
	char* str;
	char* newStr;
	str=(char*)malloc(sizeof(char*));
	char ch;
	for(int i=0;;i++){
		ch=getchar();
		if(ch=='\n'){
			newStr=(char*)realloc(str,(i+1)*sizeof(char*));
			str[i]='\0';
			break;
		}
		newStr=(char*)realloc(str,(i+1)*sizeof(char*));
		str=newStr;
		str[i]=ch;
	}
	cout<<str<<endl;
	str=reverse_str(str);
	cout<<"----------"<<endl;
	cout<<str<<endl;
}

char* reverse_str(char* str){
	int length=strlen(str);
	char t;
	for(int i=0;i<length/2;i++){
		t=str[i];
		str[i]=str[length-i-1];
		str[length-i-1]=t;
	}
	return str;
}
//时间复杂度为O(n)