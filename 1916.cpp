#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

class Node{
    public:
        int id;
        int cost;
        Node(int id, int cost){
            this->id=id;
            this->cost=cost;
        }
};

struct cmp{                 //priority queue를 최소 힙으로 만듦(작은거먼저)
    bool operator()(const Node& a, const Node& b){
        return a.cost>b.cost;
    }
};

int main(){
    int N, M;
    int start, end, cost;
    cin>>N>>M;
    int dist[N+1];
    for (int i=0; i<N+1; i++){
        dist[i]=INF;
    }
    vector<vector<Node> > adjList(N+1);
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i=0; i<M; i++){
        cin>>start>>end>>cost;
        adjList[start].push_back(Node(end, cost));
    }
    cin>>start>>end;    //목적지: end
    dist[start]=0;
    pq.push(Node(start, 0));
    while (!pq.empty()){
        Node now=pq.top();
        pq.pop();
        if (now.id==end){
            break;
        }
        if (now.cost>dist[now.id]){
            continue;
        }
        int len=adjList[now.id].size();
        for (int i=0; i<len; i++){
            Node next=adjList[now.id][i];
            if (dist[next.id]>now.cost+next.cost){
                dist[next.id]=now.cost+next.cost;
                pq.push(Node(next.id, dist[next.id]));
            }
        }
    }
    cout<<dist[end]<<"\n";
    return 0;
}