#include <iostream>
using namespace std;

int main(){
	int Am,An,Bm,Bn,Cm,Cn;
	double **A,**B,**C;
	
	system("cls");
	cout<<"矩阵的乘法 A*B"<<endl;
	cout<<"请输入第一个矩阵的行数Am和列数An："<<endl;
	cout<<"Am:";
	cin>>Am;
	cout<<"An:";
	cin>>An;

	cout<<"请输入第二个矩阵的行数Bm和列数Bn："<<endl;
	cout<<"Bm:";
	cin>>Bm;
	cout<<"Bn:";
	cin>>Bn;

	if(An != Bm){
		cout<<"An必须等于Bm！"<<endl;
		system("pause");
		return main();
	}

	Cm = Am;
	Cn = Bn;

	A = new double *[Am];
	for(int i = 0;i < Am;i++){
		A[i] = new double[An];
	}

	B = new double *[Bm];
	for(int i = 0;i < Bm;i++){
		B[i] = new double[Bn];
	}

	C = new double *[Cm];
	for(int i = 0;i < Cm;i++){
		C[i] = new double[Cn];
	}

	cout<<"请输入矩阵A:"<<endl;
	for(int i = 0;i < Am;i++){
		for(int j = 0;j < An;j++){
			cin>>A[i][j];
		}
	}
	cout<<"请输入矩阵B:"<<endl;
	for(int i = 0;i < Bm;i++){
		for(int j = 0;j < Bn;j++){
			cin>>B[i][j];
		}
	}

	double s = 0;
	for(int i = 0;i < Cm;i++){
		for(int j = 0;j < Cn;j++){
			for(int k = 0;k < An;k++){
				s += A[i][k] * B[k][j];
			}
			C[i][j] = s;
			s = 0;
		}
	}

	cout<<"结果矩阵C:"<<endl;
	for(int i = 0;i < Bm;i++){
		for(int j = 0;j < Bn;j++){
			cout<<C[i][j]<<"  ";
		}
		cout<<endl;
	}

	delete [] A;
	delete [] B;
	delete [] C;

	return 0;

}