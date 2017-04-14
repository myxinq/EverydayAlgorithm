#include <iostream>
#include <string>
using namespace std;
#define MAXLEN 20

//用于计算后缀表达式
typedef struct StackSq{
	double data[MAXLEN];
	int top;
}StackSq,*Stack;

//用于转后缀表达式存符号
typedef struct OpSatckSq{
	char op[MAXLEN];
	int top;
}OpSatckSq,*OpStack;

void initStack(Stack &St){
	St=(Stack)malloc(sizeof(StackSq));
	if(St==NULL){
		cout<<"Create error!"<<endl;
		return;
	}
	St->top=-1;
}
int isFull(Stack St){
	return (St->top==MAXLEN-1);
}
int isEmpty(Stack St){
	return (St->top==-1);
}
void push(Stack &St,double data){
	if(isFull(St)){
		cout<<"This stack is full!"<<endl;
		return;
	}
	St->top++;
	St->data[St->top]=data;
}
void pop(Stack &St){
	if(isEmpty(St)){
		cout<<"This stack is empty!"<<endl;
		return;
	}
	St->top--;
}
double top(Stack St){
	if(!isEmpty(St))
		return St->data[St->top];
	else
		cout<<"This stack is empty!"<<endl;
}
////////////////
void initOpStack(OpStack &St){
	St=(OpStack)malloc(sizeof(OpSatckSq));
	if(St==NULL){
		cout<<"Create error!"<<endl;
		return;
	}
	St->top=-1;
}
int isOpFull(OpStack St){
	return (St->top==MAXLEN-1);
}
int isOpEmpty(OpStack St){
	return (St->top==-1);
}
void pushOp(OpStack &St,char data){
	if(isOpFull(St)){
		cout<<"This OpStack is full!"<<endl;
		return;
	}
	St->top++;
	St->op[St->top]=data;
}
void popOp(OpStack &St){
	if(isOpEmpty(St)){
		cout<<"This OpStack is empty!--pop"<<endl;
		return;
	}
	St->top--;
}
char topOp(OpStack St){
	if(!isOpEmpty(St))
		return St->op[St->top];
	else
		cout<<"This OpStack is empty!--top"<<endl;
}
double calc(string str){
	Stack St;
	initStack(St);
	int i;
	int length=0;
	string strArr[100];//存放中缀表达式数组格式
	for(i=0;i<100;i++){
		strArr[i]="";
	}
	string suffix[100];//存放后缀表达式符号
	for(i=0;i<100;i++){
		suffix[i]="";
	}

	//将中缀表达式的字符串转换成数组格式
	for(i=0;i<str.length();i++){
		if(!(str[i]>=48 && str[i]<=57) && i!=0){
			length++;			
		}

		strArr[length]+=str[i];
		
		if(!(str[i]>=48 && str[i]<=57)){
			length++;
		}
	}
	
	OpStack opSt;
	initOpStack(opSt);
	int suffixLen=0;
	/************************************************************************
	* 将中缀表达式转为后缀表达式
	************************************************************************/
	for(i=0;i<length+1;i++){
		if(!(strArr[i]=="+" || strArr[i]=="-" || strArr[i]=="*" || strArr[i]=="/" || strArr[i]=="(" ||strArr[i]==")")){
			suffix[suffixLen++]=strArr[i];
			continue;
		}
		if(strArr[i]=="*" || strArr[i]=="/"){
			pushOp(opSt,strArr[i][0]);
		}
		if(strArr[i]=="+" || strArr[i]=="-"){
			if(!isOpEmpty(opSt ) && topOp(opSt)!='+' && topOp(opSt)!='-' && topOp(opSt)!='*' && topOp(opSt)!='/'){
				pushOp(opSt,strArr[i][0]);
			}
			else{
				while(!isOpEmpty(opSt)){
					suffix[suffixLen++]=topOp(opSt);
					popOp(opSt);
				}
				pushOp(opSt,strArr[i][0]);
			}
		}
		if(strArr[i]=="("){
			pushOp(opSt,strArr[i][0]);
		}
		if(strArr[i]==")"){
			while(topOp(opSt)!='(' && !isOpEmpty(opSt)){
				suffix[suffixLen++]=topOp(opSt);
				popOp(opSt);
			}
			if(!isOpEmpty(opSt))
				popOp(opSt);
		}

	}
	while(!isOpEmpty(opSt)){
		suffix[suffixLen++]=topOp(opSt);
		popOp(opSt);
	}
	/*
	cout<<"+++++++++++++++++++++++++++++++++++"<<endl;
	for(i=0;i<suffixLen;i++){
		cout<<suffix[i]<<endl;
	}
	cout<<"+++++++++++++++++++++++++++++++++++"<<endl;
	*/

	/************************************************************************
	* 后缀表达式的计算
	************************************************************************/
	double res,a,b;
	for(i=0;i<suffixLen;i++){
		if(suffix[i]=="")
			continue;
		if(!(suffix[i]=="+" || suffix[i]=="-" || suffix[i]=="*" || suffix[i]=="/")){
			push(St,atof(suffix[i].c_str()));
		}
		else{
			b=top(St);
			pop(St);
			a=top(St);
			pop(St);
			if(suffix[i]=="+"){
				res=a+b;
			}
			if(suffix[i]=="-"){
				res=a-b;
			}
			if(suffix[i]=="*"){
				res=a*b;
			}
			if(suffix[i]=="/"){
				res=a/b;
			}
			push(St,res);
		}
	}
	
	return top(St);

}
int main(){
	string str;
	double res;
	cout<<"Input str:"<<endl;
	getline(cin,str);
	res=calc(str);
	//cout<<str<<endl;
	cout<<"="<<res<<endl;
	main();
}