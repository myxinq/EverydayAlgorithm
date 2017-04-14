/************************************************************************/
/* 翻转句子中单词的顺序。
/* 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
/* 句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
/* 例如输入“I am a student.”，则输出“student. a am I”。
/************************************************************************/

#include <iostream>
#include <conio.h>
using namespace std;
void reversalWords(char* str);

int main(){
	char *str;
	char ch;
	str=(char*)malloc(1*sizeof(char*));
	int i;
	for(i=0;;i++){
		ch=getchar();	
		if(ch=='\n'){
			break;
		}
		char* newStr=(char*)realloc(str,(i+1)*sizeof(char*));
		str=newStr;
		str[i]=ch;
	}
	str[i]='\0';
	cout<<"翻转前："<<endl<<str<<endl;
	reversalWords(str);

	cout<<"----------------"<<endl;
	free(str);

}

void reversalWords(char* str){
	char* word=(char*)malloc(sizeof(char*));	
	char (*words)[50];
	char (*newWords)[50];
	words=(char (*)[50])malloc(50*sizeof(char*));
	int lengthOfWord=0;
	int numOfWords=0;
	int i=0;
	int flag=0;
	int flag1=0;
	for(i=0;i<strlen(str);i++){
		if(str[i]!=' '){
			flag=0;
			flag1=1;
		}
		if(flag==0 && flag1){
			flag1=1;
			flag=0;
			char* newWord=(char*)realloc(word,(lengthOfWord+1)*sizeof(char*));
			word=newWord;
			word[lengthOfWord]=str[i];
			lengthOfWord++;
		}
		if(str[i]==' ' || i==strlen(str)-1){
			flag=1;			
		}
		if(flag && flag1){
			char* newWord=(char*)realloc(word,(lengthOfWord+1)*sizeof(char*));
			word=newWord;
			word[lengthOfWord]='\0';
			lengthOfWord=0;
			//cout<<"----"<<word<<"----"<<endl;
			flag=0;
			flag1=0;
			//将单词存入到字符串数组中
			newWords=(char (*)[50])realloc(words,50*(numOfWords+1)*sizeof(char*));
			words=newWords;
			strcpy(words[numOfWords],word);
			numOfWords++;
			continue;
		}
	}
	char temp[50];
	for(int i=0;i<numOfWords/2;i++){
		strcpy(temp,words[i]);
		strcpy(words[i],words[numOfWords-i-1]);
		strcpy(words[numOfWords-i-1],temp);
	}
	
	cout<<endl;
		cout<<"翻转后："<<endl;
	for(int i=0;i<numOfWords;i++){
		cout<<words[i]<<" ";
	}
	cout<<endl;
	
	free(word);
	free(words);
}