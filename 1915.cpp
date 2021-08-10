#include <bits/stdc++.h>

using namespace std;

void check(){

}

int main(){
    int n, m;
    string s;
    cin>>n>>m;
    int board[n][m];
    int dp[n][m];
    for (int i=0; i<n; i++){
        cin>>s;
        for (int j=0; j<m; i++){
            board[i][j]=s[j]-'0';
            if (board[i][j]==1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j]==1){
                //check?
            }
              
        }
    }


}