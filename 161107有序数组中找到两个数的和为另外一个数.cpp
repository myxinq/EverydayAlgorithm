/***********************************************************/
// ����һ���������飬����Ϊlen�����������������X��
// ���Ƿ������������ҵ�����������������֮�͵��ڵ�������X�� 
/***********************************************************/

#include <iostream>
using namespace std;
#include <time.h>
#define LEN 50

int isFind(int* num,int &a,int &b,int x);

int main(){
	int num[LEN];
	int x,a,b;
	srand((unsigned)time(NULL));
	int k=rand()%51;
	for(int i=0;i<LEN;i++){
		num[i]=k;
		k+=rand()%8+1;
	}
	for(int i=0;i<LEN;i++){
		cout<<num[i]<<"  ";
	}
	cout<<endl<<"-----------"<<endl;
	cout<<"Input x:";
	cin>>x;
	if(isFind(num,a,b,x)){
		cout<<"Find!"<<endl<<a<<"+"<<b<<"="<<x<<endl;
	}
	else{
		cout<<"Not find!"<<endl;
	}

}

int isFind(int* num,int &a,int &b,int x){
	int* p;
	int* q;
	p=num;
	q=num+LEN-1;
	while(p<=q){
		if(*p+*q==x){
			a=*p;
			b=*q;
			return 1;			
		}
		if(*p+*q>x){
			q--;
		}
		if(*p+*q<x){
			p++;
		}
	}

	return 0;
}