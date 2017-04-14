/**********************************************************
* �������ų���С���� 
* ����һ�����������飬
* ����������������ƴ�������ų�һ������
* ��ӡ��ƴ�ӳ���������������С��һ����
* ������������{3��32��321}��
* ���ӡ���������������ųɵ���С����Ϊ321323��
* ���룺
*    ������ܰ����������������
*    ����ÿ�����԰���������ĵ�һ��Ϊһ������m (1<=m <=100)����������������ĸ�����
*    ����ĵڶ��а���m��������������ÿ��������������10000000��
*
* �����
*    ��Ӧÿ�����԰�����
*    ���m���������ųɵ���С���֡�
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
