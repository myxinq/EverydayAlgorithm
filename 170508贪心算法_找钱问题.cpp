/**
* 人民币的面值有100，50，10，5，2，1
* 假如你去超市买东西，收银员需要找你 x 元
* 编程输出最佳的方案（钱的总张数尽量小）。
* 比如找38元应该是10+10+10+5+2+1
**/

#include <iostream>
using namespace std;

int main(){
	//需要输入的总数
	int total;
	//保存面值
	int moneys[] = {100, 50, 10, 5, 2, 1};
	//保存结果
	int *res;

	cout<<"Input total money:";
	cin>>total;

	//分配最大的空间（全为0.1的）
	res = new int[10*(1 + (int)total)];

	int k = 0;//用于保存res数组的下标

	for(int i = 0;;i++){
		//当total减到0的时候就退出循环
		if(total == 0){
			break;
		}
		if(moneys[i] <= total){
			while(moneys[i] <= total){
			/*
				//当total减到0的时候就退出循环，这一步貌似可以不要
				if(total == 0){
					break;
				}
			*/
				//将结果保存到res数组中
				res[k++] = moneys[i];
				//total要减去已经保存了的数据
				total -= moneys[i];
			}
		}
	}

	//输出结果
	for(int i = 0;i < k;i++){
		cout<<res[i]<<"  ";
	}
	cout<<endl<<endl;

	delete(res);

	main();
}