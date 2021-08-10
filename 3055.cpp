#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

class Pos{
    public:
        int y,x;
        Pos(int r, int c){
            y=r;
            x=c;
        }
};

int main(){
    char c;
    int R,C;
    cin>>R>>C;
    char map[R][C];
    int dp[R][C];
    queue<Pos> q;
    int tx, ty, dest_x, dest_y;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin>>c;
            map[i][j]=c;
            dp[i][j]=0;
            if (c=='*'){
                q.push(Pos(i,j));
            }
            if (c=='S'){
                ty=i;
                tx=j;
            }
            if (c=='D'){
                dest_y=i;
                dest_x=j;
            }
        }
    }
    q.push(Pos(ty,tx));
    while (!q.empty()){
        ty=q.front().y;
        tx=q.front().x;
        q.pop();
        if (ty==dest_y && tx==dest_x){
            cout<<dp[ty][tx]<<endl;
            return 0;
        }
        for (int i=0; i<4; i++){
            int nx=tx+dx[i];
            int ny=ty+dy[i];
            if (ny<0 || nx<0 || ny>=R || nx>=C){
                continue;
            }
            if (map[ty][tx]=='*'){
                if (map[ny][nx]=='.' && dp[ny][nx]==0){
                    map[ny][nx]='*';
                    q.push(Pos(ny,nx));
                }
            }
            else{
                if (map[ny][nx]=='.' || map[ny][nx]=='D'){
                    if (dp[ny][nx]==0){
                        dp[ny][nx]=dp[ty][tx]+1;
                        q.push(Pos(ny,nx));
                    }
                }
            }
        }
    }
    cout<<"KAKTUS"<<endl;
    return 0;
}