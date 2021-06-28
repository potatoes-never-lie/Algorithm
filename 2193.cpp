#include <iostream>
using namespace std;

int main(void){
	int N; cin>>N;
	long long dp[N+1][2];
	dp[0][0]=dp[0][1]=0; dp[1][0]=dp[1][1]=1;
	if (N>1){
		dp[2][0]=2; dp[2][1]=1;
		for (int i=3; i<=N; i++){
			for (int j=0; j<2; j++){
				if (j==0)
					dp[i][j]=dp[i-1][0]+dp[i-1][1];
				else
					dp[i][j]=dp[i-2][0]+dp[i-2][1];
			}
		}
	}
	cout<<dp[N][1]<<endl;
	return 0;
}