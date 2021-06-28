#include <iostream>
using namespace std;

int main(void){
	int N; cin>>N;
	long long sum=0;
	const long long modular=1000000000;
	long long dp[N+1][10];
	for (int i=0; i<N+1; i++){
		for (int j=0; j<10; j++){
			dp[i][j]=1;
		}
	}
	for (int i=2; i<N+1; i++){
		for (int j=1; j<=9; j++){
			if (j>=2 && j<=8)
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%modular;
			else if (j==1)
				dp[i][j]=(dp[i-2][j]+dp[i-1][j+1])%modular;
			else
				dp[i][j]=(dp[i-1][j-1])%modular; 
		}
	}
	for (int i=1; i<=9; i++){
		sum=(sum+dp[N][i])%modular; 
	}
	cout<<sum<<endl;
	return 0;
}