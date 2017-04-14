/************************************************************************
* 去除数组中重复的数字
************************************************************************/
#include <iostream>
using namespace std;

int main(){
	int* num;
	int length;	
	cout<<"Input array length:"<<endl;
	cin>>length;
	num=new int[length];

	cout<<"Input "<<length<<" numbers:"<<endl;

	for(int i=0;i<length;i++){
		cin>>num[i];
	}

	for(int i=0;i<length;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<length;i++){
		for(int j=i+1;j<length;j++){
			if(num[j]==num[i]){
				length--;
				for(int k=j;k<length;k++){
					num[k]=num[k+1];
				}
				j--;
			}
		}
	}

	for(int i=0;i<length;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	main();
}
