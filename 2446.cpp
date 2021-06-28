#include <iostream>
using namespace std;

int main(void){
	int n, i, j;
	cin>>n;
	for (i=1; i <= 2*n-1; i++){
		for (j=0; j< (i<=n? i-1: 2*n-(i+1)); j++)
			cout<<" ";
		for (j=0; j< (i<=n? 2*(n-i)+1: 2*(i-n)+1); j++)
			cout<<"*";
	cout<<"\n";
	}
	return 0;
}