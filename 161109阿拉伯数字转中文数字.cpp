/************************************************/
// һ�����ڰ���������ת��������
// ��С��һ�ڵ�int������ת�������ı�ʾ���磺
// 17��һʮ�ߣ�
// 110��һ��һʮ��
// 12345��һ����ǧ������ʮ�壻
// 10101��һ����һ����һ
/************************************************/
#include <iostream>
using namespace std;

void addStr(char* &str,char* str1);
char* transferToChinese(int num);

int main(){
	char* res;
	int num;
	cout<<"Input:";
	cin>>num;
	if(num>=100000000){
		cout<<"������С��һ�ڵ�������"<<endl;
	}
	else{
		res=transferToChinese(num);
		cout<<"Out:"<<res<<endl;
	}
	main();
}

//��str1�ӵ�str����
void addStr(char* &str,char* str1){
	int len1=strlen(str);
	int len2=strlen(str1);
	char* newStr;
	newStr=(char*)realloc(str,(len1+len2)*sizeof(char*));
	str=newStr;
	int i;
	for(i=len1;i<len1+len2;i++){
		str[i]=str1[i-len1];
	}	
	str[i]='\0';
}

char* transferToChinese(int num){
	char* res;
	res=(char*)malloc(1*sizeof(char*));
	strcpy(res,"");
	char str[15];
	itoa(num,str,10);
	char t;
	int length=strlen(str);
	for(int i=length-1;i>=0;i--){
		switch (str[length-i-1]){
			case '9':addStr(res,"��");break;
			case '8':addStr(res,"��");break;
			case '7':addStr(res,"��");break;
			case '6':addStr(res,"��");break;
			case '5':addStr(res,"��");break;
			case '4':addStr(res,"��");break;
			case '3':addStr(res,"��");break;
			case '2':addStr(res,"��");break;
			case '1':addStr(res,"һ");break;
			case '0':if((i)%4!=0 && (str[length-i]!='0') && i!=3 ){
						addStr(res,"��");
					 }
					 if(i==3 && str[length-i]!='0'){
						addStr(res,"��");
					 }
				break;
		}
		switch (i%4){
			case 3:if(str[length-i-1]!='0') addStr(res,"ǧ");break;
			case 2:if(str[length-i-1]!='0') addStr(res,"��");break;
			case 1:if(str[length-i-1]!='0') addStr(res,"ʮ");break;
		}
		if(i==4){
			addStr(res,"��");
		}
	}
	return res;
}