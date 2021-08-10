#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int main(){
    int n, m, a, b, c;
    cin>>n>>m;
    int dist[n+1][n+1];
    for (int i=0; i<n+1; i++){
        for (int j=0; j<n+1; j++){
            if (i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=MAX;
            }
        }
    }
    for (int i=0; i<m; i++){
        cin>>a>>b>>c;
        dist[a][b]=min(c,dist[a][b]);
    }
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i==j){
                    continue;
                }
                dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
            }
        }
    }
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (dist[i][j]==MAX){
                cout<<0<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}