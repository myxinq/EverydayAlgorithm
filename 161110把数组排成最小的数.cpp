/**********************************************************
* 把数组排成最小的数 
* 输入一个正整数数组，
* 把数组里所有数字拼接起来排成一个数，
* 打印能拼接出的所有数字中最小的一个。
* 例如输入数组{3，32，321}，
* 则打印出这三个数字能排成的最小数字为321323。
* 输入：
*    输入可能包含多个测试样例。
*    对于每个测试案例，输入的第一行为一个整数m (1<=m <=100)代表输入的正整数的个数。
*    输入的第二行包括m个正整数，其中每个正整数不超过10000000。
*
* 输出：
*    对应每个测试案例，
*    输出m个数字能排成的最小数字。
*********************************************************/

#include <iostream>
#include<string>
using namespace std;

void convertArrayToMinNum(int* numArr,int arrLength);
int compareStr(char* str1,char* str2);

int main(){
	int m;
	int* numArr;
	int resCount=0;
	string str1,str2;
	while(1){

		cout<<"Input m:(Input 0 to exit)"<<endl;
		cin>>m;
		if(m==0){
			break;
		}
		numArr=new int[m];
		cout<<"Input "<<m<<" integers:"<<endl;
		for(int i=0;i<m;i++){
			cin>>numArr[i];
		}
		convertArrayToMinNum(numArr,m);
		delete(numArr);
	}

}
void convertArrayToMinNum(int* numArr,int arrLength){
	string res="";
	string* str=new string[arrLength];
	for(int i=0;i<arrLength;i++){
		str[i]=to_string(numArr[i]);
	}
	int min;
	for(int k=0;k<arrLength;k++){
		for(int i=0;i<arrLength;i++){
			if(str[i].empty()==1)
				continue;
			min=i;
			for(int j=i+1;j<arrLength;j++){
				if(str[j].empty()==0){
					if((str[i]+str[j])<(str[j]+str[i])){
						min=i;
						break;
					}
					else{
						min=j;
						break;
					}
				}
			
			}
			break;
		}
		res+=str[min];
		str[min]="";
	}
	cout<<res<<endl<<"----------------"<<endl;
}
