/*도움 받아서 해결함....*/
#include <iostream>
using namespace std;

int main(void){
	int T,n; 
	cin>>T;
	int dp[2][100,001];
	dp[0][0]=0; 
	dp[1][0]=0;
	for (int i=0; i<T; i++){
		cin>>n;
		for (int j=0; j<2; j++){
			for (int k=1; k<=n; k++){
				cin>>dp[j][k];
			}
		}
		for (int j=2; )
	}


	return 0;
}