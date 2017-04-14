/************************************************************************/
/* 输出和为n连续正数序列                                                    */              
/************************************************************************/
#include <iostream>
using namespace std;

void outputOrderArrayWithSumIsN(int n);
int main(){
	int n;
	cout<<"Input n:";
	cin>>n;
	outputOrderArrayWithSumIsN(n);
}

void outputOrderArrayWithSumIsN(int n){
	int sum=0;
	int k=0;
	int length=1;
	int* arr=new int[n];
	bool isRight=false;
	for(int i=1;i<n;i++){
		sum=0;
		k=0;
		length=0;
		isRight=false;
		for(int j=i;j<n;j++){															
			sum+=j;
			arr[k]=j;
			k++;	
			length++;
			if(sum==n){				
				isRight=true;
				break;
			}
			if(sum>n)
				break;
		}
		if(isRight){
			for(int j=0;j<length;j++){
				if(j<length-1)
					cout<<arr[j]<<"+";
				else
					cout<<arr[j]<<"="<<n;
			}
			cout<<endl;
		}		
	}
	delete(arr);
}

