/**
һ��СŮ��������������ָ��������1����1000��
����Ĵָ����1��ʼ����Ȼ��ʳָΪ2����ָΪ3������ָΪ4��СָΪ5��
��������ת��������ָ����6����ָΪ7��ʳָΪ8����ĴָΪ9����������ʳָ����10����˷�����
����������������ַ�ʽ����ȥ��������ʱ����ͣ���ĸ���ָ�ϣ�
**/

#include <iostream>
using namespace std;

int main(){
	int n;
	int finger = 0;
	int flag = 1;
	cout<<"Input n:";
	cin>>n;
	for(int i = 0;i < n;i++){
		if(flag == 1){
			finger++;
			if(finger == 5){
				flag = 0;
			}
		}
		else{
			finger--;
			if(finger == 1){
				flag = 1;
			}
		}
	}
	
	char fingers[][10] = {"��Ĵָ","ʳָ","��ָ","����ָ","СĴָ"};

	cout<<finger<<"  "<<fingers[finger-1];
	cout<<endl<<endl;
	
	main();
}