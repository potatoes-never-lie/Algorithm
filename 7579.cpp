#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    int m, c;
    cin>>N>>M;
    int apps[N+1];
    int value[N+1];
    int dp[N+1][10000]; //i: 앱, j: 활성화 비용 합 (i번째 앱까지 확인했을 때 j cost를 소모해서 얻을 수 있는 최대 메모리)
    int costSum=0;
    for (int i=0; i<N+1; i++){
        for (int j=0; j<1000; j++){
            dp[i][j]=0;
        }
    }
    for (int i=1; i<=N; i++){
        cin>>m;
        apps[i]=m; //각 앱의 메모리 바이트 수
    }
    for (int i=1; i<=N; i++){
        cin>>c;
        value[i]=c; //각 앱의 비용
        costSum+=c;
    }
    for (int i=1; i<=N; i++){
        for (int j=0; j<=costSum; j++){
            if (j-value[i]>=0){     //i 번째 선택
                dp[i][j]=max(dp[i-1][j-value[i]]+apps[i], dp[i][j]);
            }
                dp[i][j]=max(dp[i-1][j], dp[i][j]);
        }
    }

    for (int i=0; i<=costSum; i++){
        if (dp[N][i]>=M){
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}
