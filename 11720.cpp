#include <iostream>
using namespace std;

int main(void){
	int n;
	int sum=0;
	string s;
	cin>>n>>s;
	for (int i=0; i<n; i++){
		sum+=s[i]-48;
	}
	cout<<sum<<endl;
	return 0;
}