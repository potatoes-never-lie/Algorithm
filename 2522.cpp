#include <iostream>
using namespace std;

int main(void){
	int n, i, j;
	cin>>n;
	for (i=1; i<=2*n-1; i++){
		for (j=0; j < (i <= n ? n-i: i-n) ; j++)
			cout<<" ";
		for (j=0; j< (i <= n? i: 2*n-i); j++)
			cout<<"*";
		cout<<"\n";
	}
	return 0;
}