#include <bits/stdc++.h>
#define MAX 987654321

using namespace std;

int main(){
    int N, M, a, b;
    cin>>N>>M;
    int dist[N+1][N+1];
    int ans=0;
    for (int i=0; i<N+1; i++){
        for (int j=0; j<N+1; j++){
            dist[i][j]=MAX;
        }
    }
    for (int i=0; i<M; i++){
        cin>>a>>b;
        dist[a][b]=1;
    }
    for (int k=1; k<=N; k++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
            }
        }
    }

    for (int i=1; i<=N; i++){
        int cnt=0;
        for (int j=1; j<=N; j++){
            if (dist[i][j]!=MAX || dist[j][i]!=MAX){        //둘 중 하나라도 비교 가능하면!!(특이점)
                cnt++;
            }
        }
        if (cnt==N-1){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}