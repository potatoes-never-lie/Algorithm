#include <bits/stdc++.h>

using namespace std;
vector<int> v;

typedef struct edge{
    int start;
    int end;
    int weight;
} edge;


struct cmp{             //priority queue 오름차순으로 먼저 튀어나오게
    bool operator()(const edge& a, const edge& b){
        return a.weight > b.weight;
    }
};

int find(int a){
    if (v[a]==a){
        return a;
    }
    return v[a]=find(v[a]);
}

void union_(int a, int b){
    int pa=find(v[a]);
    int pb=find(v[b]);
    v[pa]=pb;
}


int main(){
    int N, M;
    int a,b,c;
    int cnt=0;
    int cost=0;
    priority_queue<edge, vector<edge>, cmp> pq;
    cin>>N>>M;
    for (int i=0; i<M; i++){
        cin>>a>>b>>c;
        edge e={a,b,c};
        pq.push(e);
    }
    for (int i=0; i<=N; i++){
        v.push_back(i);
    }
    while (!pq.empty()){
        edge now=pq.top();
        pq.pop();
        if (cnt==N-1){
            break;
        }
        if (find(now.start)!=find(now.end)){
            union_(now.start, now.end);
            cost+=now.weight;
            cnt++;
        }
    }
    cout<<cost<<"\n";
}