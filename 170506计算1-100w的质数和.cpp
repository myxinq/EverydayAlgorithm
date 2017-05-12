/**
* 计算1 - 100w 之间的质数和
**/

#include <iostream>
#include <time.h>
using namespace std;

int isZhiZhu(int num){
	for(int i = 2;i <= sqrt(num);i++){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}


int main(){

	int num;
	int startTime,finishTime;
	long sum = 0;
	int len;
	cout<<"Input Length:";
	cin>>len;
	startTime = time(NULL);
	for(num = 1;num <= len;num++){
		if(isZhiZhu(num)){
			//cout<<num<<" ";
			sum += num;
		}
	}
	finishTime = time(NULL);

	cout<<"sum:"<<sum<<endl;
	cout<<"Time:"<<(finishTime - startTime)<<"s"<<endl<<endl;

	main();
}