/************************************************************************/
/* �����Ķ����Ʊ�ʾ��1�ĸ���
/* ��Ŀ������һ����������������Ķ����Ʊ�����ж��ٸ�1��
/* ��������10������������Ʊ�ʾΪ1010��������1��������2��
/************************************************************************/

#include <iostream>
using namespace std;

char* decToBin(int num);
int count(char* str,char ch);

int main(){
	int num;
	cout<<"Input num:";
	cin>>num;
	cout<<"---"<<decToBin(num)<<"---"<<endl;
	cout<<"The number of 1: "<<count(decToBin(num),'1')<<endl;
	cout<<"----------------------------------"<<endl;
}

char* decToBin(int num){
	char *str=(char*)malloc(sizeof(char*));
	char *newStr;
	int i=0;
	while(num!=0){				
		str[i]=num%2+48;
		i++;
		newStr=(char*)realloc(str,(i+1)*sizeof(char*));
		str=newStr;
		num=num/2;
	}
	str[i]='\0';
	char t;
	int length=strlen(str);
	for(int i=0;i<length/2;i++){
		t=str[i];
		str[i]=str[length-i-1];
		str[length-i-1]=t;
	}
	
	return str;	
}
int count(char* str,char ch){
	int count=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]==ch){
			count++;
		}
	}
	return count;
}