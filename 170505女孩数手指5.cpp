/**
一个小女孩正在用左手手指数数，从1数到1000。
她从拇指算作1开始数起，然后，食指为2，中指为3，无名指为4，小指为5。
接下来调转方向，无名指算作6，中指为7，食指为8，大拇指为9，接下来，食指算作10，如此反复。
问如果她继续按这种方式数下去，最后结束时是在停在哪根手指上？
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
	
	char fingers[][10] = {"大拇指","食指","中指","无名指","小拇指"};

	cout<<finger<<"  "<<fingers[finger-1];
	cout<<endl<<endl;
	
	main();
}