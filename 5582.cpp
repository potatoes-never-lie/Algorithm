#include <bits/stdc++.h>

using namespace std;

int main(){
    string A, B;
    cin>>A>>B;
    int aSize=A.size();
    int bSize=B.size();
    int dp[bSize][aSize];
    int ans=0;
    for (int i=0; i<bSize; i++){
        for (int j=0; j<aSize; j++){
            dp[i][j]=0;     //문자열 1의 i번째 == 문자열 2의 j번째가 일치했을때 길이
        }
    }
    for (int i=0; i<bSize; i++){
        for (int j=0; j<aSize; j++){
            if (B[i]==A[j]){
                if (i==0 || j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(dp[i][j], ans);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}