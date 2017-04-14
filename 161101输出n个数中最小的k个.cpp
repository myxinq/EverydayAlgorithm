/************************************************************************/
/* 输出n个数中最小的k个										                */
/* 解决思路：																*/
/* 先从小到大排序，再从小输出到第k个											*/
/************************************************************************/
#include <iostream>
using namespace std;

void sort(int* &arr,int n);

int main(){
	int n,k;
	int* arr;
	cout<<"-------------------"<<endl<<"输出n个数中最小的k个"<<endl<<"-------------------"<<endl;
	cout<<"输入n:";
	cin>>n;
	cout<<"输入k:";
	cin>>k;
	if(k>n){
		cout<<"k必须小于等于"<<n<<"!"<<endl;
		return 0;
	}
	cout<<"输入n个整数："<<endl;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,n);

	cout<<"最小的"<<k<<"个："<<endl;
	for(int i=0;i<k;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl<<endl;
	delete(arr);
	main();

}
//从小到大排序
void sort(int* &arr,int n){
	int t;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}

}