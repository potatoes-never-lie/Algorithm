#include <iostream>
using namespace std;

int main(void){
	int a,b;
	int f, s, t;
	int r1, r2, r3;
	cin>>a>>b;
	f=b/100; s=(b%100)/10; t=(b%100)%10;
	r1=a*t; r2=a*s; r3=a*f;
	cout<<r1<<endl;
	cout<<r2<<endl;
	cout<<r3<<endl;
	cout<<(r1+(r2*10)+(r3*100))<<endl;
}