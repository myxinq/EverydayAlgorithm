/************************************************/
// 一亿以内阿拉伯数字转中文数字
// 把小于一亿的int型数字转换成中文表示，如：
// 17：一十七；
// 110：一百一十；
// 12345：一万两千三百四十五；
// 10101：一万零一百零一
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
		cout<<"请输入小于一亿的整数！"<<endl;
	}
	else{
		res=transferToChinese(num);
		cout<<"Out:"<<res<<endl;
	}
	main();
}

//将str1加到str后面
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
			case '9':addStr(res,"九");break;
			case '8':addStr(res,"八");break;
			case '7':addStr(res,"七");break;
			case '6':addStr(res,"六");break;
			case '5':addStr(res,"五");break;
			case '4':addStr(res,"四");break;
			case '3':addStr(res,"三");break;
			case '2':addStr(res,"二");break;
			case '1':addStr(res,"一");break;
			case '0':if((i)%4!=0 && (str[length-i]!='0') && i!=3 ){
						addStr(res,"零");
					 }
					 if(i==3 && str[length-i]!='0'){
						addStr(res,"零");
					 }
				break;
		}
		switch (i%4){
			case 3:if(str[length-i-1]!='0') addStr(res,"千");break;
			case 2:if(str[length-i-1]!='0') addStr(res,"百");break;
			case 1:if(str[length-i-1]!='0') addStr(res,"十");break;
		}
		if(i==4){
			addStr(res,"万");
		}
	}
	return res;
}