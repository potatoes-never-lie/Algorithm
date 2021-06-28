#include <iostream>
using namespace std;

int main(void){
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	if (x1-x2<0 && x2-x3<0){

	}
	else if (x1-x2>0 && x2-x3>0){

	}
	else if (x1-x2==0 && x2-x3==0){

	}
	else
		cout<<"WINNER WINNER CHICKEN DINNER!"<<endl;
	return 0;
}