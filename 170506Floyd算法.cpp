/**
* Floyed算法
**/

#include <iostream>
#include <time.h>
using namespace std;
#define M 1000
#define LEN 8

int main(){
	/*
	srand(time(NULL));
	int D[LEN][LEN];
	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			D[i][j] = rand()%100;

		}
	}
	*/

	//#define LEN 8
	//#define M 1000
	int D[LEN][LEN] = {
		{ 0, M, 8,  5, 8, M, 18, 20 },
		{ M, 0, 4, 10, M, M,  M,  M },
		{ 8, 4, 0,  M, M, M,  M,  5 },
		{ 5,10, M,  0, M, M,  M,  M },
		{ 8, M, M,  M, 0, M, 22,  M },
		{ M, M, M,  M, M, 0,  M, 10 },
		{18, M, M,  M,22, M,  0, 20 },
		{20, M, 5,  M, M,10, 20,  0 } 
	};
	
	/*
	int D[LEN][LEN];
	cout<<"请输入各个点之间的距离:"<<endl;
	for(int i = 0;i < LEN;i++){
		D[i][i] = 0;
		for(int j = i+1;j < LEN;j++){
			cout<<roads[i]<<"->"<<roads[j]<<":";
			cin>>D[i][j];
			D[j][i] = D[i][j];
		}
	}
	*/

	char roads[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int R[LEN][LEN];
	
	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			R[i][j] = j;

		}
	}
	
	for(int k = 0;k < LEN;k++){
		for(int i = 0;i < LEN;i++){
			for(int j = 0;j < LEN;j++){
				if(D[i][k] + D[k][j] < D[i][j]){
					//当中间插入一个点比不插入更短的时候，
					//就将D矩阵中的距离和R矩阵的路径更新
					D[i][j] = D[i][k] + D[k][j];
					R[i][j] = k;
				}
			}
		}
	}


	cout<<"D矩阵:\n";
	
	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			if(D[i][j] == M)
				cout<<"M \t";
			else
				cout<<D[i][j]<<" \t";
		}
		cout<<endl;
	}	
	cout<<"\n---------------------------------------- \n";
	cout<<"R矩阵:\n";

	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			cout<<R[i][j]<<" \t";
		}
		cout<<endl;
	}
	cout<<endl;

	/*
	//循环输出所有的路径
	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			int start,aim;
			start = i;
			aim = j;
			int a[100]={0};
			
			a[0] = i;
			a[1] = j;
			int num = 2;
			for(int i = 0;i < num-1;){
				if(R[a[i]][a[i+1]] != a[i] && R[a[i]][a[i+1]] != a[i+1]){

					for(int j = num;j > i+1;j--){
						a[j] = a[j-1];
					}
					a[i+1] = R[a[i]][a[i+1]];

					num++;
					i = 0;

					continue;
				}
				i++;
			}
			cout<<roads[start]<<"->"<<roads[aim]<<" : ";
			for(int i = 0;i < num;i++){
				cout<<roads[a[i]]<<" ";
			}
			cout<<endl;
			cout<<"长度为:"<<D[start][aim]<<endl;
			cout<<"\n-----------------------------------\n";
		}
	}

	*/

	int start,aim;//起始点和终点编号
	cout<<endl<<"Input start and aim number:";
	cin>>start>>aim;
	//用a数组记录经过的点
	int a[100]={0};
	a[0] = start;
	a[1] = aim;
	//num用于记录所经过的路径点数
	int num = 2;

	for(int i = 0;i < num-1;){
		if(R[a[i]][a[i+1]] != a[i] && R[a[i]][a[i+1]] != a[i+1]){
			//若两地中间找到一个必须要经过其他地点的点  则将此点插入到a数组中（数组向后移动）
			for(int j = num;j > i+1;j--){
				a[j] = a[j-1];
			}
			a[i+1] = R[a[i]][a[i+1]];

			num++;
			i = 0;

			continue;
		}
		i++;
	}

	//输出路径
	for(int i = 0;i < num;i++){
		cout<<roads[a[i]]<<" ";
	}
	
	cout<<"最短路径长度为:"<<D[start][aim]<<endl;
	cout<<"\n-----------------------------------\n";
	
}