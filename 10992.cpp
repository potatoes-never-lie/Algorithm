#include <iostream>
using namespace std;

int main(void){
	int n, i, j;
	cin>>n;
	for (i=1; i<=n-1; i++){
		for (j=1; j<=n-i; j++)
			cout<<" ";
		for (j=1; j<=2*i-1; j++){
			if (j==1 || j==2*i-1) cout<<"*";
			else cout<<" ";
		}
		cout<<"\n";
	}
	for (i=1; i<=2*n-1; i++){
		cout<<"*";
	}
	cout<<"\n";
	return 0;
}