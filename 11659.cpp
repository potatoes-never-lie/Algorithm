#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, x;
    int a,b;
    cin>>N>>M;
    int dp[N+1];
    vector<int> ans;
    dp[0]=0;
    for (int i=1; i<=N; i++){
        cin>>x;
        dp[i]=dp[i-1]+x;
    }
    for (int i=0; i<M; i++){
        cin>>a>>b;
        ans.push_back(dp[b]-dp[a-1]);
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}