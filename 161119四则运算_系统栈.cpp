#include <iostream>
#include <string>
#include <stack>
using namespace std;

double calc(string str);

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

double calc(string str){
	stack<double> St;
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
	
	stack<char> opSt;

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
			opSt.push(strArr[i][0]);
		}
		if(strArr[i]=="+" || strArr[i]=="-"){
			if(!opSt.empty() && opSt.top()!='+' && opSt.top()!='-' && opSt.top()!='*' && opSt.top()!='/'){
				opSt.push(strArr[i][0]);
			}
			else{
				while(!opSt.empty()){
					suffix[suffixLen++]=opSt.top();
					opSt.pop();
				}
				opSt.push(strArr[i][0]);
			}
		}
		if(strArr[i]=="("){
			opSt.push(strArr[i][0]);
		}
		if(strArr[i]==")"){
			while(opSt.top()!='(' && !opSt.empty()){
				suffix[suffixLen++]=opSt.top();
				opSt.pop();
			}
			if(!opSt.empty())
				opSt.pop();
		}

	}
	while(!opSt.empty()){
		suffix[suffixLen++]=opSt.top();
		opSt.pop();
	}

	/************************************************************************
	* 后缀表达式的计算
	************************************************************************/
	double res,a,b;
	for(i=0;i<suffixLen;i++){
		if(suffix[i]=="")
			continue;
		if(!(suffix[i]=="+" || suffix[i]=="-" || suffix[i]=="*" || suffix[i]=="/")){
			St.push(atof(suffix[i].c_str()));
		}
		else{
			b=St.top();
			St.pop();
			a=St.top();
			St.pop();
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
			St.push(res);
		}
	}
	
	return St.top();

}