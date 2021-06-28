#include <iostream>
using namespace std;

int main(void){
	int T;
	int n,m;
	cin>>T;
	for (int i=0; i<T; i++){
		cin>>n>>m;
		cout<<"Case #"<<i+1<<": "<<n<<" + "<<m<<" = "<<n+m<<endl;
	}
	return 0;
}
