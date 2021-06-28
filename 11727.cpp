#include <iostream>
using namespace std;

int main(void){
	int n; cin>>n;
	int sum=0;
	int* dp=new int[n+1];
	dp[0]=0; 
	for (int i=1; i<=n; i++){
		sum=(sum+dp[i-1])%10007;
		if (i%2==0)
			dp[i]=(sum+2);
		else
			dp[i]=(sum+1);
	}
	cout<<dp[n]<<endl;
	return 0;
}