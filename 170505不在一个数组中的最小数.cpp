/**
* 不在一个数组中的最小数
**/

#include <iostream>
#include <time.h>
using namespace std;
#define MAX_SIZE 1000000
//判断一个整数是否在一个数组里的函数
int isInArray(int num,int *arr){
	for(int i = 0;i < MAX_SIZE;i++){
		if(num == arr[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	int *nums;
	nums = new int[MAX_SIZE];
	int startTime;
	int finishTime;

	startTime = time(NULL);//计算开始时间
	//用于测试的数据，给个最坏的情况，1,2,3,4,.......,1000000
	for(int i = 0;i < MAX_SIZE;i++){
		nums[i] = i+1;
	}
	for(int i = 1;;i++){
		if(!isInArray(i,nums)){
			cout<<"Found! "<<i<<endl;
			break;
		}
	}
	finishTime = time(NULL);//计算结束时间
	cout<<endl<<endl<<(finishTime - startTime)<<"s"<<endl;//两个时间相减可以得到程序执行的时间
	delete(nums);
}