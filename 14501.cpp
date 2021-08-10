#include <iostream>
using namespace std;

int main(void){
    int n, t, p, maxVal, res;
    res=0;
    cin>>n;
    int T[n];
    int P[n];
    int dp[n];
    for (int i=0; i<n; i++){
        cin>>t>>p;
        T[i]=t;
        P[i]=p;
        dp[i]=0;
    }
    for (int i=n-1; i>=0; i--){
        maxVal=0;
        if (i+T[i]<=n){
            dp[i]=P[i];
        }
        else{
            dp[i]=0;
            continue;
        }
        for (int j=i+T[i]; j<n; j++){
            if (maxVal<dp[j]){
                maxVal=dp[j];
            }
        }
        dp[i]+=maxVal;
    }
    for (int i=0; i<n; i++){
        if (res<dp[i]){
            res=dp[i];
        } 
    }
    cout<<res<<endl;
    return 0;
}
