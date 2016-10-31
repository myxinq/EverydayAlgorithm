#include <iostream>
using namespace std;
#include <stdlib.h>
bool isOK(int num);
bool isSame(int num1,int num2);
int main(){
	int num1,num2,num3,num4,num5;
	for(int i=123456;i<=987654;i++){
		if(isOK(i)){
			num1=i*2;
			num2=i*3;
			num3=i*4;
			num4=i*5;
			num5=i*6;
			if(isOK(num1) && isSame(num1,i)){
				if(isOK(num2) && isSame(num2,i)){
					if(isOK(num3) && isSame(num3,i)){
						if(isOK(num4) && isSame(num4,i)){
							if(isOK(num5) && isSame(num5,i)){
								cout<<i<<"  ";
							}
						}
					}
				}
			}
		}
	}
	cout<<endl;

}

bool isOK(int num){
	int arr[6];
	char ch[6];
	bool flag=false;
	if(num>999999 || num<100000){
		return false;
	}
	itoa(num,ch,10);
	for(int i=0;i<6;i++){
		arr[i]=ch[i]-48;
	}
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if(arr[j]==arr[i]){
				//flag=false;
				return false;
			}
		}
	}

	return true;
}

bool isSame(int num1,int num2){
	char ch1[7],ch2[7];
	int arr1[6],arr2[6];
	itoa(num1,ch1,10);
	itoa(num2,ch2,10);
	for(int i=0;i<6;i++){
		arr1[i]=ch1[i]-48;
		arr2[i]=ch2[i]-48;
	}
	int t;
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if(arr1[i]>arr1[j]){
				t=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=t;
			}
			if(arr2[i]>arr2[j]){
				t=arr2[i];
				arr2[i]=arr2[j];
				arr2[j]=t;
			}
		}
	}
	for(int i=0;i<6;i++){
		ch1[i]=arr1[i]+48;
		ch2[i]=arr2[i]+48;
	}
	ch1[6]='\0';
	ch2[6]='\0';
	if(strcmp(ch1,ch2)==0){
		return true;
	}
	return false;
}