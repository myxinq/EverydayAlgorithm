/**
* ����һ�������е���С��
**/

#include <iostream>
#include <time.h>
using namespace std;
#define MAX_SIZE 1000000
//�ж�һ�������Ƿ���һ��������ĺ���
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

	startTime = time(NULL);//���㿪ʼʱ��
	//���ڲ��Ե����ݣ�������������1,2,3,4,.......,1000000
	for(int i = 0;i < MAX_SIZE;i++){
		nums[i] = i+1;
	}
	for(int i = 1;;i++){
		if(!isInArray(i,nums)){
			cout<<"Found! "<<i<<endl;
			break;
		}
	}
	finishTime = time(NULL);//�������ʱ��
	cout<<endl<<endl<<(finishTime - startTime)<<"s"<<endl;//����ʱ��������Եõ�����ִ�е�ʱ��
	delete(nums);
}