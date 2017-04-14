/************************************************************************/
/* 数字填空，使得横竖算式结果为6
/* 【】+【】-【9】=6
/*  +   -    -
/* 【】-【】*【】=6
/*  /   *    -
/* 【】+【】-【】=6
/*  =   =    =
/*  6   6    6
/* 数字范围0--99
/************************************************************************/
#include <iostream>
using namespace std;
#define MAX 100
int main(){
	int a1,a2,a3,a4,a5,a6,a7,a8;
	for(a1=0;a1<MAX;a1++){
		for(a2=0;a2<MAX;a2++){
			if(a1+a2-9!=6)
				continue;
			for(a3=0;a3<MAX;a3++){
				for(a4=0;a4<MAX;a4++){
					for(a5=0;a5<MAX;a5++){
						if(a3-a4*a5!=6)
							continue;
						for(a6=1;a6<MAX;a6++){
							if(a1+a3/a6!=6)
								continue;
							if(a3%a6!=0)
								continue;
							for(a7=0;a7<MAX;a7++){
								if(a2-a4*a7!=6)
									continue;
								for(a8=0;a8<MAX;a8++){
									if(a6+a7-a8==6 && 9-a5-a8==6){
										cout<<a1<<"\t"<<a2<<"\t"<<9<<endl;
										cout<<a3<<"\t"<<a4<<"\t"<<a5<<endl;
										cout<<a6<<"\t"<<a7<<"\t"<<a8<<endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}