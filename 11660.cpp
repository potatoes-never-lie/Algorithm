#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, x;
    int x1, y1, x2, y2;
    cin>>N>>M;
    int board[N+1][N+1];
    int dp[N+1][N+1];
    vector<int> ans;
    for (int i=0; i<=N; i++){
        for (int j=0; j<=N; j++){
            if (i==0 || j==0){
                board[i][j]=0;
                dp[i][j]=0;
            }
            else{
                cin>>x;
                board[i][j]=x;
                dp[i][j]=dp[i][j-1]+x;
            }
        }
    }
    for (int i=0; i<M; i++){
        cin>>x1>>y1>>x2>>y2;
        int sum=0;
        for (int j=x1; j<=x2; j++){
            sum+=dp[j][y2]-dp[j][y1-1];
        }
        ans.push_back(sum);
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}

/* 누적합을 만드는 점화식 + 넓이를 구하는 점화식 */