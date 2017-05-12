/**
* Floyed�㷨
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
	cout<<"�����������֮��ľ���:"<<endl;
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
					//���м����һ����Ȳ�������̵�ʱ��
					//�ͽ�D�����еľ����R�����·������
					D[i][j] = D[i][k] + D[k][j];
					R[i][j] = k;
				}
			}
		}
	}


	cout<<"D����:\n";
	
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
	cout<<"R����:\n";

	for(int i = 0;i < LEN;i++){
		for(int j = 0;j < LEN;j++){
			cout<<R[i][j]<<" \t";
		}
		cout<<endl;
	}
	cout<<endl;

	/*
	//ѭ��������е�·��
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
			cout<<"����Ϊ:"<<D[start][aim]<<endl;
			cout<<"\n-----------------------------------\n";
		}
	}

	*/

	int start,aim;//��ʼ����յ���
	cout<<endl<<"Input start and aim number:";
	cin>>start>>aim;
	//��a�����¼�����ĵ�
	int a[100]={0};
	a[0] = start;
	a[1] = aim;
	//num���ڼ�¼��������·������
	int num = 2;

	for(int i = 0;i < num-1;){
		if(R[a[i]][a[i+1]] != a[i] && R[a[i]][a[i+1]] != a[i+1]){
			//�������м��ҵ�һ������Ҫ���������ص�ĵ�  �򽫴˵���뵽a�����У���������ƶ���
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

	//���·��
	for(int i = 0;i < num;i++){
		cout<<roads[a[i]]<<" ";
	}
	
	cout<<"���·������Ϊ:"<<D[start][aim]<<endl;
	cout<<"\n-----------------------------------\n";
	
}