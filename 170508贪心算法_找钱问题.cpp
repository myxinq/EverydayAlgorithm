/**
* ����ҵ���ֵ��100��50��10��5��2��1
* ������ȥ��������������Ա��Ҫ���� x Ԫ
* ��������ѵķ�����Ǯ������������С����
* ������38ԪӦ����10+10+10+5+2+1
**/

#include <iostream>
using namespace std;

int main(){
	//��Ҫ���������
	int total;
	//������ֵ
	int moneys[] = {100, 50, 10, 5, 2, 1};
	//������
	int *res;

	cout<<"Input total money:";
	cin>>total;

	//�������Ŀռ䣨ȫΪ0.1�ģ�
	res = new int[10*(1 + (int)total)];

	int k = 0;//���ڱ���res������±�

	for(int i = 0;;i++){
		//��total����0��ʱ����˳�ѭ��
		if(total == 0){
			break;
		}
		if(moneys[i] <= total){
			while(moneys[i] <= total){
			/*
				//��total����0��ʱ����˳�ѭ������һ��ò�ƿ��Բ�Ҫ
				if(total == 0){
					break;
				}
			*/
				//��������浽res������
				res[k++] = moneys[i];
				//totalҪ��ȥ�Ѿ������˵�����
				total -= moneys[i];
			}
		}
	}

	//������
	for(int i = 0;i < k;i++){
		cout<<res[i]<<"  ";
	}
	cout<<endl<<endl;

	delete(res);

	main();
}