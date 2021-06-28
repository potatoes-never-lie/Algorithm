#include <iostream>
using namespace std;

int main(void){
	int i,j;
	int n;
	cin>>n;
	for (i=1; i<=n; i++){
		for (j=n-i; j>0; j--)
			cout<<" ";
		for (j=1; j<=2*i-1; j++)
			cout<<"*";
		cout<<"\n";
	}
	return 0;
}