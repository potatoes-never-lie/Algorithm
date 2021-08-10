#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

class Node{
    public:
        int y;
        int x;
        int cost;
        Node(int y, int x, int cost){
            this->y=y;
            this->x=x;
            this->cost=cost;
        }
};

struct cmp{
    bool operator()(const Node &a, const Node &b){      //최소 힙을 위한 비교자
        return a.cost>b.cost;
    }
};

int main(){
    int M, N;
    string s;
    cin>>M>>N;
    string map[N];
    priority_queue<Node, vector<Node>, cmp> pq;
    int dist[N][M];
    for (int i=0; i<N; i++){
        cin>>s;
        map[i]=s;
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            dist[i][j]=INF;
        }
    }
    dist[0][0]=0;
    pq.push(Node(0,0,0));
    while (!pq.empty()){
        Node now=pq.top();
        pq.pop();
        if (now.y==N-1 && now.x==M-1){
            break;
        }
        if (now.cost>dist[now.y][now.x]){
            continue;
        }
        for (int i=0; i<4; i++){
            int ny=now.y+dy[i];
            int nx=now.x+dx[i];
            if (ny<0 || nx<0 || ny>=N || nx>=M){
                continue;
            }
            int newcost=(map[ny][nx]=='0')? 0 : 1;
            if (dist[ny][nx]>now.cost+newcost){ //작을 경우에만 갱신
                dist[ny][nx]=now.cost+newcost;
                pq.push(Node(ny,nx,dist[ny][nx]));
            }
        }
    }
    cout<<dist[N-1][M-1]<<"\n";
    return 0;
}