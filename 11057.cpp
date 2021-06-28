#include <iostream>
using namespace std;

int main(void){
	int N; cin>>N;
	int dp[N+1][10];
	const int modular=10007; 
	int sum=0;
	for (int i=0; i<N+1; i++){
		for (int j=0; j<10; j++){
			if (i>1)
				dp[i][j]=0;
			else
				dp[i][j]=1;
		}
	}
	if (N>1){
		for (int i=2; i<N+1; i++){
			for (int j=0; j<10; j++){
				for (int k=j; k<10; k++){
					dp[i][j]=(dp[i][j]+dp[i-1][k])%modular;
				}
			}
		}
	}
	for (int i=0; i<10; i++){
		sum=(sum+dp[N][i])%modular;
	}
	cout<<sum<<endl;
	return 0;
}