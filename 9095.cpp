#include <iostream>
using namespace std;

int main(void){
	int n, m;
	int *dp=new int[11];
	dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=4;
	for (int i=4; i<=10; i++){
		dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
	}
	
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>m;
		cout<<dp[m]<<endl;
	}
	return 0;
}
