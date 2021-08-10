#include <bits/stdc++.h>

using namespace std;

//dp: (start, end) 일 때 근우 점수 최대값

int divideconquer(int start, int end, int flag, int ***dp, int *input){ //flag: 0(근우), 1(명우) flag는 누구 차례인가를 나타냄
    if (start==end){
        if (flag==0){
            return dp[flag][start][end]=input[start];
        }
        else{
            return dp[flag][start][end]=0;
        }
    }
    if (dp[flag][start][end]!=0){
        return dp[flag][start][end];
    }
    if (flag==0){
        dp[flag][start][end]=max(divideconquer(start,end-1,1,dp, input)+input[end], 
        divideconquer(start+1, end, 1, dp, input)+input[start]);
    }
    else{
        dp[flag][start][end]=min(divideconquer(start,end-1,0,dp, input), 
        divideconquer(start+1, end, 0, dp, input));  
    }
    return dp[flag][start][end];
}


int main(){
    int T;
    vector<int> anss;
    cin>>T;
    for (int i=0; i<T; i++){
        int N, x, ans;
        int ***dp;
        dp=new int ** [2];
        cin>>N;
        int input[N+1];
        for (int i=1; i<=N; i++){
            cin>>x;
            input[i]=x;
        }
        for (int i=0; i<2; i++){
            dp[i]=new int * [N+1];
            for (int j=0; j<N+1; j++){
                dp[i][j]=new int[N+1];
            }
        } 
        for (int i=0; i<2; i++){
            for (int j=0; j<N+1; j++){
                for (int k=0; k<N+1; k++){
                    dp[i][j][k]=0;
                }
            }
        }
        //dp 초기화
        ans=divideconquer(1, N, 0, dp, input);
        anss.push_back(ans);
        for (int i=0; i<2; i++){
            for (int j=0; j<N+1; j++){
                delete [] dp[i][j];
            }
        }
        for (int i=0; i<2; i++){
            delete [] dp[i];
        }
        delete [] dp;

    }
    for (int i=0; i<anss.size(); i++){
        cout<<anss[i]<<"\n";
    }
    return 0;
}