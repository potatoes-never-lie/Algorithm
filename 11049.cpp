#include <bits/stdc++.h>

using namespace std;

int main(){
    long r,c;
    int N;
    cin>>N;
    long dp[N][N];
    long matrix[N][2];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            dp[i][j]=0;
        }
    }
    for (int i=0; i<N; i++){
        cin>>r>>c;
        matrix[i][0]=r;
        matrix[i][1]=c;
    }
    for (int i=1; i<=N; i++){
        for (int j=0; j+i-1<N; j++){
            long minVal=pow(2,31);
            for (int k=j; k<j+i-1; k++){
                dp[j][j+i-1]=min(dp[j][k]+dp[k+1][j+i-1]+(matrix[j][0]*matrix[k][1]*matrix[j+i-1][1]), minVal);
            }
        }
    }
    cout<<dp[0][N-1]<<"\n";
    return 0;

}

/* 분할 정복으로 풀어보기 !!!!!!!!!! */