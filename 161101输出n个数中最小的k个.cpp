/************************************************************************/
/* ���n��������С��k��										                */
/* ���˼·��																*/
/* �ȴ�С���������ٴ�С�������k��											*/
/************************************************************************/
#include <iostream>
using namespace std;

void sort(int* &arr,int n);

int main(){
	int n,k;
	int* arr;
	cout<<"-------------------"<<endl<<"���n��������С��k��"<<endl<<"-------------------"<<endl;
	cout<<"����n:";
	cin>>n;
	cout<<"����k:";
	cin>>k;
	if(k>n){
		cout<<"k����С�ڵ���"<<n<<"!"<<endl;
		return 0;
	}
	cout<<"����n��������"<<endl;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr,n);

	cout<<"��С��"<<k<<"����"<<endl;
	for(int i=0;i<k;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl<<endl;
	delete(arr);
	main();

}
//��С��������
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