#include <bits/stdc++.h>
#define MAX 987654321

using namespace std;

class Edge{
    public:
        int id;     //도착점
        long cost;
    Edge(int i, long c){
        id=i;
        cost=c;
    }
};

struct cmp{
    bool operator()(const Edge& a, const Edge& b){      //작은 것부터 우선해서 나오게..
        return a.cost > b.cost;
    }
};

int main(){
    int V, E, K;
    int u,v;
    long w;
    cin>>V>>E;
    cin>>K;
    vector<vector<Edge> > adjList(V+1);
    priority_queue<Edge, vector<Edge>, cmp> pq;
    long dist[V+1];
    for (int i=0; i<V+1; i++){
        dist[i]=MAX;
    }
    for (int i=0; i<E; i++){
        cin>>u>>v>>w;
        adjList[u].push_back(Edge(v, w));
    }
    dist[K]=0;
    pq.push(Edge(K, 0));
    while (!pq.empty()){
        Edge now=pq.top();
        pq.pop();
        if (now.cost>dist[now.id]){
            continue;
        }
        for (int i=0; i<adjList[now.id].size(); i++){
            Edge next=adjList[now.id][i];
            if (dist[next.id]>now.cost+next.cost){
                dist[next.id]=now.cost+next.cost;
                pq.push(Edge(next.id, dist[next.id]));
            }
        }
    }
    for (int i=1; i<=V; i++){
        if (dist[i]==MAX){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
    return 0;
}