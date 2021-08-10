#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, x;
    cin>>N;
    int stairs[N+1];
    int dp[N+1];
    for (int i=0; i<N; i++){
        cin>>x;
        stairs[i+1]=x;
    }
    dp[0]=0;
    if (N==1){
        cout<<stairs[1]<<"\n";
    }
    else if (N==2){
        cout<<stairs[1]+stairs[2]<<"\n";
    }
    else{
        dp[1]=stairs[1];
        dp[2]=stairs[1]+stairs[2];
        for (int i=3; i<=N; i++){
            dp[i]=max(dp[i-2], stairs[i-1]+dp[i-3])+stairs[i];
        }
        cout<<dp[N]<<"\n";
    }
    return 0;
}